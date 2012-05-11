//
// Sound.hpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman/Videos
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 18:06:17 2012 vincent lemonnier
// Last update Mon May  7 18:59:21 2012 vincent lemonnier
//


#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <vector>
#include <fmod.h>

class Sound
{
private:
  FMOD_SYSTEM*		_system;
  std::vector<FMOD_SOUND*>	_data;

private:
  Sound(Sound const&);
  Sound&	operator=(Sound const&);
public:
  Sound(unsigned int);
  ~Sound();
  void	loadSound(std::string const&, unsigned int);
  void	playSound(unsigned int);
};

#endif
