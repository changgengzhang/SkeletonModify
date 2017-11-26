#pragma once

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include <QVector>

#include <glm/glm.hpp>

#include <trimesh2/TriMesh.h>


class Model : public QObject, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	Model(QObject *parent = nullptr	);
	~Model();

	void init();

	void draw(glm::mat4 modelMat, glm::mat4 viewMat, glm::mat4 projMat, glm::vec3 viewPos);

	void loadDataFromFile(QString filename);
	void setupShaderProgram(QString vertexFile, QString fragmentFile);
	void setupBufferData();
	void updateVBOData();
	void generateTexture(QString textureFile) {};
	

private:
	//////////////////////////////////////////////////////////////////////////
	void drawLines();
	void drawPoints();

	void setSkeletonMVPMat(glm::mat4 modelMat, glm::mat4 viewMat, glm::mat4 projMat);
	void assignUniformValues();
	// sphere
	void setupSphereModel();
	void drawSphere(glm::vec3 viewPos);
	// data
public:
	bool m_isValid;
	QVector<glm::vec3> m_jointsData;

	// ¹Ç÷À³¤¶È¡£¡£
	QVector<float> m_bonesLen;
private:
	// point 
	const static QVector<glm::vec3> m_color;
	QVector<uint> m_jointsConnIndex;

	QOpenGLShaderProgram *m_jointShaderProgram;
	QOpenGLVertexArrayObject *m_jointVao;
	QOpenGLBuffer *m_jointVbo;
	QOpenGLBuffer *m_jointEbo;

	// sphere
	trimesh::TriMesh* m_sphereData;
	
	QOpenGLShaderProgram *m_sphereShaderProgram;
	QOpenGLVertexArrayObject *m_sphereVao;
	QOpenGLBuffer *m_sphereVbo;
	QOpenGLBuffer *m_sphereEbo;

	// ========== uniform value ==========
	glm::mat4 m_skeletonMVPMat;

	glm::mat4 m_sphereModelMat;
	glm::mat4 m_sphereVPMat;

	glm::mat4 m_modelMat;
	glm::mat4 m_viewMat;
	glm::mat4 m_projMat;
};
