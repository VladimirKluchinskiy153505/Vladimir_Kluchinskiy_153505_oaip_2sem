#ifndef DEMANDS_H
#define DEMANDS_H


class Demands
{
public:
    void operator = (const int a){
        MinAge=a;
         MaxAge=a;
         MinHeight=a;
         MaxHeight=a;
         MinWeight=a;
        MaxWeight=a;
    };
    Demands();
    int MinAge;
    int MaxAge;
    int MinHeight;
    int MaxHeight;
    int MinWeight;
    int MaxWeight;
};

#endif // DEMANDS_H
