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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *NuberList;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *NumLine;
    QPushButton *push_back;
    QPushButton *push_front;
    QPushButton *pop_back;
    QPushButton *pop_front;
    QPushButton *clear;
    QPushButton *empty;
    QLineEdit *ItNum;
    QPushButton *see_element;
    QLabel *label_3;
    QPushButton *change_dir;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        NuberList = new QListWidget(Widget);
        NuberList->setObjectName(QString::fromUtf8("NuberList"));
        NuberList->setGeometry(QRect(510, 80, 241, 411));
        QFont font;
        font.setPointSize(12);
        NuberList->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 10, 111, 41));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 20, 161, 20));
        label_2->setFont(font1);
        NumLine = new QLineEdit(Widget);
        NumLine->setObjectName(QString::fromUtf8("NumLine"));
        NumLine->setGeometry(QRect(52, 70, 131, 41));
        push_back = new QPushButton(Widget);
        push_back->setObjectName(QString::fromUtf8("push_back"));
        push_back->setGeometry(QRect(60, 160, 75, 24));
        push_front = new QPushButton(Widget);
        push_front->setObjectName(QString::fromUtf8("push_front"));
        push_front->setGeometry(QRect(60, 210, 81, 24));
        pop_back = new QPushButton(Widget);
        pop_back->setObjectName(QString::fromUtf8("pop_back"));
        pop_back->setGeometry(QRect(60, 250, 75, 24));
        pop_front = new QPushButton(Widget);
        pop_front->setObjectName(QString::fromUtf8("pop_front"));
        pop_front->setGeometry(QRect(60, 300, 75, 24));
        clear = new QPushButton(Widget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(60, 350, 75, 24));
        empty = new QPushButton(Widget);
        empty->setObjectName(QString::fromUtf8("empty"));
        empty->setGeometry(QRect(60, 400, 75, 24));
        ItNum = new QLineEdit(Widget);
        ItNum->setObjectName(QString::fromUtf8("ItNum"));
        ItNum->setGeometry(QRect(50, 540, 51, 31));
        see_element = new QPushButton(Widget);
        see_element->setObjectName(QString::fromUtf8("see_element"));
        see_element->setGeometry(QRect(130, 550, 101, 24));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 510, 101, 20));
        QFont font2;
        font2.setPointSize(14);
        label_3->setFont(font2);
        change_dir = new QPushButton(Widget);
        change_dir->setObjectName(QString::fromUtf8("change_dir"));
        change_dir->setGeometry(QRect(660, 560, 75, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Deque", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Add Number", nullptr));
        push_back->setText(QCoreApplication::translate("Widget", "Push_Back", nullptr));
        push_front->setText(QCoreApplication::translate("Widget", "Push_Front", nullptr));
        pop_back->setText(QCoreApplication::translate("Widget", "Pop_Back", nullptr));
        pop_front->setText(QCoreApplication::translate("Widget", "Pop_Front", nullptr));
        clear->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        empty->setText(QCoreApplication::translate("Widget", "empty", nullptr));
        see_element->setText(QCoreApplication::translate("Widget", "see_element", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "i-element", nullptr));
        change_dir->setText(QCoreApplication::translate("Widget", "change_dir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
