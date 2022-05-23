#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#define ull unsigned long long int
using namespace std;
ull fact(int n) {
	if (n == 0) { return 1; }
	return n * fact(n - 1);
}
ull Count(string str) {
	ull divisor = 1;
	int l = str.length();
	for (int i = 97; i <= 122; i++) {
		int am = count(str.begin(), str.end(), char(i));
		divisor *= fact(am);
	}
	return (fact(l) / divisor);
}

TEST(Case1, Check) {
	string str = "matematica";
	ull count = Count(str);
	EXPECT_EQ(count, 151200);
}
TEST(Case2, Check) {
	string str = "redividerdetartrated";
	ull count = Count(str);
	EXPECT_EQ(count, 7332965640000);
}
TEST(Case3, Check) {
	string str = "testset";
	ull count = Count(str);
	EXPECT_EQ(count,210);
}
TEST(Case4, Check) {
	string str = "wassamassaw";
	ull count = Count(str);
	EXPECT_EQ(count, 34650);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}