#include "math_problems_test.h"

TEST(MathTest, sum_of_multiples_of_three_or_five) {
   int num{ 15 };
   int sum{ 60 };
   ASSERT_EQ(sum_multiples(num), sum);
}