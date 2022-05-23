#pragma warning( disable : 4996)
#include <iostream>
#define ll long long int
using namespace std;
char* GetNumber(int&L){
    char* line = new char[1024];
    while (true) {
        bool f = true;
        cin.getline(line, 1024, '\n');
        int l = strlen(line);
        for (int i = 0; i < l; i++) {
            if (line[0] == '-') { continue; }
            if (!(line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9' || line[i] == 'a' || line[i] == 'A' || line[i] == 'b' || line[i] == 'B' || line[i] == 'c' || line[i] == 'C' || line[i] == 'd' || line[i] == 'D')) {
                f=false;
                cout << "Invalid Output\n";
                break;
            }
        }
        if (f) {
            char* newline = new char[l+1];
            strcpy(newline, line);
            delete[] line;
            L = l+1;
            return newline;
        }
    }
}
ll degree(ll x, int n) {
    if (n == 0) { return 1; }
    ll res;
    res = degree(x, n >> 1);
    if (n & 1) { return res * res * x; }
    else { return res * res; }
}
ll from10ton(ll x, int n) {
    if (x < n) { return x; }
    return from10ton(x / n, n) * 10 + x % n;
}
ll from14to10(char*&arr,const int& l) {
    ll sum = 0; int j = 0;
    if (arr[0] == '-') { j++; }
    for (int i = l - 2; i >= j; i--) {
        if ((arr[i] == 'a') || (arr[i] == 'A')) {
            sum += 10*degree(14,l-2-i);
        }
        else if((arr[i] == 'b') || (arr[i] == 'B')) {
            sum += 11*degree(14,l-2-i);
        }
        else if ((arr[i] == 'c') || (arr[i] == 'C')) {
            sum += 12*degree(14,l-2-i);
        }
        else if ((arr[i] == 'd') || (arr[i] == 'D')) {
            sum += 13* degree(14, l - 2 - i);
        }
        else {
            sum += (int(arr[i]) - int('0')) * degree(14, l - 2 - i);
        }
    }
    if (arr[0] == '-') { sum *= -1; }
    return sum;
}
int main()
{
    /*cout << degree(2, 63)<<"\n";*/
    int L = 0; ll sum;
    cout << "Enter line" << endl;
   char* arr= GetNumber(L);
   sum = from14to10(arr, L);
   cout << "Conversion from 14 to 6:\n";
   cout << from10ton(sum,6);
   delete[]arr;
    return 0;
}

