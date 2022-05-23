/********************************************************************************
** Form generated from reading UI file 'adding.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDING_H
#define UI_ADDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adding
{
public:
    QLabel *label_13;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_day;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *line_month;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *line_year;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *line_dest;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *line_hours;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *line_minuts;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *line_number;
    QPushButton *save;

    void setupUi(QWidget *Adding)
    {
        if (Adding->objectName().isEmpty())
            Adding->setObjectName(QString::fromUtf8("Adding"));
        Adding->resize(653, 416);
        label_13 = new QLabel(Adding);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(240, 20, 151, 41));
        QFont font;
        font.setPointSize(24);
        label_13->setFont(font);
        layoutWidget = new QWidget(Adding);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 90, 168, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        line_day = new QLineEdit(layoutWidget);
        line_day->setObjectName(QString::fromUtf8("line_day"));

        horizontalLayout->addWidget(line_day);

        layoutWidget1 = new QWidget(Adding);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 150, 187, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        line_month = new QLineEdit(layoutWidget1);
        line_month->setObjectName(QString::fromUtf8("line_month"));

        horizontalLayout_2->addWidget(line_month);

        layoutWidget2 = new QWidget(Adding);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 200, 171, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        line_year = new QLineEdit(layoutWidget2);
        line_year->setObjectName(QString::fromUtf8("line_year"));

        horizontalLayout_3->addWidget(line_year);

        layoutWidget3 = new QWidget(Adding);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(270, 80, 220, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        line_dest = new QLineEdit(layoutWidget3);
        line_dest->setObjectName(QString::fromUtf8("line_dest"));

        horizontalLayout_4->addWidget(line_dest);

        layoutWidget4 = new QWidget(Adding);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(430, 140, 183, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        line_hours = new QLineEdit(layoutWidget4);
        line_hours->setObjectName(QString::fromUtf8("line_hours"));

        horizontalLayout_5->addWidget(line_hours);

        layoutWidget5 = new QWidget(Adding);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(430, 180, 197, 24));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_6->addWidget(label_6);

        line_minuts = new QLineEdit(layoutWidget5);
        line_minuts->setObjectName(QString::fromUtf8("line_minuts"));

        horizontalLayout_6->addWidget(line_minuts);

        layoutWidget6 = new QWidget(Adding);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(240, 230, 196, 24));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_7->addWidget(label_7);

        line_number = new QLineEdit(layoutWidget6);
        line_number->setObjectName(QString::fromUtf8("line_number"));

        horizontalLayout_7->addWidget(line_number);

        save = new QPushButton(Adding);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(190, 360, 75, 24));

        retranslateUi(Adding);

        QMetaObject::connectSlotsByName(Adding);
    } // setupUi

    void retranslateUi(QWidget *Adding)
    {
        Adding->setWindowTitle(QCoreApplication::translate("Adding", "Form", nullptr));
        label_13->setText(QCoreApplication::translate("Adding", "Data", nullptr));
        label->setText(QCoreApplication::translate("Adding", "Day", nullptr));
        label_2->setText(QCoreApplication::translate("Adding", "Month", nullptr));
        label_3->setText(QCoreApplication::translate("Adding", "Year", nullptr));
        label_4->setText(QCoreApplication::translate("Adding", "Destination", nullptr));
        label_5->setText(QCoreApplication::translate("Adding", "Hours", nullptr));
        label_6->setText(QCoreApplication::translate("Adding", "minutes", nullptr));
        label_7->setText(QCoreApplication::translate("Adding", "number", nullptr));
        save->setText(QCoreApplication::translate("Adding", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adding: public Ui_Adding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDING_H
