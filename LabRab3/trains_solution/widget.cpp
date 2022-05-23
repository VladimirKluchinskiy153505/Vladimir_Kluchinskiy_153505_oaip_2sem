#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>

void print_dec(my_deque<Place>&dec1)
{
    for (int i = 0; i < dec1.count_nodes(); i++) {
       qDebug()<<dec1[i].date.day<<" " << dec1[i].date.month<<" " << dec1[i].date.year<<" " << dec1[i].destination<<" " << dec1[i].time.hours<<" " << dec1[i].time.minuts << '\n';
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
         Date date;
         QString destination;
         Time time;
         int number;
         QString str;
         while(!fs.atEnd()){
             str=fs.readLine();
             date.day=number=str.left(2).toInt(nullptr,10);
                date.month=str.mid(3,2).toInt(nullptr,10);
                date.year=str.mid(6).toInt(nullptr,10);
             qDebug()<<date.day;
              qDebug()<<date.month;
               qDebug()<<date.year;

             str=fs.readLine();
             str.chop(1);
             destination=str;
             qDebug()<<destination;

             str=fs.readLine();
             time.hours=str.left(2).toInt(nullptr,10);
             time.minuts=str.mid(3,2).toInt(nullptr,10);
             qDebug()<<time.hours;
              qDebug()<<time.minuts;

             str=fs.readLine();
             number=str.toInt(nullptr,10);
qDebug()<<number;


             Place obj(date,destination,time,number);
             dec.push_back(obj);

     }
         fs.close();
         fill_list();
       //print_dec(dec);

  }
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_see_info_clicked()
{
    QListWidget* train_info=new QListWidget;
    train_info->setFont(QFont("Calibri",15));
    train_info->setFixedSize(800,600);
    for(int i=0;i<dec.count_nodes();i++){
     train_info->addItem(QString::number(dec[i].date.day)+"."+QString::number(dec[i].date.month)+"."+QString::number(dec[i].date.year));
      train_info->addItem(dec[i].destination);
      train_info->addItem(QString::number(dec[i].time.hours)+":"+QString::number(dec[i].time.minuts));
      train_info->addItem(QString::number(dec[i].number));

       train_info->show();
    }
}


void Widget::on_del_one_clicked()
{
    Deleting* blank=new Deleting(this);
    connect(blank,SIGNAL(delete_info()),this,SLOT(del_place()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::del_place()
{
dec.eraze(num_to_del);
update();
QFile fs(filename);
   if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
         QTextStream fout(&fs);

       fs.resize(0);
 for(int i=0;i<dec.count_nodes();i++){
       fout<<(dec[i].date.day)<<"." <<(dec[i].date.month)<<"."<<(dec[i].date.year)<<"\n"
          << dec[i].destination<<"\n"
          << dec[i].time.hours<<":" << dec[i].time.minuts <<"\n"
          <<dec[i].number<<"\n";

 }
 fs.close();
   }
   fill_list();
   fill_suitable_list();
}


void Widget::on_add_one_clicked()
{
    Adding* blank=new Adding(this);
    connect(blank,SIGNAL(add_info()),this,SLOT(add_place()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}
void Widget::add_place()
{
QFile fs(filename);
  if(fs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
QTextStream fout(&fs);
int lt=dec.count_nodes()-1;
fout<<"\n"<<dec[lt].date.day<<"."<<dec[lt].date.month<<"."<<dec[lt].date.year<<"\n"
      <<dec[lt].destination<<"\n"
      <<dec[lt].time.hours<<":"<<dec[lt].time.minuts<<"\n"
      <<dec[lt].number<<"\n";
  }
  fill_list();
  fill_suitable_list();
  update();
}
void Widget::on_edit_one_clicked()
{    Editing* blank=new Editing(this);
     blank->setWindowModality(Qt::ApplicationModal);
     blank->show();

}
void Widget::edit_place()
{
    update();
    QFile fs(filename);
       if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
             QTextStream fout(&fs);

           fs.resize(0);
     for(int i=0;i<dec.count_nodes();i++){
           fout<<(dec[i].date.day)<<"." <<(dec[i].date.month)<<"."<<(dec[i].date.year)<<"\n"
              << dec[i].destination<<"\n"
              << dec[i].time.hours<<":" << dec[i].time.minuts <<"\n"
              <<dec[i].number<<"\n";

     }
     fs.close();
       }
       fill_list();
       fill_suitable_list();
}

void Widget::fill_list()
{
    ui->dest_list->clear();
    for(int i=0;i<dec.count_nodes();i++){
    ui->dest_list->addItem(QString::number(dec[i].date.day)+"."+QString::number(dec[i].date.month)+"."+QString::number(dec[i].date.year)+" "+dec[i].destination+" "+QString::number(dec[i].number));
    }
}

void Widget::fill_suitable_list()
{
    ui->suitable_list->clear();
    for(int i=0;i<dec.count_nodes();i++){
        if(((  (dec[i].date.day-departure.day)+(dec[i].date.month-departure.month)*30+(dec[i].date.year-departure.year)*365 )<=0)&&(dec[i].destination==dec[ind].destination))
    ui->suitable_list->addItem(QString::number(dec[i].number)+" "+dec[i].destination);
    }
    if(!(ui->suitable_list->QListWidget::count())){
        QMessageBox::information(this,"404","no trains");
    }
}



void Widget::on_enter_date_clicked()
{
    departure.day=(ui->line_day->text()).toInt(nullptr,10);
    departure.month=(ui->line_month->text()).toInt(nullptr,10);
    departure.year=(ui->line_year->text()).toInt(nullptr,10);
    fill_suitable_list();
}


void Widget::on_dest_list_itemClicked(QListWidgetItem *item)
{
     ind=ui->dest_list->currentIndex().row();
      fill_suitable_list();
     qDebug()<<ind;
}

void Widget::on_open_directory_clicked()
{
    dec.Delete();
      filename=QFileDialog::getOpenFileName(this,"Open Man File",QDir::currentPath(),"*.txt");
      QFile fs(filename);
      if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
          qDebug() << "Input Failed\n";
        QMessageBox::warning(this,"Error","Not Found");
       }
      else{
          Date date;
          QString destination;
          Time time;
          int number;
          QString str;
          while(!fs.atEnd()){
              str=fs.readLine();
              date.day=number=str.left(2).toInt(nullptr,10);
                 date.month=str.mid(3,2).toInt(nullptr,10);
                 date.year=str.mid(6).toInt(nullptr,10);
              qDebug()<<date.day;
               qDebug()<<date.month;
                qDebug()<<date.year;

              str=fs.readLine();
              str.chop(1);
              destination=str;
              qDebug()<<destination;

              str=fs.readLine();
              time.hours=str.left(2).toInt(nullptr,10);
              time.minuts=str.mid(3,2).toInt(nullptr,10);
              qDebug()<<time.hours;
               qDebug()<<time.minuts;

              str=fs.readLine();
              number=str.toInt(nullptr,10);
 qDebug()<<number;
              Place obj(date,destination,time,number);
              dec.push_back(obj);

      }
          fs.close();
          fill_list();
   }
}
void Widget::on_qsort1_clicked()
{
    dec.qsort1();
    fill_list();
    ui->suitable_list->clear();
}


void Widget::on_qsort2_clicked()
{
    dec.qsort2();
    fill_list();
    ui->suitable_list->clear();
}

