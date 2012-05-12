/*
 * Fiahil
 * 12.05.2012
 */

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
