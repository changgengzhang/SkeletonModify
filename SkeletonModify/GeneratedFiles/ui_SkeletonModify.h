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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label1;
    QLabel *labelTotalFrame;
    QLabel *label1_2;
    QLabel *labelCurrFrame;
    QTextBrowser *textBrowserPositionValue;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QFrame *frame_3;
    QLabel *label_2;
    QFrame *frame_4;
    QDoubleSpinBox *spinBoxMoveDelta;
    QFrame *frame_5;
    QSpinBox *spinBoxSmoothStep;
    QFrame *frame;
    QRadioButton *radioButtonSmooth;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *labelCurrJoint;
    QLabel *label;
    QFrame *frame_2;
    QRadioButton *radioButtonAllJoints;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SkeletonModifyClass)
    {
        if (SkeletonModifyClass->objectName().isEmpty())
            SkeletonModifyClass->setObjectName(QStringLiteral("SkeletonModifyClass"));
        SkeletonModifyClass->resize(1463, 678);
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
        gridLayoutWidget->setGeometry(QRect(10, 10, 201, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setStyleSheet(QStringLiteral("font: 14pt"));
        label1->setFrameShape(QFrame::Panel);
        label1->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label1, 0, 0, 1, 1);

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

        gridLayout->addWidget(label1_2, 1, 0, 1, 1);

        labelCurrFrame = new QLabel(gridLayoutWidget);
        labelCurrFrame->setObjectName(QStringLiteral("labelCurrFrame"));
        labelCurrFrame->setStyleSheet(QStringLiteral("font: 14pt"));
        labelCurrFrame->setFrameShape(QFrame::Panel);
        labelCurrFrame->setFrameShadow(QFrame::Sunken);
        labelCurrFrame->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCurrFrame, 1, 1, 1, 1);

        textBrowserPositionValue = new QTextBrowser(centralWidget);
        textBrowserPositionValue->setObjectName(QStringLiteral("textBrowserPositionValue"));
        textBrowserPositionValue->setGeometry(QRect(700, 10, 751, 81));
        textBrowserPositionValue->setFrameShape(QFrame::Box);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(440, 9, 239, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(gridLayoutWidget_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 151, 41));
        label_2->setStyleSheet(QStringLiteral("font: 14pt"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(gridLayoutWidget_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Sunken);
        spinBoxMoveDelta = new QDoubleSpinBox(frame_4);
        spinBoxMoveDelta->setObjectName(QStringLiteral("spinBoxMoveDelta"));
        spinBoxMoveDelta->setGeometry(QRect(0, 0, 81, 41));
        spinBoxMoveDelta->setFocusPolicy(Qt::ClickFocus);
        spinBoxMoveDelta->setStyleSheet(QStringLiteral("font: 14pt"));
        spinBoxMoveDelta->setWrapping(false);
        spinBoxMoveDelta->setFrame(true);
        spinBoxMoveDelta->setKeyboardTracking(false);
        spinBoxMoveDelta->setDecimals(3);
        spinBoxMoveDelta->setMaximum(1);
        spinBoxMoveDelta->setSingleStep(0.001);
        spinBoxMoveDelta->setValue(0);

        gridLayout_2->addWidget(frame_4, 0, 1, 1, 1);

        frame_5 = new QFrame(gridLayoutWidget_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Sunken);
        spinBoxSmoothStep = new QSpinBox(frame_5);
        spinBoxSmoothStep->setObjectName(QStringLiteral("spinBoxSmoothStep"));
        spinBoxSmoothStep->setGeometry(QRect(0, 0, 81, 41));
        spinBoxSmoothStep->setStyleSheet(QStringLiteral("font: 14pt"));
        spinBoxSmoothStep->setMaximum(30);

        gridLayout_2->addWidget(frame_5, 1, 1, 1, 1);

        frame = new QFrame(gridLayoutWidget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        radioButtonSmooth = new QRadioButton(frame);
        radioButtonSmooth->setObjectName(QStringLiteral("radioButtonSmooth"));
        radioButtonSmooth->setGeometry(QRect(30, 0, 101, 31));
        radioButtonSmooth->setStyleSheet(QStringLiteral("font: 14pt "));

        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 7);
        gridLayout_2->setColumnStretch(1, 4);
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(230, 10, 191, 80));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
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

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        frame_2 = new QFrame(gridLayoutWidget_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        radioButtonAllJoints = new QRadioButton(frame_2);
        radioButtonAllJoints->setObjectName(QStringLiteral("radioButtonAllJoints"));
        radioButtonAllJoints->setGeometry(QRect(10, 0, 121, 31));
        radioButtonAllJoints->setStyleSheet(QStringLiteral("font: 14pt"));

        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);

        SkeletonModifyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SkeletonModifyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1463, 23));
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
        label1->setText(QApplication::translate("SkeletonModifyClass", "TotalFrame:", Q_NULLPTR));
        labelTotalFrame->setText(QString());
        label1_2->setText(QApplication::translate("SkeletonModifyClass", " CurrFrame:", Q_NULLPTR));
        labelCurrFrame->setText(QString());
        label_2->setText(QApplication::translate("SkeletonModifyClass", "  MoveDelta\357\274\232", Q_NULLPTR));
        radioButtonSmooth->setText(QApplication::translate("SkeletonModifyClass", "Smooth", Q_NULLPTR));
        labelCurrJoint->setText(QString());
        label->setText(QApplication::translate("SkeletonModifyClass", "  CurrJoint\357\274\232", Q_NULLPTR));
        radioButtonAllJoints->setText(QApplication::translate("SkeletonModifyClass", "All Joints", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SkeletonModifyClass", "    File    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SkeletonModifyClass: public Ui_SkeletonModifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKELETONMODIFY_H
