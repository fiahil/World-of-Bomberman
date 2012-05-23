/*
 * Fiahil
 * 12.05.2012
 */

#include <cstdlib>
#include "AI.hpp"

AI::AI(AIType::eAI type, Map& map)
  : APlayer(map), _type(type), _start(4), _startTimer(-1.0f)
{
  this->_AIDifficulty[AIType::EASY] = &AI::AIEasy;
  this->_AIDifficulty[AIType::MEDIUM] = &AI::AIMedium;
  this->_AIDifficulty[AIType::HARD] = &AI::AIHard;
}

AI::~AI()
{

}

void	AI::AIEasy(gdl::GameClock const& clock)
{
  int	pos = 0;
  std::vector<Dir::eDir>	ref(static_cast<int>(Dir::LAST), Dir::LAST);

  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y - 1))
    ref[pos++] = Dir::NORTH;
  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y + 1))
    ref[pos++] = Dir::SOUTH;
  if (this->_map.canMoveAt(this->_pos._x - 1, this->_pos._y))
    ref[pos++] = Dir::WEST;
  if (this->_map.canMoveAt(this->_pos._x + 1, this->_pos._y))
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
    }
}

void	AI::AIMedium(gdl::GameClock const&)
{

}

void	AI::AIHard(gdl::GameClock const&)
{

}

void AI::play(gdl::GameClock const& clock, gdl::Input&)
{
  if (this->_start >= 0 && this->_startTimer <= clock.getTotalGameTime())
    {
      --this->_start;
      this->_startTimer = clock.getTotalGameTime() + 1.0f;
    }
  else if (this->_start < 0)
    (this->*_AIDifficulty[this->_type])(clock);
}
