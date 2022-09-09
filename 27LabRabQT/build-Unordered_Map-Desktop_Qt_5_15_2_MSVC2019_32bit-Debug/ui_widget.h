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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *table;
    QPushButton *earaze_button;
    QPushButton *insert_button;
    QPushButton *find_button;
    QPushButton *clear_button;
    QPushButton *emplace_button;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *key_eraze;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *data_insert;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *key_insert;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *key_find;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1367, 720);
        table = new QTableWidget(Widget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(5, 10, 861, 551));
        earaze_button = new QPushButton(Widget);
        earaze_button->setObjectName(QString::fromUtf8("earaze_button"));
        earaze_button->setGeometry(QRect(30, 670, 75, 24));
        insert_button = new QPushButton(Widget);
        insert_button->setObjectName(QString::fromUtf8("insert_button"));
        insert_button->setGeometry(QRect(240, 670, 75, 24));
        find_button = new QPushButton(Widget);
        find_button->setObjectName(QString::fromUtf8("find_button"));
        find_button->setGeometry(QRect(530, 670, 75, 24));
        clear_button = new QPushButton(Widget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setGeometry(QRect(830, 680, 75, 24));
        emplace_button = new QPushButton(Widget);
        emplace_button->setObjectName(QString::fromUtf8("emplace_button"));
        emplace_button->setGeometry(QRect(990, 680, 75, 24));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 590, 91, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        key_eraze = new QLineEdit(widget);
        key_eraze->setObjectName(QString::fromUtf8("key_eraze"));
        key_eraze->setFont(font);

        verticalLayout->addWidget(key_eraze);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(260, 600, 201, 66));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        data_insert = new QLineEdit(widget1);
        data_insert->setObjectName(QString::fromUtf8("data_insert"));
        data_insert->setFont(font);

        verticalLayout_3->addWidget(data_insert);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(180, 600, 82, 66));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        key_insert = new QLineEdit(widget2);
        key_insert->setObjectName(QString::fromUtf8("key_insert"));
        key_insert->setFont(font);

        verticalLayout_2->addWidget(key_insert);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(530, 600, 71, 66));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_4->addWidget(label_4);

        key_find = new QLineEdit(widget3);
        key_find->setObjectName(QString::fromUtf8("key_find"));
        key_find->setFont(font);

        verticalLayout_4->addWidget(key_find);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        earaze_button->setText(QCoreApplication::translate("Widget", "eraze", nullptr));
        insert_button->setText(QCoreApplication::translate("Widget", "insert", nullptr));
        find_button->setText(QCoreApplication::translate("Widget", "find", nullptr));
        clear_button->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        emplace_button->setText(QCoreApplication::translate("Widget", "emplace", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Data", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Key", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
