#include <iostream>

#include "base64.h"
#include "hex.h"

int main(int argc, char** argv) {
  matasano::hex_t hex;
  if (argc == 2) {
    hex = matasano::string2hex(argv[1]);
  } else {
    // I'm killing your brain like a poisonous mushroom
    hex = matasano::string2hex("49276d206b696c6c696e6720796f75722062"
                               "7261696e206c696b65206120706f69736f6e"
                               "6f7573206d757368726f6f6d");
  }

  std::cout << matasano::hex2base64(hex) << std::endl;
}
