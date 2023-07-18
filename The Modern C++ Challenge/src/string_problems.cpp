#include <vector>
#include <cstdint>
#include <sstream>

#include "string_problems.h"

uint8_t hexchar_to_int(const char ch) {
   if (ch >= '0' && ch <= '9') {
      return ch - '0';
   }
   if (ch >= 'A' && ch <= 'F') {
      return ch - 'A' + 10;
   }
   if (ch >= 'a' && ch <= 'f') {
      return ch - 'a' + 10;
   }
   return '\0';
}

std::vector<uint8_t> string_to_hex_bytes(std::string_view input) {
   std::vector<uint8_t> result{};
   for (std::size_t i = 1; i < input.size(); i += 2) {
      result.push_back(
         hexchar_to_int(input[i - 1]) << 4 | hexchar_to_int(input[i])
      );
   }
   return result;
}

std::string capitalize(std::string_view text) {
   std::ostringstream result;
   bool newWord = true;
   for (const auto ch : text) {
      newWord = newWord || std::isspace(ch);
      if (std::isalpha(ch)) {
         if (newWord) {
            result << static_cast<char>(std::toupper(ch));
            newWord = false;
         }
         else {
            result << static_cast<char>(std::tolower(ch));
         }
      }
      else {
         result << ch;
      }
   }
   return result.str();
}