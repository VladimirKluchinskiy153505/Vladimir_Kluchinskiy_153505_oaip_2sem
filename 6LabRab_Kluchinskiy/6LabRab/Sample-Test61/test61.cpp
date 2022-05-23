#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
int getnum(string line,int p){
	int am = 1;

for (int i = 0; i < p; i++) {
	if (line[i] == char(32)) {
		am++;
	}
} 
return am;
}

TEST(Case1, Check) {

	EXPECT_EQ(getnum("9999 099 44412",12),3);
}
TEST(Case2, Check) {

	EXPECT_EQ(getnum("www wwww wwwww wwwwww",15),4);
}
TEST(Case3, Check) {

	EXPECT_EQ(getnum("qwe rty uio pas",10),3);
}
TEST(Case4, Check) {

	EXPECT_EQ(getnum("123 Aygyge 68y8FYTFY", 8), 2);
}
TEST(Case5, Check) {
	EXPECT_EQ(getnum(" rdtd 787787 -0-0-=0", 0), 1);
	
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}