#include "woman.h"

Woman::Woman(int number, QString name, int age, int height, int weight, QString custom, QString hobby, Demands claim)
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

Woman::Woman()
{

}

Woman::~Woman()
{

}
