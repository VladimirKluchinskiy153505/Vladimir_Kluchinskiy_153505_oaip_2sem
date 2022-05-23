#include <iostream>
#include <string>
#include <chrono>
#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\My_Vec\My_Vec.cpp>
using namespace std;
size_t n;
size_t Count = 1;
void GetC(my_vec<string>& A, my_vec<string>& B, my_vec<string>& C) {
    size_t sizeC = C.size(), sizeA = A.size(), sizeB = B.size();
    C.clear();
    size_t S = sizeA + sizeB;
    C.resize(S);
    for (int i = 0; i < sizeA; i++) {
        C[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        C[sizeA + i] = B[i];
    }
}
bool div2(string& str, int& pos) {
    int x = str.size(), a = 0;
    int* arr = new int[x];

    while (a != x) {
        arr[a] = str[a] - 48;
        ++a;
    }
    size_t carry,q=0,k=pos+1;
    while (k) {
        carry = 0;
        for (int i = q; i < x; ++i) {
            size_t cur = arr[i] + carry * 10;
            arr[i] = cur >> 1;
            carry = cur & 1;
        }
        --k;
        if (!arr[q]) {
            ++q;
        }
    }
    delete[] arr;
    return !carry;
}
void rec(my_vec<string>& A, my_vec<string>& B, my_vec<string>& C) {
    int k = 1;

    while (true) {
        size_t Csize = C.size();
        for (int i = 0; i < Csize; ++i) {//получили элементы в А из Ск-1//преобзазуем в массив цифр
          
            if (div2(C[i], k)) {
                A.push_back(C[i]);
            }
        }
        C.clear();//после того как изъяли элементы из Ск-1 мы его очищаем
        size_t Asize = A.size();
        for (int i = 0; i < Asize; i++) {//получили элементы В из А 
            string b = "1";
            for (int i = 0; i < k; ++i) {
                b+='0';
               // b.push_back('0');
            }
            b.replace(b.size() - A[i].size(), A[i].size(), A[i]);
           // b = A[i];
            B.push_back(b);
            ++Count;
            //записали их в ответ
            if (Count == n) {
                cout << b;
                return;
            }
        }
        GetC(A, B, C);//получили новый С
        ++k;
        B.clear(); A.clear();
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cout << "Enter N\n";
    cin >> n;
    if (n == 1) { std::cout << 1; return 0; }
    auto start = std::chrono::high_resolution_clock::now();
    my_vec<string> A;
    my_vec<string> B;
    my_vec<string> C(2);
    C[0] = "0"; C[1] = "1";
    rec(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    cout << '\n' << duration.count();
    return 0;
}