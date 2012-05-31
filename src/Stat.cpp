/*
 * Fiahil
 * 31.05.2012
 */

#include "Stat.hpp"

Stat::Stat()
  : _nbKills(0),
  _nbDefeats(0),
  _nbVictories(0),
  _nbMaxKills(0)
{
}

size_t		Stat::getKills(void) const
{
  return this->_nbKills;
}

size_t		Stat::getDefeats(void) const
{
  return this->_nbDefeats;
}

size_t		Stat::getVictories(void) const
{
  return this->_nbVictories;
}

size_t		Stat::getMaxKill(void) const
{
  return this->_nbMaxKills;
}

size_t		Stat::getScore(void) const
{
  return this->_nbKills * 26 +
    (this->_nbVictories / (this->_nbVictories + this->_nbDefeats)) * 100 +
    this->_nbMaxKills;
}

void		Stat::addKills(size_t val)
{
  this->_nbKills += val;
}

void		Stat::addDefeats(size_t val)
{
  this->_nbDefeats += val;
}

void		Stat::addVictories(size_t val)
{
  this->_nbVictories += val;
}

void		Stat::addMaxKills(size_t val)
{
  this->_nbMaxKills += val;
}

void		Stat::setKills(size_t val)
{
  this->_nbKills = val;
}

void		Stat::setDefeats(size_t val)
{
  this->_nbDefeats = val;
}

void		Stat::setVictories(size_t val)
{
  this->_nbVictories = val;
}

void		Stat::setMaxKills(size_t val)
{
  this->_nbMaxKills = val;
}

