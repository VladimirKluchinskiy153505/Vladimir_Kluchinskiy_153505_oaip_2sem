#include <iostream>
#include "..\LIB33\Header33.h"
using namespace std;
int main() {
	int n, k, size = 0;
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
	for (int j = 1; j < k; j += 2) {
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

