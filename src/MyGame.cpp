/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include <iostream>
#include "Camera.hpp"
#include "Match.hpp"
#include "MyGame.hpp"

MyGame::MyGame(gdl::GameClock& clock, gdl::Input& input, Match& match)
  : _clock(clock),
    _input(input),
    _match(match),
    _camera(800, 600)
{
}

MyGame::~MyGame()
{
}

void		MyGame::initialize(void)
{
  this->_camera.initialize();
  this->_match._map->initialize();
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->initialize();
}

void		MyGame::update(void)
{
  this->_camera.update(this->_clock, this->_input);
  this->_match._map->update(this->_clock, this->_input);
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->update(this->_clock, this->_input); 
}

void		MyGame::draw(void)
{
  this->_match._map->draw();
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->draw(); 
}

void		MyGame::unload(void)
{
}

bool		MyGame::isEOG(void) const
{
  return false;
}
