#include <iostream>

#include "hex.h"

int main(int argc, char** argv) {
  using namespace matasano;

  hex_t one;
  hex_t two;

  if (argc == 3) {
    one = string2hex(argv[1]);
    two = string2hex(argv[2]);
  } else {
    one = string2hex("1c0111001f010100061a024b53535009181c"); 
    two = string2hex("686974207468652062756c6c277320657965");
  }
  hex_t xored = x0r(one, two); 
  std::cout << hex2string(xored) << std::endl;
}
