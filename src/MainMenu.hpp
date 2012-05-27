/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MAINMENU_HPP__
#define __MAINMENU_HPP__

#include "AMenu.hpp"

class MainMenu : public AMenu
{
public:
  MainMenu(GameManager&);
  virtual ~MainMenu();
  
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#else

class MainMenu;

#endif
