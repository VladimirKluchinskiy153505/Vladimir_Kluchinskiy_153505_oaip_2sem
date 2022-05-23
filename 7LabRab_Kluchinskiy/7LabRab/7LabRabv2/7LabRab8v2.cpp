#include <iostream>
#define ull unsigned long long int
using namespace std;
ull degree(ull x, int n) {
    if (n == 1) { return x; }
    ull res;
    res = degree(x, n >> 1);
    if (n & 1) { return res * res * x; }
    else { return res * res; }
}
void PushBackTo(ull x, ull*& ARR, int& SIZE) {
    ull* NewArr = new ull[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
void PushBackTo111(ull x, ull*& ARR, int& SIZE) {
    ARR[SIZE] = x;
    SIZE++;
}
void GetC(ull*& A, ull*& B, ull*& C, int& sizeA, int& sizeB, int& sizeC) {
    delete[]C;
    int S = sizeA + sizeB;
    ull* NewArr = new ull[S];
    for (int i = 0; i < sizeA; i++) {
        NewArr[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        NewArr[sizeA + i] = B[i];
    }
    sizeC = S;
    C = NewArr;
}

void Clean(ull*& ARR, int& SIZE) {
    delete[] ARR;
    SIZE = 0;
    ull* NewArr = new ull[SIZE];
    ARR = NewArr;
}

void rec(ull*& A, ull*& B, ull*& C, ull*& Answer, int& sizeA, int& sizeB, int& sizeC, int& sizeAnswer) {
    int k = 1; bool flag = false;
    while (true) {
        for (int i = 0; i < sizeC; i++) {//получили элементы в А из Ск-1
            if (!((C[i] >> k) & 1)) {
                PushBackTo(C[i], A, sizeA);
            }
        }
        Clean(C, sizeC);//после того как изъяли элементы из Ск-1 мы его очищаем
        for (int i = 0; i < sizeA; i++) {//получили элементы В из А 
            ull b = A[i] + degree(10, k);
            PushBackTo(b, B, sizeB);
            PushBackTo111(b, Answer, sizeAnswer);//записали их в ответ
            if (sizeAnswer == 363) { flag = true; break; }
        }
        if (flag) { break; }
        GetC(A, B, C, sizeA, sizeB, sizeC);//получили новый С

        k++;
        Clean(B, sizeB); Clean(A, sizeA);
    }
}
int main()
{
    int sizeA = 0, sizeB = 0, sizeC = 2, sizeAnswer = 1;
    ull* A = new ull[sizeA];
    ull* B = new ull[sizeB];
    ull* C = new ull[sizeC];
    C[0] = 0; C[1] = 1;
    ull* Answer = new ull[1000];
    Answer[0] = 1;
    rec(A, B, C, Answer, sizeA, sizeB, sizeC, sizeAnswer);
    for (int i = 0; i < sizeAnswer; i++) {
        cout << i + 1 << " " << Answer[i] << "\n\n";
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] Answer;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
