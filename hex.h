#pragma once

#include <vector>
#include <string>
#include <stdint.h>

namespace matasano {
  typedef std::vector<uint8_t> hex_t;
  hex_t string2hex(const std::string& string);
  std::string hex2string(const hex_t& hex);
  hex_t x0r_with_byte(const hex_t& hex, uint8_t byte);
  hex_t x0r(const hex_t& one, const hex_t& two);
  void print(const hex_t& hex);
} // namespace matasano
