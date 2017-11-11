#pragma once

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include <QVector>

#include <glm/glm.hpp>


class Model : public QObject, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	Model(QObject *parent = nullptr);
	~Model();

	void init();

	void draw();
	void loadDataFromFile(QString filename);
	void setupShaderProgram(QString vertexFile, QString fragmentFile);
	void setupBufferData();
	void updateVBOData();
	void generateTexture(QString textureFile) {};
	void setMVPMat(glm::mat4 mvpMat);

private:
	//////////////////////////////////////////////////////////////////////////
	void drawLines();
	void drawPoints();

	void setUniformValues();


	//////////////////////////////////////////////////////////////////////////
	// data
public:
	bool m_isValid;
	QVector<glm::vec3> m_jointsData;
private:
	const static QVector<glm::vec3> m_color;
	const static QVector<uint> m_jointsConnIndex;

	// opengl 
	QOpenGLShaderProgram *m_shaderProgram;
	QOpenGLVertexArrayObject *m_vao;
	QOpenGLBuffer *m_vbo;
	QOpenGLBuffer *m_ebo;
	


	// ========== uniform value ==========
	glm::mat4 m_mvpMat;

};
