/********************************************************************************
** Form generated from reading UI file 'MrmControllerUi.ui'
**
** Created: Mon Nov 18 17:17:07 2013
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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MrmController
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QComboBox *controllableRobots;
    QLabel *label_5;
    QPushButton *controlRobot;

    void setupUi(QWidget *MrmController)
    {
        if (MrmController->objectName().isEmpty())
            MrmController->setObjectName(QString::fromUtf8("MrmController"));
        MrmController->resize(802, 165);
        gridLayout = new QGridLayout(MrmController);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(MrmController);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        gridLayout_5->addLayout(gridLayout_4, 0, 1, 1, 1);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 334, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 1, 1, 1, 1);

        controllableRobots = new QComboBox(groupBox);
        controllableRobots->setObjectName(QString::fromUtf8("controllableRobots"));
        controllableRobots->setMinimumSize(QSize(300, 0));

        gridLayout_6->addWidget(controllableRobots, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        controlRobot = new QPushButton(groupBox);
        controlRobot->setObjectName(QString::fromUtf8("controlRobot"));

        gridLayout_6->addWidget(controlRobot, 0, 2, 1, 1);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 3);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/wheel-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        tabWidget->addTab(tab_2, icon, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(MrmController);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MrmController);
    } // setupUi

    void retranslateUi(QWidget *MrmController)
    {
        MrmController->setWindowTitle(QApplication::translate("MrmController", "MRM Controller", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MrmController", "Teleoperator", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MrmController", "Controlled robot:", 0, QApplication::UnicodeUTF8));
        controlRobot->setText(QApplication::translate("MrmController", "Activate!", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MrmController", "Driving", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MrmController: public Ui_MrmController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MRMCONTROLLERUI_H
