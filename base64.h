#pragma once

#include "hex.h"

namespace matasano {
  hex_t base642hex(const std::string& string);
  std::string hex2base64(const hex_t& hex);
} // namespace matasano 
