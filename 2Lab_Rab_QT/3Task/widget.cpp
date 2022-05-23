#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    QString str1 = Translate::rpw("a+(b-c)*d");
    QString str2 = Translate::rpw("a/(b-c)*(d+e)");
    qDebug() << str1 << " " << str2;


    ui->setupUi(this);
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);


  if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
      qDebug() << "Input Failed\n";

return; }
  else{
      QString expr;
      double a,b,c,d,e;
      QString str;
      while (!fs.atEnd()) {
          str=fs.readLine();
          str.chop(1);
       expr=str;
       str=fs.readLine();
       a=str.toDouble(nullptr);
       qDebug()<<a;
       str=fs.readLine();
       b=str.toDouble(nullptr);
       str=fs.readLine();
       c=str.toDouble(nullptr);
       str=fs.readLine();
       d=str.toDouble(nullptr);
       str=fs.readLine();
       e=str.toDouble(nullptr);
       vec.push_back(Expression(expr,a,b,c,d,e));
          }

      }
  int vsize=vec.size();
  ui->table->setRowCount(vec.size());
  ui->table->setColumnCount(8);
      ui->table->horizontalHeader()->resizeSection(6,150);
  ui->table->setHorizontalHeaderLabels(QStringList()<<"Expression"<<"a"<<"b"<<"c"<<"d"<<"e"<<"Reverse_Polish_Write"<<"Resunt_in_RPW");
  for(int i=0;i<vsize;i++){
      QTableWidgetItem* itm=new QTableWidgetItem(vec[i].expr);
      ui->table->setItem(i,0,itm);

      QTableWidgetItem* itm1=new QTableWidgetItem(QString::number(vec[i].a));
      ui->table->setItem(i,1,itm1);

      QTableWidgetItem* itm2=new QTableWidgetItem(QString::number(vec[i].b));
      ui->table->setItem(i,2,itm2);

      QTableWidgetItem* itm3=new QTableWidgetItem(QString::number(vec[i].c));
      ui->table->setItem(i,3,itm3);

      QTableWidgetItem* itm4=new QTableWidgetItem(QString::number(vec[i].d));
      ui->table->setItem(i,4,itm4);

      QTableWidgetItem* itm5=new QTableWidgetItem(QString::number(vec[i].e));
      ui->table->setItem(i,5,itm5);

      QString str_tran=Translate::rpw(vec[i].expr);
      QTableWidgetItem* itm6=new QTableWidgetItem(str_tran);
     ui->table->setItem(i,6,itm6);

     QTableWidgetItem* itm7=new QTableWidgetItem(QString::number(Calculation::compute(str_tran,vec[i].a,vec[i].b,vec[i].c,vec[i].d,vec[i].e)));
    ui->table->setItem(i,7,itm7);
  }
  }
Widget::~Widget()
{
    delete ui;
}

void Widget::on_add_new_clicked()
{
    Adding* blank=new Adding(this,1);
    connect(blank,SIGNAL(renew()),this,SLOT(add_new()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::add_new()
{
    ui->table->setRowCount(vec.size());
    int i=vec.size()-1;
    QTableWidgetItem* itm=new QTableWidgetItem(vec[i].expr);
    ui->table->setItem(i,0,itm);

    QTableWidgetItem* itm1=new QTableWidgetItem(QString::number(vec[i].a));
    ui->table->setItem(i,1,itm1);

    QTableWidgetItem* itm2=new QTableWidgetItem(QString::number(vec[i].b));
    ui->table->setItem(i,2,itm2);

    QTableWidgetItem* itm3=new QTableWidgetItem(QString::number(vec[i].c));
    ui->table->setItem(i,3,itm3);

    QTableWidgetItem* itm4=new QTableWidgetItem(QString::number(vec[i].d));
    ui->table->setItem(i,4,itm4);

    QTableWidgetItem* itm5=new QTableWidgetItem(QString::number(vec[i].e));
    ui->table->setItem(i,5,itm5);

    QString str_tran=Translate::rpw(vec[i].expr);
    QTableWidgetItem* itm6=new QTableWidgetItem(str_tran);
   ui->table->setItem(i,6,itm6);

   QTableWidgetItem* itm7=new QTableWidgetItem(QString::number(Calculation::compute(str_tran,vec[i].a,vec[i].b,vec[i].c,vec[i].d,vec[i].e)));
   ui->table->setItem(i,7,itm7);
}
void Widget::on_add_new_pwr_clicked()
{
    Adding* blank=new Adding(this,0);
    connect(blank,SIGNAL(renew_prw()),this,SLOT(add_new_prw()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}
void Widget::add_new_prw()
{
    ui->table->setRowCount(vec.size());
    int i=vec.size()-1;
    QTableWidgetItem* itm=new QTableWidgetItem(vec[i].expr);
    ui->table->setItem(i,0,itm);

    QTableWidgetItem* itm1=new QTableWidgetItem(QString::number(vec[i].a));
    ui->table->setItem(i,1,itm1);

    QTableWidgetItem* itm2=new QTableWidgetItem(QString::number(vec[i].b));
    ui->table->setItem(i,2,itm2);

    QTableWidgetItem* itm3=new QTableWidgetItem(QString::number(vec[i].c));
    ui->table->setItem(i,3,itm3);

    QTableWidgetItem* itm4=new QTableWidgetItem(QString::number(vec[i].d));
    ui->table->setItem(i,4,itm4);

    QTableWidgetItem* itm5=new QTableWidgetItem(QString::number(vec[i].e));
    ui->table->setItem(i,5,itm5);

    QString str_tran=Translate::rpw(vec[i].expr);
    QTableWidgetItem* itm6=new QTableWidgetItem(str_tran);
   ui->table->setItem(i,6,itm6);

   QTableWidgetItem* itm7=new QTableWidgetItem(QString::number(Calculation::compute(str_tran,vec[i].a,vec[i].b,vec[i].c,vec[i].d,vec[i].e)));
   ui->table->setItem(i,7,itm7);
}



