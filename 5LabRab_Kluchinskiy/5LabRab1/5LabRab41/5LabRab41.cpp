#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int check(int &p,int &q) {
	int numspace;
	string str,strp,strq;
	while (true) {
		getline(cin, str);
		numspace = str.find(char(32));
		strp = str.substr(0, numspace);
		strq = str.substr(numspace + 1, str.length() - numspace);
		p = atoi(strp.c_str());
		q = atoi(strq.c_str());
		if ((p < 0) && (q < 0)) {
			return 0;
		}
		if ((p < 0) || (q < 0)||(p>q)) {
			cout << "Invalid output\n";
			continue;
		}
		else { return 1; };
		
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
int fx(int n) {
	if((n%10)>0)
	{
		return (n % 10);
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return fx(n / 10);
	}
}
int main() {
	int p, q,size=0;
	int* arr = new int[size];
	cout << "Enter P and Q (P<=Q)\n";
	while (true)
	{
		if (check(p, q) == 0) {
			break;
		}
		int sum = 0;
		for (int i = p; i <= q; i++) {
			sum += fx(i);
		}
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