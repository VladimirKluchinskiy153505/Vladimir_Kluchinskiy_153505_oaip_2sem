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
    QPushButton *eraze_button;
    QPushButton *insert_button;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *line_eraze_key;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *line_key_insert;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *line_data_insert;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *line_key_find;
    QPushButton *find_button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1280, 720);
        table = new QTableWidget(Widget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(10, 20, 1211, 611));
        table->setAutoFillBackground(true);
        eraze_button = new QPushButton(Widget);
        eraze_button->setObjectName(QString::fromUtf8("eraze_button"));
        eraze_button->setGeometry(QRect(80, 690, 75, 24));
        insert_button = new QPushButton(Widget);
        insert_button->setObjectName(QString::fromUtf8("insert_button"));
        insert_button->setGeometry(QRect(450, 690, 75, 24));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 670, 111, 24));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 660, 64, 56));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        line_eraze_key = new QLineEdit(widget);
        line_eraze_key->setObjectName(QString::fromUtf8("line_eraze_key"));

        verticalLayout_2->addWidget(line_eraze_key);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(170, 660, 64, 56));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        line_key_insert = new QLineEdit(widget1);
        line_key_insert->setObjectName(QString::fromUtf8("line_key_insert"));

        verticalLayout_3->addWidget(line_key_insert);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(240, 660, 211, 56));
        verticalLayout_4 = new QVBoxLayout(widget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_4->addWidget(label_4);

        line_data_insert = new QLineEdit(widget2);
        line_data_insert->setObjectName(QString::fromUtf8("line_data_insert"));

        verticalLayout_4->addWidget(line_data_insert);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(540, 650, 151, 58));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        line_key_find = new QLineEdit(widget3);
        line_key_find->setObjectName(QString::fromUtf8("line_key_find"));

        verticalLayout->addWidget(line_key_find);


        horizontalLayout->addLayout(verticalLayout);

        find_button = new QPushButton(widget3);
        find_button->setObjectName(QString::fromUtf8("find_button"));

        horizontalLayout->addWidget(find_button);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        eraze_button->setText(QCoreApplication::translate("Widget", "eraze", nullptr));
        insert_button->setText(QCoreApplication::translate("Widget", "insert", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "find_with_min_key", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Data", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        find_button->setText(QCoreApplication::translate("Widget", "find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
