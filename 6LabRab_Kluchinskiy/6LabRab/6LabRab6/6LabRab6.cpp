#pragma warning( disable : 4996)
#define ull unsigned long long int
#include <iostream>
#include <string>
using namespace std;
ull fact(int n) {
	if (n == 0) { return 1; }
	return n * fact(n - 1);
}
ull count(string str) {
	ull divisor = 1;
	int l = str.length();
	for (int i = 97; i <= 122; i++) {
		int am = count(str.begin(), str.end(), char(i));
		divisor *= fact(am);
	}
	return (fact(l) / divisor);
}
int main()
{
	string str;
	getline(cin, str);
	cout << "Amount of anagrams are:\n" << count(str);
	return 0;
}