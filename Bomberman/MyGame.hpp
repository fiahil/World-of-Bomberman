//
// MyGame.hpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon Apr 23 18:07:50 2012 vincent lemonnier
// Last update Mon May  7 14:35:21 2012 vincent lemonnier
//

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <Text.hpp>
#include <Game.hpp>
#include <Model.hpp>
#include "Camera.hpp"

class MyGame : public gdl::Game
{
private:
  Camera	_camera;
  gdl::Model	_test;

private:
  virtual void	initialize();
  virtual void	update();
  virtual void	draw();
  virtual void	unload();
  
public:
  MyGame();
  virtual ~MyGame();
};

#endif
