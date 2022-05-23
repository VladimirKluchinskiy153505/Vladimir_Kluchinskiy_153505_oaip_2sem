/********************************************************************************
** Form generated from reading UI file 'editingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINGDIALOG_H
#define UI_EDITINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditingDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *line_minuts;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *line_hours;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *line_year;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *line_number;
    QPushButton *save;
    QLabel *label_13;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *line_month;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *line_dest;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_day;
    QPushButton *pushButton;

    void setupUi(QWidget *EditingDialog)
    {
        if (EditingDialog->objectName().isEmpty())
            EditingDialog->setObjectName(QString::fromUtf8("EditingDialog"));
        EditingDialog->resize(799, 459);
        layoutWidget = new QWidget(EditingDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(550, 200, 197, 24));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(12);
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        line_minuts = new QLineEdit(layoutWidget);
        line_minuts->setObjectName(QString::fromUtf8("line_minuts"));

        horizontalLayout_6->addWidget(line_minuts);

        layoutWidget_2 = new QWidget(EditingDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(550, 140, 183, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        line_hours = new QLineEdit(layoutWidget_2);
        line_hours->setObjectName(QString::fromUtf8("line_hours"));

        horizontalLayout_5->addWidget(line_hours);

        layoutWidget_3 = new QWidget(EditingDialog);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 220, 171, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        line_year = new QLineEdit(layoutWidget_3);
        line_year->setObjectName(QString::fromUtf8("line_year"));

        horizontalLayout_3->addWidget(line_year);

        layoutWidget_4 = new QWidget(EditingDialog);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(310, 270, 196, 24));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        line_number = new QLineEdit(layoutWidget_4);
        line_number->setObjectName(QString::fromUtf8("line_number"));

        horizontalLayout_7->addWidget(line_number);

        save = new QPushButton(EditingDialog);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(320, 470, 75, 24));
        label_13 = new QLabel(EditingDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(270, 10, 151, 41));
        QFont font1;
        font1.setPointSize(24);
        label_13->setFont(font1);
        layoutWidget_5 = new QWidget(EditingDialog);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(40, 160, 187, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        line_month = new QLineEdit(layoutWidget_5);
        line_month->setObjectName(QString::fromUtf8("line_month"));

        horizontalLayout_2->addWidget(line_month);

        layoutWidget_6 = new QWidget(EditingDialog);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(290, 100, 220, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        line_dest = new QLineEdit(layoutWidget_6);
        line_dest->setObjectName(QString::fromUtf8("line_dest"));

        horizontalLayout_4->addWidget(line_dest);

        layoutWidget_7 = new QWidget(EditingDialog);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(40, 100, 168, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget_7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        line_day = new QLineEdit(layoutWidget_7);
        line_day->setObjectName(QString::fromUtf8("line_day"));

        horizontalLayout->addWidget(line_day);

        pushButton = new QPushButton(EditingDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 380, 75, 24));

        retranslateUi(EditingDialog);

        QMetaObject::connectSlotsByName(EditingDialog);
    } // setupUi

    void retranslateUi(QWidget *EditingDialog)
    {
        EditingDialog->setWindowTitle(QCoreApplication::translate("EditingDialog", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("EditingDialog", "minutes", nullptr));
        label_5->setText(QCoreApplication::translate("EditingDialog", "Hours", nullptr));
        label_3->setText(QCoreApplication::translate("EditingDialog", "Year", nullptr));
        label_7->setText(QCoreApplication::translate("EditingDialog", "number", nullptr));
        save->setText(QCoreApplication::translate("EditingDialog", "save", nullptr));
        label_13->setText(QCoreApplication::translate("EditingDialog", "Data", nullptr));
        label_2->setText(QCoreApplication::translate("EditingDialog", "Month", nullptr));
        label_4->setText(QCoreApplication::translate("EditingDialog", "Destination", nullptr));
        label->setText(QCoreApplication::translate("EditingDialog", "Day", nullptr));
        pushButton->setText(QCoreApplication::translate("EditingDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditingDialog: public Ui_EditingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGDIALOG_H
