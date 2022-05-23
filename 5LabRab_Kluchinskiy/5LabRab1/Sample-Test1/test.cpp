#include "pch.h"
#include <gtest/gtest.h>
double countArrayZ(double X, double Y,int k) {
	double m;
		if (abs(sin(k + 1)) <= 0.2) {
			m = k + 1;
		}
		else if ((0.2 <= abs(sin(k + 1))) && (abs(sin(k + 1)) < 0.9))
		{
			m = sqrt(k + 1);
		}
		else {
			m = sqrt(sqrt(k + 1));
		}
		return (X+ m *Y);
}

TEST(Case1, Check) {

	EXPECT_EQ(countArrayZ(1,2,0), 3);
}
TEST(Case2, Check) {

	EXPECT_NEAR(countArrayZ(3, 4, 1), 7.756,0.01);
}
TEST(Case3, Check) {

EXPECT_EQ(countArrayZ(5, 6, 2), 23);
}
TEST(Case4, Check) {

	EXPECT_EQ(countArrayZ(7, 8, 3), 23);
}
TEST(Case5, Check) {

	EXPECT_NEAR(countArrayZ(9, 10, 4), 23.95,0.01);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}