#include "man.h"

Man::Man(int number, QString name, int age, int height, int weight, QString custom, QString hobby, Demands claim)
{
this->number=number;
    this->name=name;
    this->age=age;
    this->height=height;
    this->weight=weight;
    this->custom=custom;
    this->hobby=hobby;
    this->claim=claim;
}

Man::Man()
{

}

Man::~Man()
{

}

void Man::operator=(const Man &other)
{
    this->number=other.number;
    this->name=other.name;
    this->age=other.age;
    this->height=other.height;
    this->weight=other.weight;
    this->custom=other.custom;
    this->hobby=other.hobby;
    this->claim=other.claim;
}
