#include "pch.h"
#include <gtest/gtest.h>
int fx(int n) {
	if ((n % 10) > 0)
	{
		return (n % 10);
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return fx(n / 10);
	}
}
TEST(Case1, Check) {
	EXPECT_EQ(fx(80), 8);
}
TEST(Case2, Check) {
	EXPECT_EQ(fx(123), 3);
}
TEST(Case3, Check) {
	EXPECT_EQ(fx(0), 0);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}