/*
 * Fiahil
 * 14/05/2012
 */

#ifndef __PACKMAN_HPP__
#define __PACKMAN_HPP__

#include <string>
#include <fstream>
#include "Match.hpp"
#include "Profile.hpp"

namespace Serializer
{
  class Packman
  {
    public:
      Packman(std::string const& filename);

    private:
      std::ofstream	_os;

    public:
      void	packProfile(Profile const&);
      void	packMatch(Match const&);
  };
}

#endif /* __PACKMAN_HPP__ */