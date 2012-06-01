/*
 * Fiahil
 * 12.05.2012
 */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include "enum.hpp"
#include "AIView.hpp"
#include "AI.hpp"

AI::AI(AIType::eAI type, Map& map)
  : APlayer(map),
    _view(0),
    _start(4),
    _startTimer(-1.0f),
    _clock(0),
    _state(&AI::waitState)
{
  this->_type = type;

  std::vector<std::pair<gtFunc, stFunc> >	EASY;
  std::vector<std::pair<gtFunc, stFunc> >	NORMAL;
  std::vector<std::pair<gtFunc, stFunc> >	HARD;
  std::vector<std::pair<gtFunc, stFunc> >	HALLU;

  EASY.push_back(std::make_pair(&AI::nearBomb, &AI::surviveState));
  EASY.push_back(std::make_pair(&AI::nearEmpty, &AI::attackState));
  NORMAL.push_back(std::make_pair(&AI::nearBomb, &AI::surviveState));
  NORMAL.push_back(std::make_pair(&AI::nearBonus, &AI::moveState));
  NORMAL.push_back(std::make_pair(&AI::nearEmpty, &AI::attackState));
  HARD.push_back(std::make_pair(&AI::nearBomb, &AI::surviveState));
  HARD.push_back(std::make_pair(&AI::nearBonus, &AI::moveState));
  HARD.push_back(std::make_pair(&AI::nearEmpty, &AI::attackState));
  HALLU.push_back(std::make_pair(&AI::nearEmpty, &AI::moveState));

  this->_table.reserve(5);
  this->_table.push_back(EASY);
  this->_table.push_back(NORMAL);
  this->_table.push_back(HARD);
  this->_table.push_back(HALLU);
  this->_table.push_back(HALLU);

  if (type == AIType::HALLU)
    this->_dam = 0.0;
  if (type == AIType::HARD)
    this->_dam = 0.25;

  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(-1, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::LEFTFunction);

    this->_paths.push_back(p);
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(0, -2));
    p.elt.push_back(std::make_pair(-1, -2));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::LEFTFunction);

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
    p.elt.push_back(std::make_pair(0, -2));
    p.elt.push_back(std::make_pair(1, -2));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(1, -1));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(2, 0));
    p.elt.push_back(std::make_pair(2, -1));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(1, 1));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(2, 0));
    p.elt.push_back(std::make_pair(2, 1));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(1, 1));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(0, 2));
    p.elt.push_back(std::make_pair(1, 2));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(-1, 1));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::LEFTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(0, 2));
    p.elt.push_back(std::make_pair(-1, 2));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::LEFTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-1, 1));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-2, 0));
    p.elt.push_back(std::make_pair(-2, 1));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-1, -1));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-2, 0));
    p.elt.push_back(std::make_pair(-2, -1));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(1, -1));
    p.elt.push_back(std::make_pair(1, -2));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(1, 0));
    p.elt.push_back(std::make_pair(1, 1));
    p.elt.push_back(std::make_pair(1, 2));
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(1, 1));
    p.elt.push_back(std::make_pair(2, 1));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(1, -1));
    p.elt.push_back(std::make_pair(2, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::RIGHTFunction);
    p.func.push_front(&AI::RIGHTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, 1));
    p.elt.push_back(std::make_pair(-1, 1));
    p.elt.push_back(std::make_pair(-2, 1));
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::LEFTFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-1, 1));
    p.elt.push_back(std::make_pair(-1, 2));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::DOWNFunction);
    p.func.push_front(&AI::DOWNFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(-1, 0));
    p.elt.push_back(std::make_pair(-1, -1));
    p.elt.push_back(std::make_pair(-1, -2));
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::UPFunction);

    this->_paths.push_back(p); 
  }
  {
    Path	p;

    p.elt.push_back(std::make_pair(0, -1));
    p.elt.push_back(std::make_pair(-1, -1));
    p.elt.push_back(std::make_pair(-2, -1));
    p.func.push_front(&AI::UPFunction);
    p.func.push_front(&AI::LEFTFunction);
    p.func.push_front(&AI::LEFTFunction);

    this->_paths.push_back(p); 
  }
}

bool	AI::isWall(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::WALL && this->_view->at(x, y).pp != 0;
}

bool	AI::isEmpty(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::WALL && this->_view->at(x, y).pp == 0;
}

bool	AI::isBomb(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::BOMB;
}

bool	AI::isBonus(size_t x, size_t y) const
{
  return this->_view->at(x, y).type == Elt::BONUS;
}

