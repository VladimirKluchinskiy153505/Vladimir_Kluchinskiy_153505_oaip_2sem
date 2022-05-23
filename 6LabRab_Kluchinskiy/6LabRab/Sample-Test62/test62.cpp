#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
string Print(char* L,  int SIZE) {
	int i = 0, first = 0, second = 0; string str;
	while (i != SIZE) {
		while (true) {//нашли пробел или конец стоки
			if ((L[i] == char(32)) || (i == SIZE-1)) {
				second = i;
				break;
			}
			i++;
		}// проверяем слово между first and second
		if (!(L[first] == 'e' || L[first] == 'E' || L[first] == 'y' || L[first] == 'Y' || L[first] == 'u' || L[first] == 'U' || L[first] == 'i' || L[first] == 'I' || L[first] == 'o' || L[first] == 'O' || L[first] == 'a' || L[first] == 'A')) {
			first = second + 1;
		}
		else {
			if (L[second - 1] == 'e' || L[second - 1] == 'E' || L[second - 1] == 'y' || L[second - 1] == 'Y' || L[second - 1] == 'u' || L[second - 1] == 'U' || L[second - 1] == 'i' || L[second - 1] == 'I' || L[second - 1] == 'o' || L[second - 1] == 'O' || L[second - 1] == 'a' || L[second - 1] == 'A') {
				for (int j = first; j < second; j++) {
					str.push_back(L[j]);
				}
				str.push_back(char(32));
			}
			first = second + 1;
		}
		i++;
	}
	str.pop_back();
	return str;
}


TEST(Case1, Check) {
	char line[] = "apple bridge ugly";
	int l = sizeof(line) / sizeof(char);
	string str1 = "apple ugly", str2 = Print(line, l);
	EXPECT_EQ(str1, str2);
}
TEST(Case2, Check) {
	char line[] = "1army army2 army Army arMY";
	int l = sizeof(line) / sizeof(char);
	string str1 = "army Army arMY", str2 = Print(line, l);
	EXPECT_EQ(str1, str2);
}
TEST(Case3, Check) {
	char line[] = "0angry ANGRY A Y ANGRYqwe";
	int l = sizeof(line) / sizeof(char);
	string str1 = "ANGRY A Y ANGRYqwe", str2 = Print(line, l);
	EXPECT_EQ(str1, str2);
}
TEST(Case4, Check) {
	char line[] = "tfuyygu r5 esese4 9u877yg sse itmo rz4ez";
	int l = sizeof(line) / sizeof(char);
	string str1 = "itmo", str2 = Print(line, l);
	EXPECT_EQ(str1, str2);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}