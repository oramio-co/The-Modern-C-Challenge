#include <gtest/gtest.h>
#include <cstdint>
#include <array>

#include <string_problems.h>

TEST(StringProblem, converts_8_bit_hex_vector_iter_to_string) {
   std::vector<uint8_t> input{ 0xba, 0xAD, 0xf0, 0x0d };
   std::string output = "baadf00d";
   EXPECT_EQ(bytes_to_hex_string(input.begin(), input.end()), output);
}

TEST(StringProblem, converts_8_bit_hex_array_iter_to_string) {
   std::array<uint8_t, 6> input = { {1, 2, 3, 4, 5, 6} };
   std::string output = "010203040506";
   EXPECT_EQ(bytes_to_hex_string(input.begin(), input.end()), output);
}

TEST(StringProblem, converts_8_bit_hex_vector_to_string) {
   std::vector<uint8_t> input{ 0xba, 0xAD, 0xf0, 0x0d };
   std::string output = "baadf00d";
   EXPECT_EQ(bytes_to_hex_string(input), output);
}

TEST(StringProblem, convert_string_to_hex_vector) {
   std::string input = "baadf00d";
   std::vector<uint8_t> output{ 0xba, 0xAD, 0xf0, 0x0d };
   EXPECT_EQ(string_to_hex_bytes(input), output);
}

TEST(StringProblem, convert_string_should_skip_last_letter_on_odd_indexed_string) {
   std::string input = "0102030405060";
   std::vector<uint8_t> output{ 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
   EXPECT_EQ(string_to_hex_bytes(input), output);
}

TEST(StringProblem, applies_capitalization_to_string_all_lower_case) {
   std::string input = "the modern c++ challenge";
   std::string output = "The Modern C++ Challenge";
   EXPECT_EQ(capitalize(input), output);
}

TEST(StringProblem, capitalization_handles_mixed_case_of_given_string) {
   std::string input = "THIS iS An eXampLE, anD ShOUld wORK!";
   std::string output = "This Is An Example, And Should Work!";
   EXPECT_EQ(capitalize(input), output);
}

TEST(StringProblem, join_strings_together_separated_by_a_given_delimiter) {
   std::vector<std::string> input = { "this", "is", "an", "example" };
   const char delimiter = ' ';
   std::string output = "this is an example";
   EXPECT_EQ(join_strings(input, delimiter), output);
}