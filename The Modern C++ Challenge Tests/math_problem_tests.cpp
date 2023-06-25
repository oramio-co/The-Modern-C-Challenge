#include "math_problems_test.h"

TEST(MathTest, sum_of_multiples_of_three_or_five) {
   std::vector<int> nums{ 3, 5, 10, 15, 30, 50, 100 };
   std::vector<unsigned int> sums{ 3, 8, 33, 60, 225, 593, 2418 };
   std::vector<unsigned int> results{};
   for (auto num : nums) {
      results.push_back(sum_multiples(num));
   }
   ASSERT_EQ(results, sums);
}