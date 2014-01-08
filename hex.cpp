#include "hex.h"

#include <stdexcept>
#include <sstream>
#include <cstdio>
#include <iostream>

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

hex_t text2hex(const std::string& string) {
  return hex_t(string.begin(), string.end());
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

std::string hex2string(const hex_t& hex) {
  std::stringstream ss;
  char two_chars[2];
  for (size_t i = 0; i < hex.size(); ++i)
  {
    sprintf(two_chars, "%02x", hex[i]);
    ss << two_chars;
  }
  return ss.str();
}

void print(const hex_t& hex) {
  for (int i = 0; i < hex.size(); ++i) {
    std::cout << hex[i];
  }
}

} // namespace matasano
