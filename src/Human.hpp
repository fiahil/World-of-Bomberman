/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Human_h)
#define __Bomberman_Human_h

#include <Text.hpp>
#include <Image.hpp>
#include "APlayer.hpp"
#include "Surface.hpp"
#include "Config.hpp"
#include "enum.hpp"

class Human : public APlayer
{
public:
  Human(Map &, const Config&);//, std::vector<size_t>&, std::vector<size_t> const&);
  virtual ~Human();
  virtual void play(gdl::GameClock const&, gdl::Input&);
  virtual void drawHUD(std::vector<gdl::Image>&, size_t, size_t, bool);

private:

  typedef void (APlayer::*actionFunc)(gdl::GameClock const&);
  typedef void (Human::*ptrFunc)(void);
  typedef bool (Human::*ptrJumpFunc)();
  typedef void (Human::*ptrSkillFunc)(gdl::GameClock const&);

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

  void SkillFunction(gdl::GameClock const&);

  typedef std::map< Input::eMode, eventModeSt > inputMap;

  Human::eventSt initStruct(gdl::Keys::Key, HumGame::eAction, actionFunc) const;
  Input::eMode		_mode;
  inputMap		_event;

  int		_start;
  double	_startTimer;
  gdl::Text	_text;

  void		drawStart(size_t, size_t);
  void		drawEnd(size_t, size_t, bool);

  void affNormalBomb();
  void affBigBomb();
  void affMegaBomb();

  void halluSkill(gdl::GameClock const&);
  void healSkill(gdl::GameClock const&);
  void berserkSkill(gdl::GameClock const&);
  void jumpSkill(gdl::GameClock const&);

  bool	northJumpFunction();
  bool	southJumpFunction();
  bool	westJumpFunction();
  bool	eastJumpFunction();


private:
  bool				_skillUp;
  double			_skillTimer;
  Skill::eSkill			_skill;
  std::vector<ptrSkillFunc>	_skillFunc;
  std::vector<Surface*>		_HUD;
  std::vector<ptrFunc>		_bombAff;
  std::vector<ptrJumpFunc>	_jumpDir;
  // std::vector<size_t>&	_achievements;
  // std::vector<size_t> const	_skill; // passage en simple enum
};

#endif
