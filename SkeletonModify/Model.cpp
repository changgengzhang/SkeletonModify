#include "Model.h"
#include "Utils.h"

#include <glm/gtc/type_ptr.hpp>

//// 骨架连接方式
//const QVector<uint> Model::m_jointsConnIndex({ 
//	14, 8, 8, 9, 9, 10, 10, 19, 14, 11, 
//	11, 12, 12, 13, 13, 20, 14, 15, 15, 1, 
//	1, 2, 2, 3, 3, 4, 4, 17, 1, 5, 
//	5, 6, 6, 7, 7, 18, 1, 16, 16, 0 
//});
//
//// 骨架点颜色
//const QVector<glm::vec3> Model::m_color({
//	glm::vec3(1.0f, 0.0f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 0.0f),
//
//	glm::vec3(0.0f, 1.0f, 0.0f),
//	glm::vec3(1.0f, 1.0f, 0.0f),
//	glm::vec3(0.0f, 1.0f, 0.0f),
//
//	glm::vec3(0.0f, 0.0f, 1.0f),
//	glm::vec3(1.0f, 0.0f, 1.0f),
//	glm::vec3(0.0f, 0.0f, 1.0f),
//
//	glm::vec3(0.0f, 1.0f, 0.0f),
//	glm::vec3(1.0f, 1.0f, 0.0f),
//	glm::vec3(0.0f, 1.0f, 0.0f),
//
//	glm::vec3(0.0f, 0.0f, 1.0f),
//	glm::vec3(1.0f, 0.0f, 1.0f),
//	glm::vec3(0.0f, 0.0f, 1.0f),
//
//	glm::vec3(1.0f, 0.0f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 0.0f),
//
//	glm::vec3(1.0f, 1.0f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 1.0f),
//	glm::vec3(1.0f, 1.0f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 1.0f),
//});


// 骨架点颜色
const QVector<glm::vec3> Model::m_color({
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),

	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),

	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),

	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),

	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),

	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
});



Model::Model(QObject *parent)
	: QObject(parent),
	m_isValid(false)
{
	// data
	m_jointsConnIndex = JointsConnIndex;

	// joint
	m_jointShaderProgram = new QOpenGLShaderProgram();
	m_jointVao = new QOpenGLVertexArrayObject();
	m_jointVbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_jointEbo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

	// sphere
	m_sphereShaderProgram = new QOpenGLShaderProgram();
	m_sphereVao = new QOpenGLVertexArrayObject();
	m_sphereVbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	m_sphereEbo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

}

Model::~Model()
{
}


void Model::init()
{
	initializeOpenGLFunctions();
	this->setupSphereModel();
}


void Model::draw(glm::mat4 modelMat, glm::mat4 viewMat, glm::mat4 projMat, glm::vec3 viewPos)
{
	if (m_isValid)
	{
		this->setSkeletonMVPMat(modelMat, viewMat, projMat);
		this->assignUniformValues();
		this->drawPoints();
		this->drawSphere(viewPos);
		// this->drawLines();
	}

}


void Model::drawPoints()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glPointSize(10);

	m_jointShaderProgram->bind();
	m_jointVao->bind();

	glDrawArrays(GL_POINTS, 0, m_jointsData.count());
	
	m_jointVao->release();
	m_jointShaderProgram->release();

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

	m_jointShaderProgram->bind();
	m_jointVao->bind();
	m_jointEbo->bind();
	glDrawElements(GL_LINES, m_jointsConnIndex.count(), GL_UNSIGNED_INT, 0);
	m_jointEbo->release();

	m_jointVao->release();
	m_jointShaderProgram->release();

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

	// 重新使用新的Shader
	if (m_jointShaderProgram->isLinked()) m_jointShaderProgram->removeAllShaders();\

	m_jointShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
	m_jointShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);
	// link for compile shader
	m_jointShaderProgram->link();
}


void Model::setupBufferData()
{
	// 数据更新后重新绑定，清除原先的绑定
	if (m_jointVao->isCreated()) m_jointVao->destroy();
	if (m_jointVbo->isCreated()) m_jointVbo->destroy();
	if (m_jointEbo->isCreated()) m_jointVbo->destroy();

	m_jointShaderProgram->bind();
	// create vao
	m_jointVao->create();
	m_jointVao->bind();

	// vbo set
	m_jointVbo->create();
	m_jointVbo->bind();
	m_jointVbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
	// 分配Buffer给 position and color
	//m_vbo->allocate(m_jointsData.count() * sizeof(glm::vec3) * 2);
	m_jointVbo->allocate(JointsNumber * sizeof(glm::vec3) * 2);

	// position
	m_jointVbo->write(0, m_jointsData.constData(), m_jointsData.count() * sizeof(glm::vec3));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	// clolor
	m_jointVbo->write(JointsNumber * sizeof(glm::vec3), m_color.constData(), m_color.count() * sizeof(glm::vec3));
	glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(m_jointsData.count() * sizeof(glm::vec3)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(JointsNumber * sizeof(glm::vec3)));

	// 创建画直线的索引
	m_jointEbo->create();
	m_jointEbo->bind();
	m_jointEbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_jointEbo->allocate(m_jointsConnIndex.constData() ,m_jointsConnIndex.count() * sizeof(uint));
	// 注意ebo不能release, 如果release了，在glDrawElements 时要bind
	m_jointEbo->release();

	m_jointVao->release();
	m_jointShaderProgram->release();
}


