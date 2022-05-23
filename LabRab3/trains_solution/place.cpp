#include "place.h"

Place::Place()
{

}

Place::Place(Date date, QString destination, Time time, int number)
{
this->date=date;
this->destination=destination;
this->time=time;
    this->number=number;
}

bool Place::operator<=(const Place &other)
{
    return(((this->date.day-other.date.day)+(this->date.month-other.date.month)*30+(this->date.year-other.date.year)*365)<=0);
}

bool Place::operator>=(const Place &other)
{
 return(((this->date.day-other.date.day)+(this->date.month-other.date.month)*30+(this->date.year-other.date.year)*365)>=0);
}
