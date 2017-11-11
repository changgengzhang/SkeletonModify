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
	void acceptCurrFrameIndex(int index);
	void keyPressEvent(QKeyEvent *keyEvent);
	void onMoveDeltaSpinBoxValueChanged(double d);
	void onAllJointsRadioButtonToggled(bool state);
	void onSmoothRadioButtonToggled(bool state);
	void onSmoothStepSpinBoxValueChanged(int step);

signals:
	void sendCurrFrameIndex(int);
	void sendCurrMoveJointIndex(int);
	void sendUpdataTextBrowser(int index);
	void sendChangeSmoothRadioButton(bool state);

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

	// 上下帧
	void changeCurrFrame(Qt::MouseButton button);

	// 插值
	void smoothFrames();

private:
	glm::mat4 m_projMat;

	Model *m_model;
	Backdrop *m_backdrop;
	// joints 
	int m_currMovePoints;
	int m_currFrame;
	// 移动距离
	float m_moveDelta;
	// 选中所有点
	bool m_moveAllPoints;
	// 插值
	bool m_smooth;
	int m_smoothStep;
	// joints 数据
	Data *m_data;
	// 21 个关节点的投影值
	QVector<glm::vec2> m_projectionPoints;
};
