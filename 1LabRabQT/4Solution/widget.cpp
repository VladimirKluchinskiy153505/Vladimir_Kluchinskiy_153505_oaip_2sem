#include "widget.h"
#include "ui_widget.h"
void Widget::push_back(Man obj, Man*& arrMan, int &man_size_reserved, int &man_size)
{
    if (man_size >= man_size_reserved) {
         man_size_reserved *= 2;
         Man* newarr = new Man[man_size_reserved];
         for (int i = 0; i < man_size; i++) {
             newarr[i] = arrMan[i];
         }
         delete[] arrMan;
         arrMan = newarr;
     }
     arrMan[man_size] = obj;
     man_size++;
}
void Widget::push_back(Woman obj, Woman *&arr, int &woman_size_reserved, int &woman_size)
{
    if (woman_size >= woman_size_reserved) {
         woman_size_reserved *= 2;
         Woman* newarr = new Woman[woman_size_reserved];
         for (int i = 0; i < woman_size; i++) {
             newarr[i] = arr[i];
         }
         delete[] arr;
         arr = newarr;
     }
     arr[woman_size] = obj;
     woman_size++;
}

bool Widget::satisfy(const Man &man, const Woman &woman)//man likes woman if
{
    if( (man.claim.MinAge<=woman.age)&&(woman.age<=man.claim.MaxAge)&&(man.claim.MinHeight<=woman.height)&&(woman.height<=man.claim.MaxHeight)&&(man.claim.MinWeight<=woman.weight)&&(woman.weight<=man.claim.MaxWeight)){
        return true;
    }
    else{
        return false;
    }
}
bool Widget::satisfy(const Woman &woman, const Man& man)//woman likes man if
{
    if( (woman.claim.MinAge<=man.age)&&(man.age<=woman.claim.MaxAge)&&(woman.claim.MinHeight<=man.height)&&(man.height<=woman.claim.MaxHeight)&&(woman.claim.MinWeight<=man.weight)&&(man.weight<=woman.claim.MaxWeight)){
        return true;
    }
    else{
        return false;
    }
}
void Widget::print()
{
    for(int i=0;i<man_size;i++){
        qDebug()<<arrMan[i].number<<"\n"
               <<arrMan[i].name<<"\n"
              <<arrMan[i].age<<"\n"
                 <<arrMan[i].height<<"\n"
             <<arrMan[i].weight<<"\n"
            <<arrMan[i].custom<<"\n"
           <<arrMan[i].hobby<<"\n"
          <<arrMan[i].claim.MinAge<<'-'<<arrMan[i].claim.MaxAge<<"\n"
         <<arrMan[i].claim.MinHeight<<'-'<<arrMan[i].claim.MaxHeight<<"\n"
        <<arrMan[i].claim.MinWeight<<'-'<<arrMan[i].claim.MaxWeight<<"\n";
    }
    for(int i=0;i<woman_size;i++){
        qDebug()<<arrWoman[i].number<<'\n'
               <<arrWoman[i].name<<'\n'
              <<arrWoman[i].age<<'\n'
                 <<arrWoman[i].height<<'\n'
             <<arrWoman[i].weight<<'\n'
            <<arrWoman[i].custom<<'\n'
           <<arrWoman[i].hobby<<'\n'
          <<arrWoman[i].claim.MinAge<<'-'<<arrWoman[i].claim.MaxAge<<'\n'
         <<arrWoman[i].claim.MinHeight<<'-'<<arrWoman[i].claim.MaxHeight<<'\n'
        <<arrWoman[i].claim.MinWeight<<'-'<<arrWoman[i].claim.MaxWeight<<'\n';
    }
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    man_size=0;
    man_size_reserved=2;
    woman_size=0;
    woman_size_reserved=2;
    arrMan=new Man[man_size_reserved];
    arrWoman=new Woman[woman_size_reserved];
    ui->setupUi(this);
    man_filename=QFileDialog::getOpenFileName(this,"Open Man File",QDir::currentPath(),"*.txt");
    QFile fs(man_filename);
    if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
      QMessageBox::warning(this,"Error","Not Found");
    }
    else{
        QString str;
        int num_pos;

        int number;
        QString name;
        int age;
        int height;
        int weight;
        QString custom;
        QString hobby;
        Demands claim;
        while(!fs.atEnd()){
            str=fs.readLine();
            number=str.toInt(nullptr,10);
            qDebug()<<number;

            str=fs.readLine();
            str.chop(1);
            name=str;

            str=fs.readLine();
            age=str.toInt();

            str=fs.readLine();
            height=str.toInt();

            str=fs.readLine();
            weight=str.toInt();

            str=fs.readLine();
            str.chop(1);
            custom=str;

            str=fs.readLine();
            str.chop(1);
            hobby=str;

                str=fs.readLine();
            num_pos=str.indexOf('-');
            claim.MinAge=str.left(num_pos).toInt();
            claim.MaxAge=str.mid(num_pos+1).toInt();

                str=fs.readLine();
            num_pos=str.indexOf('-');
            claim.MinHeight=str.left(num_pos).toInt();
            claim.MaxHeight=str.mid(num_pos+1).toInt();

                str=fs.readLine();
            num_pos=str.indexOf('-');
            claim.MinWeight=str.left(num_pos).toInt();
            claim.MaxWeight=str.mid(num_pos+1).toInt();

            Man obj(number,name,age,height,weight,custom,hobby,claim);
            push_back(obj,arrMan,man_size_reserved,man_size);
        }
           fs.close();
    }
      woman_filename=QFileDialog::getOpenFileName(this,"Open Woman File",QDir::currentPath(),"*.txt");
      QFile fs1(woman_filename);
        if (!fs1.open(QIODevice::ReadOnly|QIODevice::Text)) {
            qDebug() << "Input Failed\n";
          QMessageBox::warning(this,"Error","Not Found");
        }
        else{
            QString str;
            int num_pos;

            int number;
            QString name;
            int age;
            int height;
            int weight;
            QString custom;
            QString hobby;
            Demands claim;
            while(!fs1.atEnd()){
                str=fs1.readLine();
                number=str.toInt(nullptr,10);

                str=fs1.readLine();
                str.chop(1);
                name=str;

                str=fs1.readLine();
                age=str.toInt();

                str=fs1.readLine();
                height=str.toInt();

                str=fs1.readLine();
                weight=str.toInt();

                str=fs1.readLine();
                str.chop(1);
                custom=str;

                str=fs1.readLine();
                str.chop(1);
                hobby=str;

                 str=fs1.readLine();
                num_pos=str.indexOf('-');
                claim.MinAge=str.left(num_pos).toInt();
                claim.MaxAge=str.mid(num_pos+1).toInt();

                 str=fs1.readLine();
                num_pos=str.indexOf('-');
                claim.MinHeight=str.left(num_pos).toInt();
                claim.MaxHeight=str.mid(num_pos+1).toInt();

                 str=fs1.readLine();
                num_pos=str.indexOf('-');
                claim.MinWeight=str.left(num_pos).toInt();
                claim.MaxWeight=str.mid(num_pos+1).toInt();

                Woman obj(number,name,age,height,weight,custom,hobby,claim);
                push_back(obj,arrWoman,woman_size_reserved,woman_size);
            }
            fs1.close();
    }
        print();
        for(int m=0;m<man_size;m++){
            for(int w=0;w<woman_size;w++){
                bool mw=satisfy(arrMan[m],arrWoman[w]);
                 bool wm=satisfy(arrWoman[w],arrMan[m]);
                if(mw){
                    arrMan[m].vec_dream_man.push_back(w);
                }
                if(wm){
                    arrWoman[w].vec_dream_woman.push_back(m);
                }
                if(wm&&mw){
                    couple.push_back(Pair(m,w));
                }

            }
        }
        for(int i=0;i<man_size;i++){
        ui->manBox->addItem(QString::number(arrMan[i].number)+" "+arrMan[i].name);
        }
        for(int i=0;i<woman_size;i++){
        ui->womanBox->addItem(QString::number(arrWoman[i].number)+" "+arrWoman[i].name);
        }
       /* ui->listManDream->addItem("Hello");
        for(int i=0;i<9;i++){
            ui->listManDream->addItem(QString::number(i));
        }*/
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_manBox_activated(int index)
{
    QListWidget* man_list=ui->listManDream;
        QVector<int> vec=arrMan[index].vec_dream_man;
    int size=vec.size();
    man_list->clear();
    for(int i=0;i<size;i++){
 man_list->addItem(QString::number(arrWoman[vec[i]].number)+" "+arrWoman[vec[i]].name);
    }
}


