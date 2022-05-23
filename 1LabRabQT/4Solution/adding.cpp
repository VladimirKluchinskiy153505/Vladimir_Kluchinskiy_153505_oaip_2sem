#include "adding.h"
#include "ui_adding.h"

Adding::Adding(int gender,Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adding)
{
    ui->setupUi(this);
    this->ptr=ptr;
    this->gender=gender;
}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_save_clicked()
{
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
          number=ptr->man_size+1;
          Man obj=Man(number,name,age,height,weight,custom,hobby,claim);
          ptr->push_back(obj,ptr->arrMan,ptr->man_size_reserved, ptr->man_size);
          }else{
              number=ptr->woman_size+1;
              Woman obj=Woman(number,name,age,height,weight,custom,hobby,claim);
              ptr->push_back(obj,ptr->arrWoman,ptr->woman_size_reserved, ptr->woman_size);
          }

          emit renew_info();
          close();
}

