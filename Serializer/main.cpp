/*
 * Fiahil
 *
 * 3 mai 2012
 */

#include "Loader.hpp"

#include <iostream>
#include <fstream>

int	main(int argc, char** argv) {
  std::cout << "Serializer loaded." << std::endl;

  for (int i = 1; i < argc; ++i) {
    std::ifstream	input(argv[i]);

    if (!input.good()) {
      std::cerr << "Cannot open file: " << argv[i] << std::endl;
      continue;
    }
    Serializer::Loader	loader(input);

    loader.unpack();
  }
  return 0;
}
