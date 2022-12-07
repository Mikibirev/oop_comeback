// cделано Кибиревым Михаилом из ВМК-20
#include "..\CommonFraction.h"
#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// dсе тесты проводятся для следующих значений:
// 1) 8/16, 4/10;
// 2) 4/9, 8/20;
// 3) 5/6, 9/14;
TEST(TestCommonFraction, Return_Add) {									// тест сложения дробей
	{
		CommonFraction a(8, 16), b(4, 10), c = a.add_frac(b);
		EXPECT_EQ(c.get_num(), 9);
		EXPECT_EQ(c.get_dnom(), 10);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.add_frac(b);
		EXPECT_EQ(c.get_num(), 38);
		EXPECT_EQ(c.get_dnom(), 45);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.add_frac(b);
		EXPECT_EQ(c.get_num(), 31);
		EXPECT_EQ(c.get_dnom(), 21);
	}
}

TEST(TestCommonFraction, Return_Sub) {									// тест вычитания дробей
	{
		CommonFraction a(8, 16), b(4, 10), c = a.sub_frac(b);
		EXPECT_EQ(c.get_num(), 1);
		EXPECT_EQ(c.get_dnom(), 10);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.sub_frac(b);
		EXPECT_EQ(c.get_num(), 2);
		EXPECT_EQ(c.get_dnom(), 45);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.sub_frac(b);
		EXPECT_EQ(c.get_num(), 4);
		EXPECT_EQ(c.get_dnom(), 21);
	}
}

TEST(TestCommonFraction, Return_Mul) {									// тест умножения дробей
	{
		CommonFraction a(8, 16), b(4, 10), c = a.mul_frac(b);
		EXPECT_EQ(c.get_num(), 1);
		EXPECT_EQ(c.get_dnom(), 5);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.mul_frac(b);
		EXPECT_EQ(c.get_num(), 8);
		EXPECT_EQ(c.get_dnom(), 45);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.mul_frac(b);
		EXPECT_EQ(c.get_num(), 15);
		EXPECT_EQ(c.get_dnom(), 28);
	}
}

TEST(TestCommonFraction, Return_Div) {									// тест деления дробей
	{
		CommonFraction a(8, 16), b(4, 10), c = a.div_frac(b);
		EXPECT_EQ(c.get_num(), 5);
		EXPECT_EQ(c.get_dnom(), 4);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.div_frac(b);
		EXPECT_EQ(c.get_num(), 10);
		EXPECT_EQ(c.get_dnom(), 9);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.div_frac(b);
		EXPECT_EQ(c.get_num(), 35);
		EXPECT_EQ(c.get_dnom(), 27);
	}
}

TEST(TestCommonFraction, Return_More) {									// тест сравнения и возврата большего
	{
		CommonFraction a(8, 16), b(4, 10), c = a.return_more(b);
		EXPECT_EQ(c.get_num(), 8);
		EXPECT_EQ(c.get_dnom(), 16);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.return_more(b);
		EXPECT_EQ(c.get_num(), 4);
		EXPECT_EQ(c.get_dnom(), 9);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.return_more(b);
		EXPECT_EQ(c.get_num(), 5);
		EXPECT_EQ(c.get_dnom(), 6);
	}
}

TEST(TestCommonFraction, Return_Less) {									// тест сравнения и возврата меньшего
	{
		CommonFraction a(8, 16), b(4, 10), c = a.return_less(b);
		EXPECT_EQ(c.get_num(), 4);
		EXPECT_EQ(c.get_dnom(), 10);
	}

	{
		CommonFraction a(4, 9), b(8, 20), c = a.return_less(b);
		EXPECT_EQ(c.get_num(), 8);
		EXPECT_EQ(c.get_dnom(), 20);
	}

	{
		CommonFraction a(5, 6), b(9, 14), c = a.return_less(b);
		EXPECT_EQ(c.get_num(), 9);
		EXPECT_EQ(c.get_dnom(), 14);
	}
}