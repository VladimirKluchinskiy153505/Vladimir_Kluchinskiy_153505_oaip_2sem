#ifndef TRANSLATE_H
#define TRANSLATE_H
#include <QString>
#include "my_stack.h"
class Translate{
public:
class Operator {
public:
    Operator(QChar symb) :symb(symb) {
        if (symb == '*' || symb == '/') {
            priority = 3;
        }
        else if (symb == '+' || symb == '-') {
            priority = 2;
        }
        else if (symb == '(' || symb == ')') {
            priority = 1;
        }
        else {
            priority = 0;
        }
    };
    Operator() {};
    int get_priority() {
        return priority;
    }
    QChar& get_char() {
        return symb;
    }
private:
    QChar symb;
    int priority;
};
static int Priority(QChar symb) {
    if (symb == '*' || symb == '/') {
        return 3;
    }
    else if (symb == '+' || symb == '-') {
        return 2;
    }
    else if (symb == '(' || symb == ')') {
        return 1;
    }
    else {
        return 0;
    }
}
static QString rpw(QString str_source) {
    QString str_out;
    my_stack<Operator> stack;

    //cout << str_source<<'\n';
    int size = str_source.size();
    for (int i = 0; i < size; i++) {
        QChar s = str_source[i];
        if ((s == '(') || (s == ')') || (s == '+') || (s == '-') || (s == '*') || (s == '/')) {
            if (stack.empty() || s == '(') {
                stack.push(Operator(s));
            }
            else if (s == ')') {
                while (stack.top().get_char() != '(') {
                    str_out.push_back(stack.top().get_char());
                    stack.pop();
                }
                stack.pop();
            }
            else {
                while (stack.size()&&stack.top().get_priority() >= Priority(s)) {
                    str_out.push_back(stack.top().get_char());
                    stack.pop();
                }
                stack.push(Operator(s));
            }
        }
        else {
            str_out.push_back(s);
        }
    }
    while (!stack.empty()) {
        str_out.push_back(stack.top().get_char());
        stack.pop();
    }
    return str_out;
}
};
#endif // TRANSLATE_H
