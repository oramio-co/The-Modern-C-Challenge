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

TEST(MathTest, find_largest_prime_less_than_num) {
   std::vector<unsigned int> nums{ 10, 100, 1000, 10000 };
   std::vector<unsigned int> primes{ 7, 97, 997, 9973 };
   std::vector<unsigned int> results{};
   for (std::size_t i = 0; i < nums.size(); i++) {
      results.push_back(find_largest_prime(nums[i]));
   }
   ASSERT_EQ(results, primes);
}

TEST(MathTest, find_sexy_primes_pairs) {
   std::vector<unsigned int> nums{ 11, 20, 100, 500 };
   std::vector<sexy_primes_pairs> sexy_primes_list{
      { {5, 11} },
      { {5, 11}, {7, 13}, {11, 17}, {13, 19} },
      { {5, 11}, {7, 13}, {11, 17}, {13, 19}, {17, 23}, {23, 29}, {31, 37},
      {37, 43}, {41, 47}, {47, 53}, {53, 59}, {61, 67}, {67, 73}, {73, 79},
      {83, 89} },
      { {5, 11}, {7, 13}, {11, 17}, {13, 19}, {17, 23}, {23, 29}, {31, 37},
      {37, 43}, {41, 47}, {47, 53}, {53, 59}, {61, 67}, {67, 73}, {73, 79},
      {83, 89}, {97, 103}, {101, 107}, {103, 109}, {107, 113}, {131, 137},
      {151, 157}, {157, 163}, {167, 173}, {173, 179}, {191, 197}, {193, 199},
      {223, 229}, {227, 233}, {233, 239}, {251, 257}, {257, 263}, {263, 269},
      {271, 277}, {277, 283}, {307, 313}, {311, 317}, {331, 337}, {347, 353},
      {353, 359}, {367, 373}, {373, 379}, {383, 389}, {433, 439}, {443, 449},
      {457, 463}, {461, 467}}
   };
   std::vector<sexy_primes_pairs> results{};
   for (auto num : nums) {
      results.push_back(calculate_sexy_primes_pairs(num));
   }
   ASSERT_EQ(results, sexy_primes_list);
}

TEST(MathTest, calculate_abundant_numbers) {
   std::vector<unsigned int> nums{ 12, 100, 200 };
   std::vector<std::vector<unsigned int>> abundant_nums_lists{
      { 12 },
      { 12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66, 70, 72, 78, 80, 84,
         88, 90, 96, 100 },
      { 12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66, 70, 72, 78, 80, 84,
         88, 90, 96, 100, 102, 104, 108, 112, 114, 120, 126, 132, 138, 140,
         144, 150, 156, 160, 162, 168, 174, 176, 180, 186, 192, 196, 198, 200}
   };
   std::vector<std::vector<unsigned int>> results{};
   for (auto num : nums) {
      results.push_back(calculate_abundant_numbers(num));
   }
   ASSERT_EQ(results, abundant_nums_lists);
}

TEST(MathTest, DISABLED_calculate_amicable_numbers) {
   std::vector<unsigned int> nums{ 300, 1250, 1000000 };
   std::vector<amicable_numbers_pairs> amicable_nums{
      { {220, 284} },
      { {220, 284}, {1184, 1210} },
      { {220, 284}, {1184, 1210}, {2620, 2924}, {5020, 5564}, {6232, 6368},
        {10744, 10856}, {12285, 14595}, {17296, 18416}, {63020, 76084},
        {66928, 66992}, {67095, 71145}, {69615, 87633}, {79750, 88730},
        {100485, 124155}, {122265, 139815}, {122368, 123152}, {141664, 153176},
        {142310, 168730}, {171856, 176336}, {176272, 180848}, {185368, 203432},
        {196724, 202444}, {280540, 365084}, {308620, 389924}, {319550, 430402},
        {356408, 399592}, {437456, 455344}, {469028, 486178}, {503056, 514736},
        {522405, 525915}, {600392, 669688}, {609928, 686072}, {624184, 691256},
        {635624, 712216}, {643336, 652664}, {667964, 783556}, {726104, 796696},
        {802725, 863835}, {879712, 901424}, {898216, 980984} }
   };
   std::vector<amicable_numbers_pairs> results{};
   for (auto num : nums ) {
      results.push_back(calculate_amicable_numbers(num));
   }
   ASSERT_EQ(results, amicable_nums);
}

