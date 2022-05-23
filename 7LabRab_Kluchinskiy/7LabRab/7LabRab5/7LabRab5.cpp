#pragma warning( disable : 4996)
#include <iostream>
using namespace std;
int GetNumber() {
    int x;
    while (true) {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else {
            return x;
        }
    }
}
void PushBackTo(char x, char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
int main(){
    int x = 0,y,div=1000,temp,size=0;
    char w;
    char* arr = new char[size];
    y = GetNumber();
    x = abs(y);
    if (x >= 1000) {
        temp = x / 1000;
        for (int i = 0; i < temp; i++) {
            PushBackTo('M', arr, size);
        }
        x = x % 1000;
    }
    if (x >= 500) {
        temp = x / 500;
        for (int i = 0; i < temp; i++) {
            PushBackTo('D', arr, size);
        }
        x = x % 500;
    }
    if (x >= 100) {
        temp = x / 100;
        for (int i = 0; i < temp; i++) {
            PushBackTo('C', arr, size);
        }
        x = x % 100;
    }
    if (x >= 50) {
        temp = x / 50;
        for (int i = 0; i < temp; i++) {
            PushBackTo('L', arr, size);
        }
        x = x % 50;
    }
    if (x >= 10) {
        temp = x / 10;
        for (int i = 0; i < temp; i++) {
            PushBackTo('X', arr, size);
        }
        x = x % 10;
    }
    if (x > 0) {
        if (x == 9) { PushBackTo('I', arr, size);
        PushBackTo('X', arr, size);
        }
        if (x == 8) { PushBackTo('V', arr, size);
        PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
      }
        if (x == 7) { PushBackTo('V', arr, size);
        PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
        }
        if (x == 6) { PushBackTo('V', arr, size);
        PushBackTo('I', arr, size);
        }
        if (x == 5) { PushBackTo('V', arr, size); }
        if (x == 4) { PushBackTo('I', arr, size);
        PushBackTo('V', arr, size);
        }
        if (x == 3) { PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
        }
        if (x == 2) { PushBackTo('I', arr, size);
        PushBackTo('I', arr, size);
        }
        if (x == 1) { PushBackTo('I', arr, size); }
    }
    if (y < 0) { cout << '-'; }
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    delete[] arr;
    return 0;
}