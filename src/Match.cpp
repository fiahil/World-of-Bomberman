/*
 * NicoW
 * 03.05.12
 */

#include "Match.hpp"

Match::Match()
  : _map(0),
    _gameMode(GameMode::LAST)
{
}

Match::Match(Map * map, GameMode::eGameMode game_mode, const std::vector<APlayer *> & players)
  : _map(map),
    _gameMode(game_mode),
    _players(players)
{
}
