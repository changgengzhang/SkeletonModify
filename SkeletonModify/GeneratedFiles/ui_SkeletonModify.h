/********************************************************************************
** Form generated from reading UI file 'SkeletonModify.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKELETONMODIFY_H
#define UI_SKELETONMODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SkeletonModifyClass
{
public:
    QAction *actionLoadConfigureFile;
    QAction *actionSavePositionFile;
    QWidget *centralWidget;
    GLWidget *openGLWidget;
    QTextBrowser *textBrowserPositionValue;
    QGroupBox *groupBox;
    QLabel *label1;
    QLabel *labelTotalFrame;
    QLabel *label1_2;
    QLabel *labelCurrFrame;
    QLabel *label;
    QLabel *labelCurrJoint;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QSpinBox *spinBoxJumpToFrameIndex;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxMoveDelta;
    QPushButton *pushButtonCopyFrame;
    QSpinBox *spinBoxCopyFrameIndex;
    QGroupBox *groupBox_3;
    QSpinBox *spinBoxSmoothStep;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *labelStartSmoothFrame;
    QLabel *labelEndSmoothFrame;
    QPushButton *pushButtonSmooth;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SkeletonModifyClass)
    {
        if (SkeletonModifyClass->objectName().isEmpty())
            SkeletonModifyClass->setObjectName(QStringLiteral("SkeletonModifyClass"));
        SkeletonModifyClass->resize(1459, 732);
        SkeletonModifyClass->setMinimumSize(QSize(1459, 732));
        SkeletonModifyClass->setMaximumSize(QSize(1459, 732));
        SkeletonModifyClass->setStyleSheet(QStringLiteral("background-color: rgb(179, 179, 179);"));
        actionLoadConfigureFile = new QAction(SkeletonModifyClass);
        actionLoadConfigureFile->setObjectName(QStringLiteral("actionLoadConfigureFile"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        actionLoadConfigureFile->setFont(font);
        actionLoadConfigureFile->setAutoRepeat(true);
        actionSavePositionFile = new QAction(SkeletonModifyClass);
        actionSavePositionFile->setObjectName(QStringLiteral("actionSavePositionFile"));
        centralWidget = new QWidget(SkeletonModifyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new GLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 160, 1440, 540));
        textBrowserPositionValue = new QTextBrowser(centralWidget);
        textBrowserPositionValue->setObjectName(QStringLiteral("textBrowserPositionValue"));
        textBrowserPositionValue->setGeometry(QRect(760, 20, 691, 131));
        textBrowserPositionValue->setFrameShape(QFrame::Box);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 141));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        label1 = new QLabel(groupBox);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(20, 20, 111, 31));
        label1->setStyleSheet(QStringLiteral("font: 10pt"));
        label1->setFrameShape(QFrame::Panel);
        label1->setFrameShadow(QFrame::Raised);
        label1->setAlignment(Qt::AlignCenter);
        labelTotalFrame = new QLabel(groupBox);
        labelTotalFrame->setObjectName(QStringLiteral("labelTotalFrame"));
        labelTotalFrame->setGeometry(QRect(140, 20, 61, 31));
        labelTotalFrame->setStyleSheet(QStringLiteral("font: 10pt"));
        labelTotalFrame->setFrameShape(QFrame::Panel);
        labelTotalFrame->setFrameShadow(QFrame::Sunken);
        labelTotalFrame->setAlignment(Qt::AlignCenter);
        label1_2 = new QLabel(groupBox);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setGeometry(QRect(20, 60, 112, 31));
        label1_2->setStyleSheet(QStringLiteral("font: 10pt"));
        label1_2->setFrameShape(QFrame::Panel);
        label1_2->setFrameShadow(QFrame::Raised);
        label1_2->setAlignment(Qt::AlignCenter);
        labelCurrFrame = new QLabel(groupBox);
        labelCurrFrame->setObjectName(QStringLiteral("labelCurrFrame"));
        labelCurrFrame->setGeometry(QRect(140, 60, 61, 31));
        labelCurrFrame->setStyleSheet(QStringLiteral("font: 10pt"));
        labelCurrFrame->setFrameShape(QFrame::Panel);
        labelCurrFrame->setFrameShadow(QFrame::Sunken);
        labelCurrFrame->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 111, 31));
        label->setStyleSheet(QStringLiteral("font: 10pt"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);
        labelCurrJoint = new QLabel(groupBox);
        labelCurrJoint->setObjectName(QStringLiteral("labelCurrJoint"));
        labelCurrJoint->setGeometry(QRect(140, 100, 61, 31));
        labelCurrJoint->setStyleSheet(QStringLiteral("font: 10pt "));
        labelCurrJoint->setFrameShape(QFrame::Panel);
        labelCurrJoint->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 10, 221, 141));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 111, 31));
        label_4->setStyleSheet(QStringLiteral("font: 10pt"));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);
        spinBoxJumpToFrameIndex = new QSpinBox(groupBox_2);
        spinBoxJumpToFrameIndex->setObjectName(QStringLiteral("spinBoxJumpToFrameIndex"));
        spinBoxJumpToFrameIndex->setGeometry(QRect(140, 20, 61, 31));
        spinBoxJumpToFrameIndex->setStyleSheet(QStringLiteral("font: 10pt;"));
        spinBoxJumpToFrameIndex->setAlignment(Qt::AlignCenter);
        spinBoxJumpToFrameIndex->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxJumpToFrameIndex->setMaximum(100000);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 111, 31));
        label_2->setStyleSheet(QStringLiteral("font: 10pt"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);
        spinBoxMoveDelta = new QDoubleSpinBox(groupBox_2);
        spinBoxMoveDelta->setObjectName(QStringLiteral("spinBoxMoveDelta"));
        spinBoxMoveDelta->setGeometry(QRect(140, 60, 61, 31));
        spinBoxMoveDelta->setFocusPolicy(Qt::ClickFocus);
        spinBoxMoveDelta->setStyleSheet(QStringLiteral("font: 10pt"));
        spinBoxMoveDelta->setWrapping(false);
        spinBoxMoveDelta->setFrame(true);
        spinBoxMoveDelta->setKeyboardTracking(false);
        spinBoxMoveDelta->setDecimals(3);
        spinBoxMoveDelta->setMaximum(1);
        spinBoxMoveDelta->setSingleStep(0.005);
        spinBoxMoveDelta->setValue(0);
        pushButtonCopyFrame = new QPushButton(groupBox_2);
        pushButtonCopyFrame->setObjectName(QStringLiteral("pushButtonCopyFrame"));
        pushButtonCopyFrame->setGeometry(QRect(20, 100, 111, 31));
        spinBoxCopyFrameIndex = new QSpinBox(groupBox_2);
        spinBoxCopyFrameIndex->setObjectName(QStringLiteral("spinBoxCopyFrameIndex"));
        spinBoxCopyFrameIndex->setGeometry(QRect(140, 100, 61, 31));
        spinBoxCopyFrameIndex->setStyleSheet(QStringLiteral("font: 10pt"));
        spinBoxCopyFrameIndex->setAlignment(Qt::AlignCenter);
        spinBoxCopyFrameIndex->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxCopyFrameIndex->setMinimum(-30);
        spinBoxCopyFrameIndex->setMaximum(30);
        spinBoxCopyFrameIndex->setValue(0);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 10, 221, 141));
        spinBoxSmoothStep = new QSpinBox(groupBox_3);
        spinBoxSmoothStep->setObjectName(QStringLiteral("spinBoxSmoothStep"));
        spinBoxSmoothStep->setGeometry(QRect(140, 20, 61, 31));
        spinBoxSmoothStep->setStyleSheet(QStringLiteral("font: 10pt"));
        spinBoxSmoothStep->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 111, 31));
        label_3->setStyleSheet(QStringLiteral("font: 10pt"));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 60, 111, 31));
        label_6->setStyleSheet(QStringLiteral("font: 10pt"));
        label_6->setFrameShape(QFrame::Panel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);
        labelStartSmoothFrame = new QLabel(groupBox_3);
        labelStartSmoothFrame->setObjectName(QStringLiteral("labelStartSmoothFrame"));
        labelStartSmoothFrame->setGeometry(QRect(140, 60, 61, 31));
        labelStartSmoothFrame->setStyleSheet(QStringLiteral("font: 10pt"));
        labelStartSmoothFrame->setFrameShape(QFrame::Panel);
        labelStartSmoothFrame->setFrameShadow(QFrame::Sunken);
        labelEndSmoothFrame = new QLabel(groupBox_3);
        labelEndSmoothFrame->setObjectName(QStringLiteral("labelEndSmoothFrame"));
        labelEndSmoothFrame->setGeometry(QRect(140, 100, 61, 31));
        labelEndSmoothFrame->setStyleSheet(QStringLiteral("font: 10pt"));
        labelEndSmoothFrame->setFrameShape(QFrame::Panel);
        labelEndSmoothFrame->setFrameShadow(QFrame::Sunken);
        pushButtonSmooth = new QPushButton(groupBox_3);
        pushButtonSmooth->setObjectName(QStringLiteral("pushButtonSmooth"));
        pushButtonSmooth->setGeometry(QRect(20, 20, 111, 31));
        pushButtonSmooth->setStyleSheet(QStringLiteral("font: 10pt"));
        SkeletonModifyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SkeletonModifyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1459, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SkeletonModifyClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoadConfigureFile);
        menuFile->addAction(actionSavePositionFile);

        retranslateUi(SkeletonModifyClass);

        QMetaObject::connectSlotsByName(SkeletonModifyClass);
    } // setupUi

    void retranslateUi(QMainWindow *SkeletonModifyClass)
    {
        SkeletonModifyClass->setWindowTitle(QApplication::translate("SkeletonModifyClass", "SkeletonModify", Q_NULLPTR));
        actionLoadConfigureFile->setText(QApplication::translate("SkeletonModifyClass", "  Load  ", Q_NULLPTR));
        actionSavePositionFile->setText(QApplication::translate("SkeletonModifyClass", "  Save  ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SkeletonModifyClass", "Info", Q_NULLPTR));
        label1->setText(QApplication::translate("SkeletonModifyClass", "TotalFrame:", Q_NULLPTR));
        labelTotalFrame->setText(QString());
        label1_2->setText(QApplication::translate("SkeletonModifyClass", "CurrFrame:", Q_NULLPTR));
        labelCurrFrame->setText(QString());
        label->setText(QApplication::translate("SkeletonModifyClass", "CurrJoint:", Q_NULLPTR));
        labelCurrJoint->setText(QString());
        groupBox_2->setTitle(QApplication::translate("SkeletonModifyClass", "Op", Q_NULLPTR));
        label_4->setText(QApplication::translate("SkeletonModifyClass", "JumpTo", Q_NULLPTR));
        label_2->setText(QApplication::translate("SkeletonModifyClass", "MoveDelta:", Q_NULLPTR));
        pushButtonCopyFrame->setText(QApplication::translate("SkeletonModifyClass", "CopyFrameFrom:", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SkeletonModifyClass", "Smooth", Q_NULLPTR));
        label_3->setText(QApplication::translate("SkeletonModifyClass", "StartFrame:", Q_NULLPTR));
        label_6->setText(QApplication::translate("SkeletonModifyClass", "EndFrame:", Q_NULLPTR));
        labelStartSmoothFrame->setText(QString());
        labelEndSmoothFrame->setText(QString());
        pushButtonSmooth->setText(QApplication::translate("SkeletonModifyClass", "SmoothStep:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SkeletonModifyClass", "    File    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SkeletonModifyClass: public Ui_SkeletonModifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKELETONMODIFY_H
