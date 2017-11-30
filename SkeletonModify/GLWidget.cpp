#include "GLWidget.h"
#include "Utils.h"
#include "Data.h"
#include "ui_SkeletonModify.h"

#include <glm/gtc/matrix_transform.hpp>

#include <QtMath>
#include <QDateTime>


#include <iostream>

//
//const QVector<int> GLWidget::m_jointsParentsIndex({
//	16, 15,  1,  2,  3,  1,  5,
//	 6, 14,  8,  9, 14, 11, 12,
//	14, 14,  1,  4,  7, 10, 13
//});
//
//const QVector<int> GLWidget::m_bonesIndex({
//	19,  9, 10, 11, 12, 14, 15,
//	16,  0,  1,  2,  4,  5,  6,
//	-1,  8, 18, 13, 17,  3,  7
//});
//
//const QVector< QVector<int> > GLWidget::m_jointsChildrenIndex({
//	QVector<int>({ 0 }),
//	QVector<int>({ 2, 3, 4, 5, 6, 7, 0, 16, 17, 18 }),
//	QVector<int>({ 3, 4, 17 }),
//	QVector<int>({ 4, 17 }),
//	QVector<int>({ 17 }),
//	QVector<int>({ 6, 7, 18 }),
//	QVector<int>({ 7, 18 }),
//	QVector<int>({ 18 }),
//	QVector<int>({ 9, 10, 19 }),
//	QVector<int>({ 10, 19 }),
//	QVector<int>({ 19 }),
//	QVector<int>({ 12, 13, 20 }),
//	QVector<int>({ 13, 20 }),
//	QVector<int>({ 20 }),
//	QVector<int>({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20 }),
//	QVector<int>({ 0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18 }),
//	QVector<int>({ 0 }),
//	QVector<int>({ 17 }),
//	QVector<int>({ 18 }),
//	QVector<int>({ 19 }),
//	QVector<int>({ 20 }),
//});




GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	// data
	m_jointsParentsIndex = JointsParentIndex;
	m_jointsChildrenIndex = JointsChildrenIndex;
	m_bonesIndex = BonesIndex;

	m_model = new Model();
	m_backdrop = new Backdrop();
	m_arcball = new ArcBall(RenderViewWidth, RenderViewHeight, 0.1);

	m_currMovePointsIndex = -1;
	
	m_projectionPoints.resize(JointsNumber);
	m_moveDelta = 0.0f;

	m_currFrameIndex = 0;
	m_currMovePointsIndex = -1;
	m_copyFrameIndex = 0;
	m_smoothStep = 0;
}

