#define ull unsigned long long int
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
ull n, k, m;
int t;
int check(ull& k,ull& n,int&t) {
	int numspace1,numspace2;
	string str, strk, strn,strt;
	while (true) {
		getline(cin, str);
		numspace1 = str.find(char(32));
		numspace2 = str.find(char(32),numspace1+1);
		strk = str.substr(0, numspace1);
		strn = str.substr(numspace1 + 1, numspace2 - numspace1-1);
		strt = str.substr(numspace2 + 1, str.length() - numspace2);
		k = strtoull(strk.c_str(),NULL,10);
		n = strtoull(strn.c_str(),NULL,10);
		t = atoi(strt.c_str());
		if ((k== 0) && (n== 0)&&(t==0)) {
			return 0;
		}
		if (!( (0<k)&&(k<10000000000000000000)&& (0 < n) && (n < 10000000000000000000) && (0 < t) && (t < 10))   ) {
			cout << "Invalid output\n";
			continue;
		}
		else { return 1; };
	}
}
void PushBackTo(ull x,ull*& ARR, int& SIZE) {
	ull* NewArr = new ull[SIZE + 1];
	for (int i = 0; i < SIZE; i++) {
		NewArr[i] = ARR[i];
	}
	NewArr[SIZE] = x;
	SIZE++;
	delete[]ARR;
	ARR = NewArr;
}
ull fx( ) {
	ull res= 1;
	if(n&1)//if n is odd;
	{res = k;}
	while (true) {
		if (!n) {break;}//if n==0
		n >>= 1;
		k = (k * k) % m;
		if (n & 1) {
			res = (res * k) % m;
		}
	}
return res;
}
int main() {
	int size = 0;
	ull* arr = new ull[size];
	cout << "Enter K (0<K<10^19) and N (0<N<10^19) and T (0<T<10)\n";
	while (true)
	{
		if (check(k, n,t) == 0) {
			break;
		}
		m = pow(10, t);
		PushBackTo(fx(), arr, size);
	}
	cout << "\nOutput Data:\n";
	for (int i = 0; i < size; i++)
	{
		cout <<"Case #"<<i+1 <<": " << arr[i] << "\n";
	}
	delete[] arr;
	return 0;
}