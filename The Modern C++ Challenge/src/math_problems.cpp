#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

#include "math_problems.h"

unsigned int sum_multiples(int num) {
   unsigned int sum{ 0 };
   const int MAX_NUM{ 135671 };
   if (num > MAX_NUM) {
      return sum;
   }
   for (int i = 1; i <= num; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
         sum += i;
      }
   }
   return sum;
}

unsigned int sum_multiples_alt(int num) {
   const int MAX_NUM{ 135671 };
   if (num > MAX_NUM) {
      return 0;
   }
   int t = num / 3;
   int f = num / 5;
   int ft = num / 15;
   unsigned int sum_t = 3 * t * (t + 1) / 2;
   unsigned int sum_f = 5 * f * (f + 1) / 2;
   unsigned int sum_ft = 15 * ft * (ft + 1) / 2;
   return sum_t + sum_f - sum_ft;
}

int greatest_common_denominator(int a, int b) {
   if (a < b) {
      std::swap(a, b);
   }
   while (b) {
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}

unsigned int least_common_multiple(int a, int b) {
   int gcd{ greatest_common_denominator(a, b) };
   return a * b / gcd;
}

std::vector<unsigned int> generate_primes(unsigned int num) {
   std::vector<unsigned int> primes{};
   for (unsigned int i = 2; i <= num; ++i) {
      bool isPrime{ true };
      for (auto prime : primes) {
         if (prime * prime > i) {
            break;
         }
         else if (i % prime == 0) {
            isPrime = false;
            break;
         }
      }
      if (isPrime) {
         primes.push_back(i);
      }
   }
   return primes;
}

unsigned int find_largest_prime(unsigned int num) {
   return generate_primes(num).back();
}

sexy_primes_pairs calculate_sexy_primes_pairs(unsigned int num) {
   std::vector<unsigned int> primes{ generate_primes(num) };
   sexy_primes_pairs pairs{};
   for (auto it = primes.begin(); it != primes.end(); ++it) {
      auto next = std::next(it);
      bool done{ false };
      while (next != primes.end() && !done) {
         if (*next - *it > 6) {
            done = true;
         }
         else if (*next - *it == 6) {
            pairs.push_back(std::make_pair(*it, *next));
            done = true;
         }
         else {
            ++next;
         }
      }
   }
   return pairs;
}

unsigned int sum_of_factors(const unsigned int num) {
   unsigned int sum{};
   for (unsigned int i = 1; i * i <= num; ++i) {
      if (num % i) {
         continue;
      }
      if (i * i == num) {
         sum += i;
      }
      else {
         sum += i + (num / i);
      }
   }
   return sum;
}

std::vector<unsigned int> calculate_abundant_numbers(const unsigned int num) {
   std::vector<unsigned int> abundant_nums{};
   for (unsigned int i = 12; i <= num; ++i) {
      if (sum_of_factors(i) > 2 * i) {
         abundant_nums.push_back(i);
      }
   };
   return abundant_nums;
}

amicable_numbers_pairs calculate_amicable_numbers(const unsigned int num) {
   amicable_numbers_pairs pairs{};
   std::vector<unsigned int> abundant_nums{ calculate_abundant_numbers(num) };
   for (auto it = abundant_nums.begin(); it != abundant_nums.end(); ++it) {
      unsigned int sum{ sum_of_factors(*it) - *it };
      if (sum <= num && sum_of_factors(sum) - sum == *it) {
         pairs.push_back(std::make_pair(*it, sum));
      }
   }
   return pairs;
}

std::vector<unsigned int> calculate_three_digit_amrstrong_numbers() {
   std::vector<unsigned int> armstrong_nums{};
   for (unsigned int i = 100; i < 1000; ++i) {
      unsigned int ones = i % 10;
      unsigned int tens = i / 10;
      tens = tens % 10;
      unsigned int hundreds = i / 100;
      unsigned int hundreds_cubed = hundreds * hundreds * hundreds;
      unsigned int tens_cubed = tens * tens * tens;
      unsigned int ones_cubed = ones * ones * ones;
      if (hundreds_cubed + tens_cubed + ones_cubed == i) {
         armstrong_nums.push_back(i);
      }
   }
   return armstrong_nums;
}

std::vector<unsigned int> generate_prime_factorization(unsigned int num) {
   unsigned int sqrt_num{ 2 };
   while (sqrt_num * sqrt_num < num) {
      ++sqrt_num;
   }
   auto primes{ generate_primes(sqrt_num) };
   std::vector<unsigned int> prime_factorization{};
   for (auto prime : primes) {
      while (num % prime == 0) {
         prime_factorization.push_back(prime);
         num /= prime;
      }
   }
   return prime_factorization;
}

unsigned int convert_dec_to_bin(unsigned int dec) {
   unsigned int index{ 0 };
   unsigned int bin{ 0 };
   while (dec) {
      unsigned int remainder = dec % 2;
      bin += remainder * pow(10, index);
      dec /= 2;
      ++index;
   }
   return bin;
}

unsigned int convert_bin_to_dec(unsigned int bin) {
   unsigned int index{ 0 };
   unsigned int dec{ 0 };
   while (bin) {
      unsigned int remainder = bin % 10;
      dec += remainder << index;
      bin /= 10;
      ++index;
   }
   return dec;
}

std::vector<unsigned int> generate_binary_numbers(unsigned int num) {
   std::vector<unsigned int> bin_nums{};
   for (unsigned int i = 0; i < num; ++i) {
      
      bin_nums.push_back(convert_dec_to_bin(i));
   }
   return bin_nums;
}

std::vector<unsigned int> convert_bin_to_gray(std::vector<unsigned int>& bin_nums) {
   /* Bin_nums are decimal numbers that are meant to look like a binary number.
      For example, 111 might be a num in bin_nums; it is actually one-hundred
      eleven, but is meant to represent seven. Thus there is a converstion step
      of the decimal number to it's true value when in binary. The bin_to_gray
      step is a simple xor of a binary representation with half its value. Then,
      there is a final conversion of representing what that gray code would be
      in binary, as a decimal number. */
   std::vector<unsigned int> gray_codes{};
   for (auto bin : bin_nums) {
      /* Takes one-hundred eleven to seven. 111 -> 7. */
      auto num{ convert_bin_to_dec(bin) };
      /* The xor calculation. 7 (0b0111) ^ 3 (0b0011) -> 4 (0b0100). */
      unsigned int gray{ num ^ num >> 1 };
      /* Convert back from true binary value four, to decimal that looks like it:
         one-hundred, 4 -> 100 */
      gray_codes.push_back(convert_dec_to_bin(gray));
   }
   return gray_codes;
}

std::vector<unsigned int> convert_gray_to_bin(std::vector<unsigned int>& gray_nums) {
   /* See convert_bin_to_gray for intermediate conversions. */
   std::vector<unsigned int> bin_nums{};
   for (auto num : gray_nums) {
      num = convert_bin_to_dec(num);
      unsigned int mask{ num };
      while (mask) {
         mask >>= 1;
         num ^= mask;
      }
      bin_nums.push_back(convert_dec_to_bin(num));
   }
   return bin_nums;
}

enum roman_numerals {
   M = 1000,
   D = 500,
   C = 100,
   L = 50,
   X = 10,
   V = 5,
   I = 1
};

std::string roman_enum_to_string(roman_numerals num) {
   std::string roman_num{""};
   switch (num)
   {
   case M:
      roman_num = "M";
      break;
   case 500:
      roman_num = "D";
      break;
   case 100:
      roman_num = "C";
      break;
   case 50:
      roman_num = "L";
      break;
   case 10:
      roman_num = "X";
      break;
   case 5:
      roman_num = "V";
      break;
   case 1:
      roman_num = "I";
      break;
   default:
      break;
   }
   return roman_num;
}

std::string convert_dec_to_roman_numeral(int dec) {
   std::string result{""};
   const int MAX{ 3999 };
   if (dec > MAX) {
      return result;
   }
   std::vector<roman_numerals> roman_nums{M, D, C, L, X, V, I};
   const int NINE{ 9 };
   const int FOUR{ 4 };
   const int FIVE{ 5 };
   for (std::size_t i = 0; i < roman_nums.size(); i += 2) {
      int count{ dec / roman_nums[i] };
      while (count) {
         if (count == NINE) {
            result += roman_enum_to_string(roman_nums[i]) + roman_enum_to_string(roman_nums[i - 2]);
            count -= NINE;
            dec -= NINE * roman_nums[i];
         }
         else if (count == FOUR) {
            result += roman_enum_to_string(roman_nums[i]) + roman_enum_to_string(roman_nums[i - 1]);
            count -= FOUR;
            dec -= FOUR * roman_nums[i];
         }
         else if (count >= FIVE) {
            result += roman_enum_to_string(roman_nums[i - 1]);
            count -= FIVE;
            dec -= FIVE * roman_nums[i];
         }
         else {
            result += roman_enum_to_string(roman_nums[i]);
            --count;
            dec -= roman_nums[i];
         }
      }
   }
   return result;
}

unsigned int collatz_stopping_length(const unsigned int num) {
   if (num == 1) {
      return 0;
   }
   static std::map<unsigned int, unsigned int> stopping_lengths{};
   if (!stopping_lengths[num]) {
      if (num % 2 == 0) {
         stopping_lengths[num] = collatz_stopping_length(num / 2) + 1;
      }
      else {
         stopping_lengths[num] = collatz_stopping_length(3 * num + 1) + 1;
      }
   }
   return stopping_lengths[num];
}

unsigned int num_max_collatz_stopping_length(const unsigned int num) {
   unsigned int max_num{ 1 };
   unsigned int max_stopping_length{ 0 };
   for (unsigned int i = 1; i < num; ++i) {
      unsigned int stopping_length = collatz_stopping_length(i);
      if (stopping_length > max_stopping_length) {
         max_stopping_length = stopping_length;
         max_num = i;
      }
      else if (stopping_length == max_stopping_length) {
         if (i > max_num) {
            max_num = i;
         }
      }
   }
   return max_num;
}