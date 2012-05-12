
#include <iostream>
#include "Match.hpp"

Match::Match()
{
  std::cout << "Creation Match" << std::endl;
}

Match::Match(Map * map, GameMode::eGameMode game_mode, bool cheat, const std::vector<APlayer *> & players)
  : _map(map),
    _gameMode(game_mode),
    _cheat(cheat),
    _players(players)
{
  std::cout << "Creation Match" << std::endl;
}

Match::~Match()
{
  std::cout << "Destruction Match" << std::endl;
  std::cout << "/!\\ : Penser a delete tous les pointeurs APlayer / Team S'ILS ONT ETE NEW" << std::endl;
}

void		Match::setMap(Map * value)
{
  this->_map = value;
}

void		Match::setGameMode(GameMode::eGameMode value)
{
  this->_gameMode = value;
}

void		Match::setCheat(bool value)
{
  this->_cheat = value;
}

void		Match::setPlayers(const std::vector<APlayer *> & value)
{
  this->_players = value;
}


void		Match::setAllMatch(Map * map, GameMode::eGameMode gameMode, bool cheat,
				 const std::vector<APlayer *> & players)
{
  this->_map = map;
  this->_gameMode = gameMode;
  this->_cheat = cheat;
  this->_players = players;
}
