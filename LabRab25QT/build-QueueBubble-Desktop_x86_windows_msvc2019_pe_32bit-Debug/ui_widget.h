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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *ListBox;
    QLabel *label;
    QComboBox *ListBox2;
    QPushButton *pushButton;
    QPushButton *change_directory;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        ListBox = new QComboBox(Widget);
        ListBox->setObjectName(QString::fromUtf8("ListBox"));
        ListBox->setGeometry(QRect(50, 150, 181, 41));
        QFont font;
        font.setPointSize(18);
        ListBox->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 20, 111, 41));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        ListBox2 = new QComboBox(Widget);
        ListBox2->setObjectName(QString::fromUtf8("ListBox2"));
        ListBox2->setGeometry(QRect(470, 150, 151, 41));
        ListBox2->setFont(font);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 453, 141, 41));
        change_directory = new QPushButton(Widget);
        change_directory->setObjectName(QString::fromUtf8("change_directory"));
        change_directory->setGeometry(QRect(260, 450, 111, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Queue", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "BubbleSort", nullptr));
        change_directory->setText(QCoreApplication::translate("Widget", "Change_Directory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
