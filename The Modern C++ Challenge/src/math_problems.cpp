#include "math_problems.h"

unsigned int sum_multiples(int num) {
   unsigned int sum{ 0 };
   const int MAX_NUM{ 135671 };
   if (num > MAX_NUM) {
      return sum;
   }
   for (int i = 1; i <= num; i++) {
      if (i % 3 == 0 || i % 5 == 0) {
         sum += i;
      }
   }
   return sum;
}
