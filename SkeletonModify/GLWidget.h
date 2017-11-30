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

	// ����֡
	void changeCurrFrame(int op);

	// ����ĳһ֡������
	void copyFrame();

	// ��ֵ
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
	// �ƶ���λ
	float m_moveDelta;
	// ����ĳһ֡����
	int m_copyFrameIndex;
	// ��ֵ
	int m_smoothStep;

	// joints ����
	Data *m_data;

	// 21 ���ؽڵ��ͶӰֵ
	QVector<glm::vec2> m_projectionPoints;

	// �ڵ�֮��Ĺ�ϵ��Ϊ�˵����ƶ�
	QVector<int> m_jointsParentsIndex;
	QVector< QVector<int> > m_jointsChildrenIndex;
	QVector<int> m_bonesIndex;

	// 
	ChangeWidgets *m_changeWidgets;

};
