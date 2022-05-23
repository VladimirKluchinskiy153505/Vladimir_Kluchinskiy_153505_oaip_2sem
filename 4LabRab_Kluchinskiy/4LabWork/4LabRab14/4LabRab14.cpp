#include <iostream>
#include <cmath>
#include <malloc.h>
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
int main()
{
	int n, m;
	cout << "Enter size of area N*M" << endl;
	cout << "Enter N" << endl;
	n = getNatValue();
	cout << "Enter M" << endl;
	m = getNatValue();
	int** arr = (int**)malloc(sizeof(int)*(n+2));//объявление матрицы ввода
	for (int i = 0; i < n+2; i++) {
		arr[i] = (int*)calloc((m+2),sizeof(int));//и заполнение её нулями
	}

	int** ans = (int**)malloc(sizeof(int) * (n + 2));//объявление матрицы вывода
	for (int i = 0; i < n+2; i++) {
		ans[i] = (int*)malloc(sizeof(int) * (m + 2));
	}

	//for (int i = 0; i < n+2; i++) {//заполнение 0 первой
	//   for (int j = 0; j < m+2; j++) {
	//			cout<<arr[i][j];
	//   }
	//	
	//}
	cout << "Mine = 1, non Mine = 0" << endl;//заполнение пользоваттелем
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
				cin >> arr[i][j];
		}
	}
	cout << endl;
	int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
	int dy[8] = { -1,-1,0,1,1,1,0,-1 };
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			int temp = 0;
			for (int k = 0; k < 8; k++) {
				temp += arr[i + dy[k]][j + dx[k]];
			}
			ans[i][j] = temp;
		}
	}
	/////
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr[i][j] == 1)
			{
				cout << "*"<<" ";
			}
			else {
				cout << ans[i][j]<<" ";
			}
		}
		cout << endl;
	}
	/////
	for (int i = 0; i < n+2; i++) {
		free(arr[i]);
	}
	 free(arr);
	for (int i = 0; i < n+2; i++) {
		free(ans[i]);
	}
	free(ans);
	return 0;
}