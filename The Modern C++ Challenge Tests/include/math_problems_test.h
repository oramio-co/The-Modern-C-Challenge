#ifndef MATH_PROBLEMS_TEST_H
#define MATH_PROBLEMS_TEST_H

#include <gtest/gtest.h>
#include <math_problems.h>

template <typename T, typename U>
void t_EXPECT_EQ(U(*func)(T), std::vector<T> results, std::vector<U> expected) {
   for (std::size_t i = 0; i < results.size(); ++i) {
      EXPECT_EQ(func(results[i]), expected[i]);
   }
}

template <typename T, typename U>
void t_EXPECT_EQ(U(*func)(T, T), std::vector<T> first, std::vector<T> second, std::vector<U> expected) {
   for (std::size_t i = 0; i < first.size(); ++i) {
      EXPECT_EQ(func(first[i], second[i]), expected[i]);
   }
}

#endif // !MATH_PROBLEMS_TEST_H