#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#define ull unsigned long long int
using namespace std;
ull fx(int x, int n, int m) {
	ull res = 1;
	if (n & 1)//if n is odd;
	{
		res = x;
	}
	while (true) {
		if (!n) { break; }//if n==0
		n >>= 1;
		x = (x * x) % m;
		if (n & 1) {
			res = (res * x) % m;
		}
	}
	return res;
}
int Count(const int& l, int& m, string& str1, string& str2) {
	int l1 = str1.length(), l2 = str2.length(), dif = l - (l1 + l2);
	if (dif >= 0) {

		return (fx(26, dif, m) * 2)%m;
	}
	if ((l1 > l) || (l2 > l)) {
		return 0;
	}
	int num = -dif, amount = 0;
	if ((str1.substr(0, num)) == (str2.substr(l2 - num, num))) {
		amount++;
	}
	if ((str1.substr(l1 - num, num)) == (str2.substr(0, num))) {
		amount++;
	}
	return amount;
}

TEST(Case1, Check) {
	int l=50, m=200,count;
	string str1="Vector", str2="Class";
	count = Count(l, m, str1, str2);
	EXPECT_EQ(count, 152);
}
TEST(Case2, Check) {
	int l = 1000000000, m = 10000, count;
	string str1 = "success", str2 = "chess";
	count = Count(l, m, str1, str2);
	EXPECT_EQ(count, 3152);
}
TEST(Case3, Check) {
	int l = 1000000000, m = 10000, count;
	string str1 = "Mathematics", str2 = "CMath";
	count = Count(l, m, str1, str2);
	EXPECT_EQ(count, 7952);
}
TEST(Case4, Check) {
	int l = 999, m = 5000, count;
	string str1 = "111222", str2 = "222111";
	count = Count(l, m, str1, str2);
	EXPECT_EQ(count, 4352);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}