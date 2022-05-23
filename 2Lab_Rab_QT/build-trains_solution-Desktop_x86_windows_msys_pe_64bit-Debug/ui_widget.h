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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *dest_list;
    QLabel *label;
    QPushButton *enter_date;
    QLabel *label_5;
    QLabel *label_6;
    QListWidget *suitable_list;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *line_day;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *line_month;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *line_year;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *see_info;
    QPushButton *del_one;
    QPushButton *add_one;
    QPushButton *edit_one;
    QPushButton *open_directory;
    QPushButton *qsort1;
    QPushButton *qsort2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        dest_list = new QListWidget(Widget);
        dest_list->setObjectName(QString::fromUtf8("dest_list"));
        dest_list->setGeometry(QRect(50, 60, 301, 221));
        QFont font;
        font.setPointSize(12);
        dest_list->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 211, 31));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        enter_date = new QPushButton(Widget);
        enter_date->setObjectName(QString::fromUtf8("enter_date"));
        enter_date->setGeometry(QRect(480, 410, 75, 24));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 330, 131, 20));
        QFont font2;
        font2.setPointSize(14);
        label_5->setFont(font2);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 20, 181, 20));
        label_6->setFont(font1);
        suitable_list = new QListWidget(Widget);
        suitable_list->setObjectName(QString::fromUtf8("suitable_list"));
        suitable_list->setGeometry(QRect(400, 60, 291, 221));
        suitable_list->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 380, 419, 58));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        line_day = new QLineEdit(layoutWidget);
        line_day->setObjectName(QString::fromUtf8("line_day"));

        verticalLayout->addWidget(line_day);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout_2->addWidget(label_2);

        line_month = new QLineEdit(layoutWidget);
        line_month->setObjectName(QString::fromUtf8("line_month"));

        verticalLayout_2->addWidget(line_month);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        verticalLayout_3->addWidget(label_4);

        line_year = new QLineEdit(layoutWidget);
        line_year->setObjectName(QString::fromUtf8("line_year"));

        verticalLayout_3->addWidget(line_year);


        horizontalLayout->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 530, 320, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        see_info = new QPushButton(layoutWidget1);
        see_info->setObjectName(QString::fromUtf8("see_info"));

        horizontalLayout_2->addWidget(see_info);

        del_one = new QPushButton(layoutWidget1);
        del_one->setObjectName(QString::fromUtf8("del_one"));

        horizontalLayout_2->addWidget(del_one);

        add_one = new QPushButton(layoutWidget1);
        add_one->setObjectName(QString::fromUtf8("add_one"));

        horizontalLayout_2->addWidget(add_one);

        edit_one = new QPushButton(layoutWidget1);
        edit_one->setObjectName(QString::fromUtf8("edit_one"));

        horizontalLayout_2->addWidget(edit_one);

        open_directory = new QPushButton(Widget);
        open_directory->setObjectName(QString::fromUtf8("open_directory"));
        open_directory->setGeometry(QRect(610, 530, 131, 24));
        qsort1 = new QPushButton(Widget);
        qsort1->setObjectName(QString::fromUtf8("qsort1"));
        qsort1->setGeometry(QRect(370, 530, 75, 24));
        qsort2 = new QPushButton(Widget);
        qsort2->setObjectName(QString::fromUtf8("qsort2"));
        qsort2->setGeometry(QRect(460, 530, 75, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Available Destinations", nullptr));
        enter_date->setText(QCoreApplication::translate("Widget", "enter_date", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "departure date", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Suitable Trains", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "day", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "month", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "year", nullptr));
        see_info->setText(QCoreApplication::translate("Widget", "see_info", nullptr));
        del_one->setText(QCoreApplication::translate("Widget", "del_one", nullptr));
        add_one->setText(QCoreApplication::translate("Widget", "add_one", nullptr));
        edit_one->setText(QCoreApplication::translate("Widget", "edit_one", nullptr));
        open_directory->setText(QCoreApplication::translate("Widget", "open_new_directory", nullptr));
        qsort1->setText(QCoreApplication::translate("Widget", "qsort1", nullptr));
        qsort2->setText(QCoreApplication::translate("Widget", "qsort2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
