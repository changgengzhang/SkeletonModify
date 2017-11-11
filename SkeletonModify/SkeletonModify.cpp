#include "SkeletonModify.h"
#include "QFileDialog"

#include "json.h"
#include "Utils.h"

#include <fstream>
#include <QDataStream>

SkeletonModify::SkeletonModify(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	m_isvalid = false;

	// data pointer
	m_ui.openGLWidget->setData(&m_data);

	this->connectSlotsAndSignals();
	setFocusPolicy(Qt::StrongFocus);
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


// 左键下一帧，右键上一帧，在GLWidget之外的地方
void SkeletonModify::mousePressEvent(QMouseEvent *mouseEvent)
{
	int a = 0;
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
	connect(m_ui.actionSavePositionFile, SIGNAL(triggered()), this, SLOT(onSavePositionFileActionTriggered()));

	// 将路径传递给Data, 解析数据
	connect(this, SIGNAL(sendConfigureFilePath(QString)), &m_data, SLOT(acceptConfigureFilePath(QString)));

	// currFrameIndex currMoveJointIndex
	connect(this, SIGNAL(sendCurrFrameIndex(int)), m_ui.openGLWidget, SLOT(acceptCurrFrameIndex(int)));
	connect(m_ui.openGLWidget, SIGNAL(sendCurrFrameIndex(int)), this, SLOT(acceptCurrFrameIndex(int)));
	connect(m_ui.openGLWidget, SIGNAL(sendCurrFrameIndex(int)), m_ui.openGLWidget, SLOT(acceptCurrFrameIndex(int)));

	connect(m_ui.openGLWidget, SIGNAL(sendCurrMoveJointIndex(int)), this, SLOT(acceptCurrMoveJointIndex(int)));
	// key event
	connect(this, SIGNAL(sendKeyEvent(QKeyEvent*)), m_ui.openGLWidget, SLOT(keyPressEvent(QKeyEvent*)));

	// 移动距离
	connect(m_ui.spinBoxMoveDelta, SIGNAL(valueChanged(double)), m_ui.openGLWidget, SLOT(onMoveDeltaSpinBoxValueChanged(double)));

	// 选中所有点
	connect(m_ui.radioButtonAllJoints, SIGNAL(toggled(bool)), m_ui.openGLWidget, SLOT(onAllJointsRadioButtonToggled(bool)));

	// 进行插值
	connect(m_ui.radioButtonSmooth, SIGNAL(toggled(bool)), m_ui.openGLWidget, SLOT(onSmoothRadioButtonToggled(bool)));
	connect(m_ui.spinBoxSmoothStep, SIGNAL(valueChanged(int)), m_ui.openGLWidget, SLOT(onSmoothStepSpinBoxValueChanged(int)));

	// 当移动了点的位置后更新textborwser内容
	connect(m_ui.openGLWidget, SIGNAL(sendUpdataTextBrowser(int)), this, SLOT(accpetUpdataTextBrowser(int)));


	connect(m_ui.openGLWidget, SIGNAL(sendChangeSmoothRadioButton(bool)), this, SLOT(acceptChangeSmoothRadioButton(bool)));
}



//////////////////////////////////////////////////////////////////////////
// 槽函数
//////////////////////////////////////////////////////////////////////////
void SkeletonModify::onLoadConfigureFileActionTriggered()
{
	QString configureFilePath = QFileDialog::getOpenFileName(this,
		tr("Open Configure"), "F:\\data_music2dance\\frames", tr("Configure Files (*.json)"));

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

	// ui settting 
	m_ui.labelTotalFrame->setText(QString::number(m_data.m_frameCount));
	m_ui.labelCurrFrame->setText(QString::number(1));
	this->setPositionValueTextBrowser(0);
	emit sendCurrFrameIndex(0);
}

void SkeletonModify::onSavePositionFileActionTriggered()
{
	if (m_isvalid)
		m_data.saveDataToFile();
}

void SkeletonModify::acceptCurrFrameIndex(int index)
{
	m_ui.labelCurrFrame->setText(QString::number(index+1));
	// 设置当前帧的各个关节点的值
	this->setPositionValueTextBrowser(index);
}

void SkeletonModify::acceptCurrMoveJointIndex(int index)
{
	m_ui.labelCurrJoint->setText(QString::number(index));
}


void SkeletonModify::accpetUpdataTextBrowser(int index)
{
	this->setPositionValueTextBrowser(index);
}


void SkeletonModify::setPositionValueTextBrowser(int currFrame)
{
	QVector<glm::vec3> data = m_data.m_jointsData[currFrame];
	QString text;
	

	for (int i = 0; i < JointsNumber; i++)
	{
		float x = data[i].x;
		float y = data[i].y;
		float z = data[i].z;

		text += QString("[%1](%2, %3, %4) ").arg(i).arg(x).arg(y).arg(z);
		if ((i+1) % 3 == 0)
		{
			text += "\n";
		}
	}

	m_ui.textBrowserPositionValue->setText(text);
}


void SkeletonModify::acceptChangeSmoothRadioButton(bool state)
{
	m_ui.radioButtonSmooth->setChecked(state);
}