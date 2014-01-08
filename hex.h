#pragma once

#include <vector>
#include <string>
#include <stdint.h>

namespace matasano {
  typedef std::vector<uint8_t> hex_t;
  hex_t text2hex(const std::string& string);
  hex_t string2hex(const std::string& string);
  std::string hex2string(const hex_t& hex);
  void print(const hex_t& hex);
} // namespace matasano
