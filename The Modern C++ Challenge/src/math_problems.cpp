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

unsigned int find_largest_prime(unsigned int num) {
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
   return primes.back();
}

sexy_primes_pairs calculate_sexy_primes_pairs(unsigned int num) {
   return sexy_primes_pairs{};
}
