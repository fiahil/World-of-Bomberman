/*
 * Fiahil
 *
 * 3 mai 2012
 */

#include <fstream>

#include "Scanner.hpp"

namespace Serializer {
  Scanner::Scanner(std::ifstream& in) : _in(in) {
  }
}
