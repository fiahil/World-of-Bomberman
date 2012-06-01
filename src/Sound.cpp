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
  : _channel(0),
    _musicChannel(0),
    _data(Audio::LAST, 0),
    _playlist(6u, 0),
    _index(0),
    _launched(false)
{
  if (FMOD_System_Create(&(this->_system)) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  if (FMOD_System_Init(this->_system, 32, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  this->loadSound("Ressources/audio/hurt.WAV", Audio::SYLVANAS_HURT);
  this->loadSound("Ressources/audio/hurt.WAV", Audio::SYLVANAS_DEATH);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::VARIANT_HURT);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::VARIANT_DEATH);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::WORGEN_HURT);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::WORGEN_DEATH);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::ZULJIN_HURT);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::ZULJIN_DEATH);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::ENNEMY_HURT);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::ENNEMY_DEATH);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::TIMER_START);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::START);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::EXPLODE);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::BONUS);
  this->loadSound("Ressources/audio/ennemy_hurt.mp3", Audio::SUCCESS);
  this->loadSound("Ressources/audio/intro.mp3", Audio::INTRO);
  this->loadPlaylist("Ressources/audio/Game00.mp3", 0);
  this->loadPlaylist("Ressources/audio/Game01.mp3", 1);
  this->loadPlaylist("Ressources/audio/Game02.mp3", 2);
  this->loadPlaylist("Ressources/audio/Game03.mp3", 3);
  this->loadPlaylist("Ressources/audio/Game04.mp3", 4);
  this->loadPlaylist("Ressources/audio/Game05.mp3", 5);
}

Sound::~Sound()
{
  std::for_each(this->_data.begin(), this->_data.end(), predDestroySound);
  std::for_each(this->_playlist.begin(), this->_playlist.end(), predDestroySound);
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
  FMOD_System_CreateSound(this->_system,
      soundName.c_str(),
      FMOD_CREATESAMPLE,
      0, &(this->_data[index]));
}

void	Sound::loadPlaylist(std::string const& soundName, size_t index)
{
  FMOD_System_CreateSound(this->_system, soundName.c_str(),
      FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &(this->_playlist[index]));
}

void	Sound::stopLastSound(void)
{
  FMOD_Channel_Stop(this->_channel);
}

void	Sound::playBack(Audio::eAudio index)
{
  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_data[index],
      0, &this->_channel);
}

void	Sound::playMusic(void)
{
  std::random_shuffle(this->_playlist.begin(), this->_playlist.end());
  this->_index = 0;
  this->_launched = true;
  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
      this->_playlist[this->_index], 0, &this->_musicChannel);
}

void	Sound::updateMusic(void)
{
  if (!this->_launched)
    return;

  int	res;

  FMOD_Channel_IsPlaying(this->_musicChannel, &res);
  if (!res)
  {
    this->_index = (this->_index < this->_playlist.size() ? this->_index + 1 : 0); 
    FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
	this->_playlist[this->_index], 0, &this->_musicChannel);
  }
}

void	Sound::stopMusic(void)
{
  this->_launched = false;
  FMOD_Channel_Stop(this->_musicChannel);
}
