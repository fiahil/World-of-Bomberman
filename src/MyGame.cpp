/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include <iostream>
#include "MyGame.hpp"

MyGame::MyGame(gdl::GameClock& clock, gdl::Input& input)
  : _clock(clock),
    _input(input),
    _camera(800, 600),
    _map(100, 100, 2, 2)
{
}

MyGame::~MyGame()
{
}

void		MyGame::initialize(void)
{
  this->_camera.initialize();
  this->_map.initialize();
}

void		MyGame::update(void)
{
  this->_camera.update(this->_clock, this->_input);
  this->_map.update(this->_clock, this->_input);
}

void		MyGame::draw(void)
{
  this->_map.draw();
}

void		MyGame::unload(void)
{

}

bool		MyGame::isEOG(void) const
{
  return false;
}
