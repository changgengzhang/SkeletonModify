#pragma once

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include <opencv.hpp>

#include <glm/glm.hpp>

class Backdrop : public QObject, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	Backdrop(QObject *parent=nullptr);
	~Backdrop();
	void init();
	void draw();
	void setupShaderProgram(QString vertexFile, QString fragmentFile);
	void setupBufferData();
	void generateTexture(QString textureFile);
	void setMVPMat(glm::mat4 mvpMat);

private:
	//////////////////////////////////////////////////////////////////////////
	void setUniformValues();

public:
	//////////////////////////////////////////////////////////////////////////
	bool m_isvalid;

private:
	float m_vertices[30];
	QOpenGLShaderProgram *m_shaderProgram;
	QOpenGLVertexArrayObject *m_vao;
	QOpenGLBuffer *m_vbo;
	GLuint m_textureID;
	cv::Mat m_texture;

	// ========== uniform value ==========
	glm::mat4 m_mvpMat;

};
