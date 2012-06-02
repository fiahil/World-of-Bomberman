/*
 * lemonn_v
 * 21.05.2012
 */

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <vector>
#include <string>
#include <fmod.hpp>
#include "enum.hpp"

struct SoundElt
{
  SoundElt();
  ~SoundElt();

  FMOD::Sound*		sound;
  FMOD::Channel*	channel;
  bool			play;
};

class Sound
{
private:
  Sound();
  ~Sound();

  Sound(Sound const&);
  Sound&	operator=(Sound const&);

  void		loadSound(std::string const& soundName, Audio::eAudio);
  void		loadPlaylist(std::string const& soundName, size_t, std::vector<SoundElt>&);

private:
  static Sound*			_me;

  FMOD::System*			_system;
  std::vector<SoundElt>		_bank;
  std::vector<SoundElt>		_game;
  std::vector<SoundElt>		_menu;
  size_t			_mindex;
  size_t			_gindex;

public:
  static Sound*	getMe(void);
  static void	delMe(void);

  void		playBack(Audio::eAudio);
  void		playGame();
  void		playMenu();
};

#endif
