#ifndef WORKER_H
#define WORKER_H
#include <QString>
class worker{
public:
    worker(QString snp,int number,double hours,double rate):snp(snp),number(number),hours(hours),rate(rate){
        count();
    }
    worker(){};

    QString snp;
    int number;
    double hours;
    double rate;
double cash;
void count(){
    double sum = 0;
          if (hours > 144) {
              sum = (hours - 144) * rate * 2;
              sum += 144 * rate;
          }
          else {
              sum = rate * hours;
          }
          cash = sum;
}
};

#endif // WORKER_H
