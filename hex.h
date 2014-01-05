#pragma once

#include <vector>
#include <string>
#include <stdint.h>

namespace matasano {
  typedef std::vector<uint8_t> hex_t;
  hex_t string2hex(const std::string& string);
} // namespace matasano
