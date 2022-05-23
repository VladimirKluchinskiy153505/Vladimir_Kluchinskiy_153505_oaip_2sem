#include <iostream>
using namespace std;
int n;
void PushBackToString888(string x, string*& ARR, int& SIZE) {
    string* NewArr = new string[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
void PushBackToString(string x, string*& ARR, int& SIZE) {
    ARR[SIZE] = x;
    SIZE++;
}
void PushBackToInt(int x, int*& ARR, int& SIZE) {
    ARR[SIZE] = x;
    SIZE++;
}
void GetC(string*& A, string*& B, string*& C, int& sizeA, int& sizeB, int& sizeC) {
    delete[]C;
    int S = sizeA + sizeB;
    string* NewArr = new string[S];
    for (int i = 0; i < sizeA; i++) {
        NewArr[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        NewArr[sizeA + i] = B[i];
    }
    sizeC = S;
    C = NewArr;
}
void Clean(string*& ARR, int& SIZE) {
    delete[] ARR;
    SIZE = 0;
    string* NewArr = new string[10000];
    ARR = NewArr;
}
int* GetBigInteger(string str)
{
    int x = str.size(), a = 0;
    int* arr = new int[str.size()];

    while (a != x) {
        arr[a] = str[a] - '0';
        a++;
    }

    return arr;
}
bool BitShift(int* val, int i) {
    if (val[i] == 0) {
        return true;
    }
    else {
        return false;
    }
}
void divisor(int* arr, int size, int b, int*& val, int& size1, int i) {
    int k = i;
    while (k+1) {
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            long long cur = arr[i] + carry * 10;
            arr[i] = int(cur / b);
            carry = int(cur % b);
        }
        k--;
        PushBackToInt(carry, val, size1);
    }
}

void rec(string*& A, string*& B, string*& C, string*& Answer, int& sizeA, int& sizeB, int& sizeC, int& sizeAnswer) {
    int k = 1; bool flag = false;
    while (true) {
        for (int i = 0; i < sizeC; i++) {//получили элементы в А из Ск-1
            int* arrC = GetBigInteger(C[i]);
            int size = C[i].size();
            int* val = new int[550];
            int sizeval = 0;

            divisor(arrC, size, 2, val, sizeval, k);
            if (BitShift(val,k)) {
                PushBackToString(C[i], A, sizeA);
            }
            delete[] arrC;
            delete[] val;
        }
        Clean(C, sizeC);//после того как изъяли элементы из Ск-1 мы его очищаем
        for (int i = 0; i < sizeA; i++) {//получили элементы В из А 
            string b = "1";
            for (int i = 0; i < k; i++) {
                b.push_back('0');
            }
            b.replace(b.size() - A[i].size(), A[i].size(), A[i]);
            PushBackToString(b, B, sizeB);
            PushBackToString(b, Answer, sizeAnswer);//записали их в ответ
            if (sizeAnswer == n) { flag = true; break; }
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
    cin >> n;
    string* A = new string[10000];
    string* B = new string[10000];
    string* C = new string[sizeC];
    C[0] = '0'; C[1] = '1';
    string* Answer = new string[10000];
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
