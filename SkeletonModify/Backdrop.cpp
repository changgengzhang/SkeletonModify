#include "Backdrop.h"
#include "Utils.h"
#include <glm/gtc/type_ptr.hpp>


Backdrop::Backdrop(QObject *parent)
	: QObject(parent),
	m_vertices{
		-BaseViweWidth / 2,  BaseViweHeight / 2, -10.0f, 1.0f, 1.0f,
		-BaseViweWidth / 2, -BaseViweHeight / 2, -10.0f, 1.0f, 0.0f,
		 BaseViweWidth / 2, -BaseViweHeight / 2, -10.0f, 0.0f, 0.0f,
		 BaseViweWidth / 2, -BaseViweHeight / 2, -10.0f, 0.0f, 0.0f,
		 BaseViweWidth / 2,  BaseViweHeight / 2, -10.0f, 0.0f, 1.0f,
		-BaseViweWidth / 2,  BaseViweHeight / 2, -10.0f, 1.0f, 1.0f
	}
{
	m_shaderProgram = new QOpenGLShaderProgram();
	m_vao = new QOpenGLVertexArrayObject();
	m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);

	m_isvalid = false;
	m_textureID = -1;
}

Backdrop::~Backdrop()
{
}

//////////////////////////////////////////////////////////////////////////
// 这个函数是为了执行 initializeOpenGLFunctions 这个函数，这个函数不能放在构造函数中执行
void Backdrop::init()
{
	initializeOpenGLFunctions();
}


void Backdrop::draw(glm::mat4 mvpMat)
{
	if (!m_isvalid)
		return;

	m_mvpMat = mvpMat;
	this->setUniformValues();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEBUG_OUTPUT);
	
	
	m_shaderProgram->bind();
	m_vao->bind();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	m_vao->release();
	m_shaderProgram->release();
	glDisable(GL_DEPTH_TEST);
}


void Backdrop::setupShaderProgram(QString vertexFile, QString fragmentFile)
{
	initializeOpenGLFunctions();
	// 重新使用新的Shader
	if (m_shaderProgram->isLinked()) m_shaderProgram->removeAllShaders();

	m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
	m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);

	// link for compile shader
	m_shaderProgram->link();
}


void Backdrop::setupBufferData()
{
	// 数据更新后重新绑定，清除原先的绑定
	if (m_vao->isCreated()) m_vao->destroy();
	if (m_vbo->isCreated()) m_vbo->destroy();

	m_shaderProgram->bind();
	// create vao
	m_vao->create();
	m_vao->bind();

	// vbo set
	m_vbo->create();
	m_vbo->bind();
	m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
	// 分配Buffer给 position and color
	m_vbo->allocate(m_vertices, 30 * sizeof(float));
	// position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	// color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

	m_vao->release();
	m_shaderProgram->release();
}


void Backdrop::generateTexture(QString textureFile)
{
	if (m_shaderProgram == nullptr) return;

	m_shaderProgram->bind();
	m_vao->bind();

	if (m_textureID != -1)
	{
		glDeleteTextures(1, &m_textureID);
		m_textureID = -1;
	}

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_texture = cv::imread(textureFile.toStdString());
	//////////////////////////////////////////////////////////////////////////
	// 反转2次
	cv::flip(m_texture, m_texture, 1);
	cv::flip(m_texture, m_texture, 0);

	if (m_texture.empty())
		qErrnoWarning("ERROR::IMAGE::setup texture failed");
	else
	{
		// image may align
		glPixelStorei(GL_UNPACK_ALIGNMENT, (m_texture.step & 3) ? 1 : 4);
		glPixelStorei(GL_UNPACK_ROW_LENGTH, m_texture.step / m_texture.elemSize());
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_texture.cols, m_texture.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, m_texture.ptr());
		glGenerateMipmap(GL_TEXTURE_2D);
		glUniform1i(m_shaderProgram->uniformLocation("backdrop"), 0);
	}

	m_vao->release();
	m_shaderProgram->release();
}


void Backdrop::setUniformValues()
{
	m_shaderProgram->bind();
	glUniformMatrix4fv(m_shaderProgram->uniformLocation("mvpMat"), 1, GL_FALSE, glm::value_ptr(m_mvpMat));

	m_shaderProgram->release();
}
