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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SkeletonModifyClass
{
public:
    QAction *actionLoadConfigureFile;
    QWidget *centralWidget;
    GLWidget *openGLWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *checkboxPoint16;
    QCheckBox *checkboxPoint13;
    QCheckBox *checkboxPoint10;
    QCheckBox *checkboxPoint7;
    QCheckBox *checkboxPoint17;
    QCheckBox *checkboxPoint15;
    QCheckBox *checkboxPoint3;
    QCheckBox *checkboxPoint2;
    QCheckBox *checkboxPoint6;
    QCheckBox *checkboxPoint19;
    QCheckBox *checkboxPoint12;
    QCheckBox *checkboxPoint1;
    QCheckBox *checkboxPoint18;
    QCheckBox *checkboxPoint5;
    QCheckBox *checkboxPoint14;
    QCheckBox *checkboxPoint4;
    QCheckBox *checkboxPoint9;
    QCheckBox *checkboxPoint8;
    QCheckBox *checkboxPoint20;
    QCheckBox *checkboxPoint11;
    QCheckBox *checkboxPoint0;
    QPushButton *pushButtonPreFrame;
    QPushButton *pushButtonNextFrame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label1_2;
    QLabel *labelCurrFrame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QLabel *labelTotalFrame;
    QPushButton *pushButtonSaveToFile;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SkeletonModifyClass)
    {
        if (SkeletonModifyClass->objectName().isEmpty())
            SkeletonModifyClass->setObjectName(QStringLiteral("SkeletonModifyClass"));
        SkeletonModifyClass->resize(1669, 653);
        actionLoadConfigureFile = new QAction(SkeletonModifyClass);
        actionLoadConfigureFile->setObjectName(QStringLiteral("actionLoadConfigureFile"));
        centralWidget = new QWidget(SkeletonModifyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new GLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 80, 1440, 540));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(1470, 140, 181, 411));
        tabWidget->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        checkboxPoint16 = new QCheckBox(tab);
        checkboxPoint16->setObjectName(QStringLiteral("checkboxPoint16"));
        checkboxPoint16->setGeometry(QRect(100, 210, 41, 16));
        checkboxPoint13 = new QCheckBox(tab);
        checkboxPoint13->setObjectName(QStringLiteral("checkboxPoint13"));
        checkboxPoint13->setGeometry(QRect(100, 120, 41, 16));
        checkboxPoint10 = new QCheckBox(tab);
        checkboxPoint10->setObjectName(QStringLiteral("checkboxPoint10"));
        checkboxPoint10->setGeometry(QRect(100, 30, 41, 16));
        checkboxPoint7 = new QCheckBox(tab);
        checkboxPoint7->setObjectName(QStringLiteral("checkboxPoint7"));
        checkboxPoint7->setGeometry(QRect(30, 240, 41, 16));
        checkboxPoint17 = new QCheckBox(tab);
        checkboxPoint17->setObjectName(QStringLiteral("checkboxPoint17"));
        checkboxPoint17->setGeometry(QRect(100, 240, 41, 16));
        checkboxPoint15 = new QCheckBox(tab);
        checkboxPoint15->setObjectName(QStringLiteral("checkboxPoint15"));
        checkboxPoint15->setGeometry(QRect(100, 180, 41, 16));
        checkboxPoint3 = new QCheckBox(tab);
        checkboxPoint3->setObjectName(QStringLiteral("checkboxPoint3"));
        checkboxPoint3->setGeometry(QRect(30, 120, 41, 16));
        checkboxPoint2 = new QCheckBox(tab);
        checkboxPoint2->setObjectName(QStringLiteral("checkboxPoint2"));
        checkboxPoint2->setGeometry(QRect(30, 91, 41, 16));
        checkboxPoint6 = new QCheckBox(tab);
        checkboxPoint6->setObjectName(QStringLiteral("checkboxPoint6"));
        checkboxPoint6->setGeometry(QRect(30, 210, 41, 16));
        checkboxPoint19 = new QCheckBox(tab);
        checkboxPoint19->setObjectName(QStringLiteral("checkboxPoint19"));
        checkboxPoint19->setGeometry(QRect(100, 300, 41, 16));
        checkboxPoint12 = new QCheckBox(tab);
        checkboxPoint12->setObjectName(QStringLiteral("checkboxPoint12"));
        checkboxPoint12->setGeometry(QRect(100, 90, 41, 16));
        checkboxPoint1 = new QCheckBox(tab);
        checkboxPoint1->setObjectName(QStringLiteral("checkboxPoint1"));
        checkboxPoint1->setGeometry(QRect(30, 60, 41, 16));
        checkboxPoint18 = new QCheckBox(tab);
        checkboxPoint18->setObjectName(QStringLiteral("checkboxPoint18"));
        checkboxPoint18->setGeometry(QRect(100, 270, 41, 16));
        checkboxPoint5 = new QCheckBox(tab);
        checkboxPoint5->setObjectName(QStringLiteral("checkboxPoint5"));
        checkboxPoint5->setGeometry(QRect(30, 180, 41, 16));
        checkboxPoint14 = new QCheckBox(tab);
        checkboxPoint14->setObjectName(QStringLiteral("checkboxPoint14"));
        checkboxPoint14->setGeometry(QRect(100, 150, 41, 16));
        checkboxPoint4 = new QCheckBox(tab);
        checkboxPoint4->setObjectName(QStringLiteral("checkboxPoint4"));
        checkboxPoint4->setGeometry(QRect(30, 150, 41, 16));
        checkboxPoint9 = new QCheckBox(tab);
        checkboxPoint9->setObjectName(QStringLiteral("checkboxPoint9"));
        checkboxPoint9->setGeometry(QRect(30, 300, 41, 16));
        checkboxPoint8 = new QCheckBox(tab);
        checkboxPoint8->setObjectName(QStringLiteral("checkboxPoint8"));
        checkboxPoint8->setGeometry(QRect(30, 270, 41, 16));
        checkboxPoint20 = new QCheckBox(tab);
        checkboxPoint20->setObjectName(QStringLiteral("checkboxPoint20"));
        checkboxPoint20->setGeometry(QRect(100, 330, 41, 16));
        checkboxPoint11 = new QCheckBox(tab);
        checkboxPoint11->setObjectName(QStringLiteral("checkboxPoint11"));
        checkboxPoint11->setGeometry(QRect(100, 60, 41, 16));
        checkboxPoint0 = new QCheckBox(tab);
        checkboxPoint0->setObjectName(QStringLiteral("checkboxPoint0"));
        checkboxPoint0->setGeometry(QRect(30, 30, 41, 16));
        tabWidget->addTab(tab, QString());
        pushButtonPreFrame = new QPushButton(centralWidget);
        pushButtonPreFrame->setObjectName(QStringLiteral("pushButtonPreFrame"));
        pushButtonPreFrame->setGeometry(QRect(1470, 80, 71, 41));
        pushButtonPreFrame->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        pushButtonNextFrame = new QPushButton(centralWidget);
        pushButtonNextFrame->setObjectName(QStringLiteral("pushButtonNextFrame"));
        pushButtonNextFrame->setGeometry(QRect(1570, 80, 71, 41));
        pushButtonNextFrame->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 40, 161, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label1_2 = new QLabel(horizontalLayoutWidget_2);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        label1_2->setFrameShape(QFrame::WinPanel);
        label1_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(label1_2);

        labelCurrFrame = new QLabel(horizontalLayoutWidget_2);
        labelCurrFrame->setObjectName(QStringLiteral("labelCurrFrame"));
        labelCurrFrame->setStyleSheet(QLatin1String("font: 14pt \"Times New Roman\";\n"
"color: rgb(255, 0, 0);"));
        labelCurrFrame->setFrameShape(QFrame::StyledPanel);
        labelCurrFrame->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelCurrFrame);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 161, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(horizontalLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        label1->setFrameShape(QFrame::WinPanel);
        label1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(label1);

        labelTotalFrame = new QLabel(horizontalLayoutWidget);
        labelTotalFrame->setObjectName(QStringLiteral("labelTotalFrame"));
        labelTotalFrame->setStyleSheet(QLatin1String("font: 14pt \"Times New Roman\";\n"
"color: rgb(255, 0, 0);"));
        labelTotalFrame->setFrameShape(QFrame::StyledPanel);
        labelTotalFrame->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTotalFrame);

        pushButtonSaveToFile = new QPushButton(centralWidget);
        pushButtonSaveToFile->setObjectName(QStringLiteral("pushButtonSaveToFile"));
        pushButtonSaveToFile->setGeometry(QRect(1470, 570, 181, 41));
        pushButtonSaveToFile->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        SkeletonModifyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SkeletonModifyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1669, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SkeletonModifyClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoadConfigureFile);

        retranslateUi(SkeletonModifyClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SkeletonModifyClass);
    } // setupUi

    void retranslateUi(QMainWindow *SkeletonModifyClass)
    {
        SkeletonModifyClass->setWindowTitle(QApplication::translate("SkeletonModifyClass", "SkeletonModify", Q_NULLPTR));
        actionLoadConfigureFile->setText(QApplication::translate("SkeletonModifyClass", "Load Configure File", Q_NULLPTR));
        checkboxPoint16->setText(QApplication::translate("SkeletonModifyClass", "16", Q_NULLPTR));
        checkboxPoint13->setText(QApplication::translate("SkeletonModifyClass", "13", Q_NULLPTR));
        checkboxPoint10->setText(QApplication::translate("SkeletonModifyClass", "10", Q_NULLPTR));
        checkboxPoint7->setText(QApplication::translate("SkeletonModifyClass", "7", Q_NULLPTR));
        checkboxPoint17->setText(QApplication::translate("SkeletonModifyClass", "17", Q_NULLPTR));
        checkboxPoint15->setText(QApplication::translate("SkeletonModifyClass", "15", Q_NULLPTR));
        checkboxPoint3->setText(QApplication::translate("SkeletonModifyClass", "3", Q_NULLPTR));
        checkboxPoint2->setText(QApplication::translate("SkeletonModifyClass", "2", Q_NULLPTR));
        checkboxPoint6->setText(QApplication::translate("SkeletonModifyClass", "6", Q_NULLPTR));
        checkboxPoint19->setText(QApplication::translate("SkeletonModifyClass", "19", Q_NULLPTR));
        checkboxPoint12->setText(QApplication::translate("SkeletonModifyClass", "12", Q_NULLPTR));
        checkboxPoint1->setText(QApplication::translate("SkeletonModifyClass", "1", Q_NULLPTR));
        checkboxPoint18->setText(QApplication::translate("SkeletonModifyClass", "18", Q_NULLPTR));
        checkboxPoint5->setText(QApplication::translate("SkeletonModifyClass", "5", Q_NULLPTR));
        checkboxPoint14->setText(QApplication::translate("SkeletonModifyClass", "14", Q_NULLPTR));
        checkboxPoint4->setText(QApplication::translate("SkeletonModifyClass", "4", Q_NULLPTR));
        checkboxPoint9->setText(QApplication::translate("SkeletonModifyClass", "9", Q_NULLPTR));
        checkboxPoint8->setText(QApplication::translate("SkeletonModifyClass", "8", Q_NULLPTR));
        checkboxPoint20->setText(QApplication::translate("SkeletonModifyClass", "20", Q_NULLPTR));
        checkboxPoint11->setText(QApplication::translate("SkeletonModifyClass", "11", Q_NULLPTR));
        checkboxPoint0->setText(QApplication::translate("SkeletonModifyClass", "0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SkeletonModifyClass", "PointsSelect", Q_NULLPTR));
        pushButtonPreFrame->setText(QApplication::translate("SkeletonModifyClass", "Pre", Q_NULLPTR));
        pushButtonNextFrame->setText(QApplication::translate("SkeletonModifyClass", "Next", Q_NULLPTR));
        label1_2->setText(QApplication::translate("SkeletonModifyClass", " CurrFrame:", Q_NULLPTR));
        labelCurrFrame->setText(QString());
        label1->setText(QApplication::translate("SkeletonModifyClass", "TotalFrame:", Q_NULLPTR));
        labelTotalFrame->setText(QString());
        pushButtonSaveToFile->setText(QApplication::translate("SkeletonModifyClass", "Save Change To File", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SkeletonModifyClass", "    File    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SkeletonModifyClass: public Ui_SkeletonModifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKELETONMODIFY_H
