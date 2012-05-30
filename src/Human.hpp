/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Human_h)
#define __Bomberman_Human_h

#include "Text.hpp"
#include "Image.hpp"
#include "APlayer.hpp"
#include "Surface.hpp"
#include "Config.hpp"
#include "enum.hpp"
#include "AI.hpp"

class Human : public APlayer
{
  typedef bool	(APlayer::*actionFunc)(gdl::GameClock const&);
  typedef void	(Human::*ptrFunc)(void) const;
  typedef bool	(Human::*ptrJumpFunc)();
  typedef bool	(Human::*ptrSkillFunc)(gdl::GameClock const&);

  struct eventSt {
    gdl::Keys::Key		_key;
    HumGame::eAction		_action;
    actionFunc			_f;
  };

  struct eventModeSt {
    std::vector<eventSt>	_event;
    size_t			_nb;
  };

  typedef std::map<Input::eMode, eventModeSt>	inputMap;

public:
  /*
   * TODO: implement enum skill
   * TODO: implement std::vector<bool> achievements
   */
  Human(Map &, const Config&, std::vector<bool>* = 0);
  virtual ~Human(); // delete des surface

  virtual void	play(gdl::GameClock const&, gdl::Input&);
  virtual void	drawHUD(std::vector<gdl::Image>&, size_t, size_t, size_t, bool);
  virtual void	setTimer(double);

private:
  Input::eMode			_mode;
  inputMap			_event;
  int				_start;
  double			_startTimer;
  gdl::Text		       	_text;
  bool				_skillUp;
  double			_skillTimer;
  Skill::eSkill			_skill;
  std::vector<ptrSkillFunc>	_skillFunc;
  std::vector<Surface*>		_HUD;
  std::vector<ptrFunc>		_bombAff;
  std::vector<ptrJumpFunc>	_jumpDir;
  Success::eSuccess		_lastSuccess;
  double		        _successTimer;
  AI*				_hallu;
  double			_halluLifeTimer;

protected:
  virtual void draw(void);
  virtual void	 drawSuccess(Success::eSuccess s);

private:
  bool		 SkillFunction(gdl::GameClock const&);
  Human::eventSt initStruct(gdl::Keys::Key, HumGame::eAction, actionFunc) const;
  void		 drawStart(size_t, size_t, size_t);
  void		 drawEnd(size_t, size_t, bool, size_t);

  void		 affNormalBomb() const;
  void		 affBigBomb() const;
  void		 affMegaBomb() const;

  bool		 halluSkill(gdl::GameClock const&);
  bool		 healSkill(gdl::GameClock const&);
  bool		 berserkSkill(gdl::GameClock const&);
  bool		 jumpSkill(gdl::GameClock const&);

  bool		 northJumpFunction();
  bool		 southJumpFunction();
  bool		 westJumpFunction();
  bool		 eastJumpFunction();
};

#endif
