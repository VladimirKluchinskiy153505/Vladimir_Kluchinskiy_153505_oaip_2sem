#include "pch.h"
#include <gtest/gtest.h>
#define ull unsigned long long int
ull fx(ull k,ull n,ull m) {
	ull res = 1;
	if (n & 1)//if n is odd;
	{
		res = k;
	}
	while (true) {
		if (!n) { break; }//if n==0
		n >>= 1;
		k = (k * k) % m;
		if (n & 1) {
			res = (res * k) % m;
		}
	}
	return res;
}
TEST(Case1, Check) {
	EXPECT_EQ(fx(1234,1234,pow(10,4)), 736);
}
TEST(Case2, Check) {
	EXPECT_EQ(fx(2323,99999999999,pow(10,8)), 39087387);
}
TEST(Case3, Check) {
	EXPECT_EQ(fx(888,888,pow(10,8)), 91255296);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}