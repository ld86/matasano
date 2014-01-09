#include "base64.h"
#include "hex.h"

#include <sstream>
#include <stdexcept>
#include <iostream>

namespace matasano {

namespace {
  
static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

std::string base64step(char one, char two, char three) {
  std::stringstream ss;
  ss << base64_chars[(one & 0xfc) >> 2];
  ss << base64_chars[((one & 0x03) << 4) + ((two & 0xf0) >> 4)];
  ss << base64_chars[((two & 0x0f) << 2) + ((three & 0xc0) >> 6)];
  ss << base64_chars[three & 0x3f];
  return ss.str();
}

hex_t back_base64step(char one, char two, char three, char four) {
  hex_t result;
  
  one = base64_chars.find(one);
  two = base64_chars.find(two);
  three = base64_chars.find(three);
  four = base64_chars.find(four);

  result.push_back((one << 2) + ((two & 0x30) >> 4));
  result.push_back(((two & 0xf) << 4) + ((three & 0x3c) >> 2));
  result.push_back(((three & 0x3) << 6) + four);
  return result;
}

}

std::string hex2base64(const hex_t& hex) {
  uint8_t padding_count = (3 - (hex.size() % 3)) % 3;
  hex_t padded_hex(hex);
  for (size_t i = 0; i < padding_count; ++i) {
    padded_hex.push_back(0);
  }
  std::string result;
  for (size_t i = 0; i < padded_hex.size() / 3; ++i) {
    result += base64step(padded_hex[i * 3],
                         padded_hex[i * 3 + 1],
                         padded_hex[i * 3 + 2]);
  }
  result = result.substr(0, result.length() - padding_count);
  for (size_t i = 0; i < padding_count; ++i) {
    result += "=";
  }
  return result;
}

hex_t base642hex(const std::string& string) {
  hex_t result;
  std::string cutted_string = string;
  if (string.length() % 4 != 0) {
    throw std::runtime_error("if (string.length() % 4 != 0)");
  }
  size_t padding_count = string.find("=") == std::string::npos ? 0 : string.length() - string.find("=");
  if (padding_count) {
    cutted_string.replace(string.length() - padding_count, padding_count, padding_count, 'A'); 
  }
  for (size_t i = 0; i < string.length() / 4; ++i) {
    hex_t block = back_base64step(string[i * 4],
                                  string[i * 4 + 1],
                                  string[i * 4 + 2],
                                  string[i * 4 + 3]);
    result.insert(result.end(), block.begin(), block.end());
  }
  for (size_t i = 0; i < padding_count; ++i) {
    result.pop_back();
  }
  return result;
}

} // namespace matasano