GLWidget::~GLWidget()
{
}	

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	
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
	if (!m_data->m_isvalid)
	{
		return;
	}

	glEnable(GL_SCISSOR_TEST);

	// 裁剪窗口进行不同的背景颜色设置
	glScissor(0, 0, RenderViewWidth, RenderViewHeight);
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// 骨架中心点
	glm::vec3 modelCenterPos = this->calSkeletonCenter();

	// 正投影
	glViewport(0, 0, RenderViewWidth, RenderViewHeight);
	
	glm::mat4 viewFront = ViewMat;
	glm::mat4 modelMat = m_arcball->getModelMatrix(viewFront, modelCenterPos);
	glm::vec3 viewPos = ViewPos;

	m_model->draw(modelMat, viewFront, m_projMat, viewPos);

	// 背景图片
	float scaleSize = 15 * glm::tan(Fov / 2.0f) / (BaseViweHeight / 2.0f);
	modelMat = glm::mat4(1.0f);
	modelMat = glm::scale(modelMat, glm::vec3(scaleSize, scaleSize, 1.0f));
	m_backdrop->draw(m_projMat * viewFront * modelMat);

	
	// 上视图, 左下图
	glScissor(RenderViewWidth, 0.0f, RenderViewWidth / 2.0f, RenderViewHeight / 2.0f);
	glClearColor(0.5f, 0.5f, 0.5f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(RenderViewWidth, 0.0f, RenderViewWidth / 2.0f, RenderViewHeight / 2.0f);
	
	viewPos = modelCenterPos + glm::vec3(-0.9f, 0.0f, 0.0f);
	glm::mat4 viewLeftDown = glm::lookAt(viewPos, modelCenterPos, glm::vec3(0.0f, 1.0f, 0.0f));

	modelMat = m_arcball->getModelMatrix(viewLeftDown, modelCenterPos);
	m_model->draw(modelMat, viewLeftDown, m_projMat, viewPos);


	// 左视图， 左上图
	glScissor(RenderViewWidth, RenderViewHeight / 2.0f, RenderViewWidth / 2.0f, RenderViewHeight / 2.0f);
	glClearColor(0.6f, 0.6f, 0.6f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(RenderViewWidth, RenderViewHeight / 2.0f, RenderViewWidth / 2.0f, RenderViewHeight / 2.0f);
	
	viewPos = modelCenterPos + glm::vec3(0.7f, 0.0f, 0.7f);
	glm::mat4 viewLeftUp = glm::lookAt(viewPos, modelCenterPos, glm::vec3(0.0f, 1.0f, 0.0f));

	modelMat = m_arcball->getModelMatrix(viewLeftUp, modelCenterPos);
	m_model->draw(modelMat, viewLeftUp, m_projMat, viewPos);

	glDisable(GL_SCISSOR_TEST);
}


void GLWidget::resizeGL(int width, int height){}


void GLWidget::mousePressEvent(QMouseEvent *mouseEvent)
{
	makeCurrent();
	if (!m_data->m_isvalid)
		return;

	float x = mouseEvent->x();
	float y = mouseEvent->y();

	switch (mouseEvent->button())
	{
	case Qt::LeftButton:
		if (QApplication::queryKeyboardModifiers() == Qt::ControlModifier)
		{
			// arcball 
			m_arcball->mousePressEvent(mouseEvent);
		}
		else
		{
			// arcball reset
			m_arcball->reset();
			this->calSkeletonProjectionPoings();
			m_currMovePointsIndex = this->compareClickedPointAndProjPoint(glm::vec2(x, y));

			if (m_currMovePointsIndex == -1)
				this->settingFrame(1);
			else
				m_changeWidgets->labelCurrJoint->setText(QString::number(m_currMovePointsIndex));
		}
		
		break;
	case Qt::RightButton:
		this->settingFrame(2);
		break;

	default:
		break;
	}

	update();
}


void GLWidget::mouseReleaseEvent(QMouseEvent *mouseEvent)
{

}

void GLWidget::mouseMoveEvent(QMouseEvent *mouseEvent)
{
	makeCurrent();
	if (mouseEvent->buttons() & Qt::LeftButton)
	{
		if (QApplication::queryKeyboardModifiers() == Qt::ControlModifier)
		{
			// arcball 
			m_arcball->mouseMoveEvent(mouseEvent);
		}
	}
	update();
}


//////////////////////////////////////////////////////////////////////////
// self defined slots

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

	update();
}


void GLWidget::acceptCurrFrameIndex(int index)
{
	makeCurrent();
	m_currFrameIndex = index;
	m_model->m_jointsData = m_data->m_jointsData[index];
	m_model->m_bonesLen = m_data->m_bonesLen;
	m_model->updateVBOData();
	m_model->m_isValid = true;

	m_backdrop->generateTexture(m_data->m_frameBasePath.arg(m_currFrameIndex, 6, 10, QLatin1Char('0')));
	m_backdrop->m_isvalid = true;

	// 设置当前帧的值
	m_changeWidgets->labelCurrFrame->setText(QString::number(m_currFrameIndex + 1));
	// 设置 position
	this->settingPositionValueTextBrowser(m_currFrameIndex);
	this->settingSmoothIndexLables();

	update();
}



void GLWidget::onMoveDeltaSpinBoxValueChanged(double d)
{
	m_moveDelta = d;
}


