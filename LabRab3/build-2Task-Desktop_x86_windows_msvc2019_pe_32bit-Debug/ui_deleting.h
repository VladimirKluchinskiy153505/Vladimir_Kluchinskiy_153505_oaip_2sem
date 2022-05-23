/********************************************************************************
** Form generated from reading UI file 'deleting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETING_H
#define UI_DELETING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deleting
{
public:
    QLineEdit *lineb1;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_num_to_del;
    QPushButton *save_button;
    QLineEdit *lineb2;
    QLabel *label_4;
    QLabel *label_2;

    void setupUi(QWidget *Deleting)
    {
        if (Deleting->objectName().isEmpty())
            Deleting->setObjectName(QString::fromUtf8("Deleting"));
        Deleting->resize(600, 389);
        lineb1 = new QLineEdit(Deleting);
        lineb1->setObjectName(QString::fromUtf8("lineb1"));
        lineb1->setGeometry(QRect(190, 160, 41, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        lineb1->setFont(font);
        label_3 = new QLabel(Deleting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 160, 131, 31));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_3->setFont(font1);
        layoutWidget = new QWidget(Deleting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 100, 321, 40));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        line_num_to_del = new QLineEdit(layoutWidget);
        line_num_to_del->setObjectName(QString::fromUtf8("line_num_to_del"));

        horizontalLayout->addWidget(line_num_to_del);

        save_button = new QPushButton(Deleting);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(170, 240, 75, 31));
        lineb2 = new QLineEdit(Deleting);
        lineb2->setObjectName(QString::fromUtf8("lineb2"));
        lineb2->setGeometry(QRect(320, 160, 61, 31));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setItalic(true);
        lineb2->setFont(font3);
        label_4 = new QLabel(Deleting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 160, 49, 21));
        label_2 = new QLabel(Deleting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 20, 121, 31));
        label_2->setFont(font1);

        retranslateUi(Deleting);

        QMetaObject::connectSlotsByName(Deleting);
    } // setupUi

    void retranslateUi(QWidget *Deleting)
    {
        Deleting->setWindowTitle(QCoreApplication::translate("Deleting", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Deleting", "Select_from", nullptr));
        label->setText(QCoreApplication::translate("Deleting", "Enter_a_number", nullptr));
        save_button->setText(QCoreApplication::translate("Deleting", "Save", nullptr));
        label_4->setText(QCoreApplication::translate("Deleting", "To", nullptr));
        label_2->setText(QCoreApplication::translate("Deleting", "Deleting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deleting: public Ui_Deleting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETING_H
