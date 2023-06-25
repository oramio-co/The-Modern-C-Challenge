#include "math_problems_test.h"

class SumMultiplesTest : public testing::Test {
protected:
   void SetUp() override {
      nums = { 3, 5, 10, 15, 30, 50, 100 };
      sums = { 3, 8, 33, 60, 225, 593, 2418 };
   }

   std::vector<int>nums{};
   std::vector<unsigned int> sums{};
   std::vector<unsigned int> results{};
};
TEST_F(SumMultiplesTest, sum_of_multiples_of_three_or_five) {
   for (auto num : nums) {
      results.push_back(sum_multiples(num));
   }
   ASSERT_EQ(results, sums);
}
TEST_F(SumMultiplesTest, sum_of_multiples_of_three_or_five_alt) {
   for (auto num : nums) {
      results.push_back(sum_multiples_alt(num));
   }
   ASSERT_EQ(results, sums);
}

TEST(MathTest, find_greatest_common_denominator) {
   unsigned int a{ 45 };
   unsigned int b{ 72 };
   int gcd{ 9 };
   ASSERT_EQ(greatest_common_denominator(a, b), gcd);
}