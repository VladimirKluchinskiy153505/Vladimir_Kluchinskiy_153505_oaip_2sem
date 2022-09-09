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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *enter_button;
    QPushButton *all_button;
    QPushButton *any_button;
    QPushButton *count_button;
    QPushButton *none_button;
    QPushButton *size_button;
    QLabel *label_11;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *flip_button;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QLineEdit *line_flip;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *reset_button;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *line_reset;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *set_button;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *line_set;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *test_button;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLineEdit *line_test;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *button_get_string;
    QLineEdit *line_string;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *button_get_ULong;
    QLineEdit *line_ulong;
    QWidget *widget6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *button_get_ULongLong;
    QLineEdit *line_ulonglong;
    QWidget *widget7;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *button_get_bit;
    QLineEdit *bit_line;
    QWidget *widget8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *line_value;
    QWidget *widget9;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *line_N;
    QWidget *widget10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_13;
    QLineEdit *line_bit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1115, 727);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(940, 10, 121, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        enter_button = new QPushButton(Widget);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setGeometry(QRect(120, 100, 75, 24));
        enter_button->setFont(font);
        all_button = new QPushButton(Widget);
        all_button->setObjectName(QString::fromUtf8("all_button"));
        all_button->setGeometry(QRect(10, 120, 75, 24));
        all_button->setFont(font);
        any_button = new QPushButton(Widget);
        any_button->setObjectName(QString::fromUtf8("any_button"));
        any_button->setGeometry(QRect(10, 160, 75, 31));
        any_button->setFont(font);
        count_button = new QPushButton(Widget);
        count_button->setObjectName(QString::fromUtf8("count_button"));
        count_button->setGeometry(QRect(10, 210, 75, 24));
        count_button->setFont(font);
        none_button = new QPushButton(Widget);
        none_button->setObjectName(QString::fromUtf8("none_button"));
        none_button->setGeometry(QRect(10, 340, 75, 24));
        none_button->setFont(font);
        size_button = new QPushButton(Widget);
        size_button->setObjectName(QString::fromUtf8("size_button"));
        size_button->setGeometry(QRect(10, 550, 75, 24));
        size_button->setFont(font);
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(630, 370, 91, 21));
        label_11->setFont(font);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 250, 218, 68));
        widget->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        flip_button = new QPushButton(widget);
        flip_button->setObjectName(QString::fromUtf8("flip_button"));
        flip_button->setFont(font);

        horizontalLayout_2->addWidget(flip_button);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_6->addWidget(label_4);

        line_flip = new QLineEdit(widget);
        line_flip->setObjectName(QString::fromUtf8("line_flip"));
        line_flip->setFont(font);

        verticalLayout_6->addWidget(line_flip);


        horizontalLayout_2->addLayout(verticalLayout_6);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 380, 218, 68));
        widget1->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        reset_button = new QPushButton(widget1);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));
        reset_button->setFont(font);

        horizontalLayout_3->addWidget(reset_button);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_5->addWidget(label_5);

        line_reset = new QLineEdit(widget1);
        line_reset->setObjectName(QString::fromUtf8("line_reset"));
        line_reset->setFont(font);

        verticalLayout_5->addWidget(line_reset);


        horizontalLayout_3->addLayout(verticalLayout_5);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 460, 218, 68));
        widget2->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        set_button = new QPushButton(widget2);
        set_button->setObjectName(QString::fromUtf8("set_button"));
        set_button->setFont(font);

        horizontalLayout_4->addWidget(set_button);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_4->addWidget(label_6);

        line_set = new QLineEdit(widget2);
        line_set->setObjectName(QString::fromUtf8("line_set"));
        line_set->setFont(font);

        verticalLayout_4->addWidget(line_set);


        horizontalLayout_4->addLayout(verticalLayout_4);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 610, 218, 68));
        widget3->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        test_button = new QPushButton(widget3);
        test_button->setObjectName(QString::fromUtf8("test_button"));
        test_button->setFont(font);

        horizontalLayout_5->addWidget(test_button);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(widget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        line_test = new QLineEdit(widget3);
        line_test->setObjectName(QString::fromUtf8("line_test"));
        line_test->setFont(font);

        verticalLayout_3->addWidget(line_test);


        horizontalLayout_5->addLayout(verticalLayout_3);

        widget4 = new QWidget(Widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(350, 100, 721, 70));
        widget4->setFont(font);
        verticalLayout_7 = new QVBoxLayout(widget4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_7->addWidget(label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        button_get_string = new QPushButton(widget4);
        button_get_string->setObjectName(QString::fromUtf8("button_get_string"));
        button_get_string->setFont(font);

        horizontalLayout_6->addWidget(button_get_string);

        line_string = new QLineEdit(widget4);
        line_string->setObjectName(QString::fromUtf8("line_string"));
        line_string->setFont(font);

        horizontalLayout_6->addWidget(line_string);


        verticalLayout_7->addLayout(horizontalLayout_6);

        widget5 = new QWidget(Widget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(350, 190, 711, 70));
        widget5->setFont(font);
        verticalLayout_8 = new QVBoxLayout(widget5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_8->addWidget(label_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        button_get_ULong = new QPushButton(widget5);
        button_get_ULong->setObjectName(QString::fromUtf8("button_get_ULong"));
        button_get_ULong->setFont(font);

        horizontalLayout_7->addWidget(button_get_ULong);

        line_ulong = new QLineEdit(widget5);
        line_ulong->setObjectName(QString::fromUtf8("line_ulong"));
        line_ulong->setFont(font);

        horizontalLayout_7->addWidget(line_ulong);


        verticalLayout_8->addLayout(horizontalLayout_7);

        widget6 = new QWidget(Widget);
        widget6->setObjectName(QString::fromUtf8("widget6"));
        widget6->setGeometry(QRect(350, 270, 711, 70));
        widget6->setFont(font);
        verticalLayout_9 = new QVBoxLayout(widget6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        verticalLayout_9->addWidget(label_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        button_get_ULongLong = new QPushButton(widget6);
        button_get_ULongLong->setObjectName(QString::fromUtf8("button_get_ULongLong"));
        button_get_ULongLong->setFont(font);

        horizontalLayout_8->addWidget(button_get_ULongLong);

        line_ulonglong = new QLineEdit(widget6);
        line_ulonglong->setObjectName(QString::fromUtf8("line_ulonglong"));
        line_ulonglong->setFont(font);

        horizontalLayout_8->addWidget(line_ulonglong);


        verticalLayout_9->addLayout(horizontalLayout_8);

        widget7 = new QWidget(Widget);
        widget7->setObjectName(QString::fromUtf8("widget7"));
        widget7->setGeometry(QRect(570, 400, 218, 70));
        widget7->setFont(font);
        verticalLayout_10 = new QVBoxLayout(widget7);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        verticalLayout_10->addWidget(label_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        button_get_bit = new QPushButton(widget7);
        button_get_bit->setObjectName(QString::fromUtf8("button_get_bit"));
        button_get_bit->setFont(font);

        horizontalLayout_9->addWidget(button_get_bit);

        bit_line = new QLineEdit(widget7);
        bit_line->setObjectName(QString::fromUtf8("bit_line"));
        bit_line->setFont(font);

        horizontalLayout_9->addWidget(bit_line);


        verticalLayout_10->addLayout(horizontalLayout_9);

        widget8 = new QWidget(Widget);
        widget8->setObjectName(QString::fromUtf8("widget8"));
        widget8->setGeometry(QRect(210, 20, 641, 66));
        verticalLayout_2 = new QVBoxLayout(widget8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget8);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        line_value = new QLineEdit(widget8);
        line_value->setObjectName(QString::fromUtf8("line_value"));
        line_value->setFont(font);

        verticalLayout_2->addWidget(line_value);

        widget9 = new QWidget(Widget);
        widget9->setObjectName(QString::fromUtf8("widget9"));
        widget9->setGeometry(QRect(21, 21, 186, 66));
        widget9->setFont(font);
        verticalLayout = new QVBoxLayout(widget9);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget9);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        line_N = new QLineEdit(widget9);
        line_N->setObjectName(QString::fromUtf8("line_N"));
        line_N->setFont(font);

        verticalLayout->addWidget(line_N);

        widget10 = new QWidget(Widget);
        widget10->setObjectName(QString::fromUtf8("widget10"));
        widget10->setGeometry(QRect(790, 400, 82, 66));
        widget10->setFont(font);
        verticalLayout_11 = new QVBoxLayout(widget10);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(widget10);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        verticalLayout_11->addWidget(label_13);

        line_bit = new QLineEdit(widget10);
        line_bit->setObjectName(QString::fromUtf8("line_bit"));
        line_bit->setFont(font);

        verticalLayout_11->addWidget(line_bit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Bitset", nullptr));
        enter_button->setText(QCoreApplication::translate("Widget", "ENTER", nullptr));
        all_button->setText(QCoreApplication::translate("Widget", "All", nullptr));
        any_button->setText(QCoreApplication::translate("Widget", "Any", nullptr));
        count_button->setText(QCoreApplication::translate("Widget", "Count", nullptr));
        none_button->setText(QCoreApplication::translate("Widget", "None", nullptr));
        size_button->setText(QCoreApplication::translate("Widget", "Size", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "Operator[]", nullptr));
        flip_button->setText(QCoreApplication::translate("Widget", "Flip", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Position", nullptr));
        reset_button->setText(QCoreApplication::translate("Widget", "Reset", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Position", nullptr));
        set_button->setText(QCoreApplication::translate("Widget", "Set", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Position", nullptr));
        test_button->setText(QCoreApplication::translate("Widget", "Test", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Position", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "TO_STRING", nullptr));
        button_get_string->setText(QCoreApplication::translate("Widget", "get", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "To_ULong", nullptr));
        button_get_ULong->setText(QCoreApplication::translate("Widget", "get", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "To_ULongLong", nullptr));
        button_get_ULongLong->setText(QCoreApplication::translate("Widget", "get", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "Position", nullptr));
        button_get_bit->setText(QCoreApplication::translate("Widget", "get_bit", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Value", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "N", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "Bit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
