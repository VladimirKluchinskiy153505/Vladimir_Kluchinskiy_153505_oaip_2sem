#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
long double getNumber(string& str)
{
	int l = str.length(), i = 0;
	long double num;
	string str1;
	while (i < l)
	{
		if (isdigit(str[i]) || (str[i] == '-')) {//начинаться может лишь с цифры либо -
			str1 = str[i];
			while (isdigit(str[i + 1]) || str[i + 1] == 'e' || str[i + 1] == '.' || str[i + 1] == '-') {

				if ((str[i + 1] == 'e') && (str1.find("e") != -1)) {//если следующий равен e и оно уже есть, то переходим к следующему
					i++;
					break;
				}
				if ((str[i + 1] == '.') && (str1.find(".") != -1)) {//если следующий равен . и оно уже есть, то переходим к следующему
					i++;
					break;
				}
				if ((str[i + 1] == '-') && (str1[str1.size() - 1] != 'e')) {//если следующий равен - и он не перед e, то начинаем с него следующий
					break;
				}
				str1.push_back(str[i + 1]);
				i++;
			}
			num = stold(str1);
		}
		i++;
	}
	return num;
}
TEST(Case1, Check) {
	string str1 = "-2e-3";
	long double a = getNumber(str1);
	EXPECT_EQ(a, -0.002);
}
TEST(Case2, Check) {
	string str1 = "-2.5e-3";
	long double a = getNumber(str1);
	EXPECT_EQ(a, -0.0025);
}
TEST(Case3, Check) {
	string str1 = "e3e3ee";
	long double a = getNumber(str1);
	EXPECT_EQ(a, 3000);
}
TEST(Case4, Check) {
	string str1 = "3e2";
	long double a = getNumber(str1);
	EXPECT_EQ(a, 300);
}
TEST(Case5, Check) {
	string str1 = "5.369.eee";
	long double a = getNumber(str1);
	EXPECT_EQ(a, 5.369);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}