void GLWidget::onCopyFramePushButtonClicked()
{
	makeCurrent();
	this->copyFrame();
	update();
}


void GLWidget::onCopyFrameStepSpinBoxValueChanged(int index)
{
	m_copyFrameIndex = index - 1;
}


void GLWidget::onSmoothPushButtonClicked()
{
	makeCurrent();
	this->smoothFrames();	
	update();
}


void GLWidget::onSmoothStepSpinBoxValueChanged(int step)
{
	m_smoothStep = step;
	this->settingSmoothIndexLables();
}


//////////////////////////////////////////////////////////////////////////
// helper 

void GLWidget::calSkeletonProjectionPoings()
{
	glm::mat4 mvpMat = ProjMat * ViewMat;

	for (uint i = 0; i < JointsNumber; i++)
	{
		glm::vec4 onePoint = mvpMat * glm::vec4(m_data->m_jointsData[m_currFrameIndex][i], 1.0f);

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

	// too far, not select a point
	if (dist > 30)
	{
		return -1;
	}

	return selectedPoint;
}


// @d : 移动的距离
void GLWidget::movePoints(MoveDirection direction, float d)
{
	if (m_currMovePointsIndex == -1)
		return;

	calNewPosition(direction, m_currMovePointsIndex, d);

	this->settingPositionValueTextBrowser(m_currFrameIndex);
}


void GLWidget::calNewPosition(MoveDirection direction, int index, float d)
{
	// 注意14号节点的特殊判断
	// 对应的父亲节点
	int jointParentIndex;
	// 子节点
	QVector<int> jointChildrenIndex;
	// xy   yz  zx
	float x, y, z, boneLen;
	glm::vec3 moveJoint;
	glm::vec3 moveDirec;
	glm::vec3 parentJoint;
	glm::vec3 currJoint;

	jointParentIndex = m_jointsParentsIndex[index];
	jointChildrenIndex = m_jointsChildrenIndex[index];
	currJoint = m_model->m_jointsData[index];

	if (index == jointParentIndex)
	{
		// 14号节点
		switch (direction)
		{
		case MoveDirection::xAxis:
			x = currJoint.x + d;
			y = currJoint.y;
			z = currJoint.z;
			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);
			// 节点移动的方向
			moveDirec = moveJoint - currJoint;
			break;
		case MoveDirection::yAxis:
			x = currJoint.x;
			y = currJoint.y + d;
			z = currJoint.z;
			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);
			// 节点移动的方向
			moveDirec = moveJoint - currJoint;

			break;
		case MoveDirection::zAxis:
			x = currJoint.x;
			y = currJoint.y;
			z = currJoint.z+d;
			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);
			// 节点移动的方向
			moveDirec = moveJoint - currJoint;
			break;
		default:
			break;
		}
	}
	else
	{
		// 与父节点相连接的骨骼长度
		boneLen = m_data->m_bonesLen[m_bonesIndex[index]];
		// 父节点位置
		parentJoint = m_model->m_jointsData[jointParentIndex];
		float realRadius, x1, y1, z1;
		d = -d;
		switch (direction)
		{
		case MoveDirection::xAxis:
			// 投影的长度 xy平面
			z = currJoint.z;
			x = currJoint.x - parentJoint.x;
			y = currJoint.y - parentJoint.y;
			realRadius = sqrt(qPow(boneLen, 2) - qPow(z, 2));
			//左  逆时针，  右顺时针
			x1 = x * qCos(d) - y * qSin(d);
			y1 = x * qSin(d) + y * qCos(d);

			x = parentJoint.x + x1;
			y = parentJoint.y + y1;

			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);

			break;
		case MoveDirection::yAxis:
			// 投影的长度  yz平面
			x = currJoint.x;
			y = currJoint.y - parentJoint.y;
			z = currJoint.z - parentJoint.z;
			realRadius = sqrt(qPow(boneLen, 2) - qPow(x, 2));
			//左  逆时针，  右顺时针
			y1 = y * qCos(d) - z * qSin(d);
			z1 = y * qSin(d) + z * qCos(d);

			y = parentJoint.y + y1;
			z = parentJoint.z + z1;

			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);

			break;
		case MoveDirection::zAxis:
			// 投影的长度  zx平面
			y = currJoint.y;
			z = currJoint.z - parentJoint.z;
			x = currJoint.x- parentJoint.x;
			float realRadius = sqrt(qPow(boneLen, 2) - qPow(y, 2));
			//左  逆时针，  右顺时针
			z1 = z * qCos(d) - x * qSin(d);
			x1 = z * qSin(d) + x * qCos(d);

			z = parentJoint.z + z1;
			x = parentJoint.x + x1;

			// 移动后的新的点
			moveJoint = glm::vec3(x, y, z);
			
			break;
		}
	}
	// 节点移动的方向
	moveDirec = moveJoint - currJoint;
	// 同步更新m_data中的数据
	m_model->m_jointsData[index] = moveJoint;
	m_data->m_jointsData[m_currFrameIndex][index] = moveJoint;
	// 根据移动的方向，移动这个节点的所有孩子结点
	for (int i = 0; i < jointChildrenIndex.count(); i++)
	{
		int j = jointChildrenIndex[i];
		
		if (j == index)
			continue;
		
		m_model->m_jointsData[j] = m_model->m_jointsData[j] + moveDirec;
		// 同步更新m_data中的数据
		m_data->m_jointsData[m_currFrameIndex][j] = m_model->m_jointsData[j];
	}
}


