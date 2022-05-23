#include <iostream>
#include <cmath>
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
int getIntegerValue()
{
	while (true)
	{
		//cout << "Enter integer value" << endl;
		int n;
		bool p = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '-' || str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
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
			return n;
		}
	}
}
int main()
{
	cout << "Enter N,M (size of the first array[N][M])" << endl;
	int N = getNatValue();
	int M = getNatValue();
	cout << "Enter K (size of the second array[M][K])" << endl;
	int K = getNatValue();

	int** arr = (int**)malloc(sizeof(int)*N);// first array N*M
	for (int i = 0; i < N; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*M);
	}
	cout << "Fill The first array" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = getIntegerValue();
		}
	}
	cout << endl;
	//////
    int** secondArr = (int**)malloc(sizeof(int) * M);//second array M*K
	for (int i = 0; i < M; i++)
	{
		secondArr[i] = (int*)malloc(sizeof(int) * K);
	}
	cout << "Fill The second array" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			secondArr[i][j] = getIntegerValue();
		}
	}
	cout << endl;
	/////
	cout << "The third array" << endl;
	int** thirdArr = (int**)malloc(sizeof(int) * N);//third arr N*K
	for (int i = 0; i < N; i++)
	{
		thirdArr[i] = (int*)malloc(sizeof(int) * K);
	}
	/////
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += arr[i][j] * secondArr[j][k];
			}
			thirdArr[i][k] = sum;
		}
			
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			cout << thirdArr[i][k] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++)// delete first array N*M
	{
		free(arr[i]);
	}
	free(arr);

	for (int i = 0; i < M; i++)//delete second array M*K
	{
		free(secondArr[i]);
	}
	 free(secondArr);

	for(int i=0;i<N;i++)//delete third array M*K
	{
		free(thirdArr[i]);
	}
	free(thirdArr);
    return 0;
}