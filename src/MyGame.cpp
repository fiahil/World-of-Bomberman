/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include <utility>
#include <algorithm>
#include "Camera.hpp"
#include "Match.hpp"
#include "MyGame.hpp"
#include "Human.hpp"

MyGame::MyGame(gdl::GameClock& clock, gdl::Input& input, Match& match,
	       APlayer* pl1,  APlayer* pl2)
  : _clock(clock),
    _input(input),
    _match(match),
    _camera(1600, 800, pl1, pl2),
    _pl1(pl1),
    _pl2(pl2),
    _view(0),
    _EOG(false),
    _EOGTimer(-1.0f),
    _HUD(HUD::LAST)
{
}

template <typename T>
void		MyGame::drawer(T* val)
{
  val->draw();
}

void		MyGame::initialize(void)
{
  this->_match._map->initialize();
  this->_match._map->setSpawnTeam(this->_match._players);
  for (unsigned int i = 0; i < this->_match._players.size(); ++i)
    this->_match._players[i]->initialize();
  this->_HUD[HUD::LIFE_BAR] = gdl::Image::load("textures/life.png");
  this->_HUD[HUD::SHIELD] = gdl::Image::load("textures/shield.png");
  this->_HUD[HUD::SPRINT] = gdl::Image::load("textures/sprint.png");
  this->_HUD[HUD::POWER] = gdl::Image::load("textures/power.png");
  this->_HUD[HUD::LUST] = gdl::Image::load("textures/fury.png");
  this->_HUD[HUD::BOMB_OK] = gdl::Image::load("textures/bombActive.png");
  this->_HUD[HUD::BOMB_KO] = gdl::Image::load("textures/bombInactive.png");
  this->_HUD[HUD::SKILL_OK] = gdl::Image::load("textures/skillActive.png");
  this->_HUD[HUD::SKILL_KO] = gdl::Image::load("textures/skillInactive.png");
  this->_HUD[HUD::BIGBOMB_OK] = gdl::Image::load("textures/bigbombActive.png");
  this->_HUD[HUD::BIGBOMB_KO] = gdl::Image::load("textures/bigbombInactive.png");
  this->_HUD[HUD::MEGABOMB_OK] = gdl::Image::load("textures/megabombActive.png");
  this->_HUD[HUD::MEGABOMB_KO] = gdl::Image::load("textures/megabombInactive.png");
  this->_HUD[HUD::LIFE] = gdl::Image::load("textures/pv.png");

  this->_HUD[HUD::SUCCESS_ONE_KILL] = gdl::Image::load("textures/one_kill_success.png");
  this->_HUD[HUD::SUCCESS_BONUS] = gdl::Image::load("textures/bonus_success.png");
  this->_HUD[HUD::SUCCESS_FIVE_KILL] = gdl::Image::load("textures/five_kill_success.png");
  this->_HUD[HUD::SUCCESS_POWER] = gdl::Image::load("textures/power_success.png");
  this->_HUD[HUD::SUCCESS_LUST] = gdl::Image::load("textures/lust_success.png");
  this->_HUD[HUD::SUCCESS_TP] = gdl::Image::load("textures/tp_success.png");
  this->_HUD[HUD::SUCCESS_DIE] = gdl::Image::load("textures/die_success.png");
  this->_HUD[HUD::SUCCESS_FABULOUS] = gdl::Image::load("textures/fabulous_success.png");
}

bool		MyGame::updateBomb(Bomb *b)
{
  if (b->explode())
    {
      this->_match._explodedBombs.push_back(b->createExplodedBomb());
      delete b;
      return true;
    }
  else
    {
      this->_view->setBombAt(b->getPos()._x, b->getPos()._y);
      b->update(this->_clock, this->_input);
      return false;
    }
}

bool		MyGame::updateExplodedBomb(ExplodedBomb *b)
{
  if (b->isEOE())
    {
      delete b;
      return true;
    }
  else
    {
      b->update(this->_clock, this->_input);
      this->_match._map->explode(b->getPatternReal(),
				 b->getPatternFinal(),
				 this->_match._bonus);
      return false;
    }
}

