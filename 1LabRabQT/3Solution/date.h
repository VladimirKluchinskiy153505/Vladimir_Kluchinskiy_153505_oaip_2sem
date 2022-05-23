#ifndef DATE_H
#define DATE_H
#include <cmath>
void init_current_day();
class Date {
public:
    Date(int day, int month, int year);
    Date() {}
    //private:
    friend void init_current_day();
    static Date current_date;
     static Date birth_date;
     Date* ptr_to_prev;
    int day;
    int month;
    int year;
    int difference_with_prev;
    Date next_day();
    Date prev_day();
    bool is_leep();
    int week_day();
    int week_number();
   static int days_till_yout_birthday(Date date);
    int Duration(Date date);
};


#endif // DATE_H
