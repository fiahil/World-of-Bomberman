/***********************************************************************
 * Module:  AI.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:13:47 PM
 * Purpose: Declaration of the class AI
 ***********************************************************************/

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include "APlayer.hpp"

class AI : public APlayer
{
public:
  void play(gdl::GameClock const&, gdl::Input&);

protected:
private:

};

#endif
