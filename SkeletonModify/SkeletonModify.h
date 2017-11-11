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
	void connectSlotsAndSignals();

	// helper function
	void setPositionValueTextBrowser(int currFrame);

	// slots and signal function
public slots:
	
	void onLoadConfigureFileActionTriggered();
	void onSavePositionFileActionTriggered();

	void acceptCurrFrameIndex(int index);
	void acceptCurrMoveJointIndex(int index);

	void accpetUpdataTextBrowser(int index);

	void acceptChangeSmoothRadioButton(bool state);

signals:
	// 初始化时
	void sendCurrFrameIndex(int);
	// keyevent 只有主窗口响应
	void sendKeyEvent(QKeyEvent*);
	void sendConfigureFilePath(QString);

public:
	Ui::SkeletonModifyClass m_ui;

	//////////////////////////////////////////////////////////////////////////
	Data m_data;
	// 是否成功加载了配置文件
	bool m_isvalid;

};
