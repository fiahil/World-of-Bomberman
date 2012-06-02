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
  void		loadPlaylist(std::string const& soundName, size_t, std::vector<FMOD_SOUND*>* container);

private:
  static Sound*			_me;

  FMOD_SYSTEM*			_system;
  FMOD_CHANNEL*			_channel;
  FMOD_CHANNEL*			_musicChannel;
  std::vector<FMOD_SOUND*>	_data;
  std::vector<FMOD_SOUND*>	_playlist;
  std::vector<FMOD_SOUND*>	_menu;
  std::vector<FMOD_SOUND*>*	_current;
  size_t			_index;
  bool				_launched;

public:
  static Sound*	getMe(void);
  static void	delMe(void);

  void		playBack(Audio::eAudio);
  void		stopLastSound();
  void		playMusic(AudioMode::eMode);
  void		updateMusic();
  void		stopMusic();
};

#endif
