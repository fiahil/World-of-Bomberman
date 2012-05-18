/*
 * NicoW
 * 03.05.12
 */

#ifndef	__MATCH_HPP__
#define	__MATCH_HPP__

#include <string>
#include <vector>
#include "Map.hpp"
#include "Bomb.hpp"
#include "APlayer.hpp"
#include "enum.hpp"

class	Match
{
public:
  Match();
  Match(Map *, bool, GameMode::eGameMode, const std::vector<APlayer *> &);
  ~Match();

private:
  Match(const Match &);
  const Match & operator=(const Match &);

public:
  Map *				_map;
  bool				_cheat;
  GameMode::eGameMode		_gameMode;
  std::vector<APlayer *>	_players;
  std::list<Bomb>		_bombs;
  //std::list<Bonus>		_bonus;
  std::list<Bomb::ExplodedBomb>	_explodedBombs;

public:
  void		setMap(Map *);
  void		setGameMode(GameMode::eGameMode);
  void		setCheat(bool);
  void		setPlayers(const std::vector<APlayer *> &);
  void		setAllMatch(Map *,
			    bool,
			    GameMode::eGameMode,
			    const std::vector<APlayer *> &);
};

#endif	/* __MATCH_HPP__*/

