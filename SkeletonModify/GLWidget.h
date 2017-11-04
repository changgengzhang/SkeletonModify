#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QEvent>
#include <QKeyEvent>

#include <glm/glm.hpp>

#include "Model.h"
#include "Backdrop.h"

class Data;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	enum MoveDirection
	{
		xAxis,
		yAxis,
		zAxis,
	};
public:
	GLWidget(QWidget *parent);
	~GLWidget();

	void setData(Data *p) { m_data = p; }

	//////////////////////////////////////////////////////////////////////////
	public slots:
	void acceptCurrFrameIndex(uint index);
	void acceptMovePointIndex(int index);
	//void acceptMoveAixsIndex(int index);
	void keyPressEvent(QKeyEvent *keyEvent);

protected:
	// ============== virtual function inherited form QOpenGLWidget ================
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

	void mousePressEvent(QMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QMouseEvent *mouseEvent) override;
	
private:
	//////////////////////////////////////////////////////////////////////////
	// 为了摄像机能够看到，使摄像机对准骨架的中心
	const glm::vec3 calSkeletonCenter();
	
	// 鼠标选择点操作
	void calSkeletonProjectionPoings();
	int compareClickedPointAndProjPoint(glm::vec2 clickedPoint);

	// 移动点
	void movePoints(MoveDirection direction, float d);
	void moveOnePointOnOneDirection(MoveDirection direction, int index, float d);
private:
	glm::mat4 m_projMat;

	Model *m_model;
	Backdrop *m_backdrop;
	// joints 
	int m_currMovePoints;
	//int m_moveDirection;	// -1 None, 0 x, 1 y, 2 z
	uint m_currFrame;
	// joints 数据
	Data *m_data;
	// 21 个关节点的投影值
	QVector<glm::vec2> m_projectionPoints;
};
