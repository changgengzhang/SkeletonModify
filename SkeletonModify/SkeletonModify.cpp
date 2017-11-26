#include "SkeletonModify.h"
#include "QFileDialog"

#include "json.h"

#include <fstream>
#include <QDataStream>

SkeletonModify::SkeletonModify(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	m_isvalid = false;

	// һЩ��Ҫ����GLWidget��ֵ�ı���ı���ʾ��widgets
	m_changeWidgets.labelCurrFrame = m_ui.labelCurrFrame;
	m_changeWidgets.textBrowserPositionValue = m_ui.textBrowserPositionValue;
	m_changeWidgets.labelStartSmoothFrame = m_ui.labelStartSmoothFrame;
	m_changeWidgets.labelEndSmoothFrame = m_ui.labelEndSmoothFrame;
	m_changeWidgets.labelCurrJoint = m_ui.labelCurrJoint;
	m_changeWidgets.radioButtonCopyFrame = m_ui.radioButtonCopyFrame;
	m_changeWidgets.radioButtonSmooth = m_ui.radioButtonSmooth;

	// data pointer
	m_ui.openGLWidget->setData(&m_changeWidgets, &m_data);

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
	// ���������ļ���ť����¼�
	connect(m_ui.actionLoadConfigureFile, SIGNAL(triggered()), this, SLOT(onLoadConfigureFileActionTriggered()));
	connect(m_ui.actionSavePositionFile, SIGNAL(triggered()), this, SLOT(onSavePositionFileActionTriggered()));

	// currFrameIndex currMoveJointIndex
	connect(this, SIGNAL(sendCurrFrameIndex(int)), m_ui.openGLWidget, SLOT(acceptCurrFrameIndex(int)));
	connect(m_ui.openGLWidget, SIGNAL(sendCurrFrameIndex(int)), m_ui.openGLWidget, SLOT(acceptCurrFrameIndex(int)));
	
	// key event
	connect(this, SIGNAL(sendKeyEvent(QKeyEvent*)), m_ui.openGLWidget, SLOT(keyPressEvent(QKeyEvent*)));

	// �ƶ�����
	connect(m_ui.spinBoxMoveDelta, SIGNAL(valueChanged(double)), m_ui.openGLWidget, SLOT(onMoveDeltaSpinBoxValueChanged(double)));

	// ����֡����
	connect(m_ui.radioButtonCopyFrame, SIGNAL(toggled(bool)), m_ui.openGLWidget, SLOT(onCopyFrameRadioButtonToggled(bool)));
	connect(m_ui.spinBoxCopyFrameStep, SIGNAL(valueChanged(int)), m_ui.openGLWidget, SLOT(onCopyFrameStepSpinBoxValueChanged(int)));

	// ��ֵ
	connect(m_ui.radioButtonSmooth, SIGNAL(toggled(bool)), m_ui.openGLWidget, SLOT(onSmoothRadioButtonToggled(bool)));
	connect(m_ui.spinBoxSmoothStep, SIGNAL(valueChanged(int)), m_ui.openGLWidget, SLOT(onSmoothStepSpinBoxValueChanged(int)));

	// ��ת��ָ��֡
	connect(m_ui.spinBoxJumpToFrameIndex, SIGNAL(editingFinished()), this, SLOT(onJumpToFrameIndexSpinBoxFinishedEditing()));

}



//////////////////////////////////////////////////////////////////////////
// �ۺ���
//////////////////////////////////////////////////////////////////////////
void SkeletonModify::onLoadConfigureFileActionTriggered()
{
	QString configureFilePath = QFileDialog::getOpenFileName(this,
		tr("Open Configure"), "", tr("Configure Files (*.json)"));

	if (configureFilePath.isEmpty())
	{
		//m_isvalid = false;
		return;
	}
	else
	{
		m_isvalid = m_data.loadData(configureFilePath);
	}
	
	if (m_isvalid)
	{
		// ui settting 
		m_ui.labelTotalFrame->setText(QString::number(m_data.m_frameCount));
		emit sendCurrFrameIndex(0);

		// ����֡����ת�ķ�Χ
		m_ui.spinBoxJumpToFrameIndex->setMaximum(m_data.m_frameCount);
		m_ui.spinBoxJumpToFrameIndex->setMinimum(1);
	}

	

}

void SkeletonModify::onSavePositionFileActionTriggered()
{
	if (m_isvalid)
		m_data.saveDataToFile();
}


void SkeletonModify::onJumpToFrameIndexSpinBoxFinishedEditing()
{
	if (!m_data.m_isvalid)
		return;

	int frameIndex = m_ui.spinBoxJumpToFrameIndex->value();
	emit sendCurrFrameIndex(frameIndex - 1);
}