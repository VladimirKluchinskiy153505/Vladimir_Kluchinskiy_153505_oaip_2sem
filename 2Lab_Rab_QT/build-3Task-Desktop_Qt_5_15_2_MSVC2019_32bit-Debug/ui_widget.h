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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *table;
    QPushButton *add_new;
    QPushButton *add_new_pwr;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1300, 616);
        table = new QTableWidget(Widget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(40, 10, 981, 581));
        add_new = new QPushButton(Widget);
        add_new->setObjectName(QString::fromUtf8("add_new"));
        add_new->setGeometry(QRect(1200, 10, 75, 24));
        add_new_pwr = new QPushButton(Widget);
        add_new_pwr->setObjectName(QString::fromUtf8("add_new_pwr"));
        add_new_pwr->setGeometry(QRect(1180, 140, 111, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        add_new->setText(QCoreApplication::translate("Widget", "add_new", nullptr));
        add_new_pwr->setText(QCoreApplication::translate("Widget", "add_new_in_prw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
