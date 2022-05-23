﻿#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int getNatValue()
{
	while(true)
	{
		//cout << "Enter matrix order" << endl;
		int n;
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
			n = atoi(str.c_str());
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
void checkin(int** Arr, const int& n, const int& k) {
	for (int q = 0; q < n; q++) {//строки
		string str;
		getline(cin, str);
		int first = -1, second;
		for (int i = 0; i < k; i++) {//cтолбы
			second = str.find(' ', first + 1);
			string str1 = str.substr(first + 1,second-first-1);
			Arr[q][i] = atoi(str1.c_str());
			first = second;
		}
	}
}
void showArray2(int** Arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";
	}
}
void showArray1(int* Arr, int rows) {
	for (int i = 0; i < rows; i++) {
		cout << Arr[i] << "\t";
	}
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
double findAver(int* Arr, int size) {
	double sum=0;
	for (int i = 0; i < size; i++) {
		sum += Arr[i];
	}
	return (sum / size);
}
int main() {
	int n, k,size=0;
	cout << "Enter N\n";
	n = getNatValue();
	cout << "Enter K\n";
	k = getNatValue();
	if (k == 1) { cout << "No elements"; return 0; }
	int* qwe = new int[size];
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[k];
	}
	cout << "Fill Array\n";
	checkin(arr, n, k);
	for (int j = 1; j < k; j += 2){
		for (int i = 0; i < n; i++) {

			if (arr[i][j] % 2) {
				PushBackTo(arr[i][j], qwe, size);
			}
		}
	}
	cout << "New array:\n";
	showArray1(qwe, size);
	cout << "The average of New array:";
	cout << findAver(qwe, size);
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[]qwe;
	return 0;
}