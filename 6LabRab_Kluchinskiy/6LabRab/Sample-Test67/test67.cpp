#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#define ull unsigned long long int
using namespace std;
int search(string str) {
	int l = str.length(), bound;
	string str1;
	for (int i = l; i >= 1; i--) {//меняем длину гусеницы от L до 1
		for (int j = 0; j <= l - i; j++) {//пробегаем по всем точкам старта
			str1 = str.substr(j, i);
			bound = (i / 2) - 1;
			for (int p = 0; p <= bound; p++) {
				if (str1[p] != str1[i - 1 - p]) {
					return i;
				}
			}
		}
	}
	return-1;
}

TEST(Case1, Check) {
	string str = "alala";
	int l = search(str);
	EXPECT_EQ(l, 4);
}
TEST(Case2, Check) {
	string str = "aaaaaaaa";
	int l = search(str);
	EXPECT_EQ(l, -1);
}
TEST(Case3, Check) {
	string str = "repaper";
	int l = search(str);
	EXPECT_EQ(l, 6);
}
TEST(Case4, Check) {
	string str = "wwqwwqww";
	int l = search(str);
	EXPECT_EQ(l, 7);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}