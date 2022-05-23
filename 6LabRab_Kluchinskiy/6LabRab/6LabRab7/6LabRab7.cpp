#pragma warning( disable : 4996)
#include <iostream>
#include <string>
using namespace std;
 int search(string str) {
	 int l = str.length(),bound;
	 string str1;
	 for (int i = l; i >= 1; i--) {//меняем длину гусеницы от L до 1
		 for (int j = 0; j <= l - i; j++) {//пробегаем по всем точкам старта
			 str1 = str.substr(j,i);
			 bound=(i / 2) - 1;
			 for (int p = 0; p <= bound; p++) {
				 if (str1[p] != str1[i - 1 - p]) {
					 return i;
				 }
			 }
		 }
	 }
	 return-1;
 }
int main()
{
	setlocale(LC_ALL,"Russian");
	string str;
	cout << "Enter your line\n";
	getline(cin, str);
	cout << "Length of the largest non-palindrome is \n" << search(str);
	return 0;
}