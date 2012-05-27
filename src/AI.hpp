/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include <vector>
#include <queue>
#include <utility>
#include "enum.hpp"
#include "APlayer.hpp"
#include "AIView.hpp"

class AI : public APlayer
{
  typedef void	(AI::*fDifficulty)(gdl::GameClock const&);
  typedef void	(AI::*dirFunc)(gdl::GameClock const&);
  typedef bool	(AI::*isFunc)(size_t x, size_t y);
  typedef void	(AI::*stFunc)(void);
  typedef bool	(AI::*gtFunc)(void);

public:
  AI(AIType::eAI, Map&);

private:
  AIType::eAI			_type;
  AIView const*			_view;
  int				_start;
  double			_startTimer;
  gdl::GameClock const*		_clock;
  std::vector<fDifficulty>	_AIDifficulty;
  stFunc			_state;
  size_t			_xDanger;
  size_t			_yDanger;

  std::queue<std::pair<size_t, size_t> >	_target; //TODO
  std::vector<std::pair<gtFunc, stFunc> >	_EASYtable;

public:
  void	updateView(AIView const*);
  void	play(gdl::GameClock const&, gdl::Input&);

private:
  void	AIEasy(gdl::GameClock const&);
  void	AIMedium(gdl::GameClock const&);
  void	AIHard(gdl::GameClock const&);

  bool	isWall(size_t x, size_t y) const;
  bool	isBomb(size_t x, size_t y) const;

  bool	nearBomb(void);
  bool	nearBonus(void);

  void	waitState(void);
  void	surviveState(void);
  void	moveState(void);
  void	fetchState(void);

  Dir::eDir	chooseDirection() const;
};

#endif
