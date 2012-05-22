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

private:
  typedef void	(AI::*fDifficulty)();
  void	AIEasy();
  void	AIMedium();
  void	AIHard();
  std::map<AIType::eAI, fDifficulty>	_AIDifficulty;
  
public:
  AI(AIType::eAI, Map&);
  virtual ~AI();
  void play(gdl::GameClock const&, gdl::Input&);
};

#endif
