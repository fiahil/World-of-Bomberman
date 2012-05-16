/*
 * Fiahil
 * 12.05.2012
 */

#include <iostream>
#include <algorithm>
#include "Config.hpp"

Config::Config()
{
  this->_conf[HumGame::UP] = gdl::Keys::Up;
  this->_conf[HumGame::LEFT] = gdl::Keys::Left;
  this->_conf[HumGame::RIGHT] = gdl::Keys::Right;
  this->_conf[HumGame::DOWN] = gdl::Keys::Down;
  this->_conf[HumGame::ATTACK] = gdl::Keys::Space;
  this->_conf[HumGame::PAUSE] = gdl::Keys::Escape;
  this->_conf[HumGame::CHEAT] = gdl::Keys::Tab;
}

Config::~Config()
{
}

HumGame::eAction	Config::setConfig(HumGame::eAction key, gdl::Keys::Key val)
{
  std::map<HumGame::eAction, gdl::Keys::Key>::iterator it;
  if ((it = this->_conf.find(key)) != this->_conf.end())
    {
      std::map<HumGame::eAction, gdl::Keys::Key>::iterator it2;
      for (it2 = this->_conf.begin(); it2 != this->_conf.end(); ++it2)
	if (it2->second == val)
	  {
	    it2->second = gdl::Keys::Count;
	    it->second = val;
	    return it2->first;
	  }
    }
  it->second = val;
  return HumGame::LAST;
}

gdl::Keys::Key		Config::getConfig(HumGame::eAction key) const
{
  std::map<HumGame::eAction, gdl::Keys::Key>::const_iterator it;
  if ((it = this->_conf.find(key)) != this->_conf.end())
    return it->second;
  return gdl::Keys::Count;
}

bool	Config::isAllSet() const
{
  std::map<HumGame::eAction, gdl::Keys::Key>::const_iterator it2;
  for (it2 = this->_conf.begin(); it2 != this->_conf.end(); ++it2)
    if (it2->second == gdl::Keys::Count)
      return false;
  return true;
}

bool	Config::operator==(Config const & other) const
{
  for (int i = 0; (HumGame::eAction)i < HumGame::LAST; ++i)
    if (other.getConfig((HumGame::eAction)i) != this->getConfig((HumGame::eAction)i))
      return false;
  return true;
}

bool	Config::operator!=(Config const & other) const
{
  for (int i = 0; (HumGame::eAction)i < HumGame::LAST; ++i)
    if (other.getConfig((HumGame::eAction)i) == this->getConfig((HumGame::eAction)i))
      return false;
  return true;
}
