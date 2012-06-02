/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __BOMBERMAN_HPP__
#define __BOMBERMAN_HPP__

#include <cv.h>
#include <highgui.h>
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MyGame.hpp"

class Bomberman : public gdl::Game
{
public:
  Bomberman();
  virtual ~Bomberman();

private:
  MyGame*	_game;
  MenuManager*	_menu;
  bool		_intro;
  bool		_pause;
  CvCapture*	_capture;

private:
  void			updateIntro(void);
  void			updateGame(void);
  void			updateBomberman(void);

private:
  virtual void		initialize(void);
  virtual void		update(void);
  virtual void		draw(void);
  virtual void		unload(void);
};

#else

class Bomberman;

#endif /* __BOMBERMAN_HPP__ */
