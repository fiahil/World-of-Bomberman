/*
 * Fiahil
 * 14/05/2012
 */

#include <string>
#include <fstream>
#include "Packman.hpp"

namespace Serializer
{
  Packman::Packman(std::string const& filename)
    : _os(filename.c_str())
  {
  }

  void		Packman::pack()
  {
    //TODO: Implement
  }
}
