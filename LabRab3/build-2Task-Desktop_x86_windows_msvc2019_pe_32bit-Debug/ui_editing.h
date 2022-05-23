/********************************************************************************
** Form generated from reading UI file 'editing.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITING_H
#define UI_EDITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editing
{
public:
    QLabel *label_4;
    QPushButton *ok;
    QLineEdit *line_num;
    QTextEdit *textb2;
    QTextEdit *textb1;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Editing)
    {
        if (Editing->objectName().isEmpty())
            Editing->setObjectName(QString::fromUtf8("Editing"));
        Editing->resize(716, 480);
        label_4 = new QLabel(Editing);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(358, 210, 61, 31));
        QFont font;
        font.setPointSize(22);
        label_4->setFont(font);
        ok = new QPushButton(Editing);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(300, 320, 75, 41));
        ok->setFont(font);
        line_num = new QLineEdit(Editing);
        line_num->setObjectName(QString::fromUtf8("line_num"));
        line_num->setGeometry(QRect(370, 130, 113, 41));
        line_num->setFont(font);
        textb2 = new QTextEdit(Editing);
        textb2->setObjectName(QString::fromUtf8("textb2"));
        textb2->setGeometry(QRect(420, 200, 101, 51));
        textb2->setFont(font);
        textb1 = new QTextEdit(Editing);
        textb1->setObjectName(QString::fromUtf8("textb1"));
        textb1->setGeometry(QRect(230, 200, 104, 51));
        textb1->setFont(font);
        label_3 = new QLabel(Editing);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 210, 161, 41));
        label_3->setFont(font);
        label = new QLabel(Editing);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(218, 40, 261, 61));
        label->setFont(font);
        label_2 = new QLabel(Editing);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 120, 211, 51));
        label_2->setFont(font);

        retranslateUi(Editing);

        QMetaObject::connectSlotsByName(Editing);
    } // setupUi

    void retranslateUi(QWidget *Editing)
    {
        Editing->setWindowTitle(QCoreApplication::translate("Editing", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Editing", "To", nullptr));
        ok->setText(QCoreApplication::translate("Editing", "Ok", nullptr));
        label_3->setText(QCoreApplication::translate("Editing", "Select_From", nullptr));
        label->setText(QCoreApplication::translate("Editing", "Editing", nullptr));
        label_2->setText(QCoreApplication::translate("Editing", "Enter_a_number_to_edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editing: public Ui_Editing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITING_H
