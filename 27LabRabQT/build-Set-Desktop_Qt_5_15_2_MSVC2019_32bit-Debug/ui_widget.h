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
    QPushButton *change_dir_button;
    QPushButton *clear_button;
    QListWidget *list_nodes;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_24;
    QLineEdit *ub_key;
    QPushButton *FindUB_button;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLineEdit *line_size_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_2;
    QLineEdit *line_deep;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QLineEdit *line_key_insert_2;
    QPushButton *insert_button;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_21;
    QLineEdit *line1_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_20;
    QLineEdit *line2_3;
    QPushButton *eraze_range_button;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *find_button;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QLineEdit *line_key_find_2;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_17;
    QPushButton *find_max_button;
    QPushButton *find_max_rec_button;
    QVBoxLayout *verticalLayout_16;
    QPushButton *find_min_button;
    QPushButton *find_min_rec_button;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_18;
    QPushButton *pre_travel_button;
    QPushButton *pos_travel_button;
    QPushButton *in_travel_button;
    QWidget *widget6;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_19;
    QLineEdit *line_key_eraze_2;
    QPushButton *eraze_button;
    QWidget *widget7;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_23;
    QPushButton *button_iterator;
    QWidget *widget8;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_25;
    QPushButton *rcons_button;
    QWidget *widget9;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_26;
    QLineEdit *lb_key;
    QPushButton *findLB_button;
    QWidget *widget10;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_28;
    QLineEdit *ub_key_2;
    QPushButton *FindUB_button_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1900, 1000);
        treeWidget = new QTreeWidget(Widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(20, 60, 881, 821));
        QFont font;
        font.setPointSize(14);
        treeWidget->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 10, 151, 31));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        change_dir_button = new QPushButton(Widget);
        change_dir_button->setObjectName(QString::fromUtf8("change_dir_button"));
        change_dir_button->setGeometry(QRect(1580, 630, 171, 24));
        QFont font2;
        font2.setPointSize(10);
        change_dir_button->setFont(font2);
        clear_button = new QPushButton(Widget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setGeometry(QRect(1660, 570, 75, 24));
        clear_button->setFont(font2);
        list_nodes = new QListWidget(Widget);
        list_nodes->setObjectName(QString::fromUtf8("list_nodes"));
        list_nodes->setGeometry(QRect(930, 70, 191, 511));
        list_nodes->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(970, 1000, 91, 66));
        verticalLayout_19 = new QVBoxLayout(layoutWidget);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_19->addWidget(label_24);

        ub_key = new QLineEdit(layoutWidget);
        ub_key->setObjectName(QString::fromUtf8("ub_key"));

        verticalLayout_19->addWidget(ub_key);

        FindUB_button = new QPushButton(Widget);
        FindUB_button->setObjectName(QString::fromUtf8("FindUB_button"));
        FindUB_button->setGeometry(QRect(1070, 1020, 75, 24));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1260, 20, 231, 68));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        verticalLayout_8->addWidget(label_16);

        line_size_2 = new QLineEdit(widget);
        line_size_2->setObjectName(QString::fromUtf8("line_size_2"));
        line_size_2->setFont(font);

        verticalLayout_8->addWidget(line_size_2);


        horizontalLayout_11->addLayout(verticalLayout_8);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_11->addWidget(label_2);

        line_deep = new QLineEdit(widget);
        line_deep->setObjectName(QString::fromUtf8("line_deep"));
        line_deep->setFont(font);

        verticalLayout_11->addWidget(line_deep);


        horizontalLayout_11->addLayout(verticalLayout_11);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(1560, 290, 271, 102));
        verticalLayout_12 = new QVBoxLayout(widget1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_12->addWidget(label_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_9 = new QLabel(widget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_7->addWidget(label_9);

        line_key_insert_2 = new QLineEdit(widget1);
        line_key_insert_2->setObjectName(QString::fromUtf8("line_key_insert_2"));
        line_key_insert_2->setFont(font);

        verticalLayout_7->addWidget(line_key_insert_2);


        horizontalLayout_9->addLayout(verticalLayout_7);

        insert_button = new QPushButton(widget1);
        insert_button->setObjectName(QString::fromUtf8("insert_button"));
        insert_button->setFont(font);

        horizontalLayout_9->addWidget(insert_button);


        verticalLayout_12->addLayout(horizontalLayout_9);

        widget2 = new QWidget(Widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(1240, 130, 458, 112));
        verticalLayout_14 = new QVBoxLayout(widget2);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(widget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        verticalLayout_14->addWidget(label_17);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_21 = new QLabel(widget2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);

        horizontalLayout_6->addWidget(label_21);

        line1_3 = new QLineEdit(widget2);
        line1_3->setObjectName(QString::fromUtf8("line1_3"));
        line1_3->setFont(font);

        horizontalLayout_6->addWidget(line1_3);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_20 = new QLabel(widget2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        horizontalLayout_5->addWidget(label_20);

        line2_3 = new QLineEdit(widget2);
        line2_3->setObjectName(QString::fromUtf8("line2_3"));
        line2_3->setFont(font);

        horizontalLayout_5->addWidget(line2_3);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_7);

        eraze_range_button = new QPushButton(widget2);
        eraze_range_button->setObjectName(QString::fromUtf8("eraze_range_button"));
        eraze_range_button->setFont(font);

        verticalLayout_6->addWidget(eraze_range_button);


        verticalLayout_14->addLayout(verticalLayout_6);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(1240, 450, 271, 102));
        verticalLayout_15 = new QVBoxLayout(widget3);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(widget3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);

        verticalLayout_15->addWidget(label_22);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        find_button = new QPushButton(widget3);
        find_button->setObjectName(QString::fromUtf8("find_button"));
        find_button->setFont(font);

        horizontalLayout_10->addWidget(find_button);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_10 = new QLabel(widget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        verticalLayout_9->addWidget(label_10);

        line_key_find_2 = new QLineEdit(widget3);
        line_key_find_2->setObjectName(QString::fromUtf8("line_key_find_2"));
        line_key_find_2->setFont(font);

        verticalLayout_9->addWidget(line_key_find_2);


        horizontalLayout_10->addLayout(verticalLayout_9);


        verticalLayout_15->addLayout(horizontalLayout_10);

        widget4 = new QWidget(Widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(1670, 480, 173, 62));
        horizontalLayout_12 = new QHBoxLayout(widget4);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        find_max_button = new QPushButton(widget4);
        find_max_button->setObjectName(QString::fromUtf8("find_max_button"));
        find_max_button->setFont(font2);

        verticalLayout_17->addWidget(find_max_button);

        find_max_rec_button = new QPushButton(widget4);
        find_max_rec_button->setObjectName(QString::fromUtf8("find_max_rec_button"));
        find_max_rec_button->setFont(font2);

        verticalLayout_17->addWidget(find_max_rec_button);


        horizontalLayout_12->addLayout(verticalLayout_17);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        find_min_button = new QPushButton(widget4);
        find_min_button->setObjectName(QString::fromUtf8("find_min_button"));
        find_min_button->setFont(font2);

        verticalLayout_16->addWidget(find_min_button);

        find_min_rec_button = new QPushButton(widget4);
        find_min_rec_button->setObjectName(QString::fromUtf8("find_min_rec_button"));
        find_min_rec_button->setFont(font2);

        verticalLayout_16->addWidget(find_min_rec_button);


        horizontalLayout_12->addLayout(verticalLayout_16);

        widget5 = new QWidget(Widget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(1770, 560, 77, 92));
        verticalLayout_18 = new QVBoxLayout(widget5);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        pre_travel_button = new QPushButton(widget5);
        pre_travel_button->setObjectName(QString::fromUtf8("pre_travel_button"));
        pre_travel_button->setFont(font2);

        verticalLayout_18->addWidget(pre_travel_button);

        pos_travel_button = new QPushButton(widget5);
        pos_travel_button->setObjectName(QString::fromUtf8("pos_travel_button"));
        pos_travel_button->setFont(font2);

        verticalLayout_18->addWidget(pos_travel_button);

        in_travel_button = new QPushButton(widget5);
        in_travel_button->setObjectName(QString::fromUtf8("in_travel_button"));
        in_travel_button->setFont(font2);

        verticalLayout_18->addWidget(in_travel_button);

        widget6 = new QWidget(Widget);
        widget6->setObjectName(QString::fromUtf8("widget6"));
        widget6->setGeometry(QRect(1230, 290, 271, 102));
        verticalLayout_13 = new QVBoxLayout(widget6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(widget6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);

        verticalLayout_13->addWidget(label_18);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_19 = new QLabel(widget6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        verticalLayout_10->addWidget(label_19);

        line_key_eraze_2 = new QLineEdit(widget6);
        line_key_eraze_2->setObjectName(QString::fromUtf8("line_key_eraze_2"));
        line_key_eraze_2->setFont(font);

        verticalLayout_10->addWidget(line_key_eraze_2);


        horizontalLayout_8->addLayout(verticalLayout_10);

        eraze_button = new QPushButton(widget6);
        eraze_button->setObjectName(QString::fromUtf8("eraze_button"));
        eraze_button->setFont(font);

        horizontalLayout_8->addWidget(eraze_button);


        verticalLayout_13->addLayout(horizontalLayout_8);

        widget7 = new QWidget(Widget);
        widget7->setObjectName(QString::fromUtf8("widget7"));
        widget7->setGeometry(QRect(1110, 600, 173, 68));
        verticalLayout_21 = new QVBoxLayout(widget7);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(widget7);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);

        verticalLayout_21->addWidget(label_23);

        button_iterator = new QPushButton(widget7);
        button_iterator->setObjectName(QString::fromUtf8("button_iterator"));
        button_iterator->setFont(font);

        verticalLayout_21->addWidget(button_iterator);

        widget8 = new QWidget(Widget);
        widget8->setObjectName(QString::fromUtf8("widget8"));
        widget8->setGeometry(QRect(1310, 600, 207, 68));
        verticalLayout_22 = new QVBoxLayout(widget8);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(widget8);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font);

        verticalLayout_22->addWidget(label_25);

        rcons_button = new QPushButton(widget8);
        rcons_button->setObjectName(QString::fromUtf8("rcons_button"));
        rcons_button->setFont(font);

        verticalLayout_22->addWidget(rcons_button);

        widget9 = new QWidget(Widget);
        widget9->setObjectName(QString::fromUtf8("widget9"));
        widget9->setGeometry(QRect(1100, 720, 220, 82));
        verticalLayout_23 = new QVBoxLayout(widget9);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        verticalLayout_23->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(widget9);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);

        verticalLayout_23->addWidget(label_27);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        label_26 = new QLabel(widget9);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_20->addWidget(label_26);

        lb_key = new QLineEdit(widget9);
        lb_key->setObjectName(QString::fromUtf8("lb_key"));

        verticalLayout_20->addWidget(lb_key);


        horizontalLayout_13->addLayout(verticalLayout_20);

        findLB_button = new QPushButton(widget9);
        findLB_button->setObjectName(QString::fromUtf8("findLB_button"));

        horizontalLayout_13->addWidget(findLB_button);


        verticalLayout_23->addLayout(horizontalLayout_13);

        widget10 = new QWidget(Widget);
        widget10->setObjectName(QString::fromUtf8("widget10"));
        widget10->setGeometry(QRect(1360, 710, 272, 102));
        verticalLayout_25 = new QVBoxLayout(widget10);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget10);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_25->addWidget(label_7);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        label_28 = new QLabel(widget10);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);

        verticalLayout_24->addWidget(label_28);

        ub_key_2 = new QLineEdit(widget10);
        ub_key_2->setObjectName(QString::fromUtf8("ub_key_2"));
        ub_key_2->setFont(font);

        verticalLayout_24->addWidget(ub_key_2);


        horizontalLayout_14->addLayout(verticalLayout_24);

        FindUB_button_2 = new QPushButton(widget10);
        FindUB_button_2->setObjectName(QString::fromUtf8("FindUB_button_2"));
        FindUB_button_2->setFont(font);

        horizontalLayout_14->addWidget(FindUB_button_2);


        verticalLayout_25->addLayout(horizontalLayout_14);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "AVL_SET", nullptr));
        change_dir_button->setText(QCoreApplication::translate("Widget", "Change_Directory", nullptr));
        clear_button->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        label_24->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        FindUB_button->setText(QCoreApplication::translate("Widget", "Find_UB", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "Size", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Deep", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "Insertion", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        insert_button->setText(QCoreApplication::translate("Widget", "insert", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "Eraze Range", nullptr));
        label_21->setText(QCoreApplication::translate("Widget", "From", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "To", nullptr));
        eraze_range_button->setText(QCoreApplication::translate("Widget", "Eraze_Range", nullptr));
        label_22->setText(QCoreApplication::translate("Widget", "FINDING", nullptr));
        find_button->setText(QCoreApplication::translate("Widget", "find", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        find_max_button->setText(QCoreApplication::translate("Widget", "find_max", nullptr));
        find_max_rec_button->setText(QCoreApplication::translate("Widget", "find_max_rec", nullptr));
        find_min_button->setText(QCoreApplication::translate("Widget", "find_min", nullptr));
        find_min_rec_button->setText(QCoreApplication::translate("Widget", "find_min_rec", nullptr));
        pre_travel_button->setText(QCoreApplication::translate("Widget", "pre_travel", nullptr));
        pos_travel_button->setText(QCoreApplication::translate("Widget", "post_travel", nullptr));
        in_travel_button->setText(QCoreApplication::translate("Widget", "in_travel", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "ERAZE", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        eraze_button->setText(QCoreApplication::translate("Widget", "eraze", nullptr));
        label_23->setText(QCoreApplication::translate("Widget", "Iterator", nullptr));
        button_iterator->setText(QCoreApplication::translate("Widget", "show_consequence", nullptr));
        label_25->setText(QCoreApplication::translate("Widget", "Reverse_iterator", nullptr));
        rcons_button->setText(QCoreApplication::translate("Widget", "show_rev_consequence", nullptr));
        label_27->setText(QCoreApplication::translate("Widget", "Lower_Bound", nullptr));
        label_26->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        findLB_button->setText(QCoreApplication::translate("Widget", "Find_LB", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Upper_Bound", nullptr));
        label_28->setText(QCoreApplication::translate("Widget", "Key", nullptr));
        FindUB_button_2->setText(QCoreApplication::translate("Widget", "Find_UB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
