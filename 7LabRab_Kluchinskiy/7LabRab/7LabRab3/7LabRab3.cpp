#include <iostream>
#define ll long long int
using namespace std;
int getIntegerValue()
{
    while (true)
    {
        int n;
        bool p = true;
        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (!(str.at(i) == '-' || str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
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
            n = atoi(str.c_str());
            cin.ignore(32767, '\n');
            return n;
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
void PushBackTo(int x, int*& ARR, int& SIZE) {
    int* NewArr = new int[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
ll from10ton(ll x) {
    if (x < 2) { return x; }
    return from10ton(x / 2) * 10 + x % 2;
}
void reverse(int*& Arr, const int& size) {
    for (int i = 0; i < (size / 2); i++)
    {
        swap(Arr[i], Arr[size - 1 - i]);
    }
}
void PlusPlus( int*& arr1, int*& arr2, int& size1, int& size2) {
    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    if (size1 < size2) {
        int w = size1;
        for (int i = w; i < size2; i++) {
            PushBackTo(arr1[w - 1], arr1, size1);
        }
    }
    else if (size2 < size1) {
        int w = size2;
        for (int i = w; i < size1; i++) {
            PushBackTo(arr2[w - 1], arr2, size2);
        }
    }
    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    int size3 = size1; ll sum = 0;
    int* Sum = new int[size3];
    for (int i = 0; i < size1; i++) {
        Sum[i] = (arr1[i] + arr2[i] + sum) % 2;
        sum = (arr1[i] + arr2[i] + sum) / 2;
    }
    if (sum == 1) {
        for (int i = 0; i < size3; i++) {
            ll u = Sum[i];
            Sum[i] = (u + sum) % 2;
            sum = (u + sum) / 2;
        }
    }
    cout << "The Sum of Inverse N1 and N2:\n";
    cout << 0 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << Sum[i] << " ";
    }
    cout << "\n\n";
    cout << "The Strict Code of the Sum:\n";
    cout << 0 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << (Sum[i]) << " ";
    }
    delete[]Sum;
}
void PlusMinusModBlessThanA( int*& arr1, int*& arr2, int& size1, int& size2) {


    for (int i = size2 - 2; i >= 0; i--) {
        arr2[i] ^= 1;
    }

    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    if (size1 < size2) {
        int w = size1;
        for (int i = w; i < size2; i++) {
            PushBackTo(arr1[w - 1], arr1, size1);
        }
    }
    else if (size2 < size1) {
        int w = size2;
        for (int i = w; i < size1; i++) {
            PushBackTo(arr2[w - 1], arr2, size2);
        }
    }
    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    int size3 = size1; ll sum = 0;
    int* Sum = new int[size3];
    for (int i = 0; i < size1; i++) {
        Sum[i] = (arr1[i] + arr2[i] + sum) % 2;
        sum = (arr1[i] + arr2[i] + sum) / 2;
    }
    if (sum == 1) {
        for (int i = 0; i < size3; i++) {
            ll u = Sum[i];
            Sum[i] = (u + sum) % 2;
            sum = (u + sum) / 2;
        }
    }
    cout << "The Sum of Inverse N1 and N2:\n";
    cout << 0 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << Sum[i] << " ";
    }
    cout << "\n\n";
    cout << "The Strict Code of the Sum:\n";
    cout << 0 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << (Sum[i]) << " ";
    }
    delete[] Sum;
}
void PlusMinusModBMoreThanA(int*& arr1, int*& arr2, int& size1, int& size2) {


    for (int i = size2 - 2; i >= 0; i--) {
        arr2[i] ^= 1;
    }

    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    if (size1 < size2) {
        int w = size1;
        for (int i = w; i < size2; i++) {
            PushBackTo(arr1[w - 1], arr1, size1);
        }
    }
    else if (size2 < size1) {
        int w = size2;
        for (int i = w; i < size1; i++) {
            PushBackTo(arr2[w - 1], arr2, size2);
        }
    }
    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    int size3 = size1; ll sum = 0;
    int* Sum = new int[size3];
    for (int i = 0; i < size1; i++) {
        Sum[i] = (arr1[i] + arr2[i] + sum) % 2;
        sum = (arr1[i] + arr2[i] + sum) / 2;
    }
    if (sum == 1) {
        for (int i = 0; i < size3; i++) {
            ll u = Sum[i];
            Sum[i] = (u + sum) % 2;
            sum = (u + sum) / 2;
        }
    }
    cout << "The Sum of Inverse N1 and N2:\n";
    cout << 1 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << Sum[i] << " ";
    }
    cout << "\n\n";
    cout << "The Strict Code of the Sum:\n";
    cout << 1 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << (Sum[i] ^ 1) << " ";
    }
    delete[] Sum;
}
void MinusMinus( int*& arr1, int*& arr2, int& size1, int& size2) {

    for (int i = size1 - 2; i >= 0; i--) {
        arr1[i] ^= 1;
    }

    for (int i = size2 - 2; i >= 0; i--) {
        arr2[i] ^= 1;
    }

    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    if (size1 < size2) {
        int w = size1;
        for (int i = w; i < size2; i++) {
            PushBackTo(arr1[w - 1], arr1, size1);
        }
    }
    else if (size2 < size1) {
        int w = size2;
        for (int i = w; i < size1; i++) {
            PushBackTo(arr2[w - 1], arr2, size2);
        }
    }
    cout << "The Inverse code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Inverse code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";
    int size3 = size1; ll sum = 0;
    int* Sum = new int[size3];
    for (int i = 0; i < size1; i++) {
        Sum[i] = (arr1[i] + arr2[i] + sum) % 2;
        sum = (arr1[i] + arr2[i] + sum) / 2;
    }
    if (sum == 1) {
        for (int i = 0; i < size3; i++) {
            ll u = Sum[i];
            Sum[i] = (u + sum) % 2;
            sum = (u + sum) / 2;
        }
    }
    cout << "The Sum of Inverse N1 and N2:\n";
    cout << 1 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << Sum[i] << " ";
    }
    cout << "\n\n";
    cout << "The Strict Code of the Sum:\n";
    cout << 1 << " ";
    for (int i = size3 - 1; i >= 0; i--) {
        cout << (Sum[i] ^ 1) << " ";
    }
    delete[] Sum;
}
int main() {
    int size1 = 0, size2 = 0, size3;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    ll n1, n2, sum, dev = 1, y;
    cout << "Enter 2 integers\n";
    n1 = getIntegerValue(); n2=getIntegerValue();
    if (n1 < n2) { swap(n1, n2); }
    sum = from10ton(abs(n1));
    while (sum >= dev) {
        y = sum / dev % 10;
        PushBackTo(y, arr1, size1);
        dev *= 10;
    }
    if (n1 >= 0) { PushBackTo(0, arr1, size1); }
    else { PushBackTo(1, arr1, size1); }
    //reverse(arr1,size1);

    dev = 1;
    sum = from10ton(abs(n2));
    while (sum >= dev) {
        y = sum / dev % 10;
        PushBackTo(y, arr2, size2);
        dev *= 10;
    }
    if (n2 >= 0) { PushBackTo(0, arr2, size2); }
    else { PushBackTo(1, arr2, size2); }
    //reverse(arr2, size2);

    cout << "The Strict code of N1:\n";
    for (int i = size1 - 1; i >= 0; i--) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "The Strict code of N2:\n";
    for (int i = size2 - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";

    if ((n1 >= 0) && (n2 >= 0)) {
        PlusPlus( arr1, arr2, size1, size2);
    }
    else if ((n1 >= 0) && (n2 < 0) && (n1 >= abs(n2))) {
        PlusMinusModBlessThanA( arr1, arr2, size1, size2);
    }
    else if ((n1 < 0) && (n2 < 0))
    {
        MinusMinus(arr1, arr2, size1, size2);
    }
    else {
        PlusMinusModBMoreThanA( arr1, arr2, size1, size2);
    }
    delete[] arr1;
    delete[] arr2;
    return 0;
}