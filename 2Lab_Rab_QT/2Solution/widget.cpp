#include "widget.h"
#include "ui_widget.h"
void Widget::entering()
{
    filename=QFileDialog::getOpenFileName(this,"Open Man File",QDir::currentPath(),"*.txt");
    QFile fs(filename);
    if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
      QMessageBox::warning(this,"Error","Not Found");
     }
    else{
QString str;
QChar lt;
while(!fs.atEnd()){
amount_of_rows++;
    str=fs.readLine();
      lt=str[str.size()-1];
    str.chop(1);
vec.push_back(info_about_rows(amount_of_rows,str.size()));
text.push_back(str);

    }

text.push_back(lt);

fs.close();
}
    if(check(text)){
        QMessageBox::information(this,"GREAT","SUCCESS");
    }
    else{
        int sum=vec[0].sum_symb;
        int k=1;{
            while(sum<failed_num){
                sum+=vec[k].sum_symb;
                k++;
            }

            int column=vec[k-1].sum_symb-(sum-failed_num);
            QMessageBox::information(this,"Mistake","Row: "+QString::number(k)+" Symbol: "+QString::number(column));
        }

    }
  qDebug()<<text<<"\n"<<failed_num;
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    failed_num=0;
    amount_of_rows=0;
    ui->setupUi(this);
entering();
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::check(QString &str)
{
    my_stack<ex_char> stack;
    int size=str.size();
    qDebug()<<size;
    for(int i=0;i<size;i++){
        QChar symb=str[i];

      if(symb=='('){
          stack.push(ex_char(')',i+1));
      }
      else if(symb=='['){
          stack.push(ex_char(']',i+1));
      }
      else if(symb=='{'){
          stack.push(ex_char('}',i+1));
      }
      else if(symb=='<'){
          stack.push(ex_char('>',i+1));
      }

      else if((symb==')')||(symb==']')||(symb=='}')||(symb=='>')){
          if(stack.empty()||(stack.top()!=symb)){
              failed_num=i+1;
              return false;
          }
          stack.pop();
      }
    }
    failed_num=stack.get_head()->core.num;
    return stack.empty();
}


void Widget::on_change_dir_clicked()
{
    vec.clear();
    failed_num=0;
    text.clear();
    amount_of_rows=0;
entering();
}


