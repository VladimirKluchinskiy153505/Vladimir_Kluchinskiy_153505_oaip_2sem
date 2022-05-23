#define ull unsigned long long int
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int check(int& n) {
	string str;
	while (true) {
		getline(cin, str);
		n = atoi(str.c_str());
		if (n == 0) {
			return 0;
		}
		if (n<0) {
			cout << "Invalid output\n";
			continue;
		}
		else { return 1; };
	}
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
ull fx(int n) {
	if (n == 0) {
		return 0;
	}
	ull k = ((n + 1) / 2);
	return (k * k + fx(n / 2));
}
int main() {
	int n,size = 0;
	ull* arr = new ull[size];
	cout << "Enter N (1<N<10^9)\n";
	while (true)
	{
		if (check(n) == 0) {
			break;
		}
		ull sum = fx(n);
		
		PushBackTo(sum, arr, size);
	}
	cout << "\nOutput Data:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
	delete[] arr;
	return 0;
	
}