/***********************************************************************
 * Module:  MyGame.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class MyGame
 ***********************************************************************/

#include <GL/gl.h>
#include <iostream>
#include "MyGame.hpp"

MyGame::MyGame(gdl::GameClock& clock, gdl::Input& input)
  : _clock(clock), _input(input), _camera(800, 600), _map(100, 100, 2, 2)
{
}

MyGame::~MyGame()
{

}

void	MyGame::initialize()
{
  this->_camera.initialize();
  this->_map.initialize();
 }

void	MyGame::update()
{
  this->_camera.update(this->_clock, this->_input);
  this->_map.update(this->_clock, this->_input);
}

void	MyGame::draw()
{
  this->_map.draw();
}

void	MyGame::unload()
{

}

bool	MyGame::isEOG() const
{
  return false;
}
