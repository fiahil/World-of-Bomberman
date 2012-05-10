//
// Config.cpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Config
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 16:45:06 2012 nicolas magere
// Last update Thu May 10 16:50:50 2012 nicolas magere
//

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
