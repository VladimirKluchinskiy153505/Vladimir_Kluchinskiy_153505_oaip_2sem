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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTreeWidget *treeWidget;
    QLabel *label;
    QLineEdit *line_deep;
    QLabel *label_2;
    QPushButton *find_button;
    QPushButton *find_min_button;
    QPushButton *find_max_button;
    QPushButton *clear_button;
    QPushButton *eraze_button;
    QPushButton *insert_button;
    QPushButton *pre_travel_button;
    QPushButton *in_travel_button;
    QPushButton *pos_travel_button;
    QPushButton *find_min_rec_button;
    QPushButton *find_max_rec_button;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *change_dir_button;
    QListWidget *list_nodes;
    QLabel *label_10;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *line_key_eraze;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLineEdit *line_key_insert;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *line_data_insert;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *line_key_find;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QLineEdit *line2;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *line1;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1219, 706);
        QFont font;
        font.setPointSize(14);
        Widget->setFont(font);
        Widget->setAutoFillBackground(false);
        treeWidget = new QTreeWidget(Widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(9, 41, 761, 621));
        QFont font1;
        font1.setPointSize(10);
        treeWidget->setFont(font1);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 81, 26));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(105, 105, 105, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        QBrush brush6(QColor(0, 120, 215, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush7(QColor(0, 0, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush7);
        QBrush brush8(QColor(255, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush8);
        QBrush brush9(QColor(245, 245, 245, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        QBrush brush13(QColor(120, 120, 120, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush14(QColor(247, 247, 247, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        label->setPalette(palette);
        label->setFont(font);
        label->setAutoFillBackground(false);
        line_deep = new QLineEdit(Widget);
        line_deep->setObjectName(QString::fromUtf8("line_deep"));
        line_deep->setGeometry(QRect(1100, 30, 91, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1120, 0, 49, 21));
        find_button = new QPushButton(Widget);
        find_button->setObjectName(QString::fromUtf8("find_button"));
        find_button->setGeometry(QRect(1070, 440, 75, 24));
        QFont font2;
        font2.setPointSize(9);
        find_button->setFont(font2);
        find_min_button = new QPushButton(Widget);
        find_min_button->setObjectName(QString::fromUtf8("find_min_button"));
        find_min_button->setGeometry(QRect(1050, 500, 75, 24));
        find_min_button->setFont(font2);
        find_max_button = new QPushButton(Widget);
        find_max_button->setObjectName(QString::fromUtf8("find_max_button"));
        find_max_button->setGeometry(QRect(1050, 530, 75, 24));
        find_max_button->setFont(font2);
        clear_button = new QPushButton(Widget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setGeometry(QRect(1130, 670, 75, 24));
        clear_button->setFont(font2);
        eraze_button = new QPushButton(Widget);
        eraze_button->setObjectName(QString::fromUtf8("eraze_button"));
        eraze_button->setGeometry(QRect(1140, 120, 75, 24));
        eraze_button->setFont(font2);
        insert_button = new QPushButton(Widget);
        insert_button->setObjectName(QString::fromUtf8("insert_button"));
        insert_button->setGeometry(QRect(1060, 320, 75, 24));
        insert_button->setFont(font2);
        pre_travel_button = new QPushButton(Widget);
        pre_travel_button->setObjectName(QString::fromUtf8("pre_travel_button"));
        pre_travel_button->setGeometry(QRect(1040, 640, 75, 24));
        pre_travel_button->setFont(font2);
        in_travel_button = new QPushButton(Widget);
        in_travel_button->setObjectName(QString::fromUtf8("in_travel_button"));
        in_travel_button->setGeometry(QRect(1040, 670, 75, 24));
        in_travel_button->setFont(font2);
        pos_travel_button = new QPushButton(Widget);
        pos_travel_button->setObjectName(QString::fromUtf8("pos_travel_button"));
        pos_travel_button->setGeometry(QRect(1130, 640, 75, 24));
        pos_travel_button->setFont(font2);
        find_min_rec_button = new QPushButton(Widget);
        find_min_rec_button->setObjectName(QString::fromUtf8("find_min_rec_button"));
        find_min_rec_button->setGeometry(QRect(1130, 500, 81, 24));
        find_min_rec_button->setFont(font2);
        find_max_rec_button = new QPushButton(Widget);
        find_max_rec_button->setObjectName(QString::fromUtf8("find_max_rec_button"));
        find_max_rec_button->setGeometry(QRect(1130, 530, 91, 24));
        find_max_rec_button->setFont(font2);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1090, 70, 71, 16));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1090, 200, 111, 16));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1080, 370, 91, 41));
        change_dir_button = new QPushButton(Widget);
        change_dir_button->setObjectName(QString::fromUtf8("change_dir_button"));
        change_dir_button->setGeometry(QRect(1040, 610, 171, 24));
        change_dir_button->setFont(font2);
        list_nodes = new QListWidget(Widget);
        list_nodes->setObjectName(QString::fromUtf8("list_nodes"));
        list_nodes->setGeometry(QRect(840, 330, 191, 361));
        list_nodes->setFont(font2);
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(880, 10, 111, 20));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(840, 100, 121, 24));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1070, 100, 61, 66));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        line_key_eraze = new QLineEdit(widget);
        line_key_eraze->setObjectName(QString::fromUtf8("line_key_eraze"));

        verticalLayout_3->addWidget(line_key_eraze);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(950, 240, 82, 66));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        line_key_insert = new QLineEdit(widget1);
        line_key_insert->setObjectName(QString::fromUtf8("line_key_insert"));

        verticalLayout->addWidget(line_key_insert);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(1030, 240, 186, 66));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        line_data_insert = new QLineEdit(widget2);
        line_data_insert->setObjectName(QString::fromUtf8("line_data_insert"));

        verticalLayout_2->addWidget(line_data_insert);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(1150, 420, 61, 66));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        line_key_find = new QLineEdit(widget3);
        line_key_find->setObjectName(QString::fromUtf8("line_key_find"));

        verticalLayout_4->addWidget(line_key_find);

        widget4 = new QWidget(Widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(910, 50, 71, 34));
        horizontalLayout_2 = new QHBoxLayout(widget4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        line2 = new QLineEdit(widget4);
        line2->setObjectName(QString::fromUtf8("line2"));

        horizontalLayout_2->addWidget(line2);

        widget5 = new QWidget(Widget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(800, 50, 91, 34));
        horizontalLayout = new QHBoxLayout(widget5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        line1 = new QLineEdit(widget5);
        line1->setObjectName(QString::fromUtf8("line1"));

        horizontalLayout->addWidget(line1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "AVL_TREE", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Deep", nullptr));
        find_button->setText(QCoreApplication::translate("Widget", "find", nullptr));
        find_min_button->setText(QCoreApplication::translate("Widget", "find_min", nullptr));
        find_max_button->setText(QCoreApplication::translate("Widget", "find_max", nullptr));
        clear_button->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        eraze_button->setText(QCoreApplication::translate("Widget", "eraze", nullptr));
        insert_button->setText(QCoreApplication::translate("Widget", "insert", nullptr));
        pre_travel_button->setText(QCoreApplication::translate("Widget", "pre_travel", nullptr));
        in_travel_button->setText(QCoreApplication::translate("Widget", "in_travel", nullptr));
        pos_travel_button->setText(QCoreApplication::translate("Widget", "post_travel", nullptr));
        find_min_rec_button->setText(QCoreApplication::translate("Widget", "find_min_rec", nullptr));
        find_max_rec_button->setText(QCoreApplication::translate("Widget", "find_max_rec", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "ERAZE", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Insertion", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "FINDING", nullptr));
        change_dir_button->setText(QCoreApplication::translate("Widget", "Change_Directory", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "Eraze Range", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Eraze_Range", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Data", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "To", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "From", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
