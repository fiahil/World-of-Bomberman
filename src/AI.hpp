/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include <vector>
#include <deque>
#include <utility>
#include "enum.hpp"
#include "APlayer.hpp"
#include "AIView.hpp"

class AI : public APlayer
{
  typedef void	(AI::*fDifficulty)(gdl::GameClock const&);
  typedef bool	(AI::*dirFunc)(gdl::GameClock const&);
  typedef bool	(AI::*isFunc)(size_t x, size_t y);
  typedef void	(AI::*stFunc)(void);
  typedef bool	(AI::*gtFunc)(void);

  struct Path
  {
    std::vector<std::pair<int, int> >	elt;
    std::deque<dirFunc>			func;
  };

public:
  AI(AIType::eAI, Map&);

private:
  AIView const*			_view;
  int				_start;
  double			_startTimer;
  gdl::GameClock const*		_clock;
  stFunc			_AIstate;
  std::deque<dirFunc>		_target;
  std::vector<Path>		_paths;

  std::vector<std::vector<std::pair<gtFunc, stFunc> > >	_table;

public:
  void	updateView(AIView const*);
  void	play(gdl::GameClock const&, gdl::Input&);

private:
  bool	isWall(size_t x, size_t y) const;
  bool	isBomb(size_t x, size_t y) const;
  bool	isEmpty(size_t x, size_t y) const;
  bool	isBonus(size_t x, size_t y) const;

  bool	nearBomb(void);
  bool	nearBonus(void);
  bool	nearEmpty(void);

  void	waitState(void);
  void	surviveState(void);
  void	attackState(void);
  void	moveState(void);

  bool	pathFind(size_t x, size_t y, size_t cx, size_t cy);
  bool	pathDiscovery(size_t cx, size_t cy, Path const& p);
  bool	dodgeBomb(size_t x, size_t y, size_t cx, size_t cy);
  bool	dodgingX(size_t cx, size_t cy);
  bool	dodgingY(size_t cx, size_t cy);
};

#endif
