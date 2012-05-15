/*
 * Fiahil
 * 15/05/2012
 */

#ifndef __UNPACKMAN_HPP__
#define __UNPACKMAN_HPP__

#include "Profile.hpp"
#include "Match.hpp"

namespace Serializer
{
  class Unpackman
  {
    public:
      Unpackman(Profile&, Match&);

    public:
      Profile&	pf;
      Match&	ma;
  };
}

#endif /* __UNPACKMAN_HPP__ */

