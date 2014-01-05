#include "hex.h"

#include <stdexcept>

namespace matasano {

namespace {

uint8_t char2int(char symbol) {
  if (isdigit(symbol)) {
    return symbol - '0';
  }
  if (symbol >= 'A' && symbol <= 'F') {
    return 10 + (symbol - 'A');
  }
  if (symbol >= 'a' && symbol <= 'f') {
    return 10 + (symbol - 'a');
  }
}

}

hex_t string2hex(const std::string& string) { 
  if (string.length() % 2 == 1) {
    throw std::runtime_error("string.length() % 2 == 1");
  }
  hex_t result;
  result.resize(string.length() / 2);
  for (size_t i = 0 ; i < string.length() / 2; ++i) {
    if (isxdigit(string[i * 2]) && isxdigit(string[i * 2 + 1])) {
      result[i] = char2int(string[i * 2]) * 16 + char2int(string[i * 2 + 1]);
    } else {
      throw std::runtime_error("isxdigit(string[i * 2]) && isxdigit(string[i * 2 + 1])");
    }
  }
  return result;
}

} // namespace matasano
