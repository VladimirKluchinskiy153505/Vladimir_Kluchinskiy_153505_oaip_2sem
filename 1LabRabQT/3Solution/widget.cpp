#include "widget.h"
#include "ui_widget.h"
#include "deleting.h"
#include <ctime>
#include <QDebug>
#include <QFileDialog>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init_current_day();
       res_size = 2;
       date_size = 0;
        arr = new Date[res_size];
         filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
      QFile fs(filename);


       if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
           qDebug() << "Input Failed\n";
          // qWarning("Cannot open file");
       }
       QString str;
       while (!fs.atEnd()) {
           str=fs.readLine();
           Date obj( (str.left(2).toInt(nullptr,10) ), (str.mid(3, 2).toInt(nullptr,10)), (str.mid(6, 4).toInt(nullptr,10)) );
           push_back(obj, arr, res_size, date_size);
           qDebug()<<date_size<<'\n';
           if(date_size>1){
           arr[date_size-1].ptr_to_prev=&arr[date_size-2];
           arr[date_size-1].difference_with_prev=(arr[date_size-1].day + (arr[date_size-1].month-1)*30 + (arr[date_size-1].year-1)*365)- (arr[date_size-2].day+(arr[date_size-2].month-1)*30+(arr[date_size-2].year-1)*365);
           }

           qDebug() << str << "1\n";
       }
       for (int i = 0; i < date_size; i++) {
           qDebug() << arr[i].day << " " << arr[i].month << " " << arr[i].year << "   " << arr[i].week_number() << '\n';
       }
       qDebug() << Date::current_date.day<<" "<<Date::current_date.month<<" "<<Date::current_date.year << '\n';
          ui->table->setRowCount(date_size);
          ui->table->setColumnCount(11);
          ui->table->horizontalHeader()->resizeSection(1,150);
             ui->table->horizontalHeader()->resizeSection(6,150);
            ui->table->setHorizontalHeaderLabels(QStringList()<<"Date"<<"Diff_with_previous"<<"Next_Day"<<"PreviousDay"<<"IsLeap"<<"Week_Number"<<"DaysTillYourBirthday"<<"Duration"<<"Your_Birthday"<<"Current_Day"<<"WeekDay");
            for(int i=0;i<date_size;i++){
                QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].day)+"."+QString::number(arr[i].month)+"."+QString::number(arr[i].year));
                ui->table->setItem(i,0,itm);
            }
            QTableWidgetItem* birth=new QTableWidgetItem(QString::number(Date::birth_date.day)+"."+QString::number(Date::birth_date.month)+"."+QString::number(Date::birth_date.year));
            QTableWidgetItem* curr=new QTableWidgetItem(QString::number(Date::current_date.day)+"."+QString::number(Date::current_date.month)+"."+QString::number(Date::current_date.year));
            ui->table->setItem(0,8,birth);
            ui->table->setItem(0,9,curr);
          // connect(blank,SIGNAL(Birthday::save_birth_date),this,SLOT(quit()));
            blank=new Birthday;
            blank->setWindowModality(Qt::ApplicationModal);
              connect(blank,SIGNAL(save_birth_date()),this,SLOT(save_new_birthday()));
               fs.close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::push_back(Date& obj, Date *&arr, int &res_size, int &date_size)
{
    if (date_size >= res_size) {
         res_size *= 2;
         Date* newarr = new Date[res_size];
         for (int i = 0; i < date_size; i++) {
             newarr[i] = arr[i];
         }
         delete arr;
         arr = newarr;
     }
     arr[date_size] = obj;
     date_size++;
}

void Widget::init_current_day()
{
    int d, m, y;
    time_t now = time(NULL);

    tm* ltm = localtime(&now);

    y = 1900 + ltm->tm_year;
    m = ltm->tm_mon+1;
    d = ltm->tm_mday;
    Date::current_date = Date(d, m, y);
  //  qDebug()<<d<<" "<<m<<" "<<y;
}


void Widget::on_enter_birthday_clicked()
{
      blank->show();
}

void Widget::save_new_birthday()
{
    QTableWidgetItem* birth=new QTableWidgetItem(QString::number(Date::birth_date.day)+"."+QString::number(Date::birth_date.month)+"."+QString::number(Date::birth_date.year));
    ui->table->setItem(0,8,birth);
}

void Widget::on_diff_with_prev_clicked()
{
    for(int i=1;i<date_size;i++){
        QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].difference_with_prev));
        ui->table->setItem(i,1,itm);
    }
}
void Widget::on_show_nextday_clicked()
{
    for(int i=0;i<date_size;i++){
        QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].next_day().day)+"."+QString::number(arr[i].next_day().month)+"."+QString::number(arr[i].next_day().year));
        ui->table->setItem(i,2,itm);
    }
}


void Widget::on_show_prev_day_clicked()
{
    for(int i=0;i<date_size;i++){
        QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].prev_day().day)+"."+QString::number(arr[i].prev_day().month)+"."+QString::number(arr[i].prev_day().year));
        ui->table->setItem(i,3,itm);
    }
}


void Widget::on_is_leap_clicked()
{
    for(int i=0;i<date_size;i++){
        QTableWidgetItem* itm;
        if(arr[i].is_leep()){
                itm =new QTableWidgetItem("yes");
        }
      else{
             itm =new QTableWidgetItem("no");
        }
        ui->table->setItem(i,4,itm);
    }
}


void Widget::on_week_number_clicked()
{
    for(int i=0;i<date_size;i++){
        QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].week_number()));
        ui->table->setItem(i,5,itm);
    }
}


void Widget::on_days_till_birth_clicked()
{
    QTableWidgetItem* itm =new QTableWidgetItem(QString::number(Date::days_till_yout_birthday(Date::current_date)));
    ui->table->setItem(0,6,itm);

}

