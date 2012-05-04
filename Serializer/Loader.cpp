/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>
#include <iostream>
#include <string>

#include "Scanner.hpp"
#include "Loader.hpp"

namespace Serializer {
  Loader::Loader(std::ifstream& in) : _lexer(in) {
  }

  bool	Loader::unpack(void) { 
    std::cout << "PARSING" << std::endl;
  }
}
