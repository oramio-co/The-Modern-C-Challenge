#ifndef STRING_PROBLEMS_H
#define STRING_PROBLEMS_H

#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>

template <typename Iter>
std::string bytes_to_hex_string(Iter begin, const Iter end) {
   std::ostringstream oss;
   oss << std::hex << std::setfill('0');
   while (begin != end) {
      oss << std::setw(2) << static_cast<unsigned>(*begin);
      ++begin;
   }
   return oss.str();
};

template <typename Collection>
std::string bytes_to_hex_string(const Collection& col) {
   return bytes_to_hex_string(std::begin(col), std::end(col));
};

std::vector<uint8_t> string_to_hex_bytes(std::string_view);

std::string capitalize(std::string_view);

std::string join_strings(const std::vector<std::string>& list, char delimiter);

#endif // !STRING_PROBLEMS_H