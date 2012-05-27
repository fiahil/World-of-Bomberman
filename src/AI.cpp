/*
 * Fiahil
 * 12.05.2012
 */

#include <cstdlib>
#include <iostream>
#include "enum.hpp"
#include "AIView.hpp"
#include "AI.hpp"

AI::AI(AIType::eAI type, Map& map)
  : APlayer(map),
    _type(type),
    _view(0),
    _start(4),
    _startTimer(-1.0f),
    _clock(0),
    _AIDifficulty(AIType::LAST, 0),
    _state(&AI::waitState)
{
  this->_AIDifficulty[AIType::EASY] = &AI::AIEasy;
  this->_AIDifficulty[AIType::MEDIUM] = &AI::AIMedium;
  this->_AIDifficulty[AIType::HARD] = &AI::AIHard;

  this->_EASYtable.push_back(std::make_pair(&AI::nearBomb, &AI::surviveState));
  this->_EASYtable.push_back(std::make_pair(&AI::nearBonus, &AI::fetchState));
}

bool	AI::isWall(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::WALL && this->_view->at(x, y).pp != 0;
}

bool	AI::isBomb(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::BOMB;
}

// TODO : old code AIEasy
  /*int				pos = 0;
  std::vector<Dir::eDir>	ref(static_cast<int>(Dir::LAST), Dir::LAST);

  if (this->isOk(this->_pos._x, this->_pos._y - 1))
    ref[pos++] = Dir::NORTH;
  if (this->isOk(this->_pos._x, this->_pos._y + 1))
    ref[pos++] = Dir::SOUTH;
  if (this->isOk(this->_pos._x - 1, this->_pos._y))
    ref[pos++] = Dir::WEST;
  if (this->isOk(this->_pos._x + 1, this->_pos._y))
    ref[pos++] = Dir::EAST;
  if (pos)
    {
      pos = random() % pos;
      if (ref[pos] == Dir::NORTH)
	this->UPFunction(clock);
      else if (ref[pos] == Dir::SOUTH)
	this->DOWNFunction(clock);
      else if (ref[pos] == Dir::WEST)
	this->LEFTFunction(clock);
      else
	this->RIGHTFunction(clock);
    }*/

void	AI::AIEasy(gdl::GameClock const& clock)
{
  this->_clock = &clock;
  (this->*_state)();
}

void	AI::AIMedium(gdl::GameClock const&)
{

}

void	AI::AIHard(gdl::GameClock const&)
{

}

Dir::eDir	AI::chooseDirection(void) const
{
  /*
   * TODO: remplacer par point de destination
   */
  return static_cast<Dir::eDir>(random() % Dir::LAST);
}

bool	AI::nearBomb(void)
{
  for (int y = -5; y < 5; ++y)
    {
      for (int x = -5; x < 5; ++x)
	{
	  if (isBomb(this->_pos._x + x, this->_pos._y + y))
	    {
	      this->_xDanger = this->_pos._x + x;
	      this->_yDanger = this->_pos._y + y;
	      return true;
	    }
	}
    }
  return false;
}

bool	AI::nearBonus(void)
{
  return false;
}

void	AI::waitState(void)
{
  for (std::vector<std::pair<gtFunc, stFunc> >::iterator it = this->_EASYtable.begin();
       it != this->_EASYtable.end();
       ++it)
    {
      if ((this->*(it->first))())
  	{
	  this->_state = it->second;
  	  (this->*(it->second))();
  	  break;
  	}
    }
}

void	AI::surviveState(void)
{
  std::vector<dirFunc>	dir(static_cast<int>(Dir::LAST), &AI::UPFunction);

  dir[Dir::NORTH] = &AI::UPFunction;
  dir[Dir::SOUTH] = &AI::DOWNFunction;
  dir[Dir::WEST] = &AI::ATTACKFunction;
  dir[Dir::EAST] = &AI::ATTACKFunction;

  if (!nearBomb())
    {
      this->_state = &AI::waitState;
      return;
    }
  (this->*(dir[this->chooseDirection()]))(*this->_clock);
}

void	AI::moveState(void)
{
  if (this->_target.size() == 0)
    {
      this->_state = &AI::waitState;
      return;
    }
  //TODO
}

void	AI::fetchState(void)
{
}

void	AI::updateView(AIView const* v)
{
  this->_view = v;
}

void	AI::play(gdl::GameClock const& clock, gdl::Input&)
{
  if ((this->_start >= 0) && (this->_startTimer <= clock.getTotalGameTime()))
    {
      --this->_start;
      this->_startTimer = clock.getTotalGameTime() + 1.0f;
    }
  else if (this->_start < 0)
    (this->*_AIDifficulty[this->_type])(clock);
}
