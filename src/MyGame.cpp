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
	       APlayer* pl1,  APlayer* pl2)
  : _clock(clock),
    _input(input),
    _match(match),
    _camera(800, 600, pl1, pl2),
    _pl1(pl1),
    _pl2(pl2),
    _EOG(false),
    _EOGTimer(-1.0f),
    _HUD(HUD::LAST)
{
}

MyGame::~MyGame()
{
}

void		MyGame::initialize(void)
{
  this->_match._map->initialize();
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->initialize();
  this->_HUD[HUD::LIFE_BAR] = gdl::Image::load("textures/life.png");
  this->_HUD[HUD::SHIELD] = gdl::Image::load("textures/shield.png");
  this->_HUD[HUD::POWER] = gdl::Image::load("textures/power.png");
  this->_HUD[HUD::LUST] = gdl::Image::load("textures/fury.png");
  this->_HUD[HUD::BOMB_OK] = gdl::Image::load("textures/bombActive.png");
  this->_HUD[HUD::BOMB_KO] = gdl::Image::load("textures/bombInactive.png");
  this->_HUD[HUD::BIGBOMB_OK] = gdl::Image::load("textures/bigbombActive.png");
  this->_HUD[HUD::BIGBOMB_KO] = gdl::Image::load("textures/bigbombInactive.png");
  this->_HUD[HUD::MEGABOMB_OK] = gdl::Image::load("textures/megabombActive.png");
  this->_HUD[HUD::MEGABOMB_KO] = gdl::Image::load("textures/megabombInactive.png");
  this->_HUD[HUD::LIFE] = gdl::Image::load("textures/pv.png");
}

void		MyGame::update(void)
{
  Bomb*	newBomb;

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
	  (*it)->update(this->_clock, this->_input);
	  this->_match._map->explode((*it)->getPatternReal(), (*it)->getPatternFinal(), this->_match._bonus);
	  for (std::vector<APlayer*>::iterator i = this->_match._players.begin();
	       i != this->_match._players.end();)
	    {
	      (*i)->takeDamage((*it));
	      if ((*i)->getPv() == 0)
		{
		  (*it)->getPlayer()->incNbKills();
		  this->_dead.push_back((*i));
		  i = this->_match._players.erase(i);
		}
	      else
		++i;
	    }
	  ++it;
	}
    }
  for (std::list<Bonus*>::iterator it = this->_match._bonus.begin();
       it != this->_match._bonus.end(); ++it)
    (*it)->update(this->_clock, this->_input);

  int	nb = 0;
  this->_EOG = true;
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    {
      for (std::list<Bonus*>::iterator it = this->_match._bonus.begin();
	   it != this->_match._bonus.end(); ++it)
	if (this->_match._players[i]->takeBonus((*it)))
	  {
	    delete (*it);
	    this->_match._bonus.erase(it);
	    break;
	  }
      if (this->_match._players[i]->getTeamId() != this->_match._players[0]->getTeamId())
	this->_EOG = false;
      if (this->_pl1 == this->_match._players[i] || this->_pl2 == this->_match._players[i])
	++nb;
      this->_match._players[i]->update(this->_clock, this->_input);
      if ((newBomb = this->_match._players[i]->isAttack()))
	this->_match._bombs.push_back(newBomb);
    }
  if (!nb)
    this->_EOG = true;
  for (std::list<APlayer*>::iterator it = this->_dead.begin();
       it != this->_dead.end(); ++it)
    (*it)->update(this->_clock, this->_input);
  if (this->_EOG && this->_EOGTimer < 0.0f)
    this->_EOGTimer = this->_clock.getTotalGameTime() + 3.0f;
}

void		MyGame::drawGame(APlayer* p, size_t lag)
{
  this->_match._map->setOptimization(&p->getPos());
  this->_match._map->draw();
  for (std::list<Bomb*>::iterator it = this->_match._bombs.begin();
       it != this->_match._bombs.end(); ++it)
    (*it)->draw();
  for (std::list<ExplodedBomb*>::iterator it = this->_match._explodedBombs.begin();
       it != this->_match._explodedBombs.end(); ++it)
    (*it)->draw();
  for (std::list<Bonus*>::iterator it = this->_match._bonus.begin();
       it != this->_match._bonus.end(); ++it)
    (*it)->draw();
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->draw();
  for (std::list<APlayer*>::iterator it = this->_dead.begin();
       it != this->_dead.end(); ++it)
    (*it)->draw();
  this->_camera.setViewHUD();
  p->drawHUD(this->_HUD, 600, lag, this->_EOG);
}

void		MyGame::draw(void)
{
  this->_camera.setSplitScreenLeft();
  this->drawGame(this->_pl1, 0);

  this->_camera.setSplitScreenRight();
  this->drawGame(this->_pl2, 410);
}

void		MyGame::unload(void)
{
}

bool		MyGame::isEOG(void) const
{
  return (this->_EOG && this->_clock.getTotalGameTime() >= this->_EOGTimer);
}
