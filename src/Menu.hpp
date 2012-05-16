/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <Game.hpp>
#include "MyGame.hpp"
#include "MenuManager.hpp"

class Menu : public gdl::Game
{
public:
  Menu();
  virtual ~Menu();

private:
  MyGame*	_game;
  MenuManager	_menu;

private:
  virtual void		initialize(void);
  virtual void		update(void);
  virtual void		draw(void);
  virtual void		unload(void);
};

#else

class Menu;

#endif /* __MENU_HPP__ */
