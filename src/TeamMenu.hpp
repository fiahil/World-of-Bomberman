/*
 * Texan
 * 27.05.2012
 */

#ifndef __TEAMMENU_HPP__
#define __TEAMMENU_HPP__

#include "GameManager.hpp"
#include "AMenu.hpp"

class	TeamMenu : public AMenu
{
public:
  TeamMenu(GameManager&);
  virtual ~TeamMenu(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif
