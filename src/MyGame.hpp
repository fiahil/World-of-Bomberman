/***********************************************************************
 * Module:  MyGame.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class MyGame
 ***********************************************************************/

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <GameClock.hpp>
#include <Input.hpp>
#include "Camera.hpp"
#include "Map.hpp"

class MyGame
{
private:
  gdl::GameClock&	_clock;
  gdl::Input&		_input;
  Camera	_camera;
  //std::vector<AObj*>	_obj;
  Map		_map;

public:
  MyGame(gdl::GameClock&, gdl::Input&);
  ~MyGame();
  void	initialize();
  void	update();
  void	draw();
  void	unload();
  bool	isEOG() const;
};

#else

class MyGame;

#endif
