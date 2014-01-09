#include <string>
#include <map>
#include <iostream>

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::string d = argv[1];

  if (d.size() % 32 != 0) {
    return 2;
  }
  
  typedef std::map<std::string, size_t> histo_t;
  histo_t histo;

  for (size_t block_num = 0; block_num < d.size() / 32; ++block_num) {
    std::string block(d.begin() + block_num * 32, d.begin() + (block_num + 1) * 32);
    histo[block]++;
  }
  
  for (histo_t::const_iterator it = histo.begin(); it != histo.end(); ++it) {
    if (it->second > 1) {
      std::cout << d << std::endl;
    }
  }
}
