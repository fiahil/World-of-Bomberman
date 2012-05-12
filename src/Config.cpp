/*
 * Fiahil
 * 12.05.2012
 */

#include <iostream>
#include "Config.hpp"

Config::Config()
{
  /* TODO: IMPLEMENT */std::cout << "Construction Config" << std::endl;
}

Config::~Config()
{
  /* TODO: IMPLEMENT */std::cout << "Destruction Config" << std::endl;
}

size_t		Config::getIdEvent(void) const
{
  return this->_idEvent;
}

size_t		Config::getIdKey(void) const
{
  return this->_idKey;
}

size_t		Config::getIdJoystick(void) const
{
  return this->_idJoystick;
}

void		Config::setIdEvent(size_t idEvent)
{
  this->_idEvent = idEvent;
}

void		Config::setIdKey(size_t idKey)
{
  this->_idKey = idKey;
}

void		Config::setIdJoystick(size_t idJoystick)
{
  this->_idJoystick = idJoystick;
}

void		Config::setAllConfig(size_t idEvent, size_t idKey, size_t idJoystick)
{
  this->_idEvent = idEvent;
  this->_idKey = idKey;
  this->_idJoystick = idJoystick;
}
