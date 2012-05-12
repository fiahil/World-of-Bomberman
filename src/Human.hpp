/***********************************************************************
 * Module:  Human.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:13:39 PM
 * Purpose: Declaration of the class Human
 ***********************************************************************/

#if !defined(__Bomberman_Human_h)
#define __Bomberman_Human_h

#include "APlayer.hpp"
#include "Config.hpp"

class Human : public APlayer
{
public:
  Human(std::string const&, const Config&);
  virtual ~Human();
  virtual void play(gdl::GameClock const&, gdl::Input&);

protected:
private:
  Config		_config;	// modified : implement

};

#endif
