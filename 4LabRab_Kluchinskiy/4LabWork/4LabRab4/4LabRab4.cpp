#include <iostream>
#include <cmath>
using namespace std;
int getNatValue()
{
	while (true)
	{
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
double getDoubleValue()
{
	while (true)
	{
        double a;
		bool p = true;
		string str;
		cin >> str;
		bool counterpoint = (count(str.begin(), str.end(), '.') > 1);
		bool counterE = (count(str.begin(), str.end(), 'e') > 1);
		bool counterMinus = (count(str.begin(), str.end(), '-') > 2);

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '0' || str.at(i) == '-' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
				str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9' || str.at(i) == '.' || str.at(i) == 'e') || counterpoint || counterE || counterMinus)
			{
				p = false;
				cout << "Please try again.\n";
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (p)
		{
			a = atof(str.c_str());
			cin.ignore(32767, '\n');
			return a;
		}
	}
}
int main()
{
	int rows, cols,count=0;
	cout << "Enter amount of rows" << endl;
	rows = getNatValue();
	cout << "Enter amount of colums" << endl;
	cols = getNatValue();
	double **arr = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];
	}
	cout << "Fill array" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			arr[i][j]=getDoubleValue();
        }
		cout << endl;
	}
	cout << endl;
	if(rows==1 && cols==1)
	{
		cout << "One elment has no neighbors";
		return 0;
	}
	if (rows == 1) {
		if (cols == 2) {
			if (abs(arr[0][0] - arr[0][1]) != 0)
			{
				cout << 1; return 0;
			}
			else { cout << 0; return 0; }
		}
		for (int q = 1; q < cols - 1; q++)
		{
			if ((arr[0][q] < arr[0][q - 1]) && (arr[0][q] < arr[0][q + 1]))
			{
				count++;
			}
		}
		cout << count;
		return 0;
	}
	if (cols == 1) {
		if (rows == 2) {
			if (abs(arr[0][0] - arr[1][0]) != 0)
			{
				cout << 1; return 0;
			}
			else { cout << 0; return 0; }
		}
		for (int q = 1; q < rows - 1; q++)
		{
			if ((arr[q][0] < arr[q-1][0]) && (arr[q][0] < arr[q+1][0]))
			{
				count++;
			}
		}
		cout << count;
		return 0;
	}
	for (int i = 1; i < rows - 1; i++){//centr
        for (int j = 1; j < cols-1; j++){
			int dx[8] = { 0,-1,-1,-1,0,1,1,1};
			int dy[8] = { -1,-1,0,1,1,1,0,-1};
			for (int k = 0; k < 8; k++)
			{
				if (arr[i][j] >= arr[i + dy[k]][j+dx[k]])
				{
					break;
				}
				if (k == 7) { count++; }
			}
			
		}
	}
	          int i = 0;
		for (int j = 1; j < cols - 1; j++) {//up 
			int dx[5] = { -1,-1,0,1,1};
			int dy[5] = { 0,1,1,1,0};
			for (int k = 0; k < 5; k++)
			{
				if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
				{
					break;
				}
				if (k == 4) { count++; }
			}
        }
		i = rows-1;//down
		for (int j = 1; j < cols - 1; j++) {
			int dx[5] = {-1,-1,0,1,1};
			int dy[5] = {0,-1,-1,-1,0};
			for (int k = 0; k < 5; k++)
			{
				if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
				{
					break;
				}
				if (k == 4) { count++; }
			}
        }
		int j = 0;//left
		for (int i = 1; i < rows - 1; i++) {
			int dx[5] = { 0,1,1,1,0 };
			int dy[5] = { -1,-1,0,1,1 };
			for (int k = 0; k < 5; k++)
			{
				if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
				{
					break;
				}
				if (k == 4) { count++; }
			}
        }
		 j = cols-1;//right
		for (int i = 1; i < rows - 1; i++) {
			int dx[5] = { 0,-1,-1,-1,0 };
			int dy[5] = { -1,-1,0,1,1 };
			for (int k = 0; k < 5; k++)
			{
				if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
				{
					break;
				}
				if (k == 4) { count++; }
			}
		}
		i = 0; j = 0;//up left
		for (int k = 0; k < 3; k++)
		{
			int dx[3] = { 1,1,0 };
			int dy[3] = { 0,1,1};
			if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
			{
				break;
			}
			if (k == 2) { count++; }
		}
		i = 0; j = cols - 1;//up right
		for (int k = 0; k < 3; k++)
		{
			int dx[3] = { -1,-1,0 };
			int dy[3] = { 0,1,1 };
			if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
			{
				break;
			}
			if (k == 2) { count++; }
		}
		i = rows-1; j =cols-1;//down right
		for (int k = 0; k < 3; k++)
		{
			int dx[3] = {0,-1,-1 };
			int dy[3] = { -1,-1,0 };
			if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
			{
				break;
			}
			if (k == 2) { count++; }
		}
		i = rows - 1; j = 0;//down left
		for (int k = 0; k < 3; k++)
		{
			int dx[3] = { 0,1,1 };
			int dy[3] = { -1,-1,0 };
			if (arr[i][j] >= arr[i + dy[k]][j + dx[k]])
			{
				break;
			}
			if (k == 2) { count++; }
		}
		cout << count;
      for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}