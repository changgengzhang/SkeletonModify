#include "SkeletonModify.h"
#include "QFileDialog"

#include "json.h"
#include "Utils.h"

#include <fstream>

SkeletonModify::SkeletonModify(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	m_isvalid = false;
	m_currFrame = 0;
	m_currMovePoints = -1;
	
	// data pointer
	m_ui.openGLWidget->setData(&m_data);

	this->connectSlotsAndSignals();
}

//////////////////////////////////////////////////////////////////////////
// event filter
bool SkeletonModify::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == m_ui.openGLWidget)
		return SkeletonModify::eventFilter(obj, event);
	
}


// keypressevent
void SkeletonModify::keyPressEvent(QKeyEvent *keyEvent)
{
	if (m_isvalid)
		emit sendKeyEvent(keyEvent);
}

void SkeletonModify::mousePressEvent(QMouseEvent *mouseEvent)
{
	
}


void SkeletonModify::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
	
}


//////////////////////////////////////////////////////////////////////////
// Helper Fuctions
//////////////////////////////////////////////////////////////////////////
void SkeletonModify::connectSlotsAndSignals()
{
	// 加载配置文件按钮点击事件
	connect(m_ui.actionLoadConfigureFile, SIGNAL(triggered()), this, SLOT(onLoadConfigureFileActionTriggered()));
	// 将路径传递给Data, 解析数据
	connect(this, SIGNAL(sendConfigureFilePath(QString)), &m_data, SLOT(acceptConfigureFilePath(QString)));

	// 当前帧的索引号，更新OpenGL数据
	connect(this, SIGNAL(sendCurrFrameIndex(uint)), m_ui.openGLWidget, SLOT(acceptCurrFrameIndex(uint)));

	// 下一帧，上一帧，播放
	connect(m_ui.pushButtonPreFrame, SIGNAL(clicked()), this, SLOT(onPreFramePushButtonClicked()));
	connect(m_ui.pushButtonNextFrame, SIGNAL(clicked()), this, SLOT(onNextFramePushButtonClicked()));
	//connect(m_ui.pushButtonPlayFrame, SIGNAL(clicked()), this, SLOT(onPlayFramePushButtonClicked()));

	// 21个关节点的触发槽函数
	connect(this, SIGNAL(sendPointCheckboxInfo(int, int)), this, SLOT(acceptPointCheckboxInfo(int, int)));
	connect(m_ui.checkboxPoint0, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox0StateChanged(int)));
	connect(m_ui.checkboxPoint1, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox1StateChanged(int)));
	connect(m_ui.checkboxPoint2, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox2StateChanged(int)));
	connect(m_ui.checkboxPoint3, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox3StateChanged(int)));
	connect(m_ui.checkboxPoint4, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox4StateChanged(int)));
	connect(m_ui.checkboxPoint5, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox5StateChanged(int)));
	connect(m_ui.checkboxPoint6, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox6StateChanged(int)));
	connect(m_ui.checkboxPoint7, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox7StateChanged(int)));
	connect(m_ui.checkboxPoint8, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox8StateChanged(int)));
	connect(m_ui.checkboxPoint9, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox9StateChanged(int)));
	connect(m_ui.checkboxPoint10, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox10StateChanged(int)));
	connect(m_ui.checkboxPoint11, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox11StateChanged(int)));
	connect(m_ui.checkboxPoint12, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox12StateChanged(int)));
	connect(m_ui.checkboxPoint13, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox13StateChanged(int)));
	connect(m_ui.checkboxPoint14, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox14StateChanged(int)));
	connect(m_ui.checkboxPoint15, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox15StateChanged(int)));
	connect(m_ui.checkboxPoint16, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox16StateChanged(int)));
	connect(m_ui.checkboxPoint17, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox17StateChanged(int)));
	connect(m_ui.checkboxPoint18, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox18StateChanged(int)));
	connect(m_ui.checkboxPoint19, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox19StateChanged(int)));
	connect(m_ui.checkboxPoint20, SIGNAL(stateChanged(int)), this, SLOT(onPoint1Checkbox20StateChanged(int)));
	// 将选择的要移动的点index传给GLWidget
	connect(this, SIGNAL(sendMovePointIndex(int)), m_ui.openGLWidget, SLOT(acceptMovePointIndex(int)));

	// key event
	connect(this, SIGNAL(sendKeyEvent(QKeyEvent*)), m_ui.openGLWidget, SLOT(keyPressEvent(QKeyEvent*)));
	// 保存改变后的点到文件中
	connect(m_ui.pushButtonSaveToFile, SIGNAL(clicked()), this, SLOT(onSaveToFilePushButtonClicked()));
}





