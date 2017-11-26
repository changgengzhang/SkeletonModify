#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QVector>

#include "ui_SkeletonModify.h"
#include "Data.h"
#include "Utils.h"


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
	void connectSlotsAndSignals();

	// slots and signal function
public slots:
	void onLoadConfigureFileActionTriggered();
	void onSavePositionFileActionTriggered();
	void onJumpToFrameIndexSpinBoxFinishedEditing();

signals:
	// ��ʼ��ʱ
	void sendCurrFrameIndex(int);
	// keyevent ֻ����������Ӧ
	void sendKeyEvent(QKeyEvent*);

public:
	Ui::SkeletonModifyClass m_ui;

	//////////////////////////////////////////////////////////////////////////
	Data m_data;

	ChangeWidgets m_changeWidgets;

	// �Ƿ�ɹ������������ļ�
	bool m_isvalid;

};
