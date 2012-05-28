/*
 * lemonn_v
 * 21.05.2012
 */

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <vector>
#include <string>
#include <fmod.h>
#include "enum.hpp"

class Sound
{
private:
  Sound();
  ~Sound();

  Sound(Sound const&);
  Sound&	operator=(Sound const&);

  void		loadSound(std::string const& soundName, Audio::eAudio);

private:
  static Sound*			_me;

  FMOD_SYSTEM*			_system;
  std::vector<FMOD_SOUND*>	_data;

public:
  static Sound*	getMe(void);
  static void	delMe(void);

  void		playBack(Audio::eAudio);
};

#endif