/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>

#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

namespace Serializer {
  class Scanner {
    public:
      Scanner(std::ifstream&);

    private:
      std::ifstream&	_in;
  };
}

#endif /* __SCANNER_HPP__ */
