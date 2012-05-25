#include "ES.hpp"

using namespace choro3;

int main() {

  printf("%c\n", '\377');

  ES es = ES::load(std::cin)[0];
  ES::prettify(es, std::cout);

  return 0;
}
