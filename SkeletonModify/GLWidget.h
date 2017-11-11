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
	// Ϊ��������ܹ�������ʹ�������׼�Ǽܵ�����
	const glm::vec3 calSkeletonCenter();
	
	// ���ѡ������
	void calSkeletonProjectionPoings();
	int compareClickedPointAndProjPoint(glm::vec2 clickedPoint);

	// �ƶ���
	void movePoints(MoveDirection direction, float d);
	void moveOnePointOnOneDirection(MoveDirection direction, int index, float d);

	// ����֡
	void changeCurrFrame(Qt::MouseButton button);

	// ��ֵ
	void smoothFrames();

private:
	glm::mat4 m_projMat;

	Model *m_model;
	Backdrop *m_backdrop;
	// joints 
	int m_currMovePoints;
	int m_currFrame;
	// �ƶ�����
	float m_moveDelta;
	// ѡ�����е�
	bool m_moveAllPoints;
	// ��ֵ
	bool m_smooth;
	int m_smoothStep;
	// joints ����
	Data *m_data;
	// 21 ���ؽڵ��ͶӰֵ
	QVector<glm::vec2> m_projectionPoints;
};
