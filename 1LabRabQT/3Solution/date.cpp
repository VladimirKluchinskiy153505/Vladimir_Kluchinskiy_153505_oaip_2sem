#include "date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->ptr_to_prev=nullptr;
}
Date Date::current_date = Date(1, 1, 1);
Date Date::birth_date=Date(1,1,1);
Date Date::next_day()
{
    if (this->month == 1) {
         if (this->day == 31) {
             return Date(1, 2, this->year);//31.01
         }
         else {
             return Date(this->day + 1, 1, this->year);//30.01
         }
     }
     else if (this->month == 2) {
         if ((this->day == 29) || (!(this->is_leep()) && (this->day == 28))) {
             return Date(1, 3, this->year);//29.02
         }
         else {
             return Date(this->day + 1, 2, this->year);//27.02
         }
     }
     else if (this->month == 3) {
         if (this->day == 31) {
             return Date(1, 4, this->year);
         }
         else {
             return Date(this->day + 1, 3, this->year);
         }
     }
     else if (this->month == 4) {
         if (this->day == 30) {
             return Date(1, 5, this->year);
         }
         else {
             return Date(this->day + 1, 4, this->year);
         }
     }
     else if (this->month == 5) {
         if (this->day == 31) {
             return Date(1, 6, this->year);
         }
         else {
             return Date(this->day + 1, 5, this->year);
         }
     }
     else if (this->month == 6) {
         if (this->day == 30) {
             return Date(1, 7, this->year);
         }
         else {
             return Date(this->day + 1, 6, this->year);
         }
     }
     else if (this->month == 7) {
         if (this->day == 31) {
             return Date(1, 8, this->year);
         }
         else {
             return Date(this->day + 1, 7, this->year);
         }
     }
     else if (this->month == 8) {
         if (this->day == 31) {
             return Date(1, 9, this->year);
         }
         else {
             return Date(this->day + 1, 8, this->year);
         }
     }
     else if (this->month == 9) {
         if (this->day == 30) {
             return Date(1, 10, this->year);
         }
         else {
             return Date(this->day + 1, 9, this->year);
         }
     }
     else if (this->month == 10) {
         if (this->day == 31) {
             return Date(1, 11, this->year);
         }
         else {
             return Date(this->day + 1, 10, this->year);
         }
     }
     else if (this->month == 11) {
         if (this->day == 30) {
             return Date(1, 12, this->year);
         }
         else {
             return Date(this->day + 1, 11, this->year);
         }
     }
     else {
         if (this->day == 31) {
             return Date(1, 1, this->year + 1);
         }
         else {
             return Date(this->day + 1, 12, this->year);
         }
    }
}

Date Date::prev_day()
{
    if (this->month == 1) {
        if (this->day == 1) {
            return Date(31, 12, this->year - 1);
        }
        else {
            return Date(this->day - 1, 1, this->year);
        }
    }
    else if (this->month == 2) {
        if (this->day == 1) {
            return Date(31, 1, this->year);
        }
        else {
            return Date(this->day - 1, 2, this->year);
        }
    }
    else if (this->month == 3) {
        if (this->day == 1) {
            if (this->is_leep()) {
                return Date(29, 2, this->year);
            }
            else {
                return Date(28, 2, this->year);
            }
        }
        else {
            return Date(this->day - 1, 3, this->year);
        }
    }
    else if (this->month == 4) {
        if (this->day == 1) {
            return Date(31, 3, this->year);
        }
        else {
            return Date(this->day - 1, 4, this->year);
        }
    }
    else if (this->month == 5) {
        if (this->day == 1) {
            return Date(30, 4, this->year);
        }
        else {
            return Date(this->day - 1, 5, this->year);
        }
    }
    else if (this->month == 6) {
        if (this->day == 1) {
            return Date(31, 5, this->year);
        }
        else {
            return Date(this->day - 1, 6, this->year);
        }
    }
    else if (this->month == 7) {
        if (this->day == 1) {
            return Date(30, 6, this->year);
        }
        else {
            return Date(this->day - 1, 7, this->year);
        }
    }
    else if (this->month == 8) {
        if (this->day == 1) {
            return Date(31, 7, this->year);
        }
        else {
            return Date(this->day - 1, 8, this->year);
        }
    }
    else if (this->month == 9) {
        if (this->day == 1) {
            return Date(31, 8, this->year);
        }
        else {
            return Date(this->day - 1, 9, this->year);
        }
    }
    else if (this->month == 10) {
        if (this->day == 1) {
            return Date(30, 9, this->year);
        }
        else {
            return Date(this->day - 1, 10, this->year);
        }
    }
    else if (this->month == 11) {
        if (this->day == 1) {
            return Date(31, 10, this->year);
        }
        else {
            return Date(this->day - 1, 11, this->year);
        }
    }
    else {
        if (this->day == 1) {
            return Date(30, 11, this->year - 1);
        }
        else {
            return Date(this->day - 1, 12, this->year);
        }
    }
}

bool Date::is_leep()
{
    if (this->year % 4) {
        return false;
    }
    else {
        if (!(this->year % 100) && (this->year % 400)) {
            return false;
        }
        else {
            return true;
        }
    };
}

int Date::week_day()
{
    int d = this->day;
    int m = this->month;
    int y = this->year;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 +y / 400 + t[m - 1] + d) % 7;
}

int Date::week_number()
{
    return (this->month * 4) + (this->day / 7);
}

int Date::days_till_yout_birthday(Date date)
{
    return ((birth_date.day+(birth_date.month-1)*30)- (date.day+(date.month-1)*30)+365)%365;
}

int Date::Duration(Date date)
{
        return abs((this->day + (this->month-1) * 30 + (this->year-1)*365) - (date.day + (date.month-1) * 30 +(date.year-1)*365) );
}


