/*
 * Fiahil
 * 14/05/2012
 */

#ifndef __PACKMAN_HPP__
#define __PACKMAN_HPP__

#include <string>
#include <fstream>

namespace Serializer
{
  class Packman
  {
    public:
      Packman(std::string const& filename);

    private:
      std::ofstream	_os;

    public:
      void	pack();
  };
}

#endif /* __PACKMAN_HPP__ */