void Model::updateVBOData()
{
	m_jointVbo->write(0, m_jointsData.constData(), m_jointsData.count() * sizeof(glm::vec3));
}



void Model::setSkeletonMVPMat(glm::mat4 modelMat, glm::mat4 viewMat, glm::mat4 projMat)
{
	m_modelMat = modelMat;
	m_viewMat = viewMat;
	m_projMat = projMat;
	m_skeletonMVPMat = m_projMat * m_viewMat * m_modelMat;
}


void Model::assignUniformValues()
{
	m_jointShaderProgram->bind();
	glUniformMatrix4fv(m_jointShaderProgram->uniformLocation("mvpMat"), 1, GL_FALSE, glm::value_ptr(m_skeletonMVPMat));
	m_jointShaderProgram->release();
}


void Model::setupSphereModel()
{
	// 加载球模型
	m_sphereData = trimesh::TriMesh::read("sphere.ply");
	m_sphereData->need_normals();

	// shader program 
	if (m_sphereShaderProgram->isLinked()) m_sphereShaderProgram->removeAllShaders();

	m_sphereShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, sphereVertexShaderFile);
	m_sphereShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, sphereFragShaderFile);
	// link for compile shader
	m_sphereShaderProgram->link();

	// 数据更新后重新绑定，清除原先的绑定
	if (m_sphereVao->isCreated()) m_sphereVao->destroy();
	if (m_sphereVbo->isCreated()) m_sphereVbo->destroy();
	if (m_sphereEbo->isCreated()) m_sphereEbo->destroy();

	// create vao
	m_sphereVao->create();
	m_sphereVao->bind();

	// vbo set
	m_sphereVbo->create();
	m_sphereVbo->bind();
	m_sphereVbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);

	int verticesSize = m_sphereData->vertices.size() * sizeof(trimesh::point);
	int normalSize = m_sphereData->normals.size() * sizeof(trimesh::point);

	m_sphereVbo->allocate(verticesSize + normalSize);

	m_sphereVbo->write(0, m_sphereData->vertices.data(), verticesSize);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

	m_sphereVbo->write(verticesSize, m_sphereData->normals.data(), normalSize);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)verticesSize);

	// face
	m_sphereEbo->create();
	m_sphereEbo->bind();
	m_sphereEbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
	m_sphereEbo->allocate(m_sphereData->faces.data(), m_sphereData->faces.size() * sizeof(trimesh::TriMesh::Face));
	
	// 注意ebo不能release, 如果release了，在glDrawElements 时要bind
	m_sphereEbo->release();

	m_sphereVao->release();
	m_sphereShaderProgram->release();
}


void Model::drawSphere(glm::vec3 viewPos)
{
	for (int i = 0; i < JointsNumber - 1; i++)
	{
		int a = m_jointsConnIndex[i * 2 + 0];
		int b = m_jointsConnIndex[i * 2 + 1];

		glm::vec3 ajoint = m_modelMat * glm::vec4((m_jointsData[a]), 1.0f);
		glm::vec3 bjoint = m_modelMat * glm::vec4((m_jointsData[b]), 1.0f);

		glm::vec3 boneCenter = (ajoint + bjoint) * 0.5f;
		glm::vec3 boneDirec = bjoint - ajoint;
		
		// 先缩放, 获取骨架长度
		float boneLen = m_bonesLen[BonesIndex[b]];
		// 在y轴上放大到和骨骼长度一样， sphere 的方向为(0, 1.0f, 0.0f)
		glm::mat4 modelMat = glm::mat4(1.0f);

		modelMat = glm::scale(modelMat, glm::vec3(boneLen * 0.2, boneLen, boneLen * 0.2));

		// 旋转
		glm::vec3 rotateAxis = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), boneDirec);
		float rotateTheta = glm::acos(glm::dot(glm::vec3(0.0f, 1.0f, 0.0f), boneDirec) / (glm::length(boneDirec)));
		// 这里加上,m_modelMat,是arcball的旋转
		modelMat = glm::rotate(glm::mat4(1.0f), rotateTheta, rotateAxis) * modelMat;
	
		// 平移
		modelMat = glm::translate(glm::mat4(1.0f), boneCenter) * modelMat;

		m_sphereModelMat = modelMat;
		m_sphereVPMat = m_projMat * m_viewMat;
		// 矩阵
		m_sphereShaderProgram->bind();

		// uniform 变量设置
		glm::vec3 lightPos = glm::vec3(-10.0f, 10.0f, 10.0f);

		glUniformMatrix4fv(m_sphereShaderProgram->uniformLocation("modelMat"), 1, GL_FALSE, glm::value_ptr(m_sphereModelMat));
		glUniformMatrix4fv(m_sphereShaderProgram->uniformLocation("vpMat"), 1, GL_FALSE, glm::value_ptr(m_sphereVPMat));
		glUniform3fv(m_sphereShaderProgram->uniformLocation("lightPos"), 1, glm::value_ptr(lightPos));
		glUniform3fv(m_sphereShaderProgram->uniformLocation("viewPos"), 1, glm::value_ptr(viewPos));

		glEnable(GL_DEPTH_TEST);

		m_sphereVao->bind();
		m_sphereEbo->bind();
		
		glDrawElements(GL_TRIANGLES, m_sphereData->faces.size() * 3, GL_UNSIGNED_INT, 0);
		
		m_sphereEbo->release();
		m_sphereVao->release();
	}
}
