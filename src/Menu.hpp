/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <cv.h>
#include <highgui.h>
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MyGame.hpp"

class Menu : public gdl::Game
{
public:
  Menu();
  virtual ~Menu();

private:
  MyGame*	_game;
  MenuManager*	_menu;
  bool		_intro;
  CvCapture*	_capture;

private:
  virtual void		initialize(void);
  virtual void		update(void);
  virtual void		draw(void);
  virtual void		unload(void);
};

#else

class Menu;

#endif /* __MENU_HPP__ */
