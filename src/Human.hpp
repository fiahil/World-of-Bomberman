/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Human_h)
#define __Bomberman_Human_h

#include "APlayer.hpp"
#include "Config.hpp"

struct Input
{
  enum eMode {
    CHEAT,
    GAME,
    MENU,
    LAST
  };

};

struct HumGame {

  enum eAction {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    ATTACK,
    PAUSE,
    CHEAT,
    LAST
  };

};

class Human : public APlayer
{
public:
  Human(Map &);//, const Config&, std::vector<size_t>&, std::vector<size_t> const&);
  virtual ~Human();
  virtual void play(gdl::GameClock const&, gdl::Input&);

private:

  typedef void (APlayer::*actionFunc)();

  struct eventSt {
    gdl::Keys::Key _key;
    HumGame::eAction         _action;
    actionFunc     _f;
  };

  struct eventModeSt {
    std::vector<eventSt>        _event;
    size_t			_nb;
    double			_freq;
  };

  typedef std::map< Input::eMode, eventModeSt > inputMap;

  Human::eventSt initStruct(gdl::Keys::Key, HumGame::eAction, actionFunc) const;
  Input::eMode		_mode;
  inputMap		_event;

private:
  // Config			_config;
  // std::vector<size_t>&	_achievements;
  // std::vector<size_t> const	_skill;
};

#endif
