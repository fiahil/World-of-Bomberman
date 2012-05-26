/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <GameClock.hpp>
#include <Input.hpp>
#include "AI.hpp"
#include "AIView.hpp"
#include "Camera.hpp"
#include "Match.hpp"

class MyGame
{
public:
  MyGame(gdl::GameClock&, gdl::Input&, Match&, APlayer*, APlayer* pl2 = 0);

private:
  gdl::GameClock&	_clock;
  gdl::Input&		_input;
  Match&		_match;
  Camera		_camera;
  APlayer*		_pl1;
  APlayer*		_pl2;
  AIView*		_view;
  std::list<APlayer*>	_dead;
  bool			_EOG;
  double		_EOGTimer;

  std::vector<gdl::Image>	_HUD;
  gdl::Model			_Mbomb;
  gdl::Model			_MExplodedBomb;

private:
  template<typename T>
  static void	drawer(T* val);
  void		drawGame(APlayer*) const;

public:
  bool		operator()(Bomb*);

  void		initialize(void);
  void		update(void);
  void		draw(void);
  void		unload(void);
  bool		isEOG(void) const;
};

#else

class MyGame;

#endif /* __MYGAME_HPP__ */