void Widget::on_duration_clicked()
{
    for(int i=0;i<date_size;i++){
        QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].Duration(Date::current_date)));
        ui->table->setItem(i,7,itm);
    }
}
void Widget::on_week_day_clicked()
{
    for(int i=0;i<date_size;i++){
        QString day;
        if(arr[i].week_day()==1){
            day="Monday";
        }
        else if(arr[i].week_day()==2){
            day="Tuesday";
        }

        else if(arr[i].week_day()==3){
            day="Wednesday";
        }

        else if(arr[i].week_day()==4){
            day="Thurthday";
        }

        else if(arr[i].week_day()==5){
            day="Friday";
        }

        else if(arr[i].week_day()==6){
            day="Saturday";
        }

        else {
            day="Sunday";
        }
        QTableWidgetItem* itm =new QTableWidgetItem(day);
        ui->table->setItem(i,10,itm);
    }
}

void Widget::on_add_newone_clicked()
{
    blank1=new Adding(this);
    connect(blank1,SIGNAL(renew_info()),this,SLOT(add_new_date()));
    blank1->setWindowModality(Qt::ApplicationModal);
blank1->show();
}

void Widget::add_new_date()
{
    int day=addinformation.left(2).toInt(nullptr,10);
      int month=addinformation.mid(3,2).toInt(nullptr,10);
      int year=addinformation.mid(6,4).toInt(nullptr,10);
      Date obj=Date(day,month,year);
      push_back(obj,arr,res_size,date_size);
  qDebug()<<day<<' '<<month<<' '<<year;


   QFile fs(filename);
  if(fs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
      QTextStream fout(&fs);
      int Seek=0;
      for(int i=0;i<date_size-1;i++){
          Seek+=12;
      }
      Seek-=2;
      fout.seek(Seek);
  fout<<'\n'<<(QString::number(arr[date_size-1].day)+"."+QString::number(arr[date_size-1].month)+"."+QString::number(arr[date_size-1].year));
  QTableWidgetItem* itm1 =new QTableWidgetItem(QString::number(arr[date_size-1].day)+"."+QString::number(arr[date_size-1].month)+"."+QString::number(arr[date_size-1].year));
  ui->table->setRowCount(date_size);
  ui->table->setItem(date_size-1,0,itm1);
  }
  else{
      qWarning("Could not open file");
  }
  fs.close();
}


void Widget::on_edit_one_clicked()
{
    blank2=new Editing(this);
    connect(blank2,SIGNAL(update_info()),this,SLOT(edit_existing_date()));
    blank2->setWindowModality(Qt::ApplicationModal);
blank2->show();
}
void Widget::edit_existing_date()
{
    int day=editinformation.left(2).toInt(nullptr,10);
      int month=editinformation.mid(3,2).toInt(nullptr,10);
      int year=editinformation.mid(6,4).toInt(nullptr,10);
      Date obj=Date(day,month,year);
      arr[num_to_edit0]=Date(day,month,year);
  qDebug()<<day<<' '<<month<<' '<<year;


   QFile fs(filename);
  QTextStream fout(&fs);
  if(fs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
      QTextStream fout(&fs);
      int Seek=0;
      for(int i=0;i<num_to_edit0;i++){
          Seek+=12;
      }
      qDebug()<<num_to_edit0;
      if(num_to_edit0){
      Seek-=2;
            fout.seek(Seek);
              fout<<'\n'<<(QString::number(arr[num_to_edit0].day)+"."+QString::number(arr[num_to_edit0].month)+"."+QString::number(arr[num_to_edit0].year))<<"     ";
      }
      else{
              fout.seek(0);
               fout<<(QString::number(arr[num_to_edit0].day)+"."+QString::number(arr[num_to_edit0].month)+"."+QString::number(arr[num_to_edit0].year))<<"     ";
      }

  QTableWidgetItem* itm1 =new QTableWidgetItem(QString::number(arr[num_to_edit0].day)+"."+QString::number(arr[num_to_edit0].month)+"."+QString::number(arr[num_to_edit0].year));
  ui->table->setItem(num_to_edit0,0,itm1);
  }
  else{
      qWarning("Could not open file");
  }
  fs.close();
}


void Widget::on_delete_one_clicked()
{
    blank3=new Deleting(this);
    connect(blank3,SIGNAL(del_info()),this,SLOT(delete_existing_date()));
    blank3->setWindowModality(Qt::ApplicationModal);
    blank3->show();
}

void Widget::delete_existing_date()
{
    if(!date_size){
         QMessageBox::warning(this,"Not found","try again\n");
         return;
    }
    QFile fs(filename);
   if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
       QString s;
       QTextStream fout(&fs);
       int k=0;
         while(!fs.atEnd())
          {
              QString line = fs.readLine();
              qDebug()<<line;
              if(k!=num_to_delete0){
                  s.append(line);
              }
              k++;
          }
          fs.resize(0);
          fout.seek(0);
          qDebug()<<s;
          fout << s;
          fs.close();

        Date* newarr = new Date[res_size];

                 for (int i = 0; i < num_to_delete0; i++) {
                     newarr[i] = arr[i];
                 }
                 for (int i = num_to_delete0 + 1; i<date_size; i++) {
                     newarr[i - 1] = arr[i];
                 }
                 delete[]arr;
                 arr = newarr;
                 date_size -= 1;


                   ui->table->setRowCount(date_size);
                   for(int i=0;i<date_size;i++){
                       QTableWidgetItem* itm =new QTableWidgetItem(QString::number(arr[i].day)+"."+QString::number(arr[i].month)+"."+QString::number(arr[i].year));
                       ui->table->setItem(i,0,itm);
                   }
        }

   else{
        qWarning("Could not open file");
   }


   fs.close();
}