void GLWidget::changeCurrFrame(int op)
{
	// 1 next 2 previous
	switch (op)
	{
	case 1:
		if (m_currFrameIndex == m_data->m_frameCount - 1)
		{
			m_currFrameIndex = m_data->m_frameCount - 1;
		}
		else
		{
			++m_currFrameIndex;
		}
		break;
	case  2:
		if (m_currFrameIndex == 0)
		{
			m_currFrameIndex = 0;
		}
		else
		{
			--m_currFrameIndex;
		}
		break;
	default:
		break;
	}
}


void GLWidget::copyFrame()
{
	// out of range
	m_copyFrameIndex = m_copyFrameIndex < 0 ? 0 : m_copyFrameIndex;
	m_copyFrameIndex = m_copyFrameIndex < m_data->m_frameCount ? m_copyFrameIndex : (m_data->m_frameCount - 1);

	m_data->m_jointsData[m_currFrameIndex] = m_data->m_jointsData[m_copyFrameIndex];
	// 更新冲洗渲染的数据
	m_model->m_jointsData = m_data->m_jointsData[m_currFrameIndex];
	m_model->updateVBOData();
	m_model->m_isValid = true;
}


void GLWidget::smoothFrames()
{	
	int startFrameIndex = m_currFrameIndex - m_smoothStep;
	//  out of range
	startFrameIndex = startFrameIndex < 0 ? 0 : startFrameIndex;
	
	this->interpolateOneJoint(-1, 14, startFrameIndex, m_currFrameIndex);
	
	this->interpolateOneJoint(14, 8, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(8, 9, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(9, 10, startFrameIndex, m_currFrameIndex);
	// this->interpolateOneJoint(10, 19, startFrameIndex, m_currFrameIndex);

	this->interpolateOneJoint(14, 11, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(11, 12 , startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(12, 13, startFrameIndex, m_currFrameIndex);
	//this->interpolateOneJoint(13, 20, startFrameIndex, m_currFrameIndex);

	this->interpolateOneJoint(14, 15, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(15, 1, startFrameIndex, m_currFrameIndex);
	//this->interpolateOneJoint(1, 16, startFrameIndex, m_currFrameIndex);
	//this->interpolateOneJoint(16, 0, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(1, 0, startFrameIndex, m_currFrameIndex);

	this->interpolateOneJoint(1, 2, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(2, 3, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(3, 4, startFrameIndex, m_currFrameIndex);
	//this->interpolateOneJoint(4, 17, startFrameIndex, m_currFrameIndex);

	this->interpolateOneJoint(1, 5, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(5, 6, startFrameIndex, m_currFrameIndex);
	this->interpolateOneJoint(6, 7, startFrameIndex, m_currFrameIndex);
	//this->interpolateOneJoint(7, 18, startFrameIndex, m_currFrameIndex);
}



void GLWidget::interpolateOneJoint(int parentJointIndex, int currJointIndex, int startFrameIndex, int endFrameIndex)
{
	int currFrameIndex;
	glm::vec3 startJointPos, endJointPos, perStepVec, currJointPos;
	
	startJointPos = m_data->m_jointsData[startFrameIndex][currJointIndex];
	endJointPos = m_data->m_jointsData[endFrameIndex][currJointIndex];
	perStepVec = (endJointPos - startJointPos) / (float)(endFrameIndex - startFrameIndex);


	// 特殊处理14号点
	if (currJointIndex == 14)
	{
		for (int step = 1, currFrameIndex = startFrameIndex + 1; currFrameIndex < endFrameIndex; step++, currFrameIndex++)
		{
			currJointPos = startJointPos + perStepVec * (float)step;
			m_data->m_jointsData[currFrameIndex][currJointIndex] = currJointPos;
		}

	}
	else
	{
		// 直线平均插值
		glm::vec3 currParentJointPos, currFakeJointPos, currBoneDirec;
		float currBoneLen;

		for (int step = 1, currFrameIndex = startFrameIndex + 1; currFrameIndex < endFrameIndex; step++, currFrameIndex++)
		{
			// 计算插值点
			currFakeJointPos = startJointPos + perStepVec * (float)step;
			currParentJointPos = m_data->m_jointsData[currFrameIndex][parentJointIndex];
			// 方向可能是反的
			currBoneDirec = glm::normalize(currFakeJointPos - currParentJointPos);
			
			currBoneLen = m_data->m_bonesLen[m_bonesIndex[currJointIndex]];
			currJointPos = currParentJointPos + currBoneLen * currBoneDirec;

			// 更新数据
			m_data->m_jointsData[currFrameIndex][currJointIndex] = currJointPos;
		}

	}
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


void GLWidget::settingPositionValueTextBrowser(int currFrame)
{
	QVector<glm::vec3> data = m_data->m_jointsData[currFrame];
	QString text;


	for (int i = 0; i < JointsNumber; i++)
	{
		float x = data[i].x;
		float y = data[i].y;
		float z = data[i].z;

		text += QString("[%1](%2, %3, %4) ")
			.arg(i, 2, 10, QLatin1Char(' '))
			.arg(x, 11, 'f', 8,QLatin1Char(' '))
			.arg(y, 11, 'f', 8, QLatin1Char(' '))
			.arg(z, 11, 'f', 8, QLatin1Char(' '));
		if ((i + 1) % 2 == 0)
			text += "\n";
	}

	m_changeWidgets->textBrowserPositionValue->setText(text);
}


void GLWidget::settingSmoothIndexLables()
{
	// setting lables of start and end frame index
	m_changeWidgets->labelEndSmoothFrame->setText(QString::number(m_currFrameIndex + 1));

	int startFrameIndex = m_currFrameIndex - m_smoothStep;
	startFrameIndex = startFrameIndex < 0 ? 0 : startFrameIndex;

	m_changeWidgets->labelStartSmoothFrame->setText(QString::number(startFrameIndex + 1));
}


void GLWidget::settingFrame(int op)
{
	if (op == -1)
		return;

	this->changeCurrFrame(op);
	// 当前帧的index
	m_changeWidgets->labelCurrFrame->setText(QString::number(m_currFrameIndex + 1));
	emit sendCurrFrameIndex(m_currFrameIndex);
}

