/********************************************************************************
** Form generated from reading UI file 'MrmControllerUi.ui'
**
** Created: Thu Nov 28 16:17:22 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MRMCONTROLLERUI_H
#define MRMCONTROLLERUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MrmController
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *lblCurrentRobot;
    QLabel *lblCurrentInput;
    QLabel *lblCurrentTopic;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QComboBox *controllableRobots;
    QLabel *label_5;
    QPushButton *selectOutputButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QComboBox *inputMethods;
    QPushButton *selectInputButton;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLCDNumber *lcdLinear;
    QLabel *label_6;
    QLCDNumber *lcdAngular;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *keyboardTeleop;

    void setupUi(QWidget *MrmController)
    {
        if (MrmController->objectName().isEmpty())
            MrmController->setObjectName(QString::fromUtf8("MrmController"));
        MrmController->resize(595, 423);
        gridLayout = new QGridLayout(MrmController);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(MrmController);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        lblCurrentRobot = new QLabel(groupBox_2);
        lblCurrentRobot->setObjectName(QString::fromUtf8("lblCurrentRobot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblCurrentRobot->sizePolicy().hasHeightForWidth());
        lblCurrentRobot->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblCurrentRobot->setFont(font);

        gridLayout_2->addWidget(lblCurrentRobot, 0, 1, 1, 1);

        lblCurrentInput = new QLabel(groupBox_2);
        lblCurrentInput->setObjectName(QString::fromUtf8("lblCurrentInput"));
        lblCurrentInput->setFont(font);

        gridLayout_2->addWidget(lblCurrentInput, 1, 1, 1, 1);

        lblCurrentTopic = new QLabel(groupBox_2);
        lblCurrentTopic->setObjectName(QString::fromUtf8("lblCurrentTopic"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(false);
        lblCurrentTopic->setFont(font1);

        gridLayout_2->addWidget(lblCurrentTopic, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        groupBox = new QGroupBox(MrmController);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        controllableRobots = new QComboBox(groupBox);
        controllableRobots->setObjectName(QString::fromUtf8("controllableRobots"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(controllableRobots->sizePolicy().hasHeightForWidth());
        controllableRobots->setSizePolicy(sizePolicy2);
        controllableRobots->setMinimumSize(QSize(300, 0));

        gridLayout_6->addWidget(controllableRobots, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        selectOutputButton = new QPushButton(groupBox);
        selectOutputButton->setObjectName(QString::fromUtf8("selectOutputButton"));

        gridLayout_6->addWidget(selectOutputButton, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(MrmController);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        inputMethods = new QComboBox(groupBox_3);
        inputMethods->setObjectName(QString::fromUtf8("inputMethods"));

        gridLayout_5->addWidget(inputMethods, 0, 0, 1, 1);

        selectInputButton = new QPushButton(groupBox_3);
        selectInputButton->setObjectName(QString::fromUtf8("selectInputButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(selectInputButton->sizePolicy().hasHeightForWidth());
        selectInputButton->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(selectInputButton, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(MrmController);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lcdLinear = new QLCDNumber(MrmController);
        lcdLinear->setObjectName(QString::fromUtf8("lcdLinear"));
        lcdLinear->setMaximumSize(QSize(100, 16777215));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(68, 68, 68, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(102, 102, 102, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(85, 85, 85, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(34, 34, 34, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(45, 45, 45, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        lcdLinear->setPalette(palette);
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        lcdLinear->setFont(font2);
        lcdLinear->setFrameShape(QFrame::NoFrame);
        lcdLinear->setFrameShadow(QFrame::Plain);
        lcdLinear->setSmallDecimalPoint(false);
        lcdLinear->setSegmentStyle(QLCDNumber::Filled);
        lcdLinear->setProperty("value", QVariant(0));

        gridLayout_4->addWidget(lcdLinear, 0, 1, 1, 1);

        label_6 = new QLabel(MrmController);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        lcdAngular = new QLCDNumber(MrmController);
        lcdAngular->setObjectName(QString::fromUtf8("lcdAngular"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        lcdAngular->setPalette(palette1);
        lcdAngular->setFrameShape(QFrame::NoFrame);
        lcdAngular->setFrameShadow(QFrame::Plain);
        lcdAngular->setSmallDecimalPoint(false);
        lcdAngular->setSegmentStyle(QLCDNumber::Filled);

        gridLayout_4->addWidget(lcdAngular, 1, 1, 1, 1);

        label_7 = new QLabel(MrmController);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(MrmController);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(label_8, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_4, 6, 0, 1, 1);

        keyboardTeleop = new QLineEdit(MrmController);
        keyboardTeleop->setObjectName(QString::fromUtf8("keyboardTeleop"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(62, 62, 62, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(81, 81, 81, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(88, 88, 88, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(99, 99, 99, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(74, 74, 74, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush12);
        QBrush brush13(QColor(167, 228, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush13);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush14(QColor(69, 138, 207, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        keyboardTeleop->setPalette(palette2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        keyboardTeleop->setFont(font3);
        keyboardTeleop->setAutoFillBackground(false);
        keyboardTeleop->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(keyboardTeleop, 4, 0, 1, 1);


        retranslateUi(MrmController);

        QMetaObject::connectSlotsByName(MrmController);
    } // setupUi

    void retranslateUi(QWidget *MrmController)
    {
        MrmController->setWindowTitle(QApplication::translate("MrmController", "Multi-Robot teleoperator", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MrmController", "Configuration", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MrmController", "Input:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MrmController", "Current robot:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MrmController", "Velocity topic:", 0, QApplication::UnicodeUTF8));
        lblCurrentRobot->setText(QApplication::translate("MrmController", "Robot #1", 0, QApplication::UnicodeUTF8));
        lblCurrentInput->setText(QApplication::translate("MrmController", "Joystick (/dev/input/js0)", 0, QApplication::UnicodeUTF8));
        lblCurrentTopic->setText(QApplication::translate("MrmController", "/pioneer_1/cmd_vel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MrmController", "Teleoperator", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MrmController", "Controlled robot:", 0, QApplication::UnicodeUTF8));
        selectOutputButton->setText(QApplication::translate("MrmController", "Select", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MrmController", "Input method", 0, QApplication::UnicodeUTF8));
        inputMethods->clear();
        inputMethods->insertItems(0, QStringList()
         << QApplication::translate("MrmController", "Joystick", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MrmController", "Keyboard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MrmController", "Mouse", 0, QApplication::UnicodeUTF8)
        );
        selectInputButton->setText(QApplication::translate("MrmController", "Select", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MrmController", "Linear velocity", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MrmController", "Angular velocity", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MrmController", "m/s", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MrmController", "m/s", 0, QApplication::UnicodeUTF8));
        keyboardTeleop->setText(QApplication::translate("MrmController", "Click here and use arrow keys to control the robot", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MrmController: public Ui_MrmController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MRMCONTROLLERUI_H
