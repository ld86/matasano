#include "crypto.h"

int main(int argc, char** argv) {
  using namespace matasano;
  hex_t d;
  if (argc == 2) {
    d = string2hex(argv[1]);
  } else {
    d = string2hex("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
  }
  uint8_t key = find_x0r_key(d);
  print(x0r_with_byte(d, key)); // Cooking MC's like a pound of bacon
}
