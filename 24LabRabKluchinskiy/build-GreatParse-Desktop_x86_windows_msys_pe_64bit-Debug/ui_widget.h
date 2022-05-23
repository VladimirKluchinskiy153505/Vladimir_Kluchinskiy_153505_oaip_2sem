/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listVar;
    QListWidget *listArray;
    QListWidget *listClasses;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listFunctions;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *listMistake;
    QLabel *label_6;
    QListWidget *BranchList;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1499, 700);
        QFont font;
        font.setPointSize(16);
        Widget->setFont(font);
        listVar = new QListWidget(Widget);
        listVar->setObjectName(QString::fromUtf8("listVar"));
        listVar->setGeometry(QRect(20, 50, 241, 431));
        listArray = new QListWidget(Widget);
        listArray->setObjectName(QString::fromUtf8("listArray"));
        listArray->setGeometry(QRect(300, 50, 231, 421));
        listClasses = new QListWidget(Widget);
        listClasses->setObjectName(QString::fromUtf8("listClasses"));
        listClasses->setGeometry(QRect(590, 50, 231, 421));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 101, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 10, 81, 21));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(600, 10, 221, 31));
        listFunctions = new QListWidget(Widget);
        listFunctions->setObjectName(QString::fromUtf8("listFunctions"));
        listFunctions->setGeometry(QRect(865, 50, 241, 421));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(930, 10, 101, 31));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1200, 10, 91, 31));
        listMistake = new QListWidget(Widget);
        listMistake->setObjectName(QString::fromUtf8("listMistake"));
        listMistake->setGeometry(QRect(1140, 50, 256, 411));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 530, 121, 21));
        BranchList = new QListWidget(Widget);
        BranchList->setObjectName(QString::fromUtf8("BranchList"));
        BranchList->setGeometry(QRect(10, 490, 131, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Variables", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Arrays", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Classes_and_Structures", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Functions", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Mistakes", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Branching", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
