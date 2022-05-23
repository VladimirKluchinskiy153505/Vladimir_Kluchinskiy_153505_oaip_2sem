#include "pch.h"
#include <gtest/gtest.h>
#define ull unsigned long long int
ull fx(int n) {
	if (n == 0) {
		return 0;
	}
	ull k = ((n + 1) / 2);
	return (k * k + fx(n / 2));
}
TEST(Case1, Check) {
	EXPECT_EQ(fx(7), 21);
}
TEST(Case2, Check) {
	EXPECT_EQ(fx(777), 201537);
}
TEST(Case3, Check) {
	EXPECT_EQ(fx(1000000), 333333339224);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}