/*
 * lemonn_v
 * 07.05.12
 */

#include <unistd.h>

#include <GL/gl.h>
#include <iostream>
#include "Camera.hpp"
#include "Match.hpp"
#include "MyGame.hpp"

MyGame::MyGame(gdl::GameClock& clock, gdl::Input& input, Match& match,
	       APlayer const* pl1,  APlayer const* pl2)
  : _clock(clock),
    _input(input),
    _match(match),
    _camera(800, 600, pl1, pl2)
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
  for (std::list<Bomb>::iterator it = this->_match._bombs.begin(); it != this->_match._bombs.end();)
    {
      if ((*it).explode())
	{
	  Bomb::Pattern	origin = (*it).getPattern();

	  this->_match._map->explode(origin);
	  this->_match._explodedBombs.push_back((*it).createExplodedBomb(origin));
	  it = this->_match._bombs.erase(it);
	}
      else
	++it;
    }
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
