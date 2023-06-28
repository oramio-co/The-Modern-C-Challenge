#include <algorithm>
#include <vector>
#include <cmath>

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

std::vector<unsigned int> generate_binary_numbers() {
   return {};
}