//////////////////////////////////////////////////////////////////////////
// 槽函数
//////////////////////////////////////////////////////////////////////////
void SkeletonModify::onLoadConfigureFileActionTriggered()
{
	QString configureFilePath = QFileDialog::getOpenFileName(this,
		tr("Open Configure"), "../Data", tr("Configure Files (*.json)"));

	if (configureFilePath.isEmpty())
	{
		//m_isvalid = false;
		return;
	}
	else
	{
		emit sendConfigureFilePath(configureFilePath);
		m_isvalid = true;
	}
	m_currFrame = 0;

	// ui settting 
	m_ui.labelTotalFrame->setText(QString::number(m_data.m_frameCount));
	m_ui.labelCurrFrame->setText(QString::number(m_currFrame + 1));
	emit sendCurrFrameIndex(0);
}


// 前后帧的选择
void SkeletonModify::onPreFramePushButtonClicked()
{
	if (!m_isvalid)
		return;

	if (m_currFrame == 0)
		m_currFrame = 0;
	else
	{
		--m_currFrame;
		m_ui.labelCurrFrame->setText(QString::number(m_currFrame + 1));
		emit sendCurrFrameIndex(m_currFrame);
	}
}


void SkeletonModify::onNextFramePushButtonClicked()
{
	if (!m_isvalid)
		return;

	if (m_currFrame == m_data.m_frameCount - 1)
		m_currFrame = m_data.m_frameCount - 1;
	else
	{
		m_currFrame++;
		m_ui.labelCurrFrame->setText(QString::number(m_currFrame + 1));
		emit sendCurrFrameIndex(m_currFrame);
	}
}


//void SkeletonModify::onPlayFramePushButtonClicked()
//{
//
//}

//////////////////////////////////////////////////////////////////////////
// 21个关节点的slots
// 总的处理函数
void SkeletonModify::acceptPointCheckboxInfo(int index, int state)
{
	if (!m_isvalid)
		return;

	if (index != m_currMovePoints)
	{
		if (state == Qt::Unchecked)
			return;
		else
		{
			int tmp = m_currMovePoints;
			m_currMovePoints = index;

			this->setPointCheckboxState(tmp, Qt::Unchecked);
			emit sendMovePointIndex(m_currMovePoints);
			return;
		}
	}
	else
	{
		m_currMovePoints = -1;
		emit sendMovePointIndex(m_currMovePoints);
		return;
	}
}

void SkeletonModify::setPointCheckboxState(int index, Qt::CheckState state)
{
	switch (index)
	{
	case 0:
		m_ui.checkboxPoint0->setCheckState(state);
		break;
	case 1:
		m_ui.checkboxPoint1->setCheckState(state);
		break;
	case 2:
		m_ui.checkboxPoint2->setCheckState(state);
		break;
	case 3:
		m_ui.checkboxPoint3->setCheckState(state);
		break;
	case 4:
		m_ui.checkboxPoint4->setCheckState(state);
		break;
	case 5:
		m_ui.checkboxPoint5->setCheckState(state);
		break;
	case 6:
		m_ui.checkboxPoint6->setCheckState(state);
		break;
	case 7:
		m_ui.checkboxPoint7->setCheckState(state);
		break;
	case 8:
		m_ui.checkboxPoint8->setCheckState(state);
		break;
	case 9:
		m_ui.checkboxPoint9->setCheckState(state);
		break;
	case 10:
		m_ui.checkboxPoint10->setCheckState(state);
		break;
	case 11:
		m_ui.checkboxPoint11->setCheckState(state);
		break;
	case 12:
		m_ui.checkboxPoint12->setCheckState(state);
		break;
	case 13:
		m_ui.checkboxPoint13->setCheckState(state);
		break;
	case 14:
		m_ui.checkboxPoint14->setCheckState(state);
		break;
	case 15:
		m_ui.checkboxPoint15->setCheckState(state);
		break;
	case 16:
		m_ui.checkboxPoint16->setCheckState(state);
		break;
	case 17:
		m_ui.checkboxPoint17->setCheckState(state);
		break;
	case 18:
		m_ui.checkboxPoint18->setCheckState(state);
		break;
	case 19:
		m_ui.checkboxPoint19->setCheckState(state);
		break;
	case 20:
		m_ui.checkboxPoint20->setCheckState(state);
		break;
	default:
		break;
	}
}


void SkeletonModify::onSaveToFilePushButtonClicked()
{
	if (m_isvalid)
		m_data.saveDataToFile();
}