void Widget::on_womanBox_activated(int index)
{
    QListWidget* woman_list=ui->listWomanDream;
        QVector<int> vec=arrWoman[index].vec_dream_woman;
    int size=vec.size();
    woman_list->clear();
    for(int i=0;i<size;i++){
 woman_list->addItem(QString::number(arrMan[vec[i]].number)+" "+arrMan[vec[i]].name);
    }
}


void Widget::on_show_coupes_clicked()
{
    /*list_widget_couples->clear();
    for(int i=0;i<couple.size();i++){
        int m=couple[i].man_num;
        int w=couple[i].woman_num;
        list_widget_couples->addItem(QString::number(arrMan[m].number)+"."+arrMan[m].name+" and  "+QString::number(arrWoman[w].number)+"."+arrWoman[w].name);
    }*/
    MakePairs* window_couples=new MakePairs(this);
   window_couples->setWindowModality(Qt::ApplicationModal);
    window_couples->show();
}


void Widget::on_man_info_clicked()
{
    QListWidget* man_info=new QListWidget;
    man_info->setFixedSize(800,600);
    for(int i=0;i<man_size;i++){
     man_info->addItem(QString::number(arrMan[i].number));
      man_info->addItem(arrMan[i].name);
       man_info->addItem(QString::number(arrMan[i].age));
       man_info->addItem(QString::number(arrMan[i].height));
       man_info->addItem(QString::number(arrMan[i].weight));
       man_info->addItem(arrMan[i].custom);
       man_info->addItem(arrMan[i].hobby+"\n");
       man_info->show();
    }
}


