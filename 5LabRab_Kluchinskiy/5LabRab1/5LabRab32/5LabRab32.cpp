#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int getNatValue()
{
	while (true)
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
void checkin(double** Arr, const int& n, const int& k) {
	for (int q = 0; q < n; q++) {//строки
		string str;
		getline(cin, str);
		int first = -1, second;
		for (int i = 0; i < k; i++) {//cтолбы
			second = str.find(' ', first + 1);
			string str1 = str.substr(first + 1, second - first - 1);
			Arr[q][i] = atof(str1.c_str());
			first = second;
		}
	}
}
void showArray2(double** Arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";
	}
}
void transfer(double** Arr, int n, int k) {
	int i1 = n / 2 - 1;
	int j1 = k / 2 - 1;
	for (int i = 0; i <= i1; i++) {
		for (int j = 0; j < k; j++) {
			swap(Arr[i][j], Arr[n - 1 - i][k - 1 - j]);
		}
	}if (n % 2) {
		for (int j = 0; j <= j1; j++) {
			swap(Arr[i1 + 1][j], Arr[i1 + 1][k - 1 - j]);
		}
	}
}
void PushBackTo(int x, int*& ARR, int& SIZE) {
	int* NewArr = new int[SIZE+1];
	for (int i = 0; i < SIZE; i++) {
		NewArr[i] = ARR[i];
	}
	NewArr[SIZE] = x;
	SIZE++;
	delete[]ARR;
	ARR = NewArr;
}
int main() {
	int n, k, sizei = 0, sizej = 0, am = 0;
	cout << "Enter N\n";
	n = getNatValue();
	cout << "Enter K\n";
	k = getNatValue();
	int* iii = new int[sizei];
	int* jjj = new int[sizej];
	double** arr = new double* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new double[k];
		}
		cout << "Fill Array\n";
		checkin(arr, n, k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if (arr[i][j] == 0) {
					PushBackTo(i, iii, sizei);
					PushBackTo(j, jjj, sizej);
					am++;
				}
			}
		}
		cout << "\n";
		cout << "Amount of nulls :" << am << "\n";
		cout << "Null elements are:\n";

		for (int q = 0; q < sizei;q++) 
		{
			cout << "[" << iii[q] << "][" << jjj[q] << "]\t";
		}
		cout << "\n";
		transfer(arr, n, k);
		cout << "Transfered matrix:\n";
		showArray2(arr, n, k);
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		delete[] iii;
		delete[] jjj;
	return 0;
}