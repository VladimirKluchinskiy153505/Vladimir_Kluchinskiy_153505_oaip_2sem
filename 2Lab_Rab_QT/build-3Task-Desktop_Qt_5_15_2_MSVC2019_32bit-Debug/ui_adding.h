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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adding
{
public:
    QLabel *label;
    QPushButton *save;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineA;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineB;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineC;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineD;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineE;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *lineExpression;

    void setupUi(QWidget *Adding)
    {
        if (Adding->objectName().isEmpty())
            Adding->setObjectName(QString::fromUtf8("Adding"));
        Adding->resize(640, 479);
        label = new QLabel(Adding);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 161, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        save = new QPushButton(Adding);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(310, 380, 75, 24));
        widget = new QWidget(Adding);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 170, 153, 198));
        widget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        lineA = new QLineEdit(widget);
        lineA->setObjectName(QString::fromUtf8("lineA"));
        lineA->setFont(font);

        horizontalLayout->addWidget(lineA);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        lineB = new QLineEdit(widget);
        lineB->setObjectName(QString::fromUtf8("lineB"));
        lineB->setFont(font);

        horizontalLayout_2->addWidget(lineB);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        lineC = new QLineEdit(widget);
        lineC->setObjectName(QString::fromUtf8("lineC"));
        lineC->setFont(font);

        horizontalLayout_3->addWidget(lineC);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);

        lineD = new QLineEdit(widget);
        lineD->setObjectName(QString::fromUtf8("lineD"));
        lineD->setFont(font);

        horizontalLayout_4->addWidget(lineD);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_5->addWidget(label_7);

        lineE = new QLineEdit(widget);
        lineE->setObjectName(QString::fromUtf8("lineE"));
        lineE->setFont(font);

        horizontalLayout_5->addWidget(lineE);


        verticalLayout_2->addLayout(horizontalLayout_5);

        widget1 = new QWidget(Adding);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(220, 70, 251, 91));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        lineExpression = new QLineEdit(widget1);
        lineExpression->setObjectName(QString::fromUtf8("lineExpression"));
        lineExpression->setFont(font);

        verticalLayout_3->addWidget(lineExpression);


        retranslateUi(Adding);

        QMetaObject::connectSlotsByName(Adding);
    } // setupUi

    void retranslateUi(QWidget *Adding)
    {
        Adding->setWindowTitle(QCoreApplication::translate("Adding", "Form", nullptr));
        label->setText(QCoreApplication::translate("Adding", "Add_New_One", nullptr));
        save->setText(QCoreApplication::translate("Adding", "Save", nullptr));
        label_3->setText(QCoreApplication::translate("Adding", "A", nullptr));
        label_4->setText(QCoreApplication::translate("Adding", "B", nullptr));
        label_5->setText(QCoreApplication::translate("Adding", "C", nullptr));
        label_6->setText(QCoreApplication::translate("Adding", "D", nullptr));
        label_7->setText(QCoreApplication::translate("Adding", "E", nullptr));
        label_2->setText(QCoreApplication::translate("Adding", "Enter Expression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adding: public Ui_Adding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDING_H
