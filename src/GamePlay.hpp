/***********************************************************************
 * Module:  GamePlay.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class GamePlay
 ***********************************************************************/

#ifndef __GAMEPLAY_HPP__
#define __GAMEPLAY_HPP__

#include <Game.hpp>
#include "Camera.hpp"
#include "Map.hpp"

class GamePlay : public gdl::Game
{
private:
  Camera	_camera;
  Map		_map;

private:
  virtual void	initialize();
  virtual void	update();
  virtual void	draw();
  virtual void	unload();

public:
  GamePlay();
  virtual ~GamePlay();
};

#else

class GamePlay;

#endif
