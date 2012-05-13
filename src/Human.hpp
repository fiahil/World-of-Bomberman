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
  Human(const Config&, std::vector<size_t>&, std::vector<size_t> const&);
  virtual ~Human();
  virtual void play(gdl::GameClock const&, gdl::Input&);

protected:
private:
  Config			_config;
  std::vector<size_t>&		_achievements;
  std::vector<size_t> const	_skill;
};

#endif