bool		MyGame::updatePlayer(APlayer *p)
{
  Human*	ph = dynamic_cast<Human*>(p);

  if (ph)
    ph->setHalluView(this->_view);

  std::for_each< std::list<ExplodedBomb*>::iterator, APlayer& >
    (
     this->_match._explodedBombs.begin(),
     this->_match._explodedBombs.end(),
     (*p));

     if (p->getPv() == 0)
       {
	 if (p->getLastHitId() != p)
	   p->getLastHitId()->incNbKills();
	 this->_match._dead.push_back(p);
	 return true;
       }

     for (std::list<Bonus*>::iterator it = this->_match._bonus.begin();
	  it != this->_match._bonus.end();
	  ++it)
       {
	 if (p->takeBonus((*it)))
	   {
	     delete (*it);
	     this->_match._bonus.erase(it);
	     break;
	   }
	 this->_view->setBonusAt((*it)->getPos()._x, (*it)->getPos()._y, (*it)->getType());
       }

     if (p->getTeamId() != this->_match._players.front()->getTeamId())
       this->_EOG = false;

     if (this->_pl1 == p || this->_pl2 == p)
    	++this->_nb;

     Bomb*		newBomb;

     p->update(this->_clock, this->_input);
     if ((newBomb = p->isAttack()))
       this->_match._bombs.push_back(newBomb);
     return false;
  }

bool		MyGame::updateDeadPlayer(APlayer* p)
{
  if (p->isUnanim())
    {
      this->_match._cadaver.push_back(p);
      return true;
    }
  else
    {
      p->update(this->_clock, this->_input);
      return false;
    }
}

void		MyGame::update(void)
{

  this->_nb = 0;

  if (this->_view)
    delete this->_view;
  this->_view = new AIView(*this->_match._map);

  this->_match._map->update(this->_clock, this->_input);

  for (std::vector<APlayer*>::iterator it = this->_match._players.begin();
       it != this->_match._players.end();
       ++it)
    {
      AI	*tmp;

      if ((tmp = dynamic_cast<AI*>(*it)))
	tmp->updateView(this->_view);
    }

  this->removeIf
    (this->_match._bombs,
    &MyGame::updateBomb);

  this->removeIf
    (this->_match._explodedBombs,
     &MyGame::updateExplodedBomb);

  this->_EOG = true;
  this->removeIf
    (this->_match._players,
     &MyGame::updatePlayer);

  if (!this->_nb)
    this->_EOG = true;

  this->removeIf
    (this->_match._dead,
     &MyGame::updateDeadPlayer);

  if (this->_EOG && this->_EOGTimer < 0.0f)
    {
      if ((this->_match._gameMode == GameMode::COOP) &&
	  (this->_pl1->getPv() || this->_pl2->getPv()))
	{
	  if (this->_pl1->getPv() != 100)
	    this->_pl1->setPv(90);
	  if (this->_pl2->getPv() != 100)
	    this->_pl2->setPv(90);
	}
      this->_EOGTimer = this->_clock.getTotalGameTime() + 4.0f;
    }
}

void		MyGame::drawGame(APlayer* p) const
{
  this->_match._map->setOptimization(&p->getPos());
  this->_match._map->draw();
  std::for_each(this->_match._bombs.begin(),
		this->_match._bombs.end(),
		static_cast<void(*)(Bomb*)>(&MyGame::drawer));

  std::for_each(this->_match._explodedBombs.begin(),
		this->_match._explodedBombs.end(),
		static_cast<void(*)(ExplodedBomb*)>(&MyGame::drawer));

  std::for_each(this->_match._bonus.begin(),
		this->_match._bonus.end(),
		static_cast<void(*)(Bonus*)>(&MyGame::drawer));

  std::for_each(this->_match._dead.begin(),
  		this->_match._dead.end(),
  		static_cast<void(*)(APlayer*)>(&MyGame::drawer));

  std::for_each(this->_match._players.begin(),
		this->_match._players.end(),
		static_cast<void(*)(APlayer*)>(&MyGame::drawer));
}

void		MyGame::draw(void)
{
  if (this->_match._gameMode == GameMode::COOP || this->_match._gameMode == GameMode::VERSUS)
    {
      this->_camera.setSplitScreenLeft();
      this->drawGame(this->_pl1);
      this->_camera.setViewHUD();
      this->_pl1->drawHUD(this->_HUD, 800, 0, 0, this->_EOG);
      this->_camera.setSplitScreenRight();
      this->drawGame(this->_pl2);
      this->_camera.setViewHUD();
      this->_pl2->drawHUD(this->_HUD, 800, 810, 0, this->_EOG);
    }
  else
    {
      this->_camera.setNormalScreen();
      this->drawGame(this->_pl1);
      this->_camera.setViewHUD();
      this->_pl1->drawHUD(this->_HUD, 800, 0, 350, this->_EOG);
    }
}

void		MyGame::unload(void)
{
}

bool		MyGame::isEOG(void) const
{
  return (this->_EOG && this->_clock.getTotalGameTime() >= this->_EOGTimer);
}

bool		MyGame::isPause() const
{
  bool	tmp = this->_pl1->getPause();

  this->_pl1->setPause(false);
  return tmp;
}

void		MyGame::resumeGame()
{
  double	time = this->_clock.getTotalGameTime() + 0.15f;
  this->_pl1->setTimer(time);
  if (this->_pl2)
    this->_pl2->setTimer(time);
}
