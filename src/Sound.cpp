/*
 * lemonn_v
 * 21.05.2012
 */

#include <string>
#include <stdexcept>
#include <algorithm>
#include "Sound.hpp"

static void	predDestroySound(FMOD_SOUND* it)
{
  FMOD_Sound_Release(it);
}

Sound*		Sound::_me = 0;

Sound::Sound()
  : _data(Audio::LAST, 0)
{
  if (FMOD_System_Create(&(this->_system)) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  if (FMOD_System_Init(this->_system, 32, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
}

Sound::~Sound()
{
  std::for_each(this->_data.begin(), this->_data.end(), predDestroySound);
  FMOD_System_Close(this->_system);
  FMOD_System_Release(this->_system);
}

Sound*	Sound::getMe(void)
{
  if (!Sound::_me)
    Sound::_me = new Sound(); 
  return Sound::_me;
}

void	Sound::delMe(void)
{
  delete Sound::_me;
  Sound::_me = 0;
}

void	Sound::loadSound(std::string const& soundName, Audio::eAudio index)
{
  if (FMOD_System_CreateSound(this->_system,
			      soundName.c_str(),
			      FMOD_CREATESAMPLE,
			      0, &(this->_data[index])) != FMOD_OK)
    throw std::runtime_error("FMOD cannot load " + soundName + ".");
}

void	Sound::playBack(Audio::eAudio index)
{
  if (FMOD_System_PlaySound(this->_system,
			    FMOD_CHANNEL_FREE,
			    this->_data[index],
			    0, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot play a sound.");
}