TEST(MathTest, calculate_three_digit_armstrong_numbers) {
   std::vector<unsigned int> armstrong_numbers{153, 370, 371, 407};
   ASSERT_EQ(calculate_three_digit_amrstrong_numbers(), armstrong_numbers);
}

TEST(MathTest, generate_prime_factors) {
   std::vector<unsigned int> nums{ 9, 510510 };
   std::vector<std::vector<unsigned int>> prime_factorizations{ 
      {3, 3}, 
      {2, 3, 5, 7, 11, 13, 17 }
   };
   std::vector<std::vector<unsigned int>> results;
   for (auto num : nums) {
      results.push_back(generate_prime_factorization(num));
   }
   ASSERT_EQ(results, prime_factorizations);
}

TEST(MathTest, generates_three_digit_binary_numbers) {
   std::vector<unsigned int> bin_nums{ 000, 001, 10, 11, 100, 101, 110, 111 };
   ASSERT_EQ(generate_binary_numbers(8), bin_nums);
}

TEST(MathTest, converts_binary_digit_to_gray_code) {
   auto bin_nums{ generate_binary_numbers(8) };
   std::vector<unsigned int> gray_code_nums{ 0, 1, 11, 10, 110, 111, 101, 100 };
   ASSERT_EQ(convert_bin_to_gray(bin_nums), gray_code_nums);
}

TEST(MathTest, converts_gray_code_to_binary_digit) {
   std::vector<unsigned int> gray_code_nums{0, 1, 11, 10, 110, 111, 101, 100 };
   std::vector<unsigned int> bin_nums{0, 1, 10, 11, 100, 101, 110, 111 };
   ASSERT_EQ(convert_gray_to_bin(gray_code_nums), bin_nums);
}

class RomanNumeralsTest : public testing::Test {
protected:
   std::vector<int> dec_nums{};
   std::vector<std::string> roman_numerals{};
   std::vector<std::string> results{};
};

TEST_F(RomanNumeralsTest, convert_basic_roman_numerals) {
   dec_nums = { 1, 5, 10, 50, 100, 500, 1000 };
   roman_numerals = { "I", "V", "X", "L", "C", "D", "M" };
   for (auto num : dec_nums) {
      results.push_back(convert_dec_to_roman_numeral(num));
   }
   ASSERT_EQ(results, roman_numerals);
}

TEST_F(RomanNumeralsTest, convert_multiple_basic_roman_numerals) {
   dec_nums = { 3, 30, 300, 3000 };
   roman_numerals = { "III", "XXX", "CCC", "MMM" };
   for (auto num : dec_nums) {
      results.push_back(convert_dec_to_roman_numeral(num));
   }
   ASSERT_EQ(results, roman_numerals);
}

TEST_F(RomanNumeralsTest, convert_numerals_including_four_or_nine) {
   dec_nums = { 4, 9, 40, 90, 400, 900 };
   roman_numerals = { "IV", "IX", "XL", "XC", "CD", "CM" };
   for (auto num : dec_nums) {
      results.push_back(convert_dec_to_roman_numeral(num));
   }
   ASSERT_EQ(results, roman_numerals);
}

TEST_F(RomanNumeralsTest, convert_mixed_roman_numerals) {
   dec_nums = { 543, 1419, 2396, 3974 };
   roman_numerals = { "DXLIII", "MCDXIX", "MMCCCXCVI", "MMMCMLXXIV" };
   for (auto num : dec_nums) {
      results.push_back(convert_dec_to_roman_numeral(num));
   }
   ASSERT_EQ(results, roman_numerals);
}

TEST(MathTest, calculate_stopping_length_of_collatz_conjecture_sequence) {
   std::vector<unsigned int> nums{ 1, 2, 4, 8, 16, 5, 32, 10, 64, 3, 20, 21, 128};
   std::vector<unsigned int> stopping_length{0, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 7, 7};
   std::vector<unsigned int> results{};
   for (auto num : nums) {
      results.push_back(collatz_stopping_length(num));
   }
   ASSERT_EQ(results, stopping_length);
}