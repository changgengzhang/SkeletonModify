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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelTotalFrame;
    QLabel *label1_2;
    QLabel *labelCurrFrame;
    QLabel *label1;
    QTextBrowser *textBrowserPositionValue;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QFrame *frame_4;
    QDoubleSpinBox *spinBoxMoveDelta;
    QFrame *frame_5;
    QSpinBox *spinBoxCopyFrameStep;
    QFrame *frame;
    QRadioButton *radioButtonCopyFrame;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_6;
    QRadioButton *radioButtonSmooth;
    QFrame *frame_7;
    QSpinBox *spinBoxSmoothStep;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *labelStartSmoothFrame;
    QLabel *label_6;
    QLabel *labelEndSmoothFrame;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *labelCurrJoint;
    QLabel *label;
    QFrame *frame_2;
    QSpinBox *spinBoxJumpToFrameIndex;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SkeletonModifyClass)
    {
        if (SkeletonModifyClass->objectName().isEmpty())
            SkeletonModifyClass->setObjectName(QStringLiteral("SkeletonModifyClass"));
        SkeletonModifyClass->resize(1661, 674);
        actionLoadConfigureFile = new QAction(SkeletonModifyClass);
        actionLoadConfigureFile->setObjectName(QStringLiteral("actionLoadConfigureFile"));
        actionSavePositionFile = new QAction(SkeletonModifyClass);
        actionSavePositionFile->setObjectName(QStringLiteral("actionSavePositionFile"));
        centralWidget = new QWidget(SkeletonModifyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new GLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 100, 1440, 540));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 221, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTotalFrame = new QLabel(gridLayoutWidget);
        labelTotalFrame->setObjectName(QStringLiteral("labelTotalFrame"));
        labelTotalFrame->setStyleSheet(QStringLiteral("font: 14pt"));
        labelTotalFrame->setFrameShape(QFrame::Panel);
        labelTotalFrame->setFrameShadow(QFrame::Sunken);
        labelTotalFrame->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTotalFrame, 0, 1, 1, 1);

        label1_2 = new QLabel(gridLayoutWidget);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setStyleSheet(QStringLiteral("font: 14pt"));
        label1_2->setFrameShape(QFrame::Panel);
        label1_2->setFrameShadow(QFrame::Raised);
        label1_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1_2, 1, 0, 1, 1);

        labelCurrFrame = new QLabel(gridLayoutWidget);
        labelCurrFrame->setObjectName(QStringLiteral("labelCurrFrame"));
        labelCurrFrame->setStyleSheet(QStringLiteral("font: 14pt"));
        labelCurrFrame->setFrameShape(QFrame::Panel);
        labelCurrFrame->setFrameShadow(QFrame::Sunken);
        labelCurrFrame->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCurrFrame, 1, 1, 1, 1);

        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setStyleSheet(QStringLiteral("font: 14pt"));
        label1->setFrameShape(QFrame::Panel);
        label1->setFrameShadow(QFrame::Raised);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);
        textBrowserPositionValue = new QTextBrowser(centralWidget);
        textBrowserPositionValue->setObjectName(QStringLiteral("textBrowserPositionValue"));
        textBrowserPositionValue->setGeometry(QRect(1460, 100, 191, 541));
        textBrowserPositionValue->setFrameShape(QFrame::Box);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(490, 9, 261, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(gridLayoutWidget_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Sunken);
        spinBoxMoveDelta = new QDoubleSpinBox(frame_4);
        spinBoxMoveDelta->setObjectName(QStringLiteral("spinBoxMoveDelta"));
        spinBoxMoveDelta->setGeometry(QRect(0, 0, 91, 41));
        spinBoxMoveDelta->setFocusPolicy(Qt::ClickFocus);
        spinBoxMoveDelta->setStyleSheet(QStringLiteral("font: 14pt"));
        spinBoxMoveDelta->setWrapping(false);
        spinBoxMoveDelta->setFrame(true);
        spinBoxMoveDelta->setKeyboardTracking(false);
        spinBoxMoveDelta->setDecimals(3);
        spinBoxMoveDelta->setMaximum(1);
        spinBoxMoveDelta->setSingleStep(0.005);
        spinBoxMoveDelta->setValue(0);

        gridLayout_2->addWidget(frame_4, 0, 1, 1, 1);

        frame_5 = new QFrame(gridLayoutWidget_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Sunken);
        spinBoxCopyFrameStep = new QSpinBox(frame_5);
        spinBoxCopyFrameStep->setObjectName(QStringLiteral("spinBoxCopyFrameStep"));
        spinBoxCopyFrameStep->setGeometry(QRect(0, 0, 91, 41));
        spinBoxCopyFrameStep->setStyleSheet(QStringLiteral("font: 14pt"));
        spinBoxCopyFrameStep->setAlignment(Qt::AlignCenter);
        spinBoxCopyFrameStep->setMinimum(-30);
        spinBoxCopyFrameStep->setMaximum(30);
        spinBoxCopyFrameStep->setValue(0);

        gridLayout_2->addWidget(frame_5, 1, 1, 1, 1);

        frame = new QFrame(gridLayoutWidget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        radioButtonCopyFrame = new QRadioButton(frame);
        radioButtonCopyFrame->setObjectName(QStringLiteral("radioButtonCopyFrame"));
        radioButtonCopyFrame->setGeometry(QRect(30, 0, 101, 41));
        radioButtonCopyFrame->setStyleSheet(QStringLiteral("font: 14pt "));

        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 14pt"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 7);
        gridLayout_2->setColumnStretch(1, 4);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(770, 10, 391, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_6 = new QFrame(verticalLayoutWidget);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        radioButtonSmooth = new QRadioButton(frame_6);
        radioButtonSmooth->setObjectName(QStringLiteral("radioButtonSmooth"));
        radioButtonSmooth->setGeometry(QRect(30, 0, 121, 41));
        radioButtonSmooth->setLayoutDirection(Qt::LeftToRight);
        radioButtonSmooth->setStyleSheet(QStringLiteral("font: 14pt ;"));

        horizontalLayout->addWidget(frame_6);

        frame_7 = new QFrame(verticalLayoutWidget);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::Panel);
        frame_7->setFrameShadow(QFrame::Raised);
        spinBoxSmoothStep = new QSpinBox(frame_7);
        spinBoxSmoothStep->setObjectName(QStringLiteral("spinBoxSmoothStep"));
        spinBoxSmoothStep->setGeometry(QRect(0, 0, 191, 41));
        spinBoxSmoothStep->setStyleSheet(QStringLiteral("font: 14pt"));
        spinBoxSmoothStep->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(frame_7);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 14pt"));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        labelStartSmoothFrame = new QLabel(verticalLayoutWidget);
        labelStartSmoothFrame->setObjectName(QStringLiteral("labelStartSmoothFrame"));
        labelStartSmoothFrame->setStyleSheet(QStringLiteral("font: 14pt"));
        labelStartSmoothFrame->setFrameShape(QFrame::Panel);
        labelStartSmoothFrame->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(labelStartSmoothFrame);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font: 14pt"));
        label_6->setFrameShape(QFrame::Panel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        labelEndSmoothFrame = new QLabel(verticalLayoutWidget);
        labelEndSmoothFrame->setObjectName(QStringLiteral("labelEndSmoothFrame"));
        labelEndSmoothFrame->setStyleSheet(QStringLiteral("font: 14pt"));
        labelEndSmoothFrame->setFrameShape(QFrame::Panel);
        labelEndSmoothFrame->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(labelEndSmoothFrame);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(250, 10, 211, 81));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelCurrJoint = new QLabel(gridLayoutWidget_3);
        labelCurrJoint->setObjectName(QStringLiteral("labelCurrJoint"));
        labelCurrJoint->setStyleSheet(QStringLiteral("font: 14pt "));
        labelCurrJoint->setFrameShape(QFrame::Panel);
        labelCurrJoint->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(labelCurrJoint, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 14pt"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        frame_2 = new QFrame(gridLayoutWidget_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        spinBoxJumpToFrameIndex = new QSpinBox(frame_2);
        spinBoxJumpToFrameIndex->setObjectName(QStringLiteral("spinBoxJumpToFrameIndex"));
        spinBoxJumpToFrameIndex->setGeometry(QRect(0, 0, 71, 41));
        spinBoxJumpToFrameIndex->setStyleSheet(QStringLiteral("font: 14pt;"));
        spinBoxJumpToFrameIndex->setAlignment(Qt::AlignCenter);
        spinBoxJumpToFrameIndex->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxJumpToFrameIndex->setMaximum(100000);

        gridLayout_3->addWidget(frame_2, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 14pt"));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 1);
        SkeletonModifyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SkeletonModifyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1661, 23));
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
        labelTotalFrame->setText(QString());
        label1_2->setText(QApplication::translate("SkeletonModifyClass", " CurrFrame:", Q_NULLPTR));
        labelCurrFrame->setText(QString());
        label1->setText(QApplication::translate("SkeletonModifyClass", "TotalFrame:", Q_NULLPTR));
        radioButtonCopyFrame->setText(QApplication::translate("SkeletonModifyClass", "CopyFrom", Q_NULLPTR));
        label_2->setText(QApplication::translate("SkeletonModifyClass", "MoveDelta:", Q_NULLPTR));
        radioButtonSmooth->setText(QApplication::translate("SkeletonModifyClass", "SmoothStep", Q_NULLPTR));
        label_3->setText(QApplication::translate("SkeletonModifyClass", "StartFrame\357\274\232", Q_NULLPTR));
        labelStartSmoothFrame->setText(QString());
        label_6->setText(QApplication::translate("SkeletonModifyClass", "EndFrame\357\274\232", Q_NULLPTR));
        labelEndSmoothFrame->setText(QString());
        labelCurrJoint->setText(QString());
        label->setText(QApplication::translate("SkeletonModifyClass", "CurrJoint:", Q_NULLPTR));
        label_4->setText(QApplication::translate("SkeletonModifyClass", "JumpTo", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SkeletonModifyClass", "    File    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SkeletonModifyClass: public Ui_SkeletonModifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKELETONMODIFY_H
