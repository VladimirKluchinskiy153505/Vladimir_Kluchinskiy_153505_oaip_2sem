// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include<C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\New_String\New_String.cpp>
#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\My_Vec\My_Vec.cpp>
using namespace std;
bool div2(string str, int pos) {
    int x = str.size(), a = 0;
    int* arr = new int[str.size()];

    while (a != x) {
        arr[a] = str[a] - 48;
        a++;
    }
    int k = pos;
    size_t q = 0;
    size_t carry;
    while (k + 1) {
        carry = 0;
        for (int i = q; i < x; ++i) {
            size_t cur = arr[i] + carry * 10;
            arr[i] = (cur >> 1);
            carry = cur & 1;
        }
        for (int i = q; i < x; ++i) {
            cout << arr[i];
        }
        cout << "\n";
        --k;
        if (arr[q] == 0) {
            ++q;
        }
    }

    delete[] arr;
    return !carry;
}
void del(string str) {
    int x = str.size(), a = 0;
    int* arr = new int[x];

    while (a != x) {
        arr[a] = str[a] - 48;
        a++;
    }
    for (int i = 0; i < x; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';
    int carry = 0;
    for (int i = 0; i <x; ++i) {
        size_t cur = arr[i] + carry * 1ll * 10;
        arr[i] = cur / 2;
        carry = cur % 2;
        cout << carry << " ";
    }
    cout << '\n';
    for (int i = 0; i < x; ++i) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}
int main()
{
   /* MyString str = "geekforgeeks a computer science";
    const char* s2 = "Oleg";
    const char* s = "ced";
    cout << str.find("geeks") << '\n';
   cout << str.replace(0,1 , s2);*/
    cmatch result;
    regex regular("([\\w-]+)"
        "(@)"
        "([\\w-]+)"
        "(\.)"
        "([a-z]{2,5})");
    if (regex_search(str.c_str(), result, regular)) {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << '\n';
        }
    }

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
