/***********************************************************************
 * Module:  Menu.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <Game.hpp>
#include "MyGame.hpp"

class Menu : public gdl::Game
{
private:
  MyGame*	_game;

public:
  Menu();
  virtual ~Menu();

private:
  virtual void	initialize();
  virtual void	update();
  virtual void	draw();
  virtual void	unload();
};

#else

class Menu;

#endif
