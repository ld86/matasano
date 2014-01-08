#include "hex.h"
#include "crypto.h"

int main() {
  using namespace matasano;

  hex_t e = text2hex("Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal");
  hex_t key = text2hex("ICE");
  hex_t d = x0r_with_key(e, key);
  print_digits(d);
}
