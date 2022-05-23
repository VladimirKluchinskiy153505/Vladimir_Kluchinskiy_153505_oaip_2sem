#ifndef MAN_H
#define MAN_H
#include <QString>
#include <demands.h>
#include <QVector>
class Man
{
public:
    Man(int number,QString name,int age,int height, int weight, QString custom,QString hobby,Demands claim );
   Man();
   ~Man();
   void operator=(const Man& other);
    int number;
    QString name;
    int age;
    int height;
    int weight;
    QString custom;
    QString hobby;
    Demands claim;
    QVector<int> vec_dream_man;

};

#endif // MAN_H
