#pragma warning( disable : 4996)
#include <iostream>
#include <string>
using namespace std;
char* GetNumber(int& L) {
    char* line = new char[1024];
    while (true) {
        bool f = true;
        cin.getline(line, 1024, '\n');
        int l = strlen(line);
        for (int i = 0; i < l; i++) {
            if (line[0] == '-') { continue; }
            if (!(line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9' || line[i] == 'a' || line[i] == 'A' || line[i] == 'b' || line[i] == 'B' || line[i] == 'c' || line[i] == 'C' || line[i] == 'd' || line[i] == 'D')) {
                f = false;
                cout << "Invalid Output\n";
                break;
            }
        }
        if (f) {
            char* newline = new char[l + 1];
            strcpy(newline, line);
            delete[] line;
            L = l + 1;
            return newline;
        }
    }
}
int GetN(char x) {
    if (x == '0') {
        return 0;
    }
    if (x == '1') {
        return 1;
    }
    if (x == '2') {
        return 2;
    }
    if (x == '3') {
        return 3;
    }
    if (x == '4') {
        return 4;
    }
    if (x == '5') {
        return 5;
    }
    if (x == '6') {
        return 6;
    }
    if (x == '7') {
        return 7;
    }
    if (x == '8') {
        return 8;
    }
    if (x == '9') {
        return 9;
    }
    if ((x == 'A') || (x == 'a')) {
        return 10;
    }
    if ((x == 'B') || (x == 'b')) {
        return 11;
    }
    if ((x == 'C') || (x == 'c')) {
        return 12;
    }
    if ((x == 'D') || (x == 'd')) {
        return 13;
    }
}
char GetS(int x) {
    if (x == 0) {
        return '0';
    }
    if (x == 1) {
        return '1';
    }
    if (x == 2) {
        return '2';
    }
    if (x == 3) {
        return '3';
    }
    if (x == 4) {
        return '4';
    }
    if (x == 5) {
        return '5';
    }
    if (x == 6) {
        return '6';
    }
    if (x == 7) {
        return '7';
    }
    if (x == 8) {
        return '8';
    }
    if (x == 9) {
        return '9';
    }
    if (x == 10) {
        return 'A';
    }
    if (x == 11) {
        return 'B';
    }
    if (x == 12) {
        return 'C';
    }
    if (x == 13) {
        return 'D';
    }
}
void DelFirst(char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE - 1];
    for (int i = 1; i < SIZE; i++) {
        NewArr[i - 1] = ARR[i];
    }
    SIZE--;
    delete[]ARR;
    ARR = NewArr;
}
void DelLast(char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE - 1];
    for (int i = 0; i < SIZE - 1; i++) {
        NewArr[i] = ARR[i];
    }
    SIZE--;
    delete[]ARR;
    ARR = NewArr;
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
void reverse(char*& Arr, const int& size) {
    for (int i = 0; i < (size / 2); i++)
    {
        swap(Arr[i], Arr[size - 1 - i]);
    }
}
void Summary(int& size, char*& Sum, int& Min, char*& MaxArr, char*& arr1, char*& arr2) {
    int sum = 0;
    for (int i = 0; i < Min; i++) {
        int w = GetN(arr1[i]) + GetN(arr2[i]);
        Sum[i] = GetS((w + sum) % 14);
        sum = (w + sum) / 14;
    }
    for (int i = Min; i < size; i++) {
        int u = GetN(MaxArr[i]);
        Sum[i] = GetS((u + sum) % 14);
        sum = (u + sum) / 14;
    }
    if (sum) {
        PushBackTo(sum + int('0'), Sum, size);
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << Sum[i] << " ";
    }
}
void Difference(int& size, char*& Dif, int& Min, char*& MaxArr, char*& MinArr) {
    int k = 0;
    for (int i = 0; i < Min; i++) {
        int dif = GetN(MaxArr[i]) - GetN(MinArr[i]) + k;
        if (dif < 0) {
            Dif[i] = GetS(14 + dif);
            k = -1;
        }
        else {
            Dif[i] = GetS(dif);
            k = 0;
        }
    }
    for (int i = Min; i < size; i++) {
        int dif = GetN(MaxArr[i]) + k;
        if (dif < 0) {
            Dif[i] = GetS(14 + dif);
            k = -1;
        }
        else {
            Dif[i] = GetS(dif);
            k = 0;
        }
    }
    while ((Dif[size - 1] == '0') && (size > 1)) {
        DelLast(Dif, size);
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << Dif[i] << " ";
    }
}
int main() {
    int L1 = 0, L2 = 0, Min, size;
    bool minus1 = false, minus2 = false;
    char* MaxArr; char* MinArr;
    cout << "Enter Two Numbers {0,1,2...A,B,C,D}\n";
    char* arr1 = GetNumber(L1);
    char* arr2 = GetNumber(L2);
    DelLast(arr1, L1);
    DelLast(arr2, L2);
    if (arr1[0] == char(45)) {
        minus1 = true;
        DelFirst(arr1, L1);
    }
    if (arr2[0] == char(45)) {
        minus2 = true;
        DelFirst(arr2, L2);
    }
    MaxArr = arr1;
    MinArr = arr2;
    Min = L2;
    size = L1;
    if (L1 < L2) {
        MaxArr = arr2;
        MinArr = arr1;
        Min = L1;
        size = L2;
    }
    else if (L1 > L2) {
        MaxArr = arr1;
        MinArr = arr2;
        Min = L2;
        size = L1;
    }
    else {
        int i = 0;
        while (i != L1) {
            if (arr1[i] > arr2[i]) {
                MaxArr = arr1;
                MinArr = arr2;
                Min = L2;
                size = L1;
                break;
            }
            else if (arr1[i] < arr2[i]) {
                MaxArr = arr2;
                MinArr = arr1;
                Min = L1;
                size = L2;
                break;
            }
            i++;
        }
    }
    reverse(arr1, L1);
    reverse(arr2, L2);
    char* Sum = new char[size];
    char* Dif = new char[size];
    if (minus1 && minus2) {
        cout << "The SUM Is:\n" << '-';
        Summary(size, Sum, Min, MaxArr, arr1, arr2);
        cout << "\nThe Difference Is:\n";
        Difference(size, Dif, Min, MaxArr, MinArr);
    }
    else if (minus1 || minus2) {
        cout << "The SUM Is:\n";
        Difference(size, Dif, Min, MaxArr, MinArr);
        cout << "\nThe Difference Is:\n";
        Summary(size, Sum, Min, MaxArr, arr1, arr2);
    }
    else {
        cout << "The SUM Is:\n";
        Summary(size, Sum, Min, MaxArr, arr1, arr2);
        cout << "\nThe Difference Is:\n";
        Difference(size, Dif, Min, MaxArr, MinArr);
    }
    delete[] arr1;
    delete[] arr2;
    delete[] Sum;
    delete[] Dif;
    return 0;
}