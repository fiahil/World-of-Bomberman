//
// Sound.cpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman/Videos
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 18:06:29 2012 vincent lemonnier
// Last update Mon May  7 18:59:32 2012 vincent lemonnier
//

#include <string>
#include <stdexcept>
#include <algorithm>
#include "Sound.hpp"

static void	predDestroySound(FMOD_SOUND* it)
{
  FMOD_Sound_Release(it);
}

Sound::Sound(unsigned int size) : _data(size, 0)
{
  if (FMOD_System_Create(&(this->_system)) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  if (FMOD_System_Init(this->_system, 32, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
}

Sound::~Sound()
{
  std::for_each(this->_data.begin(), this->_data.end(), predDestroySound);
  this->_data.clear();
  FMOD_System_Close(this->_system);
  FMOD_System_Release(this->_system);
}

void	Sound::loadSound(std::string const& soundName, unsigned int index)
{
  if (FMOD_System_CreateSound(this->_system, soundName.c_str(), FMOD_CREATESAMPLE, 0, &(this->_data[index])) != FMOD_OK)
    throw std::runtime_error("FMOD cannot load " + soundName + ".");
}

void	Sound::playSound(unsigned int index)
{
  if (FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_data[index], 0, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot play a sound.");
}
