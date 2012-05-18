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
  Bomb*	newBomb;
  
  this->_camera.update(this->_clock, this->_input);
  this->_match._map->update(this->_clock, this->_input);
  for (std::list<Bomb*>::iterator it = this->_match._bombs.begin(); it != this->_match._bombs.end();)
    {
      if ((*it)->explode())
	{
	  this->_match._explodedBombs.push_back((*it)->createExplodedBomb());
	  delete (*it);
	  it = this->_match._bombs.erase(it);
	}
      else
	{
	  (*it)->update(this->_clock, this->_input);
	  ++it;
	}
    }
  for (std::list<ExplodedBomb*>::iterator it = this->_match._explodedBombs.begin();
       it != this->_match._explodedBombs.end();)
    {
      if ((*it)->isEOE())
	{
	  delete (*it);
	  it = this->_match._explodedBombs.erase(it);
	}
      else
	{
	  this->_match._map->explode((*it)->getPatternReal(), (*it)->getPatternFinal());
	  (*it)->update(this->_clock, this->_input);
	  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
	    this->_match._players[i]->takeDamage((*it)->getPatternReal(), (*it)->getType());
	  ++it;
	}
    }
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    {
      this->_match._players[i]->update(this->_clock, this->_input);
      if ((newBomb = this->_match._players[i]->isAttack()))
	this->_match._bombs.push_back(newBomb);
    }
}

void		MyGame::draw(void)
{
  this->_match._map->draw();
  for (std::list<Bomb*>::iterator it = this->_match._bombs.begin();
       it != this->_match._bombs.end(); ++it)
    (*it)->draw();
  for (std::list<ExplodedBomb*>::iterator it = this->_match._explodedBombs.begin();
       it != this->_match._explodedBombs.end(); ++it)
    (*it)->draw();
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
