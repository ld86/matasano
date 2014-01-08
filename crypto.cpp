#include "crypto.h"

#include "hex.h"
#include <iostream>
#include <stdexcept>

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

uint8_t find_x0r_byte(const hex_t& hex) {
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

hex_t x0r_with_key(const hex_t& e, const hex_t& key) {
  hex_t result(e);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] ^= key[i % key.size()];
  }
  return result;
}

hex_t x0r_with_byte(const hex_t& hex, uint8_t byte) {
  hex_t result(hex);
  for (size_t i = 0; i < result.size(); ++i) {
    result[i] ^= byte;
  }
  return result;
}

hex_t x0r(const hex_t& one, const hex_t& two) {
  if (one.size() != two.size()) {
    throw std::runtime_error("one.size() != two.size()");
  }
  hex_t result;
  result.resize(one.size());
  for (size_t i = 0; i < one.size(); ++i) {
    result[i] = one[i] ^ two[i];
  }
  return result;
}

size_t hamming(const hex_t& one, const hex_t& two) {
  size_t result = 0;
  if (one.size() != two.size()) {
    throw std::runtime_error("one.size() != two.size()");
  }
  for (size_t i = 0; i < one.size(); ++i) {
    uint8_t c = one[i] ^ two[i];
    c = (c & 0x55) + ((c >> 1) & 0x55);
    c = (c & 0x33) + ((c >> 2) & 0x33);
    c = (c & 0x0F) + ((c >> 4) & 0x0F);
    result += c;
  }
  return result;
}

} // namespace matasano
