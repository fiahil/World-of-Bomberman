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
  std::list<APlayer*>	_cadaver;
  bool			_EOG;
  double		_EOGTimer;
  size_t		_nb;

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

private:
  template<typename T, typename U>
  void    removeIf(T & cont, U rmFunc)
  {
    typename T::iterator           it = cont.begin();

    while (it != cont.end())
      {
	if ((this->*rmFunc)(*it))
	  it = cont.erase(it);
	else
	  ++it;
      }
  }

  bool	updateBomb(Bomb *);
  bool	updateExplodedBomb(ExplodedBomb *);
  bool	updatePlayer(APlayer *);
  bool	updateDeadPlayer(APlayer* p);

};

#else

class MyGame;

#endif /* __MYGAME_HPP__ */
