/*
 * NicoW
 * 03.05.12
 */

#ifndef	__MATCH_HPP__
#define	__MATCH_HPP__

#include <string>
#include <vector>
#include "Map.hpp"
#include "Bonus.hpp"
#include "Bomb.hpp"
#include "APlayer.hpp"
#include "enum.hpp"

class Match
{
public:
  Match();
  Match(Map *, GameMode::eGameMode, const std::vector<APlayer *> &);
  ~Match();

private:
  Match(const Match &);
  const Match & operator=(const Match &);

public:
  Map*				_map;
  GameMode::eGameMode		_gameMode;
  std::string			_date;
  size_t			_nbPlayer;
  std::vector<APlayer*>		_players;
  std::list<Bomb*>		_bombs;
  std::list<Bonus*>		_bonus;
  std::list<ExplodedBomb*>	_explodedBombs;
};

#endif	/* __MATCH_HPP__*/

