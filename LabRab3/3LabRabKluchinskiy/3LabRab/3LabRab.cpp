// 3LabRab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include "C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\Stack\Stack.cpp"
//#include "C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\Unique_ptr\Unique_ptr.cpp"
#include "C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\New_Stack\New_Stack.cpp"
using namespace std;

class Translate {
public:
    class Operator {
    public:
        Operator(char symb) :symb(symb) {
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
        char& get_char() {
            return symb;
        }
    private:
        char symb;
        int priority;
    };
    static int Priority(char symb) {
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
    static string rpw(string str_source) {
        string str_out;
        my_stack<Operator> stack;

        //cout << str_source<<'\n';
        int size = str_source.size();
        for (int i = 0; i < size; i++) {
            char s = str_source[i];
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
                    while (stack.top().get_priority() >= Priority(s)) {
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


int main()
{
    string source,str;
    getline(cin, source);
    str = Translate::rpw(source);
    cout << str;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
