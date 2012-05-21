/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <GameClock.hpp>
#include <Input.hpp>
#include "Camera.hpp"
#include "Match.hpp"

class	MyGame
{
public:
  MyGame(gdl::GameClock&, gdl::Input&, Match&, APlayer const*, APlayer const* pl2 = 0);
  ~MyGame();

private:
  gdl::GameClock&	_clock;
  gdl::Input&		_input;
  Match&		_match;
  Camera		_camera;

private:
  std::vector<gdl::Image>	_HUD;

public:
  void		initialize(void);
  void		update(void);
  void		draw(void);
  void		unload(void);
  bool		isEOG(void) const;
};

#else

class MyGame;

#endif /* __MYGAME_HPP__ */
