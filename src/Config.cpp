/*
 * NicoW
 * 03.05.12
 */

#include <iostream>
#include "Config.hpp"

Config::Config()
{
  /**/std::cout << "Construction Config" << std::endl;
}

Config::~Config()
{
  /**/std::cout << "Destruction Config" << std::endl;
}

Config::Config(const Config & oth)
{
  /**/std::cout << "Construction Config" << std::endl;
  this->_idEvent = oth.getIdEvent();
  this->_idKey = oth.getIdKey();
  this->_idJoystick = oth.getIdJoystick();
}

const Config & Config::operator=(const Config & oth)
{
  if (this != &oth)
    {
      this->_idEvent = oth.getIdEvent();
      this->_idKey = oth.getIdKey();
      this->_idJoystick = oth.getIdJoystick();
    }
  return *this;
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