bool	AI::nearBomb(void)
{
  int	x = 0;
  int	y = -7;

  for (y = -7; y < 0; ++y)
  {
    if (isWall(this->_pos._x + x, this->_pos._y + y))
      break;
    if (isBomb(this->_pos._x + x, this->_pos._y + y))
    {
      return this->dodgeBomb(this->_pos._x + x, this->_pos._y + y,
	  this->_pos._x, this->_pos._y);
    }
  }
  for (y = 0; y < 7; ++y)
  {
    if (isWall(this->_pos._x + x, this->_pos._y + y))
      break;
    if (isBomb(this->_pos._x + x, this->_pos._y + y))
    {
      return this->dodgeBomb(this->_pos._x + x, this->_pos._y + y,
	  this->_pos._x, this->_pos._y);
    }
  }
  y = 0;
  for (x = -7; x < 0; ++x)
  {
    if (isWall(this->_pos._x + x, this->_pos._y + y))
      break;
    if (isBomb(this->_pos._x + x, this->_pos._y + y))
    {
      return this->dodgeBomb(this->_pos._x + x, this->_pos._y + y,
	  this->_pos._x, this->_pos._y);
    }
  }
  for (x = 0; x < 7; ++x)
  {
    if (isWall(this->_pos._x + x, this->_pos._y + y))
      break;
    if (isBomb(this->_pos._x + x, this->_pos._y + y))
    {
      return this->dodgeBomb(this->_pos._x + x, this->_pos._y + y,
	  this->_pos._x, this->_pos._y);
    }
  }
  return false;
}

bool	AI::nearBonus(void)
{
  std::vector<std::pair<int, int> >	tmp;

  for (int y = -4; y < 4; ++y)
  {
    for (int x = -4; x < 4; ++x)
    {
      if (isBonus(this->_pos._x + x, this->_pos._y + y)) 
      {
	if (this->pathFind(this->_pos._x + x, this->_pos._y + y,
	    	           this->_pos._x, this->_pos._y))
	  tmp.push_back(std::make_pair(x, y));
      }
    }
  }
  this->_target.clear();
  if (tmp.size() > 0)
  {
    size_t	rander = random() % tmp.size();

    this->pathFind(this->_pos._x + tmp[rander].first,
	           this->_pos._y + tmp[rander].second,
		   this->_pos._x, this->_pos._y);
    return true;
  }
  return false;
}

bool	AI::nearEmpty(void)
{
  std::vector<std::pair<int, int> >	tmp;

  for (int y = -4; y < 4; ++y)
  {
    for (int x = -4; x < 4; ++x)
    {
      if (isEmpty(this->_pos._x + x, this->_pos._y + y)) 
      {
	if (this->pathFind(this->_pos._x + x, this->_pos._y + y,
	    	           this->_pos._x, this->_pos._y))
	  tmp.push_back(std::make_pair(x, y));
      }
    }
  }
  this->_target.clear();
  if (tmp.size() > 0)
  {
    size_t	rander = random() % tmp.size();

    this->pathFind(this->_pos._x + tmp[rander].first,
	           this->_pos._y + tmp[rander].second,
		   this->_pos._x, this->_pos._y);
    return true;
  }
  return false;
}

void	AI::waitState(void)
{
  for (std::vector<std::pair<gtFunc, stFunc> >::iterator it = this->_table.at(this->_type).begin();
      it != this->_table.at(this->_type).end();
      ++it)
  {
    if ((this->*(it->first))())
    {
      this->_state = it->second;
      return;
    }
  }
}

void	AI::surviveState(void)
{
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

void	AI::attackState(void)
{
  this->_target.push_back(&AI::ATTACKFunction);
  this->_state = &AI::moveState;
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

bool	AI::dodgeBomb(size_t x, size_t y, size_t cx, size_t cy)
{
  if (x == cx)
    return this->dodgingX(cx, cy);
  else if (y == cy)
    return this->dodgingY(cx, cy);
  return false;
}

bool	AI::dodgingX(size_t cx, size_t cy)
{
  if (isEmpty(cx - 1, cy))
  {
    this->_target.push_back(&AI::LEFTFunction);
    return true;
  }
  if (isEmpty(cx + 1, cy))
  {
    this->_target.push_back(&AI::RIGHTFunction);
    return true;
  }
  return false;
}

bool	AI::dodgingY(size_t cx, size_t cy)
{
  if (isEmpty(cx, cy - 1))
  {
    this->_target.push_back(&AI::UPFunction);
    return true;
  }
  if (isEmpty(cx, cy + 1))
  {
    this->_target.push_back(&AI::DOWNFunction);
    return true;
  }
  return false;
}

void	AI::updateView(AIView const* v)
{
  this->_view = v;
}

void	AI::play(gdl::GameClock const& clock, gdl::Input&)
{
  assert(this->_view);
  if ((this->_start >= 0) && (this->_startTimer <= clock.getTotalGameTime()))
  {
    --this->_start;
    this->_startTimer = clock.getTotalGameTime() + 1.0f;
  }
  else if (this->_start < 0)
  {
    this->_clock = &clock;
    (this->*_state)();
  }
}
