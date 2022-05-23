#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void PushBackTo(long double x, long double*& ARR, int& SIZE) {
	long double* NewArr = new long double[SIZE + 1];
	for (int i = 0; i < SIZE; i++) {
		NewArr[i] = ARR[i];
	}
	NewArr[SIZE] = x;
	SIZE++;
	delete[]ARR;
	ARR = NewArr;
}
void getNumber(string &str,long double*&arr,int&size)
{
	int l = str.length(), i = 0;
	long double num;
	string str1;
		while(i<l)
		{
			if (isdigit(str[i])||(str[i]=='-')) {//начинаться может лишь с цифры либо -
				str1 = str[i];
				while (isdigit(str[i + 1]) || str[i + 1] == 'e' || str[i + 1] == '.' || str[i + 1] == '-') {

					if ((str[i + 1]=='e')&& (str1.find("e")!=-1)) {//если следующий равен e и оно уже есть, то переходим к следующему
						i++;
						break;
					}
					if ((str[i + 1] == '.') && (str1.find(".") != -1)) {//если следующий равен . и оно уже есть, то переходим к следующему
						i++;
						break;
					}
					if ((str[i+1]== '-')&&(str1[str1.size()-1]!='e')) {//если следующий равен - и он не перед e, то начинаем с него следующий
						break;
					}
					str1.push_back(str[i + 1]);
					i++;
				}
				num = stold(str1);
				PushBackTo(num, arr, size);
			}
			i++;
		}
}
int main()
{
	//setlocale(LC_ALL, "Russian");
	long double sum = 0;
	string str;
	int size = 0;
	long double* arr = new long double[size];
	cout << "Enter your line\n";
	getline(cin, str);
	getNumber(str,arr,size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		sum += arr[i];
	}
	cout << "The Sum is: " << sum;
	delete[] arr;
	return 0;
}