#include "Model.h"
#include "Utils.h"

#include <glm/gtc/type_ptr.hpp>

// �Ǽ����ӷ�ʽ
const QVector<uint> Model::m_jointsConnIndex({ 
	14, 8, 8, 9, 9, 10, 10, 19, 14, 11, 
	11, 12, 12, 13, 13, 20, 14, 15, 15, 1, 
	1, 2, 2, 3, 3, 4, 4, 17, 1, 5, 
	5, 6, 6, 7, 7, 18, 1, 16, 16, 0 
});

// �Ǽܵ���ɫ
const QVector<glm::vec3> Model::m_color({
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
});


Model::Model(QObject *parent)
	: QObject(parent),
	m_isValid(false)
{
	m_shaderProgram = new QOpenGLShaderProgram();
	m_vao = new QOpenGLVertexArrayObject();
	m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_ebo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
}

Model::~Model()
{
}


void Model::init()
{
	initializeOpenGLFunctions();
}


void Model::draw()
{
	if (m_isValid)
	{
		this->setUniformValues();
		this->drawPoints();
		this->drawLines();
	}

}


void Model::drawPoints()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glPointSize(10);

	m_shaderProgram->bind();
	m_vao->bind();

	glDrawArrays(GL_POINTS, 0, m_jointsData.count());
	
	m_vao->release();
	m_shaderProgram->release();

	glDisable(GL_PROGRAM_POINT_SIZE);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_DEPTH_TEST);
}


void Model::drawLines()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LINE_SMOOTH);
	//glEnable(GL_LINE_STIPPLE);
	glLineWidth(2);

	m_shaderProgram->bind();
	m_vao->bind();
	m_ebo->bind();
	glDrawElements(GL_LINES, m_jointsConnIndex.count(), GL_UNSIGNED_INT, 0);
	m_ebo->release();

	m_vao->release();
	m_shaderProgram->release();

	// glDisable(GL_LINE_STIPPLE);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_DEPTH_TEST);
}


void Model::loadDataFromFile(QString filename)
{
	
}


void Model::setupShaderProgram(QString vertexFile, QString fragmentFile)
{
	initializeOpenGLFunctions();
	// ����ʹ���µ�Shader
	if (m_shaderProgram->isLinked()) m_shaderProgram->removeAllShaders();

	m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
	m_shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);

	// link for compile shader
	m_shaderProgram->link();
}


void Model::setupBufferData()
{
	// ���ݸ��º����°󶨣����ԭ�ȵİ�
	if (m_vao->isCreated()) m_vao->destroy();
	if (m_vbo->isCreated()) m_vbo->destroy();
	if (m_ebo->isCreated()) m_vbo->destroy();

	m_shaderProgram->bind();
	// create vao
	m_vao->create();
	m_vao->bind();

	// vbo set
	m_vbo->create();
	m_vbo->bind();
	m_vbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
	// ����Buffer�� position and color
	//m_vbo->allocate(m_jointsData.count() * sizeof(glm::vec3) * 2);
	m_vbo->allocate(JointsNumber * sizeof(glm::vec3) * 2);

	// position
	//m_vbo->write(0, m_jointsData.constData(), m_jointsData.count() * sizeof(glm::vec3));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	// clolor
	m_vbo->write(m_color.count() * sizeof(glm::vec3), m_color.constData(), m_color.count() * sizeof(glm::vec3));
	glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(m_jointsData.count() * sizeof(glm::vec3)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(JointsNumber * sizeof(glm::vec3)));

	// ������ֱ�ߵ�����
	m_ebo->create();
	m_ebo->bind();
	m_ebo->setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_ebo->allocate(m_jointsConnIndex.constData() ,m_jointsConnIndex.count() * sizeof(uint));
	// ע��ebo����release, ���release�ˣ���glDrawElements ʱҪbind
	m_ebo->release();

	m_vao->release();
	m_shaderProgram->release();
}


void Model::updateVBOData()
{
	m_vbo->write(0, m_jointsData.constData(), m_jointsData.count() * sizeof(glm::vec3));
}



void Model::setMVPMat(glm::mat4 mvpMat)
{
	m_mvpMat = mvpMat;
}

void Model::setUniformValues()
{
	m_shaderProgram->bind();
	glUniformMatrix4fv(m_shaderProgram->uniformLocation("mvpMat"), 1, GL_FALSE, glm::value_ptr(m_mvpMat));
	m_shaderProgram->release();
}

