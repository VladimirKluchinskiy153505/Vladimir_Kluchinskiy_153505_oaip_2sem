// regex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\New_String\New_String.cpp>
#include<fstream>
#include <iostream>
#include <regex>
#include<string>
using namespace std;
int main()
{
	//regex_match
	ifstream fin;
	fin.open("Input.txt");
	if (!fin.is_open()) {
		cout <<"Output failed\n";
		return 0;
	}
	//MyString str = "email@holst.ru";
	cmatch result;
regex regular("(int|void|double)\\s+\w+\\(.*\\)");

	//regex regular("([\w])");
	//MyString str;
	while (!fin.eof()) {
		string str;
		getline(fin, str);
		if (regex_search(str.c_str(), result, regular)) {
			for (int i = 0; i < result.size(); ++i) {
				cout << result[i] << '\n';
			}
		}
		//cout << str << '\n';
	}
	//cout << str.c_str()<<'\n';
	
	
	fin.close();
	return 0;
}

