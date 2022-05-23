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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *list_work;
    QListWidget *res_list;
    QPushButton *enter_criteria;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *salary_list;
    QListWidget *hours_list;
    QListWidget *over_list;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *line_del;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_name;
    QLineEdit *line_number;
    QLineEdit *line_hours;
    QLineEdit *line_rate;
    QPushButton *add_one;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1920, 1000);
        list_work = new QListWidget(Widget);
        list_work->setObjectName(QString::fromUtf8("list_work"));
        list_work->setGeometry(QRect(30, 40, 291, 551));
        QFont font;
        font.setPointSize(14);
        list_work->setFont(font);
        res_list = new QListWidget(Widget);
        res_list->setObjectName(QString::fromUtf8("res_list"));
        res_list->setGeometry(QRect(360, 40, 271, 551));
        QFont font1;
        font1.setPointSize(12);
        res_list->setFont(font1);
        enter_criteria = new QPushButton(Widget);
        enter_criteria->setObjectName(QString::fromUtf8("enter_criteria"));
        enter_criteria->setGeometry(QRect(20, 650, 101, 24));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 10, 49, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 10, 49, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(750, 10, 49, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1060, 20, 49, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1350, 20, 71, 16));
        salary_list = new QListWidget(Widget);
        salary_list->setObjectName(QString::fromUtf8("salary_list"));
        salary_list->setGeometry(QRect(660, 50, 281, 531));
        salary_list->setFont(font1);
        hours_list = new QListWidget(Widget);
        hours_list->setObjectName(QString::fromUtf8("hours_list"));
        hours_list->setGeometry(QRect(970, 51, 251, 531));
        hours_list->setFont(font1);
        over_list = new QListWidget(Widget);
        over_list->setObjectName(QString::fromUtf8("over_list"));
        over_list->setGeometry(QRect(1250, 61, 271, 521));
        over_list->setFont(font1);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(980, 710, 49, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1120, 710, 71, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1250, 710, 49, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1400, 710, 49, 16));
        label_9->setFont(font1);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1332, 670, 216, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        line_del = new QLineEdit(widget);
        line_del->setObjectName(QString::fromUtf8("line_del"));

        horizontalLayout->addWidget(line_del);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(950, 740, 633, 26));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_name = new QLineEdit(widget1);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        horizontalLayout_2->addWidget(line_name);

        line_number = new QLineEdit(widget1);
        line_number->setObjectName(QString::fromUtf8("line_number"));

        horizontalLayout_2->addWidget(line_number);

        line_hours = new QLineEdit(widget1);
        line_hours->setObjectName(QString::fromUtf8("line_hours"));

        horizontalLayout_2->addWidget(line_hours);

        line_rate = new QLineEdit(widget1);
        line_rate->setObjectName(QString::fromUtf8("line_rate"));

        horizontalLayout_2->addWidget(line_rate);

        add_one = new QPushButton(widget1);
        add_one->setObjectName(QString::fromUtf8("add_one"));

        horizontalLayout_2->addWidget(add_one);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        enter_criteria->setText(QCoreApplication::translate("Widget", "Enter_Criteria", nullptr));
        label->setText(QCoreApplication::translate("Widget", "NAMES", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "DATA", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "SALARY", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "HOURS", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "OVER_WORK", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Name", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Number", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Hours", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "Rate", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        add_one->setText(QCoreApplication::translate("Widget", "Add_One", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
