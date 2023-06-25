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
   std::vector<int> a{ 45 , 45, 45 };
   std::vector<int> b{ 72 , 71, 90 };
   std::vector<int> gcd{ 9 , 1, 45};
   std::vector<int> results{};
   for (std::size_t i = 0; i < a.size(); i++) {
      results.push_back(greatest_common_denominator(a[i], b[i]));
   }
   ASSERT_EQ(results, gcd);
}

TEST(MathTest, find_least_common_multiple) {
   std::vector<int> a{ 6, 6, 7 };
   std::vector<int> b{ 9, 12, 12};
   std::vector<unsigned int> lcm{ 18, 12, 84};
   std::vector<unsigned int> results{};
   for (std::size_t i = 0; i < a.size(); i++) {
      results.push_back(least_common_multiple(a[i], b[i]));
   }
   ASSERT_EQ(results, lcm);
}