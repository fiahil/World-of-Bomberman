/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <GameClock.hpp>
#include <Input.hpp>
#include "Camera.hpp"
#include "Map.hpp"

class	MyGame
{
public:
  MyGame(gdl::GameClock&, gdl::Input&);
  ~MyGame();

private:
  gdl::GameClock&	_clock;
  gdl::Input&		_input;
  Camera		_camera;
  //std::vector<AObj*>	_obj;
  Map			_map;

public:
  void		initialize(void);
  void		update(void);
  void		draw(void);
  void		unload(void);
  bool		isEOG(void) const;
};

#else

class MyGame;

#endif /* __MYGAME_HPP__ */
