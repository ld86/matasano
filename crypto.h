#pragma once

#include "hex.h"

namespace matasano {
  hex_t x0r_with_byte(const hex_t& hex, uint8_t byte);
  hex_t x0r(const hex_t& one, const hex_t& two);
  uint8_t find_x0r_byte(const hex_t& hex);
  hex_t x0r_with_key(const hex_t& e, const hex_t& key);
  size_t hamming(const hex_t& one, const hex_t& two);
} // namespace matasano
