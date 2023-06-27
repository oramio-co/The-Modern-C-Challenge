#include <algorithm>
#include <vector>

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

std::vector<unsigned int> calculate_abundant_numbers(unsigned int num) {
   std::vector<unsigned int> abundant_nums{};
   for (unsigned int i = 12; i <= num; ++i) {
      unsigned int sum{0};
      for (unsigned int j = 1; j * j <= i; ++j) {
         if (i % j) {
            continue;
         }
         if (j * j == i) {
            sum += j;
         }
         else {
            sum += j + (i / j);
         }
      }
      if (sum > 2 * i) {
         abundant_nums.push_back(i);
      }
   };
   return abundant_nums;
}

amicable_numbers_pairs calculate_amicable_numbers(unsigned int num) {
   return { {} };
}