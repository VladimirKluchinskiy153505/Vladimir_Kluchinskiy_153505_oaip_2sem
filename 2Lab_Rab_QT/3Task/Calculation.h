#ifndef CALCULATION_H
#define CALCULATION_H
#include "my_stack.h"
#include <QString>
class Calculation{
public:
    static double compute(QString source,double a,double b,double c,double d,double e){
        my_stack<double> stack;
        int size = source.size();
        for (int i = 0; i < size; i++) {
                QChar s = source[i];
                if (s == '+') {
                    double temp = stack.top();
                   stack.pop();
                    double res = stack.top() + temp;
                    stack.pop();
                    stack.push(res);
                }
                else if (s == '-') {
                    double temp = stack.top();
                    stack.pop();
                    double res = (stack.top() - temp);
                     stack.pop();
                    stack.push(res);
                }
                else if (s == '*') {
                    double temp = stack.top();
                    stack.pop();
                    double res = (stack.top() * temp);
                     stack.pop();
                    stack.push(res);
                }
                else if (s == '/') {
                    double temp = stack.top();
                    stack.pop();
                    double res = (stack.top()/ temp);
                     stack.pop();
                    stack.push(res);
                }
                else {
                    if(s=='a'){
                        stack.push(a);
                    }
                   else if(s=='b'){
                        stack.push(b);
                    }

                    else if(s=='c'){
                         stack.push(c);
                     }
                    else if(s=='d'){
                         stack.push(d);
                     }
                    else if(s=='e'){
                         stack.push(e);
                     }
                }
            }
        return stack.top();
    }
};

#endif // CALCULATION_H
