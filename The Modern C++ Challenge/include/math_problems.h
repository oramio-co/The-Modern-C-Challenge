#ifndef MATH_PROBLEMS_H
#define MATH_PROBLEMS_H

#include <string>

using sexy_primes_pairs = std::vector<std::pair<unsigned int, unsigned int>>;
using amicable_numbers_pairs = std::vector<std::pair<unsigned int, unsigned int>>;

unsigned int sum_multiples(int num);
unsigned int sum_multiples_alt(int num);
int greatest_common_denominator(int a, int b);
unsigned int least_common_multiple(int a, int b);
std::vector<unsigned int> generate_primes(unsigned int num);
unsigned int find_largest_prime(unsigned int num);
sexy_primes_pairs calculate_sexy_primes_pairs(unsigned int num);
unsigned int sum_of_factors(const unsigned int num);
std::vector<unsigned int> calculate_abundant_numbers(const unsigned int num);
amicable_numbers_pairs calculate_amicable_numbers(const unsigned int num);
std::vector<unsigned int> calculate_three_digit_amrstrong_numbers();
std::vector<unsigned int> generate_prime_factorization(unsigned int num);
unsigned int convert_dec_to_bin(unsigned int dec);
unsigned int convert_bin_to_dec(unsigned int bin);
std::vector<unsigned int> generate_binary_numbers(unsigned int num);
std::vector<unsigned int> convert_bin_to_gray(std::vector<unsigned int>& bin_nums);
std::vector<unsigned int> convert_gray_to_bin(std::vector<unsigned int>& gray_nums);
std::string convert_dec_to_roman_numeral(int dec);

#endif // !MATH_PROBLEMS_H