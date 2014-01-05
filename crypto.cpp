#include "crypto.h"

#include "hex.h"
#include <iostream>
namespace matasano {

  static size_t count_readable(const hex_t& hex) {
    size_t count = 0;
    for (size_t i = 0; i < hex.size(); ++i) {
      if (isdigit(hex[i]) || isalpha(hex[i]) || isspace(hex[i])) {
        count++;
      }
    }
    return count;
  }

  uint8_t find_x0r_key(const hex_t& hex) {
    size_t max = 0;
    uint8_t key = 0;
    for (uint16_t i = 0; i <= 0xff; ++i) {
      hex_t xored = x0r_with_byte(hex, i);
      size_t count = count_readable(xored);
      if (count >= max) {
        max = count;
        key = i;
      }
    }
    return key;
  }

} // namespace matasano
