#include "GLWidget.h"
#include "Utils.h"
#include "Data.h"

#include <glm/gtc/matrix_transform.hpp>

GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	m_model = new Model();
	m_backdrop = new Backdrop();
	m_currMovePoints = -1;
	
	m_projectionPoints.resize(JointsNumber);
	m_moveDelta = 0.0f;
	m_moveAllPoints = false;
}

GLWidget::~GLWidget()
{
}	


void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.1f, 0.2f, 0.3f, 1);
	
	// m_projMat = glm::perspective(Fov, BaseViweWidth / BaseViweHeight, 0.1f, 100.f);
	m_projMat = ProjMat;

	//////////////////////////////////////////////////////////////////////////
	// 这里要将m_backdrop 放在 m_model前面初始化
	// 不然将出现奇怪的现象，不信可以试一下。。。。
	m_backdrop->init();
	m_backdrop->setupShaderProgram(backdropVertexShaderFile, backdropFragShaderFile);
	m_backdrop->setupBufferData();

	m_model->init();
	m_model->setupShaderProgram(skeletonVertexShaderFile, skeletonFragShaderFile);
	m_model->setupBufferData();

}


void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (!m_data->m_isvalid)
	{
		return;
	}

	// 正投影
	glViewport(0, 0, RenderViewWidth, RenderViewHeight);
	// glm::mat4 viewFront = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.7f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 viewFront = ViewMat;

	m_model->setMVPMat(m_projMat * viewFront);
	m_model->draw();

	// 背景图片
	float scaleSize = 15 * glm::tan(Fov / 2.0f) / (BaseViweHeight / 2.0f);
	glm::mat4 modelMat = glm::mat4(1.0f);
	modelMat = glm::scale(modelMat, glm::vec3(scaleSize, scaleSize, 1.0f));
	m_backdrop->setMVPMat(m_projMat * viewFront * modelMat);
	m_backdrop->draw();

	// 计算骨架中心点位置，以便虚拟的两个摄像机对准
	glm::vec3 center = this->calSkeletonCenter();
	// 右前方
	glViewport(RenderViewWidth, 0.0f, RenderViewHeight / 2.0f, RenderViewHeight / 2.0f);
	glm::mat4 viewLeftFront = glm::lookAt(center + glm::vec3(0.5f, 0.0f, 0.5f), center, glm::vec3(0.0f, 1.0f, 0.0f));
	m_model->setMVPMat(m_projMat * viewLeftFront);
	m_model->draw();

	// 左前方
	glViewport(RenderViewWidth, RenderViewHeight / 2.0f, RenderViewHeight / 2.0f, RenderViewHeight / 2.0f);
	glm::mat4 viewRightFront = glm::lookAt(center + glm::vec3(-0.5f, 0.0f, 0.0f), center, glm::vec3(0.0f, 1.0f, 0.0f));
	m_model->setMVPMat(m_projMat * viewRightFront);
	m_model->draw();

}


void GLWidget::resizeGL(int width, int height)
{

}


void GLWidget::mousePressEvent(QMouseEvent *mouseEvent)
{
	makeCurrent();
	if (!m_data->m_isvalid)
		return;

	float x = mouseEvent->x();
	float y = mouseEvent->y();

	this->calSkeletonProjectionPoings();
	m_currMovePoints = this->compareClickedPointAndProjPoint(glm::vec2(x, y));

	// 上下帧
	if (m_currMovePoints == -1)
	{
		this->changeCurrFrame(mouseEvent->button());
		// 选择了上下帧后，将进行插值的按钮关闭
		emit sendChangeSmoothRadioButton(false);
	}
	else
	{
		emit sendCurrMoveJointIndex(m_currMovePoints);
	}
	update();
}


void GLWidget::mouseReleaseEvent(QMouseEvent *mouseEvent)
{

}


void GLWidget::mouseMoveEvent(QMouseEvent *mouseEvent)
{

}


void GLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
	makeCurrent();
	float moveDelta = m_moveDelta;

	switch (keyEvent->key())
	{
	// A D 左右（x方向移动）
	case Qt::Key_A:
		this->movePoints(MoveDirection::xAxis, -moveDelta);
		m_model->updateVBOData();
		break;
	case Qt::Key_D:
		this->movePoints(MoveDirection::xAxis, moveDelta);
		m_model->updateVBOData();
		break;
	// W S 上下（y 方向移动）
	case Qt::Key_W:
		this->movePoints(MoveDirection::yAxis, moveDelta);
		m_model->updateVBOData();
		break;
	case Qt::Key_S:
		this->movePoints(MoveDirection::yAxis, -moveDelta);
		m_model->updateVBOData();
		break;
	case Qt::Key_Q:
		this->movePoints(MoveDirection::zAxis, moveDelta);
		m_model->updateVBOData();
		break;
	case Qt::Key_E:
		this->movePoints(MoveDirection::zAxis, -moveDelta);
		m_model->updateVBOData();
		break;
	default:
		break;
	}

	// 每次更新了点的数据后都尝试着进行插值
	this->smoothFrames();

	update();
}


void GLWidget::onMoveDeltaSpinBoxValueChanged(double d)
{
	m_moveDelta = d;
}

void GLWidget::onAllJointsRadioButtonToggled(bool state)
{
	m_moveAllPoints = state;
}


void GLWidget::onSmoothRadioButtonToggled(bool state)
{
	m_smooth = state;
}

void GLWidget::onSmoothStepSpinBoxValueChanged(int step)
{
	m_smoothStep = step;
}

//////////////////////////////////////////////////////////////////////////
// helper 
void GLWidget::calSkeletonProjectionPoings()
{
	glm::mat4 mvpMat = ProjMat * ViewMat;

	for (uint i = 0; i < JointsNumber; i++)
	{
		glm::vec4 onePoint = mvpMat * glm::vec4(m_data->m_jointsData[m_currFrame][i], 1.0f);

		int x = (onePoint.x / onePoint.w * 0.5 + 0.5) * RenderViewWidth;
		int y = RenderViewHeight - (onePoint.y / onePoint.w * 0.5 + 0.5) * RenderViewHeight;

		m_projectionPoints[i] = glm::vec2(x, y);
	}

}


int  GLWidget::compareClickedPointAndProjPoint(glm::vec2 clickedPoint)
{
	float dist = std::numeric_limits<float>::max();
	int selectedPoint = -1;
	for (uint i = 0; i < m_projectionPoints.count(); i++)
	{
		float tmpDist = glm::length(m_projectionPoints[i] - clickedPoint);
		if (dist > tmpDist)
		{
			selectedPoint = i;
			dist = tmpDist;
		}
	}

	// 距离太远了，就假设没有选中点，是选择下一帧
	if (dist > 50)
	{
		return -1;
	}

	return selectedPoint;
}


// @d : 移动的距离
void GLWidget::movePoints(MoveDirection direction, float d)
{
	if (m_currMovePoints == -1 && !m_moveAllPoints)
		return;

	if (m_moveAllPoints)
	{
		for (int i = 0; i < JointsNumber; i++)
		{
			this->moveOnePointOnOneDirection(direction, i, d);
			// 更新存储在Skeleton中的数据
			m_data->m_jointsData[m_currFrame][i] = m_model->m_jointsData[i];
		}
	}
	else
	{
		this->moveOnePointOnOneDirection(direction, m_currMovePoints, d);
		// 更新存储在Skeleton中的数据
		m_data->m_jointsData[m_currFrame][m_currMovePoints] = m_model->m_jointsData[m_currMovePoints];
	}
	emit sendUpdataTextBrowser(m_currFrame);
}


