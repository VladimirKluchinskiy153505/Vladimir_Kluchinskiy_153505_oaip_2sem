#ifndef RECOVERY_H
#define RECOVERY_H
#include <QString>
#include <my_stack.h>
class Recovery{
    public:
    static QString recovery(QString source){
        my_stack<QString> stack;
        int size = source.size();
        for (int i = 0; i < size; i++) {
            QChar s = source[i];
            if (s == '+') {
                QString temp = stack.top();
                QString str;
                stack.pop();
                if (i != size - 1) {
                     str = ('(' + stack.top() + '+' + temp + ')');
                }
                else {
                str = (stack.top() + '+' + temp);
                }
                stack.pop();
                stack.push(str);
            }
            else if (s == '-') {
                QString temp = stack.top();
                QString str;
                stack.pop();
                if (i != size - 1) {
                    str = ('(' + stack.top() + '-' + temp + ')');
                }
                else {
                    str = (stack.top() + '-' + temp);
                }
                stack.pop();
                stack.push(str);
            }
            else if (s == '*') {
                QString temp = stack.top();
                stack.pop();
                QString str = ( stack.top() + '*' + temp );
                stack.pop();
                stack.push(str);
            }
            else if (s == '/') {
                QString temp = stack.top();
                stack.pop();
                QString str = (stack.top() + '/' + temp);
                stack.pop();
                stack.push(str);
            }
            else {
                QString str;
                str.push_back(s);
                stack.push(str);
            }
        }
        return stack.top();
    }
};

#endif // RECOVERY_H
