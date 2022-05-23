#include "widget.h"
#include "ui_widget.h"
void Widget::fill_list()
{
ui->list_work->clear();
for(int i=0;i<dec.count_nodes();i++){
    ui->list_work->addItem(dec[i].snp);
}
}
void Widget::fill_res_list()
{
    ui->res_list->clear();
    ui->res_list->addItem(dec[index].snp+"\n"+"Number: "+QString::number(dec[index].number)+"\n"+"Hours: "+QString::number(dec[index].hours)+"\n"+"Rate: "+QString::number(dec[index].rate)+"\n"+"Cash: "+QString::number(dec[index].cash));
}
void Widget::fill_salary_list()
{
    ui->salary_list->clear();
    for(int i=0;i<dec.count_nodes();i++){
        if(dec[i].cash>=salary){
    ui->salary_list->addItem(dec[i].snp+"\n"+"Number: "+QString::number(dec[i].number)+"\n"+"Hours: "+QString::number(dec[i].hours)+"\n"+"Rate: "+QString::number(dec[i].rate)+"\n"+"Cash: "+QString::number(dec[i].cash));
    }
    }
}
void Widget::fill_hours_list()
{
    ui->hours_list->clear();
    for(int i=0;i<dec.count_nodes();i++){
        if(dec[i].hours>=hours){
    ui->hours_list->addItem(dec[i].snp+"\n"+"Number: "+QString::number(dec[i].number)+"\n"+"Hours: "+QString::number(dec[i].hours)+"\n"+"Rate: "+QString::number(dec[i].rate)+"\n"+"Cash: "+QString::number(dec[i].cash));
    }
    }
}

void Widget::fill_over_list()
{
    ui->over_list->clear();
    for(int i=0;i<dec.count_nodes();i++){
        if(dec[i].hours>144){
    ui->over_list->addItem(dec[i].snp+"\n"+"Number: "+QString::number(dec[i].number)+"\n"+"Hours: "+QString::number(dec[i].hours)+"\n"+"Rate: "+QString::number(dec[i].rate)+"\n"+"Cash: "+QString::number(dec[i].cash));
    }
    }
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
      filename=QFileDialog::getOpenFileName(this,"Open Man File",QDir::currentPath(),"*.txt");
      QFile fs(filename);
      if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
          qDebug() << "Input Failed\n";
        QMessageBox::warning(this,"Error","Not Found");
       }
      else{
          QString snp;
          int number;
          double hours;
          double rate;
          QString str;
          while(!fs.atEnd()){
              str=fs.readLine();
              str.chop(1);
              snp=str;

         str=fs.readLine();
         number=str.toInt(nullptr,10);

         str=fs.readLine();
         hours=str.toDouble(nullptr);

         str=fs.readLine();
         rate=str.toDouble(nullptr);

      worker obj= worker(snp,number,hours,rate);
              dec.push_back(obj);
              ui->list_work->addItem(dec.get_tail().snp);
      }
}
      fs.close();
      fill_over_list();
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_list_work_itemClicked(QListWidgetItem *item)
{
    index=ui->list_work->currentIndex().row();
    fill_res_list();
    qDebug()<<index;
}
void Widget::on_enter_criteria_clicked()
{
    Info* blank=new Info(this);
    connect(blank,SIGNAL(renew()),this,SLOT(fill_salary_list()));
    connect(blank,SIGNAL(renew()),this,SLOT(fill_hours_list()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::on_pushButton_clicked()
{
    int num=ui->line_del->text().toInt(nullptr,10);
    if((num>0)&&(num<=dec.count_nodes())){
        dec.eraze(num-1);
        qDebug()<<dec.count_nodes()<<"\n";
        if(dec.count_nodes()){
        fill_list();
        fill_hours_list();
        fill_over_list();
        fill_res_list();
        fill_salary_list();
        }
    }
}


void Widget::on_add_one_clicked()
{
    QString snp;
    int number;
    double hours;
    double rate;
    snp=ui->line_name->text();
    number=ui->line_number->text().toInt(nullptr,10);
    hours=ui->line_hours->text().toDouble(nullptr);
    rate=ui->line_rate->text().toDouble(nullptr);
    worker obj= worker(snp,number,hours,rate);
            dec.push_back(obj);
            ui->list_work->addItem(dec.get_tail().snp);
            int lt=dec.count_nodes()-1;
            if(dec.get_tail().cash>=salary){
                  ui->salary_list->addItem(dec[lt].snp+"\n"+"Number: "+QString::number(dec[lt].number)+"\n"+"Hours: "+QString::number(dec[lt].hours)+"\n"+"Rate: "+QString::number(dec[lt].rate)+"\n"+"Cash: "+QString::number(dec[lt].cash));
            }
            if(dec[lt].hours>=hours){
        ui->hours_list->addItem(dec[lt].snp+"\n"+"Number: "+QString::number(dec[lt].number)+"\n"+"Hours: "+QString::number(dec[lt].hours)+"\n"+"Rate: "+QString::number(dec[lt].rate)+"\n"+"Cash: "+QString::number(dec[lt].cash));
        }
            if(dec[lt].hours>144){
        ui->over_list->addItem(dec[lt].snp+"\n"+"Number: "+QString::number(dec[lt].number)+"\n"+"Hours: "+QString::number(dec[lt].hours)+"\n"+"Rate: "+QString::number(dec[lt].rate)+"\n"+"Cash: "+QString::number(dec[lt].cash));
        }

}


