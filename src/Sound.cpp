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
  : _musicChannel(0),
    _data(Audio::LAST, 0),
    _dataChannel(Audio::LAST, 0),
    _playlist(6u, 0),
    _menu(5u, 0),
    _current(0),
    _index(0),
    _launched(false)
{
  if (FMOD_System_Create(&(this->_system)) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  if (FMOD_System_Init(this->_system, 32, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create.");
  this->loadSound("Ressources/audio/SylvanasHurt.ogg", Audio::SYLVANAS_HURT);
  this->loadSound("Ressources/audio/SylvanasDeath.ogg", Audio::SYLVANAS_DEATH);
  this->loadSound("Ressources/audio/VarianHurt.ogg", Audio::VARIANT_HURT);
  this->loadSound("Ressources/audio/VarianDeath.ogg", Audio::VARIANT_DEATH);
  this->loadSound("Ressources/audio/WorgenHurt.ogg", Audio::WORGEN_HURT);
  this->loadSound("Ressources/audio/WorgenDeath.ogg", Audio::WORGEN_DEATH);
  this->loadSound("Ressources/audio/ZuljinHurt.ogg", Audio::ZULJIN_HURT);
  this->loadSound("Ressources/audio/ZuljinDeath.ogg", Audio::ZULJIN_DEATH);
  this->loadSound("Ressources/audio/ChickenHurt.ogg", Audio::ENNEMY_HURT);
  this->loadSound("Ressources/audio/ChickenDeath.ogg", Audio::ENNEMY_DEATH);
  this->loadSound("Ressources/audio/Timer.ogg", Audio::TIMER_START);
  this->loadSound("Ressources/audio/Start.ogg", Audio::START);
  this->loadSound("Ressources/audio/Explode.ogg", Audio::EXPLODE);
  this->loadSound("Ressources/audio/ExplodeDiffuse.ogg", Audio::EXPLODE_DIFFUSE);
  this->loadSound("Ressources/audio/Bonus.ogg", Audio::BONUS);
  this->loadSound("Ressources/audio/Achievement.ogg", Audio::SUCCESS);
  this->loadSound("Ressources/audio/intro.mp3", Audio::INTRO);
  this->loadSound("Ressources/audio/Menu.ogg", Audio::MENU);
  this->loadPlaylist("Ressources/audio/Game00.mp3", 0, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Game01.mp3", 1, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Game02.mp3", 2, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Game03.mp3", 3, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Game04.mp3", 4, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Game05.mp3", 5, &this->_playlist);
  this->loadPlaylist("Ressources/audio/Menu00.mp3", 0, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu01.mp3", 1, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu02.mp3", 2, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu03.mp3", 3, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu04.mp3", 4, &this->_menu);
}

Sound::~Sound()
{
  std::for_each(this->_data.begin(), this->_data.end(), predDestroySound);
  std::for_each(this->_playlist.begin(), this->_playlist.end(), predDestroySound);
  std::for_each(this->_menu.begin(), this->_menu.end(), predDestroySound);
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

void	Sound::loadPlaylist(std::string const& soundName, size_t index, std::vector<FMOD_SOUND*>* container)
{
  FMOD_System_CreateSound(this->_system, soundName.c_str(),
      FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &container->at(index));
}

void	Sound::stopSound(Audio::eAudio index)
{
  FMOD_Channel_Stop(this->_dataChannel.at(index));
}

void	Sound::playBack(Audio::eAudio index)
{
  int	play = 0;

  FMOD_Channel_IsPlaying(this->_dataChannel.at(index), &play);
  if (!play)
    FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE, this->_data.at(index),
	0, &(this->_dataChannel.at(index)));
}

void	Sound::playMusic(AudioMode::eMode playlist)
{
  if (playlist == AudioMode::GAME)
    this->_current = &this->_playlist;
  else
    this->_current = &this->_menu;

  std::random_shuffle((*this->_current).begin(), (*this->_current).end());
  this->_index = 0;
  this->_launched = true;
  FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
      (*this->_current)[this->_index], 0, &this->_musicChannel);
  FMOD_Channel_SetVolume(this->_musicChannel, 0.4f);
}

void	Sound::updateMusic()
{
  if (!this->_launched || !this->_current)
    return;

  int				res;

  FMOD_Channel_IsPlaying(this->_musicChannel, &res);
  if (!res)
  {
    this->_index = (this->_index < (*this->_current).size()-1 ? this->_index+1 : 0); 
    FMOD_System_PlaySound(this->_system, FMOD_CHANNEL_FREE,
	(*this->_current)[this->_index], 0, &this->_musicChannel);
  }
}

void	Sound::stopMusic()
{
  this->_launched = false;
  this->_current = 0;
  FMOD_Channel_Stop(this->_musicChannel);
}
