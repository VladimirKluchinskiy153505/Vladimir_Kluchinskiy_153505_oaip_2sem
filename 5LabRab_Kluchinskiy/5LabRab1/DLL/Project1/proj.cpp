#include <iostream>
#include<Windows.h>
using namespace std;
int main() {
	HINSTANCE load;
	load = LoadLibrary(L"DLL.dll");
	typedef int(*getNatValue)();
	typedef void (*checkin)(double**, const int&, const int& );
	typedef void(*showArray2)(double** , int , int );
	typedef void(*transfer)(double** , int , int );
	typedef void(*PushBackTo)(int , int*&, int&);
	int n,k,sizei = 0, sizej = 0, am = 0;
	getNatValue getn;
	getn = (getNatValue)GetProcAddress(load, "getNatValue");

	checkin Check;
	Check = (checkin)GetProcAddress(load, "checkin");

	showArray2  show2;
	show2=(showArray2)GetProcAddress(load, "showArray2");

	transfer Trans;
	Trans=(transfer)GetProcAddress(load, "transfer");

	PushBackTo PushB;
	PushB=(PushBackTo)GetProcAddress(load, "PushBackTo");
	


	cout << "Enter N\n";
	n = getn();
	cout << "Enter K\n";
    k = getn();
	int* iii = new int[sizei];
	int* jjj = new int[sizej];
	double** arr = new double* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[k];
	}
	cout << "Fill Array\n";
	Check(arr, n, k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (arr[i][j] == 0) {
				PushB(i, iii, sizei);
				PushB(j, jjj, sizej);
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
	Trans(arr, n, k);
	cout << "Transfered matrix:\n";
	show2(arr, n, k);
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] iii;
	delete[] jjj;
	FreeLibrary(load);
	return 0;
}