/*
 * NicoW
 * 03.05.12
 */

#ifndef	__MATCH_HPP__
#define	__MATCH_HPP__

#include <string>
#include <vector>
#include "Map.hpp"
#include "APlayer.hpp"
#include "enum.hpp"

// Ajouter color et nom team et id team dans APlayer

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

