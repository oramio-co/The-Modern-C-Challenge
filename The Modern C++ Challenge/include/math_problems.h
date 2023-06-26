#ifndef MATH_PROBLEMS_H
#define MATH_PROBLEMS_H

using sexy_primes_pairs = std::vector<std::pair<unsigned int, unsigned int>>;

unsigned int sum_multiples(int num);
unsigned int sum_multiples_alt(int num);
int greatest_common_denominator(int a, int b);
unsigned int least_common_multiple(int a, int b);
std::vector<unsigned int> generate_primes(unsigned int num);
unsigned int find_largest_prime(unsigned int num);
sexy_primes_pairs calculate_sexy_primes_pairs(unsigned int num);

#endif // !MATH_PROBLEMS_H