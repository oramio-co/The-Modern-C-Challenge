#ifndef STRING_PROBLEMS_H
#define STRING_PROBLEMS_H

#include <string>
#include <vector>
#include <cstdint>

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

#endif // !STRING_PROBLEMS_H