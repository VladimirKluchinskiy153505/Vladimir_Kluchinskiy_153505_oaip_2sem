#include "editingdialog.h"
#include "ui_editingdialog.h"

EditingDialog::EditingDialog(int gender,Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingDialog)
{
    ui->setupUi(this);
    this->gender=gender;
    this->ptr=ptr;
}

EditingDialog::~EditingDialog()
{
    delete ui;
}

void EditingDialog::on_save_clicked()
{
    if(gender){
    connect(this,SIGNAL(update_info()),ptr,SLOT(edit_man()));}
    else{
          connect(this,SIGNAL(update_info()),ptr,SLOT(edit_woman()));
    }
    number=ui->line_num->text().toInt(nullptr,10);
    name=ui->line_name->text();
    age=(ui->line_age->text()).toInt(nullptr,10);
    height=(ui->line_height->text()).toInt(nullptr,10);
    weight=(ui->line_weight->text()).toInt(nullptr,10);
   custom=ui->line_custom->text();
   hobby=ui->line_hobby->text();

    claim.MinAge=(ui->line_min_age->text()).toInt(nullptr,10);
     claim.MaxAge=(ui->line_max_age->text()).toInt(nullptr,10);

      claim.MinHeight=(ui->line_min_height->text()).toInt(nullptr,10);
       claim.MaxHeight=(ui->line_max_height->text()).toInt(nullptr,10);

        claim.MinWeight=(ui->line_min_weight->text()).toInt(nullptr,10);
         claim.MaxWeight=(ui->line_max_weight->text()).toInt(nullptr,10);
         if(gender){
         Man obj=Man(number,name,age,height,weight,custom,hobby,claim);
        ptr->arrMan[ptr->num_man_to_edit] = obj;

         }else{
             Woman obj=Woman(number,name,age,height,weight,custom,hobby,claim);
             ptr->arrWoman[ptr->num_woman_to_edit]=obj;
         }

         emit update_info();
         close();
}