void Widget::on_women_info_clicked()
{
    QListWidget* woman_info=new QListWidget;
      woman_info->setFixedSize(800,600);
    for(int i=0;i<woman_size;i++){
     woman_info->addItem(QString::number(arrWoman[i].number));
      woman_info->addItem(arrWoman[i].name);
       woman_info->addItem(QString::number(arrWoman[i].age));
       woman_info->addItem(QString::number(arrWoman[i].height));
       woman_info->addItem(QString::number(arrWoman[i].weight));
       woman_info->addItem(arrWoman[i].custom);
       woman_info->addItem(arrWoman[i].hobby+"\n");
       woman_info->show();
    }
}


void Widget::on_add_man_clicked()
{
Adding* blank=new Adding(1,this);
connect(blank,SIGNAL(renew_info()),this,SLOT(add_new_man()));
blank->setWindowModality(Qt::ApplicationModal);
blank->show();
}

void Widget::add_new_man()
{
QFile fs(man_filename);
  if(fs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){

QTextStream fout(&fs);
int lt=man_size-1;
fout<<"\n"<<QString::number(arrMan[lt].number)<<"\n"<<arrMan[lt].name<<"\n"<<QString::number(arrMan[lt].age)<<"\n"
   <<QString::number(arrMan[lt].height)<<"\n"<<QString::number(arrMan[lt].weight)<<"\n"<<arrMan[lt].custom<<"\n"<<arrMan[lt].hobby<<"\n"
  <<QString::number(arrMan[lt].claim.MinAge)+"-"+QString::number(arrMan[lt].claim.MaxAge)<<"\n"
  << QString::number(arrMan[lt].claim.MinHeight)+"-"+QString::number(arrMan[lt].claim.MaxHeight)<<"\n"
   <<  QString::number(arrMan[lt].claim.MinWeight)+"-"+QString::number(arrMan[lt].claim.MaxWeight);


ui->manBox->addItem(QString::number(arrMan[lt].number)+" "+arrMan[lt].name);




    for(int w=0;w<woman_size;w++){
        bool mw=satisfy(arrMan[lt],arrWoman[w]);
         bool wm=satisfy(arrWoman[w],arrMan[lt]);
        if(mw){
            arrMan[lt].vec_dream_man.push_back(w);
        }
        if(wm){
            arrWoman[w].vec_dream_woman.push_back(lt);
        }
        if(wm&&mw){
            couple.push_back(Pair(lt,w));
        }

    }

  }
  else{
      QMessageBox::warning(this,"Error","Not found");
  }
}


