#include <iostream>
#include <string>
#define ull unsigned long long int
using namespace std;
ull getNatValue()
{
    while (true)
    {
        ull n;
        bool p = true;
        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (!(str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
                str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9'))
            {
                p = false;
                cout << "Please try again." << endl;
                cin.ignore(32767, '\n');
                break;
            }
        }
        if (p)
        {
            n = stoll(str);
            cin.ignore(32767, '\n');
            if (n == 0)
            {
                cout << "Invalid output" << endl;
                continue;
            }
            return n;
        }
    }
}
int subtract(ull x, ull y) {//разность
    while (y) {
        ull borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

ull inc(ull i) {//++
    ull mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}

ull divide(ull n, ull d) {//делить
    ull q = 0;
    while (n >= d) {
        ull i = 0, D = d;
        while (n >= (D << 1)) {
            i = inc(i);
            D <<= 1;
        }
        q |= 1 << i;
        n = subtract(n, D);
  
    }
    return q;
}

int add(ull x, ull y) { //добавить 
    while (y) {
        ull carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

ull multiply(ull a, ull b) {//умножить
    ull result = 0;
    while (b) 
    {
        if (b & 1) 
        {
            result = add(result, a);
        }
        a <<= 1; 
        b >>= 1; 
    }
    return result;
}

ull mod(ull a, ull b) {//остаток по модулю
    ull r = divide(a, b);
    return subtract(a, multiply(r, b));
}

int main() {
    ull n, m1, m2, m3;
    cout << "Enter your number\n";
    n = getNatValue();
    cout << "Enter 3 moduls\n";
    m1= getNatValue();
    m2 = getNatValue();
    m3 = getNatValue();
    cout << "Remainders are:\n";
    cout<<(mod(n, m1))<<"\n";
    cout << (mod(n, m2))<<"\n";
    cout << (mod(n, m3));
    return 0;
}