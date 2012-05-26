/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include <vector>
#include "enum.hpp"
#include "APlayer.hpp"
#include "AIView.hpp"

class AI : public APlayer
{

  typedef void	(AI::*fDifficulty)(gdl::GameClock const&);

public:
  AI(AIType::eAI, Map&);

private:
  AIType::eAI			_type;
  AIView const*			_view;
  int				_start;
  double			_startTimer;
  std::vector<fDifficulty>	_AIDifficulty;

public:
  void	updateView(AIView const*);
  void	play(gdl::GameClock const&, gdl::Input&);

private:
  void	AIEasy(gdl::GameClock const&);
  void	AIMedium(gdl::GameClock const&);
  void	AIHard(gdl::GameClock const&);

  bool	isWall(size_t x, size_t y) const;
  bool	isExplosion(size_t x, size_t y) const;

};

#endif
