#include "pch.h" 
#include <iostream>
#include "MathLibrary.h"
using namespace std;
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

	for (int q = 0; q < sizei; q++)
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