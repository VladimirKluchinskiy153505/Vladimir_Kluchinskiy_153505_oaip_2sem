#include <iostream>
#include <cmath>
using namespace std;
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
int** squareOdd(int n) {

	int** arr = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	int w = 1;
	for (int i = (n - 1) / 2, j = 0; i <= n - 1, j <= (n - 1) / 2; i++, j++) { //Заполнение ромба
		for (int ii = i, jj = j; ii >= i - (n - 1) / 2, jj <= j + (n - 1) / 2; ii--, jj++) {
			arr[ii][jj] = w;
			w += 2;
		}
		if (i == n - 1) { break; }
		for (int ii = i, jj = j + 1; ii >= i - (n - 3) / 2, jj <= (j + 1) + (n - 3) / 2; ii--, jj++) {
			arr[ii][jj] = w;
			w += 2;
		}
	}

	int c = arr[(n - 1) / 2][(n - 1) / 2];

	////////
	//заполнение верхнего левого угла

	w = c + n;
	for (int j = 0; j < (n - 1) / 2; j++) {//заполнили строку и каждый столбец треугольника
		arr[0][j] = w;
		int y = w;
		for (int i = 0; i < (n - 1) / 2 - j; i++)
		{
			arr[i][j] = y;
			y += n - 1;//идём вниз
		}
		w += n + 1;//идём вправо
	}
	////////

	w = c - 1;//заполнение верхнего правого угла
	for (int j = n - 1; j > (n - 1) / 2; j--) {//заполнили строку и каждый столбец треугольника
		arr[0][j] = w;
		int y = w;
		for (int i = 0; i < (n - 1) / 2 - (n - 1) + j; i++)
		{
			arr[i][j] = y;
			y += n - 1;//идём вниз
		}
		w -= n + 1;//идём влево
	}
	///////
	w = c - n;       //заполнение нижнего правого угла
	for (int j = n - 1; j > (n - 1) / 2; j--) {//заполнили строку и каждый столбец треугольника
		arr[n - 1][j] = w;
		int y = w;
		for (int i = n - 1; i > (n - 1) / 2 + (n - 1) - j; i--)
		{
			arr[i][j] = y;
			y -= n - 1;//идём вверх
		}
		w -= n + 1;//идём влево
	}
	//////////
					 // заполнение нижнего левого угла
	w = c + 1;
	for (int j = 0; j < (n - 1) / 2; j++) { //заполнили строку и каждый столбец треугольника
		arr[n - 1][j] = w;
		int y = w;
		for (int i = n - 1; i > (n - 1) / 2 + j; i--)
		{
			arr[i][j] = y;
			y -= n - 1;//идём вверх
		}
		w += n + 1;//идём вправо
	}
	return(arr);
}
void square4(int n)
{
	int  i, j;
	int** arr = (int**)malloc(sizeof(int) * n);
	for (int k = 0; k < n; k++) {
		arr[k] = (int*)malloc(sizeof(int) * n);
	}

	for (i = 0; i < n; i++)//заполнили по порядку
		for (j = 0; j < n; j++)
			arr[i][j] = (n * i) + j + 1;

	for (i = 0; i < n / 4; i++)//поменяли элементы из левого верхнего с правым нижним
		for (j = 0; j < n / 4; j++)
			arr[i][j] = (n * n + 1) - arr[i][j];

	for (i = 0; i < n / 4; i++)//поменяли элементы из левого нижнего с правым нижним
		for (j = 3 * (n / 4); j < n; j++)
			arr[i][j] = (n * n + 1) - arr[i][j];

	for (i = 3 * n / 4; i < n; i++)//поменяли элементы из правого верхнего с левым нижним
		for (j = 0; j < n / 4; j++)
			arr[i][j] = (n * n + 1) - arr[i][j];

	for (i = 3 * n / 4; i < n; i++)//поменяли элементы из правого нижнего с левым верхним
		for (j = 3 * n / 4; j < n; j++)
			arr[i][j] = (n * n + 1) - arr[i][j];


	for (i = n / 4; i < 3 * n / 4; i++)// переворачиваем центр
		for (j = n / 4; j < 3 * n / 4; j++)
			arr[i][j] = (n * n + 1) - arr[i][j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << arr[i][j] << "\t ";
		cout << "\n" << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
void square2(int N) {
	int n = N / 2;
	int** qwe1 = squareOdd(n);//объявление подквадратов

	int** qwe2 = (int**)malloc(sizeof(int) * n);
	for (int k = 0; k < n; k++) {
		qwe2[k] = (int*)malloc(sizeof(int) * n);
	}

	int** qwe3 = (int**)malloc(sizeof(int) * n);
	for (int k = 0; k < n; k++) {
		qwe3[k] = (int*)malloc(sizeof(int) * n);
	}

	int** qwe4 = (int**)malloc(sizeof(int) * n);
	for (int k = 0; k < n; k++) {
		qwe4[k] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			qwe2[i][j] = qwe1[i][j] + n * n;
			qwe3[i][j] = qwe1[i][j] + 2 * n * n;
			qwe4[i][j] = qwe1[i][j] + 3 * n * n;
		}
	}
	//step 2//перемещение
   //swap 1 and 4
	int shC = (n - 1) / 2;
	for (int i = 0; i < shC; i++) {
		for (int j = 0; j < shC; j++) {
			swap(qwe1[i][j], qwe4[i][j]);
		}
	}
	for (int j = 1; j < shC + 1; j++) {
		swap(qwe1[shC][j], qwe4[shC][j]);
	}
	for (int i = shC + 1; i < n; i++) {
		for (int j = 0; j < shC; j++) {
			swap(qwe1[i][j], qwe4[i][j]);
		}
	}
	////
	///swap 3 and 2
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > n - shC; j--) {
			swap(qwe2[i][j], qwe3[i][j]);
		}
	}
	//step 3
	int** qwe = (int**)malloc(sizeof(int) * N);//объявление финального квадрата и заполнения
	for (int k = 0; k < N; k++) {
		qwe[k] = (int*)malloc(sizeof(int) * N);
	}
	//copy M1 to M
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			qwe[i][j] = qwe1[i][j];
		}
	}
	//copy M2 to M
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			qwe[i + n][j + n] = qwe2[i][j];
		}
	}
	//copy M3 to M
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			qwe[i][j + n] = qwe3[i][j];
		}
	}
	//copy M4 to M
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			qwe[i + n][j] = qwe4[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << qwe[i][j] << "\t";
		}
		cout << endl << endl;
	}
	//// удаление подквадратов и квадрата
	for (int i = 0; i < N; i++)
	{
		free(qwe[i]);
	}
	free(qwe);
	for (int i = 0; i < n; i++)
	{
		free(qwe1[i]);
	}
	free(qwe1);
	for (int i = 0; i < n; i++)
	{
		free(qwe2[i]);
	}
	free(qwe2);
	for (int i = 0; i < n; i++)
	{
		free(qwe3[i]);
	}
	free(qwe3);
	for (int i = 0; i < n; i++)
	{
		free(qwe4[i]);
	}
	free(qwe4);
}
int main()
{
	int n;
	cout << "Enter size of square" << endl;
	n = getIntegerValue();
	if ((n % 2) == 1)
	{
		int** Odd = squareOdd(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << Odd[i][j] << "\t";
			}
			cout << endl << endl;
		}
		for (int i = 0; i < n; i++) {
			free(Odd[i]);
		}
		free(Odd);
	}
	else if ((n % 4) == 0) {
		square4(n);
	}
	else {
		square2(n);
	}
	return 0;
}