#include "widget.h"
#include "ui_widget.h"
#include "ui_Information.h"
#include "rectangle.h"
#include "rhomb.h"
#include "circle.h"
#include "hexagon.h"
#include  "star5.h"
#include<QMessageBox>
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
     scene = new QGraphicsScene(0,0,1600,900,this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
//scene->setStickyFocus(true);//липкий фокус
   // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
 scene->addRect(scene->sceneRect());
 timer= new QTimer(this);
  connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
  timer->start(10);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_openCanvas_clicked()
{
    canvas= new GraphicsPainter(0);
    canvas->SetDraw(true);
    canvas->show();
}

void Widget::on_add_Square_clicked()
{
    Quadrate *item = new Quadrate();
    // Создаём графический элемента
    item->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item);
    vec.push_back(item);
}


void Widget::on_Enter_Information_clicked()
{
   info =new Info(nullptr);
   info->setWindowModality(Qt::ApplicationModal);
   info->show();
}


void Widget::on_change_centroid_clicked()
{
    centroid=new Centroid(nullptr);
    centroid->setWindowModality(Qt::ApplicationModal);
    centroid->show();
}


void Widget::on_See_Sq_Per_Centr_clicked()
{
    viewsquare=new ViewSquare(nullptr);
    viewsquare->setWindowModality(Qt::ApplicationModal);
    viewsquare->show();
}


void Widget::on_add_rectangle_clicked()
{
    Rectangle *item1 = new Rectangle();
  // Создаём графический элемента
    item1->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item1);
    vec.push_back(item1);
}


void Widget::on_del_last_clicked()
{
    if(!vec.size()){
         QMessageBox::warning(this,"Error","No Elements\n");
    }
    else{
    delete vec[vec.size()-1];
    vec.pop_back();
  Info:: obj=nullptr;
   ViewSquare::obj=nullptr;
   Centroid::obj=nullptr;
    }
}


void Widget::on_add_rhomb_clicked()
{
    Rhomb *item2 = new Rhomb();
  // Создаём графический элемента
    item2->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item2);
    vec.push_back(item2);
}


void Widget::on_add_circle_clicked()
{
    Circle *item3 = new Circle();
  // Создаём графический элемента
    item3->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item3);
    vec.push_back(item3);
}


void Widget::on_add_triangle_clicked()
{
    Triangle *item4 = new Triangle();
  // Создаём графический элемента
    item4->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item4);
    vec.push_back(item4);
}


void Widget::on_add_hexagon_clicked()
{
    Hexagon *item5 = new Hexagon();
  // Создаём графический элемента
    item5->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item5);
    vec.push_back(item5);
}


void Widget::on_add_5star_clicked()
{
    Star5 *item6 = new Star5(5);
  // Создаём графический элемента
    item6->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item6);
    vec.push_back(item6);
}


void Widget::on_add_6star_clicked()
{
    Star5 *item7 = new Star5(6);
  // Создаём графический элемента
    item7->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item7);
    vec.push_back(item7);
}


void Widget::on_add_8star_clicked()
{
    Star5 *item8 = new Star5(8);
  // Создаём графический элемента
    item8->setPos(randomBetween(0, 1600),    // Устанавливаем случайную позицию элемента
                 randomBetween(0,900));
    scene->addItem(item8);
    vec.push_back(item8);
}

