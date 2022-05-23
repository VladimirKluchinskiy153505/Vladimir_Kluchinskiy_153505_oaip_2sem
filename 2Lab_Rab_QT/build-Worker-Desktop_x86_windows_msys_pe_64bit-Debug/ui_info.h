/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QPushButton *pushButton;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *line_hours;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *line_salary;

    void setupUi(QWidget *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(473, 347);
        pushButton = new QPushButton(Info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 280, 75, 24));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 20, 111, 16));
        label_3->setFont(font);
        widget = new QWidget(Info);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 160, 203, 34));
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        line_hours = new QLineEdit(widget);
        line_hours->setObjectName(QString::fromUtf8("line_hours"));
        line_hours->setFont(font);

        horizontalLayout->addWidget(line_hours);

        widget1 = new QWidget(Info);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 80, 202, 34));
        widget1->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        line_salary = new QLineEdit(widget1);
        line_salary->setObjectName(QString::fromUtf8("line_salary"));
        line_salary->setFont(font);

        horizontalLayout_2->addWidget(line_salary);


        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QWidget *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Info", "Save", nullptr));
        label_3->setText(QCoreApplication::translate("Info", "Information", nullptr));
        label_2->setText(QCoreApplication::translate("Info", "Enter Hours", nullptr));
        label->setText(QCoreApplication::translate("Info", "Enter Salary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
