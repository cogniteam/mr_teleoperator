/********************************************************************************
** Form generated from reading UI file 'MrmControllerUi.ui'
**
** Created: Mon Dec 16 10:56:53 2013
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MrmController
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QComboBox *inputMethods;
    QPushButton *addControllerButton;
    QComboBox *controllableRobots;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayoutContainer;

    void setupUi(QWidget *MrmController)
    {
        if (MrmController->objectName().isEmpty())
            MrmController->setObjectName(QString::fromUtf8("MrmController"));
        MrmController->resize(595, 423);
        gridLayout = new QGridLayout(MrmController);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(MrmController);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        inputMethods = new QComboBox(groupBox_3);
        inputMethods->setObjectName(QString::fromUtf8("inputMethods"));
        inputMethods->setMinimumSize(QSize(150, 0));

        gridLayout_5->addWidget(inputMethods, 0, 0, 1, 1);

        addControllerButton = new QPushButton(groupBox_3);
        addControllerButton->setObjectName(QString::fromUtf8("addControllerButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addControllerButton->sizePolicy().hasHeightForWidth());
        addControllerButton->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(addControllerButton, 0, 2, 1, 1);

        controllableRobots = new QComboBox(groupBox_3);
        controllableRobots->setObjectName(QString::fromUtf8("controllableRobots"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(controllableRobots->sizePolicy().hasHeightForWidth());
        controllableRobots->setSizePolicy(sizePolicy1);
        controllableRobots->setMinimumSize(QSize(300, 0));

        gridLayout_5->addWidget(controllableRobots, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        scrollArea = new QScrollArea(MrmController);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 575, 334));
        horizontalLayoutContainer = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayoutContainer->setObjectName(QString::fromUtf8("horizontalLayoutContainer"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(MrmController);

        QMetaObject::connectSlotsByName(MrmController);
    } // setupUi

    void retranslateUi(QWidget *MrmController)
    {
        MrmController->setWindowTitle(QApplication::translate("MrmController", "Multi-Robot teleoperator", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MrmController", "Add controller", 0, QApplication::UnicodeUTF8));
        inputMethods->clear();
        inputMethods->insertItems(0, QStringList()
         << QApplication::translate("MrmController", "Joystick", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MrmController", "Keyboard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MrmController", "Mouse", 0, QApplication::UnicodeUTF8)
        );
        addControllerButton->setText(QApplication::translate("MrmController", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MrmController: public Ui_MrmController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MRMCONTROLLERUI_H
