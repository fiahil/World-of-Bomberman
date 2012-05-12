/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include "APlayer.hpp"

class AI : public APlayer
{
public:
  void play(gdl::GameClock const&, gdl::Input&);
};

#endif
