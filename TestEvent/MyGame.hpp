//
// MyGame.hpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon Apr 23 18:07:50 2012 vincent lemonnier
// Last update Mon May  7 10:53:49 2012 benjamin businaro
//

#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <Text.hpp>
#include <Game.hpp>
#include <map>
#include <vector>
#include <GL/gl.h>

class MyGame : public gdl::Game
{
protected:
  virtual void	initialize();
  virtual void	update();
  virtual void	draw();
  virtual void	unload();

private:

  enum inputMode {
    CHEAT,
    GAME,
    MENU
  };

  enum Action {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    ATTACK,
    QUIT,
    PAUSE,
    SELECT,
    OTHER,
    ActionCount
  };


  typedef void (MyGame::*actionFunc)();

  struct eventSt {
    gdl::Keys::Key _key;
    Action	   _action;
    actionFunc	   _f;
  };

  struct eventModeSt {
    std::vector<eventSt>	_event;
    size_t		_nb;
    double		_freq;
  };

private :

  /*
  ** une map/vectore referencer par le mode de saisi active (menu, game, cheat, ...)
  **    et contenant uns structure :
  **       - map/vector event,
  **       - nombre d'event dans ce mode,
  **       - frequence du mode,
  **       - ... etc
  */


  typedef std::map< inputMode, eventModeSt > inputMap;

  void UPFunction();
  void LEFTFunction();
  void RIGHTFunction();
  void DOWNFunction();
  void ATTACKFunction();
  void QUITFunction();
  void PAUSEFunction();
  void SELECTFunction();
  MyGame::eventSt initStruct(gdl::Keys::Key, Action, actionFunc) const;
  inputMode	_mode;
  inputMap	_event;

public:
  MyGame();
  virtual ~MyGame();
};

#endif
