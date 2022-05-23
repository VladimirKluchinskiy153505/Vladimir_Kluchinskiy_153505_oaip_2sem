#include "editingdialog.h"
#include "ui_editingdialog.h"

EditingDialog::EditingDialog(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingDialog)
{
    ui->setupUi(this);
    this->ptr=ptr;
}

EditingDialog::~EditingDialog()
{
    delete ui;
}

void EditingDialog::on_pushButton_clicked()
{
       connect(this,SIGNAL(edit_info()),ptr,SLOT(edit_place()));
    int k=ptr->num_to_edit;
    date.day=(ui->line_day->text()).toInt(nullptr,10);
    date.month=(ui->line_month->text()).toInt(nullptr,10);
    date.year=(ui->line_year->text()).toInt(nullptr,10);
    dest=(ui->line_dest->text());
    time.hours=(ui->line_hours->text()).toInt(nullptr,10);
    time.minuts=(ui->line_minuts->text()).toInt(nullptr,10);
    number=(ui->line_number->text()).toInt(nullptr,10);

ptr->dec[k]=Place(date,dest,time,number);
    emit edit_info();
    close();
}

