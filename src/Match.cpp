/*
 * NicoW
 * 03.05.12
 */

#include <iostream>
#include "Match.hpp"

Match::Match()
{
  std::cout << "Creation Match" << std::endl;
}

Match::Match(Map * map, bool cheat, GameMode::eGameMode game_mode, const std::vector<APlayer *> & players)
  : _map(map),
    _cheat(cheat),
    _gameMode(game_mode),
    _players(players)
{
   /**/std::cout << "Creation Match" << std::endl;
}

Match::~Match()
{
  /**/std::cout << "Destruction Match" << std::endl;
  /**/std::cout << "/!\\ : Penser a delete tous les pointeurs APlayer / Team S'ILS ONT ETE NEW" << std::endl;
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


void		Match::setAllMatch(Map * map,
				   bool cheat,
				   GameMode::eGameMode gameMode,
				   const std::vector<APlayer *> & players)
{
  this->_map = map;
  this->_cheat = cheat;
  this->_gameMode = gameMode;
  this->_players = players;
}
