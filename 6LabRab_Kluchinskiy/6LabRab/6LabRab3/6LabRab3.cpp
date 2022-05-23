#pragma warning( disable : 4996)
#include <iostream>
#include <cmath>
using namespace std;
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
void Find(char* &L, const int& SIZE,int*& num, int&sizenum) {
	for (int i = 0; i < SIZE; i++) {
		if (L[i] == '0' || L[i] == '1' || L[i] == '2' || L[i] == '3' || L[i] == '4' || L[i] == '5' || L[i] == '6' || L[i] == '7' || L[i] == '8' || L[i] == '9') {
			int x = (int)L[i]-(int)'0';
			PushBackTo(x, num, sizenum);
		}
	}
}
int main()
{
	int size = 0,sum=0;
	char* line = new char[255];
	int* num = new int [size];
	cout << "Enter line" << endl;
	cin.getline(line, 255, '\n');
	int l = strlen(line);
    char* newline = new char[l + 1];
	strcpy(newline, line);
	delete[] line;
    Find(newline, l + 1,num,size);
	cout << "Input Numbers:\n";
	for (int i = 0; i < size; i++) {
		cout << num[i] << " ";
	}
	for (int i = 0; i < size; i++) {
		sum += num[i] * pow(-1, i);
	}
	cout << "The sum is:\n" << sum;
	delete[] newline;
	return 0;
}