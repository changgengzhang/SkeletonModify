#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QMap>

#include <glm/glm.hpp>

#include "Model.h"
#include "Backdrop.h"
#include "Utils.h"
#include "ArcBall.h"

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

	void setData(ChangeWidgets *u, Data *p) { m_changeWidgets = u;  m_data = p; }

	//////////////////////////////////////////////////////////////////////////
	public slots:
	void acceptCurrFrameIndex(int index);
	void keyPressEvent(QKeyEvent *keyEvent);
	void onMoveDeltaSpinBoxValueChanged(double d);

	void onCopyFramePushButtonClicked();
	void onCopyFrameStepSpinBoxValueChanged(int index);

	void onSmoothPushButtonClicked();
	void onSmoothStepSpinBoxValueChanged(int step);

signals:
	void sendCurrFrameIndex(int);

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
	// choose the joints by mouse
	void calSkeletonProjectionPoings();
	int compareClickedPointAndProjPoint(glm::vec2 clickedPoint);

	// move points
	void movePoints(MoveDirection direction, float d);
	void calNewPosition(MoveDirection direction, int index, float d);

	// 上下帧
	void changeCurrFrame(int op);

	// 复制某一帧的数据
	void copyFrame();

	// 插值
	void smoothFrames();
	void interpolateOneJoint(int parentJointIndex, int currJointIndex, int startFrameIndex, int endFrameIndex);	

	// helper
	const glm::vec3 calSkeletonCenter();
	void settingPositionValueTextBrowser(int currFrame);
	void settingSmoothIndexLables();
	void settingFrame(int op);

private:
	glm::mat4 m_projMat;

	Model *m_model;
	Backdrop *m_backdrop;
	ArcBall *m_arcball;

	// joints 
	int m_currMovePointsIndex;
	int m_currFrameIndex;
	// 移动单位
	float m_moveDelta;
	// 复制某一帧数据
	int m_copyFrameIndex;
	// 插值
	int m_smoothStep;

	// joints 数据
	Data *m_data;

	// 21 个关节点的投影值
	QVector<glm::vec2> m_projectionPoints;

	// 节点之间的关系，为了调整移动
	QVector<int> m_jointsParentsIndex;
	QVector< QVector<int> > m_jointsChildrenIndex;
	QVector<int> m_bonesIndex;

	// 
	ChangeWidgets *m_changeWidgets;

};
