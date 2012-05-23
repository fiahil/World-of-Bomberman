/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AI_h)
#define __Bomberman_AI_h

#include "enum.hpp"
#include "APlayer.hpp"

class AI : public APlayer
{
private:
  AIType::eAI	_type;
  int		_start;
  double	_startTimer;

private:
  typedef void	(AI::*fDifficulty)(gdl::GameClock const&);
  void	AIEasy(gdl::GameClock const&);
  void	AIMedium(gdl::GameClock const&);
  void	AIHard(gdl::GameClock const&);
  std::map<AIType::eAI, fDifficulty>	_AIDifficulty;
  
public:
  AI(AIType::eAI, Map&);
  virtual ~AI();
  void play(gdl::GameClock const&, gdl::Input&);
};

#endif
