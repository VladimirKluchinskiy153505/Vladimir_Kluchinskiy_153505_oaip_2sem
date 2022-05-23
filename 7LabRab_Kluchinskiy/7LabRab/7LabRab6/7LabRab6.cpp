#pragma warning( disable : 4996)
#include <iostream>
#define ll long long int
using namespace std;
int GetNumber(ll& x) {
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
void PushBackTo(int x, int*& ARR, ll& SIZE) {
    int* NewArr = new int[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
int main() {
    ll x, y, size = 0, n = GetNumber(n);
    int* arr = new int[size];
    for (int i = 0; i < n; i++) {
        x = GetNumber(x);
        y = abs(x);
        PushBackTo((y + 1) / 10, arr, size);
    }
    cout << "\nAnswers are:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }
    delete[] arr;
    return 0;
}