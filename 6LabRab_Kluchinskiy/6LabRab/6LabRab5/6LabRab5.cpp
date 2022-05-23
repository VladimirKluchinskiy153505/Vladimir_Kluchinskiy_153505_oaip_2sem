#pragma warning( disable : 4996)
#define ull unsigned long long int
#include <cmath>
#include <iostream>
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
void checkin(int&l, int&m,string &str1,string &str2) {
		string str,str01;
		getline(cin, str);
		int first = 0, second=str.find(' ',first+1);
		str01 = str.substr(first, second - first);
		l = atoi(str01.c_str());
		first = second;
		second= str.find(' ', first + 1);
		str01 = str.substr(first + 1, second - first - 1);
		m = atoi(str01.c_str());
		getline(cin, str1);
		getline(cin, str2);
	
}
ull fx(int x,int n,int m) {
	ull res = 1;
	if (n & 1)//if n is odd;
	{
		res = x;
	}
	while (true) {
		if (!n) { break; }//if n==0
		n >>= 1;
		x = (x * x) % m;
		if (n & 1) {
			res = (res * x) % m;
		}
	}
	return res;
}
int count(const int&l,const int&m,string&str1,string&str2) {
	int l1 = str1.length(), l2 = str2.length(), dif = l - (l1 + l2);
	if (dif >= 0) {
		
		return fx(26,dif,m)*2%m;
	}
	if ((l1 > l) || (l2 > l)) {
		return 0;
	}
	int num = -dif, amount = 0;
	if ((str1.substr(0, num)) == (str2.substr(l2 - num, num))) {
		amount++;
	}
	if ((str1.substr(l1-num,num)) == (str2.substr(0, num))) {
		amount++;
	}
	return amount;
}
void PushBackTo(int x, int*& ARR, int& SIZE) {
	SIZE++;
	ARR[SIZE - 1] = x;
}
int main()
{
	int n, l, m,size=0;
	cout << "Enter amount of Input\n";
	cin >> n;
	cin.ignore();
	int* answer = new int[n];
	for (int i = 0; i < n; i++) {
		string str1, str2;
		checkin(l, m, str1, str2);
		PushBackTo(count(l, m, str1, str2),answer,size);
	}
	cout << "\nAnswers are:\n";
	for (int i = 0; i < n; i++) {
		cout << answer[i] << "\n";
	}
	delete[] answer;
	return 0;
}