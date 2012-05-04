/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#ifndef __LOADER_HPP__
#define __LOADER_HPP__

#include <fstream>

#include "Scanner.hpp"

namespace Serializer {
  class Loader {
    public:
      Loader(std::ifstream&);
      
      Scanner	_lexer;

      bool	unpack(void);

    private:
      Loader(Loader const&);
  };
}

#endif /* __LOADER_HPP__ */
