#ifndef WOMAN_H
#define WOMAN_H
#include <QString>
#include "demands.h"
#include <QVector>
class Woman
{
public:
    Woman(int number,QString name,int age,int height, int weight, QString custom,QString hobby,Demands claim);
    Woman();
    ~Woman();
    int number;
    QString name;
    int age;
    int height;
    int weight;
    QString custom;
    QString hobby;
    Demands claim;
    QVector<int> vec_dream_woman;
};

#endif // WOMAN_H
