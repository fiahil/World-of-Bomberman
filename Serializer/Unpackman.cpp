/*
 * Fiahil
 * 15/05/2012
 */

#include <string>
#include "Profile.hpp"
#include "Match.hpp"
#include "Unpackman.hpp"

namespace Serializer
{
  Unpackman::Unpackman(Profile& p, Match& m)
    : pf(p), ma(m)
  {
  }
}
