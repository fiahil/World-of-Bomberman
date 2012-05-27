/*
 * NicoW
 * 27.05.12
 */

#ifndef		__GAME_CHOOSE_HPP__
#define		__GAME_CHOOSE_HPP__

#include "AMenu.hpp"

class	GameChoose : public AMenu
{
public:
  GameChoose(GameManager&);
  virtual ~GameChoose(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#endif		/* __GAME_CHOOSE_HPP__ */
