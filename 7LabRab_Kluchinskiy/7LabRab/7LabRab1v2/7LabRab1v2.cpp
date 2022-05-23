#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
ll sum = 0;
ll degree(ll x, int n) {
    if (n == 0) { return 1; }
    ll res;
    res = degree(x, n >> 1);
    if (n & 1) { return res * res * x; }
    else { return res * res; }
}
void from14to10(int &x,int &num) {
   if(x==0xA){
       sum += 10 * degree(14, num);
   }
   else if (x == 0xB) {
       sum += 11 * degree(14, num);
   }
   else if (x == 0xC) {
       sum += 12 * degree(14, num);
   }
   else if (x == 0xD) {
       sum += 13 * degree(14, num);
   }
   else {
       sum += x*degree(14,num);
   }
}
ll from10ton(ll x, int n) {
    if (x < n) { return x; }
    return from10ton(x / n, n) * 10 + x % n;
}
int main() {
    int x,k=0,dev=1;
    while (true) {
        bool stop = false;
        cout << "14th (0,...9,A,B,C,D): ";
        cin >> hex >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        while (true) {
            if (dev > x) {break; }
            int a = (x / dev) % 16;
            if (a == 0xE || a == 0xF) 
            {
                stop = true;
                cout << "Invalid output\n"; 
                cin.ignore(32767, '\n');
                break;
            }
            from14to10(a, k);
            k++;
            cout << a << " ";
            dev *= 16;
        }
        if (stop) { continue; }
        cout << "\n" << dec << "dec:" << sum << "\n";
        cout << "six: " << from10ton(sum, 6);
        return 0;
    }
}