void Widget::on_add_woman_clicked()
{
    Adding* blank=new Adding(0,this);
    connect(blank,SIGNAL(renew_info()),this,SLOT(add_new_woman()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}


void Widget::add_new_woman()
{
    QFile fs(woman_filename);
      if(fs.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){

    QTextStream fout(&fs);
    int lt=woman_size-1;
    fout<<"\n"<<QString::number(arrWoman[lt].number)<<"\n"<<arrWoman[lt].name<<"\n"<<QString::number(arrWoman[lt].age)<<"\n"
       <<QString::number(arrWoman[lt].height)<<"\n"<<QString::number(arrWoman[lt].weight)<<"\n"<<arrWoman[lt].custom<<"\n"<<arrWoman[lt].hobby<<"\n"
      <<QString::number(arrWoman[lt].claim.MinAge)+"-"+QString::number(arrWoman[lt].claim.MaxAge)<<"\n"
      << QString::number(arrWoman[lt].claim.MinHeight)+"-"+QString::number(arrWoman[lt].claim.MaxHeight)<<"\n"
       <<  QString::number(arrWoman[lt].claim.MinWeight)+"-"+QString::number(arrWoman[lt].claim.MaxWeight);


    ui->womanBox->addItem(QString::number(arrWoman[lt].number)+" "+arrWoman[lt].name);

     for(int m=0;m<man_size;m++){
            bool mw=satisfy(arrMan[m],arrWoman[lt]);
             bool wm=satisfy(arrWoman[lt],arrMan[m]);
            if(mw){
                arrMan[m].vec_dream_man.push_back(lt);
            }
            if(wm){
                arrWoman[lt].vec_dream_woman.push_back(m);
            }
            if(wm&&mw){
                couple.push_back(Pair(m,lt));
            }

        }

      }
      else{
          QMessageBox::warning(this,"Error","Not found");
      }
}



void Widget::on_del_man_clicked()
{
    Deleting* blank=new Deleting(1,this);
    connect(blank,SIGNAL(delete_info()),this,SLOT(del_man()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::del_man()
{
    if(!man_size){
         QMessageBox::warning(this,"Not found","try again\n");
         return;
    }
    Man* newarr = new Man[man_size_reserved];

             for (int i = 0; i < num_man_to_del; i++) {
                 newarr[i] = arrMan[i];
             }
             for (int i = num_man_to_del + 1; i<man_size; i++) {
                 newarr[i - 1] = arrMan[i];
             }
             delete[]arrMan;
             arrMan = newarr;
             man_size -= 1;


QFile fs(man_filename);
   if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
         QTextStream fout(&fs);

       fs.resize(0);
 for(int i=0;i<man_size;i++){
       fout<<QString::number(arrMan[i].number)<<"\n"<<arrMan[i].name<<"\n"<<QString::number(arrMan[i].age)<<"\n"
          <<QString::number(arrMan[i].height)<<"\n"<<QString::number(arrMan[i].weight)<<"\n"<<arrMan[i].custom<<"\n"<<arrMan[i].hobby<<"\n"
         <<QString::number(arrMan[i].claim.MinAge)+"-"+QString::number(arrMan[i].claim.MaxAge)<<"\n"
         << QString::number(arrMan[i].claim.MinHeight)+"-"+QString::number(arrMan[i].claim.MaxHeight)<<"\n"
          <<  QString::number(arrMan[i].claim.MinWeight)+"-"+QString::number(arrMan[i].claim.MaxWeight)<<"\n";

 }
 fs.close();
   }
   update_man_box();
   update_dream_vector();
}


void Widget::on_del_woman_clicked()
{
    Deleting* blank=new Deleting(0,this);
    connect(blank,SIGNAL(delete_info()),this,SLOT(del_woman()));
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::del_woman()
{
    if(!woman_size){
         QMessageBox::warning(this,"Not found","try again\n");
         return;
    }
    Woman* newarr = new Woman[woman_size_reserved];

             for (int i = 0; i < num_woman_to_del; i++) {
                 newarr[i] = arrWoman[i];
             }
             for (int i = num_woman_to_del + 1; i<woman_size; i++) {
                 newarr[i - 1] = arrWoman[i];
             }
             delete[]arrWoman;
             arrWoman = newarr;
             woman_size -= 1;


QFile fs(woman_filename);
   if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
         QTextStream fout(&fs);

       fs.resize(0);
 for(int i=0;i<woman_size;i++){
       fout<<QString::number(arrWoman[i].number)<<"\n"<<arrWoman[i].name<<"\n"<<QString::number(arrWoman[i].age)<<"\n"
          <<QString::number(arrWoman[i].height)<<"\n"<<QString::number(arrWoman[i].weight)<<"\n"<<arrWoman[i].custom<<"\n"<<arrWoman[i].hobby<<"\n"
         <<QString::number(arrWoman[i].claim.MinAge)+"-"+QString::number(arrWoman[i].claim.MaxAge)<<"\n"
         << QString::number(arrWoman[i].claim.MinHeight)+"-"+QString::number(arrWoman[i].claim.MaxHeight)<<"\n"
          <<  QString::number(arrWoman[i].claim.MinWeight)+"-"+QString::number(arrWoman[i].claim.MaxWeight)<<"\n";

 }
 fs.close();
   }
   update_woman_info();
   update_dream_vector();
}


void Widget::on_edit_man_clicked()
{
    Editing* blank=new Editing(1,this);
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::edit_man()
{
    if(!man_size){
         QMessageBox::warning(this,"Not found","try again\n");
         return;
    }
    QFile fs(man_filename);
       if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
             QTextStream fout(&fs);
             fs.resize(0);
 for(int k=0;k<man_size;k++){
   fout<<QString::number(arrMan[k].number)
      <<"\n"<<arrMan[k].name
     <<"\n"<<QString::number(arrMan[k].age)
    <<"\n"<<QString::number(arrMan[k].height)
   <<"\n"<<QString::number(arrMan[k].weight)
   <<"\n"<<arrMan[k].custom
   <<"\n"<<arrMan[k].hobby
   <<"\n"<<QString::number(arrMan[k].claim.MinAge)+"-"+QString::number(arrMan[k].claim.MaxAge)
   <<"\n"<< QString::number(arrMan[k].claim.MinHeight)+"-"+QString::number(arrMan[k].claim.MaxHeight)
   <<"\n"<<  QString::number(arrMan[k].claim.MinWeight)+"-"+QString::number(arrMan[k].claim.MaxWeight)<<"\n";
}
}
       fs.close();

       ui->manBox->setItemText(num_man_to_edit,QString::number(arrMan[num_man_to_edit].number)+" "+arrMan[num_man_to_edit].name);


          update_dream_vector();
}


void Widget::on_edit_woman_clicked()
{
    Editing* blank=new Editing(0,this);
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
}

void Widget::edit_woman()
{
    if(!woman_size){
         QMessageBox::warning(this,"Not found","try again\n");
         return;
    }
    QFile fs(woman_filename);
       if(fs.open(QIODevice::ReadWrite|QIODevice::Text)){
             QTextStream fout(&fs);
             fs.resize(0);
 for(int k=0;k<woman_size;k++){
   fout<<QString::number(arrWoman[k].number)
      <<"\n"<<arrWoman[k].name
     <<"\n"<<QString::number(arrWoman[k].age)
    <<"\n"<<QString::number(arrWoman[k].height)
   <<"\n"<<QString::number(arrWoman[k].weight)
   <<"\n"<<arrWoman[k].custom
   <<"\n"<<arrWoman[k].hobby
   <<"\n"<<QString::number(arrWoman[k].claim.MinAge)+"-"+QString::number(arrWoman[k].claim.MaxAge)
   <<"\n"<< QString::number(arrWoman[k].claim.MinHeight)+"-"+QString::number(arrWoman[k].claim.MaxHeight)
   <<"\n"<<  QString::number(arrWoman[k].claim.MinWeight)+"-"+QString::number(arrWoman[k].claim.MaxWeight)<<"\n";
}
}
       fs.close();

       ui->womanBox->setItemText(num_woman_to_edit,QString::number(arrWoman[num_woman_to_edit].number)+" "+arrWoman[num_woman_to_edit].name);
        update_dream_vector();
}

void Widget::update_dream_vector()
{
    couple.clear();
    for(int m=0;m<man_size;m++){
    arrMan[m].vec_dream_man.clear();
}
for(int w=0;w<woman_size;w++){
arrWoman[w].vec_dream_woman.clear();
}

    for(int m=0;m<man_size;m++){
        for(int w=0;w<woman_size;w++){
            bool mw=satisfy(arrMan[m],arrWoman[w]);
             bool wm=satisfy(arrWoman[w],arrMan[m]);
            if(mw){
                arrMan[m].vec_dream_man.push_back(w);
            }
            if(wm){
                arrWoman[w].vec_dream_woman.push_back(m);
            }
            if(wm&&mw){
                couple.push_back(Pair(m,w));
            }

        }
    }
}

void Widget::update_man_box()
{
    ui->manBox->clear();
    for(int i=0;i<man_size;i++){
    ui->manBox->addItem(QString::number(arrMan[i].number)+" "+arrMan[i].name);
    }
}

void Widget::update_woman_info()
{
    for(int i=0;i<woman_size;i++){
    ui->womanBox->addItem(QString::number(arrWoman[i].number)+" "+arrWoman[i].name);
    }
}

