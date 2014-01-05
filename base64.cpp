#include "base64.h"
#include "hex.h"

#include <sstream>

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

}

std::string hex2base64(const hex_t& hex) {
  uint8_t padding_count = (3 - (hex.size() % 3)) % 3;
  hex_t padded_hex(hex);
  for (size_t i = 0; i < padding_count; ++i) {
    padded_hex.push_back(0);
  }
  std::stringstream result;
  for (size_t i = 0; i < padded_hex.size() / 3; ++i) {
    result << base64step(padded_hex[i * 3],
                         padded_hex[i * 3 + 1],
                         padded_hex[i * 3 + 2]);
  }
  for (size_t i = 0; i < padding_count; ++i) {
    result << '=';
  }
  return result.str();
}

hex_t base642hex(const std::string& string) {
  return hex_t();
}

} // namespace matasano