void GLWidget::moveOnePointOnOneDirection(MoveDirection direction, int index, float d)
{
	float x, y, z;

	switch (direction)
	{
	case MoveDirection::xAxis:
		x = m_model->m_jointsData[index].x + d;
		y = m_model->m_jointsData[index].y;
		z = m_model->m_jointsData[index].z;
		m_model->m_jointsData[index] = glm::vec3(x, y, z);
		break;
	case MoveDirection::yAxis:
		x = m_model->m_jointsData[index].x;
		y = m_model->m_jointsData[index].y + d;
		z = m_model->m_jointsData[index].z;
		m_model->m_jointsData[index] = glm::vec3(x, y, z);
		break;
	case MoveDirection::zAxis:
		x = m_model->m_jointsData[index].x;
		y = m_model->m_jointsData[index].y;
		z = m_model->m_jointsData[index].z + d;
		m_model->m_jointsData[index] = glm::vec3(x, y, z);
		break;
	default:
		break;
	}
}


void GLWidget::changeCurrFrame(Qt::MouseButton button)
{
	switch (button)
	{
	case Qt::LeftButton:
		if (m_currFrame == m_data->m_frameCount - 1)
		{
			m_currFrame = m_data->m_frameCount - 1;
		}
		else
		{
			++m_currFrame;
		}
		break;
	case  Qt::RightButton:
		if (m_currFrame == 0)
		{
			m_currFrame = 0;
		}
		else
		{
			--m_currFrame;
		}
		break;
	default:
		break;
	}

	emit sendCurrFrameIndex(m_currFrame);
}


void GLWidget::smoothFrames()
{
	if (!m_smooth)
		return;

	int startFrameIndex = (m_currFrame - m_smoothStep) < 0 ? 0 : m_currFrame - m_smoothStep;
	//int startFrameIndex;
	//int tmp = m_currFrame - m_smoothStep;
	//if((m_currFrame - m_smoothStep) < 0)
	//// if (tmp < 0)
	//	startFrameIndex = 0;
	//else
	//	startFrameIndex = m_currFrame - m_smoothStep;

	int endFrameIndex = m_currFrame;
	int realSmoothStep = endFrameIndex - startFrameIndex;
	
	if (realSmoothStep < 2)
		return;

	QVector<glm::vec3> startFramePosition = m_data->m_jointsData[startFrameIndex];
	QVector<glm::vec3> endFramePosition = m_data->m_jointsData[endFrameIndex];

	
	for (int i = 0; i < JointsNumber; i++)
	{
		// 计算距离
		glm::vec3 start = startFramePosition[i];
		glm::vec3 end = endFramePosition[i];
		
		// 简单的线性插值吧
		float delta = glm::length(start - end) / realSmoothStep;
		glm::vec3 direc = end - start;

		for (int j = startFrameIndex + 1; j < endFrameIndex; j++)
		{
			m_data->m_jointsData[j][i] = start + direc * delta * (float)(j - startFrameIndex);
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// slots

void GLWidget::acceptCurrFrameIndex(int index)
{
	makeCurrent();
	m_currFrame = index;
	m_model->m_jointsData = m_data->m_jointsData[index];
	m_model->updateVBOData();
	m_model->m_isValid = true;

	m_backdrop->generateTexture(m_data->m_frameBasePath.arg(m_currFrame, 6, 10, QLatin1Char('0')));
	m_backdrop->m_isvalid = true;
	update();
}


//////////////////////////////////////////////////////////////////////////
// Helper function
const glm::vec3  GLWidget::calSkeletonCenter()
{
	/*glm::vec3 maxCoord = glm::vec3(std::numeric_limits<float>::min());
	glm::vec3 minCoord = glm::vec3(std::numeric_limits<float>::max());
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 vertex;

	for (uint i = 0; i < m_model->m_jointsData.count(); i++)
	{
		vertex = m_model->m_jointsData[i];
		maxCoord = glm::vec3(
			vertex.x > maxCoord.x ? vertex.x : maxCoord.x,
			vertex.y > maxCoord.y ? vertex.y : maxCoord.y,
			vertex.z > maxCoord.z ? vertex.z : maxCoord.z
		);
		minCoord = glm::vec3(
			vertex.x < minCoord.x ? vertex.x : minCoord.x,
			vertex.y < minCoord.y ? vertex.y : minCoord.y,
			vertex.z < minCoord.z ? vertex.z : minCoord.z
		);
	}

	center = (maxCoord + minCoord) / 2.0f;*/

	glm::vec3 center = m_model->m_jointsData[14];

	return center;
}
