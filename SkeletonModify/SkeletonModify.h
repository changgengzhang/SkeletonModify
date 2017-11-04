#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QVector>

#include "ui_SkeletonModify.h"
#include "Data.h"

class SkeletonModify : public QMainWindow
{
	Q_OBJECT

public:
	SkeletonModify(QWidget *parent = Q_NULLPTR);

protected:	// protect 
	bool eventFilter(QObject *obj, QEvent *event);
	void keyPressEvent(QKeyEvent *keyEvent) override;
	void mousePressEvent(QMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QMouseEvent *mouseEvent) override;

private:
	//////////////////////////////////////////////////////////////////////////
	void connectSlotsAndSignals();

	// helper functions
	void setPointCheckboxState(int index, Qt::CheckState state);
	
public slots:
	//////////////////////////////////////////////////////////////////////////
	// slots and signal function
	void onLoadConfigureFileActionTriggered();
	void onPreFramePushButtonClicked();
	void onNextFramePushButtonClicked();
	//void onPlayFramePushButtonClicked();

	// ��������21����Ĵ����ۺ����ˡ�����
	// ����21��checkbox���ܺ���
	void acceptPointCheckboxInfo(int index, int state);

	void onPoint1Checkbox0StateChanged(int state) { emit sendPointCheckboxInfo(0, state); }
	void onPoint1Checkbox1StateChanged(int state) { emit sendPointCheckboxInfo(1, state); }
	void onPoint1Checkbox2StateChanged(int state) { emit sendPointCheckboxInfo(2, state); }
	void onPoint1Checkbox3StateChanged(int state) { emit sendPointCheckboxInfo(3, state); }
	void onPoint1Checkbox4StateChanged(int state) { emit sendPointCheckboxInfo(4, state); }
	void onPoint1Checkbox5StateChanged(int state) { emit sendPointCheckboxInfo(5, state); }
	void onPoint1Checkbox6StateChanged(int state) { emit sendPointCheckboxInfo(6, state); }
	void onPoint1Checkbox7StateChanged(int state) { emit sendPointCheckboxInfo(7, state); }
	void onPoint1Checkbox8StateChanged(int state) { emit sendPointCheckboxInfo(8, state); }
	void onPoint1Checkbox9StateChanged(int state) { emit sendPointCheckboxInfo(9, state); }
	void onPoint1Checkbox10StateChanged(int state) { emit sendPointCheckboxInfo(10, state); }
	void onPoint1Checkbox11StateChanged(int state) { emit sendPointCheckboxInfo(11, state); }
	void onPoint1Checkbox12StateChanged(int state) { emit sendPointCheckboxInfo(12, state); }
	void onPoint1Checkbox13StateChanged(int state) { emit sendPointCheckboxInfo(13, state); }
	void onPoint1Checkbox14StateChanged(int state) { emit sendPointCheckboxInfo(14, state); }
	void onPoint1Checkbox15StateChanged(int state) { emit sendPointCheckboxInfo(15, state); }
	void onPoint1Checkbox16StateChanged(int state) { emit sendPointCheckboxInfo(16, state); }
	void onPoint1Checkbox17StateChanged(int state) { emit sendPointCheckboxInfo(17, state); }
	void onPoint1Checkbox18StateChanged(int state) { emit sendPointCheckboxInfo(18, state); }
	void onPoint1Checkbox19StateChanged(int state) { emit sendPointCheckboxInfo(19, state); }
	void onPoint1Checkbox20StateChanged(int state) { emit sendPointCheckboxInfo(20, state); }

	// ������º�ĵ㵽�ļ���
	void onSaveToFilePushButtonClicked();


	//////////////////////////////////////////////////////////////////////////
signals:
	void sendCurrFrameIndex(uint);
	void sendPointCheckboxInfo(int, int);
	void sendMovePointIndex(int);
	// keyevent ֻ����������Ӧ
	void sendKeyEvent(QKeyEvent*);
	void sendConfigureFilePath(QString);

	//////////////////////////////////////////////////////////////////////////
public:
	Ui::SkeletonModifyClass m_ui;

	//////////////////////////////////////////////////////////////////////////
	Data m_data;
	// �Ƿ�ɹ������������ļ�
	bool m_isvalid;
	// ��ǰ֡��ͬʱ��Ӧ��Ӧ�Ĺؽڵ�����
	uint m_currFrame;
	// ѡ��ĵ�ǰ��Ҫ�ƶ��ĵ�
	int m_currMovePoints;
	

};
