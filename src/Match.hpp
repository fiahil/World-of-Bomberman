
#ifndef		__MATCH_HPP__
#define		__MATCH_HPP__

#include <string>
#include <vector>
#include "Map.hpp"
#include "APlayer.hpp"
#include "enum.hpp"

// Ajouter color et nom team et id team dans APlayer

class	Match
{
private:
  Match(const Match &);
  const Match & operator=(const Match &);

public:
  Map *				_map;
  GameMode::eGameMode		_gameMode;
  bool				_cheat;
  std::vector<APlayer *>	_players;

  Match();
  Match(Map *, GameMode::eGameMode, bool, const std::vector<APlayer *> &);
  ~Match();

  void		setMap(Map *);
  void		setGameMode(GameMode::eGameMode);
  void		setCheat(bool);
  void		setPlayers(const std::vector<APlayer *> &);
  void		setAllMatch(Map *, GameMode::eGameMode, bool,
			    const std::vector<APlayer *> &);
};

#endif		/* __MATCH_HPP__*/
