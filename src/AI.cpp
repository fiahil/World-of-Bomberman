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

  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
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

bool	AI::nearBomb(void)
{
  for (int y = -5; y < 5; ++y)
    {
      for (int x = -5; x < 5; ++x)
	{
	  if (isBomb(this->_pos._x + x, this->_pos._y + y))
	    {
	      return this->pathFind(this->_pos._x + x, this->_pos._y + y,
		      		    this->_pos._x, this->_pos._y);
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
  if (!nearBomb())
    {
      this->_state = &AI::waitState;
      return;
    }
  this->_state = &AI::moveState;
}

void	AI::moveState(void)
{
  if (this->_target.size() == 0)
    {
      this->_state = &AI::waitState;
      return;
    }
  if ((this->*(this->_target.back()))(*this->_clock))
    this->_target.pop_back();
}

void	AI::fetchState(void)
{
}

bool	AI::pathDiscovery(size_t cx, size_t cy, Path const& p)
{
  for (size_t i = 0; i < p.elt.size(); ++i)
  {
    if (isWall(cx + p.elt[i].first, cy + p.elt[i].second))
      return false;
  }
  return true;
}

bool	AI::pathFind(size_t x, size_t y, size_t cx, size_t cy)
{
  for (std::vector<Path>::iterator it = this->_paths.begin();
      it != this->_paths.end();
      ++it)
  {
    if (pathDiscovery(cx, cy, *it) &&
	cx + it->elt[it->elt.size() - 1].first == x &&
	cy + it->elt[it->elt.size() - 1].second == y)
    {
      this->_target.insert(this->_target.begin(), it->func.begin(), it->func.end());
      return true;
    }
  }
  return false;
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
