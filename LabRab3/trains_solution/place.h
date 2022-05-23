#ifndef PLACE_H
#define PLACE_H


#include <QString>
struct Date{
    int day;
    int month;
    int year;
};
struct Time{
    int hours;
    int minuts;
};

class Place
{
public:
    Place();
    Place(Date date,QString destination,Time time,int number);
    bool operator<=(const Place& other);
     bool operator>=(const Place& other);
    Date date;
    QString destination;
    Time time;
    int number;

};

#endif // PLACE_H
