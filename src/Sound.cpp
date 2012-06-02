/*
 * lemonn_v
 * 21.05.2012
 */

#include <string>
#include <stdexcept>
#include <algorithm>
#include "Sound.hpp"

Sound*		Sound::_me = 0;

SoundElt::SoundElt()
  : sound(0),
  channel(0)
{
}

SoundElt::~SoundElt()
{
  if (this->sound)
    this->sound->release();
}

Sound::Sound()
  : _system(0),
  _bank(Audio::LAST),
  _game(6),
  _menu(5),
  _mindex(0),
  _gindex(0)
{
  if (FMOD::System_Create(&(this->_system)) != FMOD_OK)
    throw std::runtime_error("FMOD cannot be initialized.");
  if (this->_system->init(32, FMOD_INIT_NORMAL, 0) != FMOD_OK)
    throw std::runtime_error("FMOD cannot create runtime environnement.");
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
  this->loadPlaylist("Ressources/audio/Game00.mp3", 0, &this->_game);
  this->loadPlaylist("Ressources/audio/Game01.mp3", 1, &this->_game);
  this->loadPlaylist("Ressources/audio/Game02.mp3", 2, &this->_game);
  this->loadPlaylist("Ressources/audio/Game03.mp3", 3, &this->_game);
  this->loadPlaylist("Ressources/audio/Game04.mp3", 4, &this->_game);
  this->loadPlaylist("Ressources/audio/Game05.mp3", 5, &this->_game);
  this->loadPlaylist("Ressources/audio/Menu00.mp3", 0, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu01.mp3", 1, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu02.mp3", 2, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu03.mp3", 3, &this->_menu);
  this->loadPlaylist("Ressources/audio/Menu04.mp3", 4, &this->_menu);
}

Sound::~Sound()
{
  this->_system->close();
  this->_system->release();
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

#include <iostream> //TODO

void	Sound::loadSound(std::string const& soundName, Audio::eAudio index)
{
  this->_system->createSound(soundName.c_str(), FMOD_CREATESAMPLE, 0,
      &(this->_bank.at(index).sound));
}

void	Sound::loadPlaylist(std::string const& soundName, size_t idx, std::vector<SoundElt>* bk)
{
  this->_system->createSound(soundName.c_str(),
      FMOD_CREATESTREAM,
      0, &(bk->at(idx).sound));
}

void	Sound::playBack(Audio::eAudio index)
{
  bool	i = false;

  if (this->_bank.at(index).channel)
    this->_bank.at(index).channel->isPlaying(&i);
  if (!i)
    this->_system->playSound(FMOD_CHANNEL_FREE, this->_bank.at(index).sound,
	0, &(this->_bank.at(index).channel));
}

void	Sound::stop(Audio::eAudio index)
{
  bool	i = false;

  if (this->_bank.at(index).channel)
    this->_bank.at(index).channel->isPlaying(&i);
  if (i)
    this->_bank.at(index).channel->stop();
}

void	Sound::playGame()
{
  std::random_shuffle(this->_game.begin(), this->_game.end());
  this->_gindex = 0;
  this->_system->playSound(FMOD_CHANNEL_FREE, this->_game.at(this->_gindex).sound,
      0, &(this->_game.at(this->_gindex).channel));
}

void	Sound::playMenu()
{
  std::random_shuffle(this->_menu.begin(), this->_menu.end());
  this->_mindex = 0;
 
  std::cout << this->_menu.at(this->_mindex).channel << std::endl;
 
  this->_system->playSound(FMOD_CHANNEL_FREE, this->_menu.at(this->_mindex).sound,
      0, &(this->_menu.at(this->_mindex).channel));
 
  std::cout << this->_menu.at(this->_mindex).channel << std::endl;
}

void	Sound::updateMenu()
{
  bool	i = false;

  if (this->_menu.at(this->_mindex).channel)
    this->_menu.at(this->_mindex).channel->isPlaying(&i);
  if (!i)
  {
    this->_mindex++;
    if (this->_mindex >= this->_menu.size())
      this->_mindex = 0;
    this->_system->playSound(FMOD_CHANNEL_FREE, this->_menu.at(this->_mindex).sound,
	0, &(this->_menu.at(this->_mindex).channel));
  }
}

void	Sound::updateGame()
{
  bool  i = false;

  if (this->_game.at(this->_gindex).channel)
    this->_game.at(this->_gindex).channel->isPlaying(&i);
  if (!i)
  {
    this->_gindex++;
    if (this->_gindex >= this->_game.size())
      this->_gindex = 0;
    this->_system->playSound(FMOD_CHANNEL_FREE, this->_game.at(this->_gindex).sound,
	0, &(this->_game.at(this->_gindex).channel));
  }
}

void	Sound::stopMenu()
{
  bool	i = false;

  if (this->_menu.at(this->_mindex).channel)
    this->_menu.at(this->_mindex).channel->isPlaying(&i);
  if (i)
    this->_menu.at(this->_mindex).channel->stop();
}

void	Sound::stopGame()
{
  bool	i = false;

  if (this->_game.at(this->_gindex).channel)
    this->_game.at(this->_gindex).channel->isPlaying(&i);
  if (i)
    this->_game.at(this->_gindex).channel->stop();
}
