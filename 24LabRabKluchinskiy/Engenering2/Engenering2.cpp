#include <iostream>
#include <string>
#include <chrono>
#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\My_Vec\My_Vec.cpp>
#define Shi short int;
using namespace std;
size_t n;
size_t Count = 1;
void GetC(my_vec<my_vec<short int>>& A, my_vec<my_vec<short int>>& B, my_vec<my_vec<short int>>& C) {
    size_t sizeC = C.size(), sizeA = A.size(), sizeB = B.size();
    C.clear2();
    size_t S = sizeA + sizeB;
    C.resize(S);
    for (int i = 0; i < sizeA; i++) {
        C[i] =A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        C[sizeA + i] = B[i];
    }
}

bool div2(my_vec<short int>& arr, int pos) {
    int x = arr.size();
    int k = pos;
    size_t carry;
    while (k + 1) {
        carry = 0;
        for (int i = 0; i < x; ++i) {
            size_t cur = arr[i] + carry * 10;
            arr[i] = (cur / 2);
            carry = cur % 2;
        }
        --k;
    }
    return !carry;
}
void rec(my_vec<my_vec<short int>>& A, my_vec<my_vec<short int>>& B, my_vec<my_vec<short int>>& C) {
    int k = 1;
    while (true) {
        for (int i = 0; i < C.size(); ++i) {//получили элементы в А из Ск-1//преобзазуем в массив цифр
            my_vec<short int>copyC;
            copyC= C[i];
           /* for (auto& now : copyC) {
                cout << now;
            }
            cout << '\n';*/
           if (div2(copyC, k)) {
                A.emplace_back(std::move(C[i]));
            }
        }
     /*   for (auto& now : A) {
            for (auto& sec : now) {
                cout << sec;
            }
            cout << '\n';
          }*/
        C.clear2();//после того как изъяли элементы из Ск-1 мы его очищаем
        for (int i = 0; i < A.size(); i++) {//получили элементы В из А 
            my_vec<short int> b;
            b.push_back(1);
            for (int i = 0; i < k; i++) {
                b.push_back(0);
            }
            size_t Alast= A[i].size()-1;
            for (int j =0; j <=Alast; ++j) {
                b[k - j] = b[k - j] | A[i][Alast - j];
            }
            // b = A[i];

            B.emplace_back(std::move(b));

            ++Count;
            //записали их в ответ
            if (Count == n) {//если досчитали, то выводим и выходим
                //cout << "finish\n";
                for (auto now : b) {
                    cout <<now;
                }
                return;
            }
        }
        GetC(A, B, C);//получили новый С
     /*   cout << '\n';
        for (auto& now : C) {
            for (auto& sec : now) {
                cout << sec << " ";
            }
            cout << '\n';
        }
        cout << '\n';*/
        ++k;
        B.clear(); A.clear();
    }
}
int main()
{
    cout << "Enter N\n";
    cin >> n;
    if (n == 1) { cout << 1; return 0; }
    auto start = chrono::high_resolution_clock::now();
    my_vec< my_vec<short int>> A;
    my_vec<my_vec<short int>> B;
    my_vec<my_vec<short int>> C(2);
    C[0].push_back(0); C[1].push_back(1);
    rec(A, B, C);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << '\n' << duration.count();
    return 0;
}