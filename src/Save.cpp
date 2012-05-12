//
// Save.cpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 18:37:35 2012 nicolas magere
// Last update Thu May 10 19:06:47 2012 nicolas magere
//

#include <iostream>
#include "Save.hpp"

Save::Save()
{
  std::cout << "Creation Save" << std::endl;
}


Save::~Save()
{
  std::cout << "Destruction Save" << std::endl;
  std::cout << "/!\\ : Penser a delete tous les pointeurs APlayer / Team S'ILS ONT ETE NEW" << std::endl;
}


Save::Save(const Save & oth)
{
  this->_map = oth.getMap();
  this->_id = oth.getId();
  this->_gameMode = oth.getGameMode();
  this->_cheat = oth.getCheat();
  this->_players = oth.getPlayers();
  this->_teams = oth.getTeams();
}

const Save & Save::operator=(const Save & oth)
{
  if (this != &oth)
    {
      this->_map = oth.getMap();
      this->_id = oth.getId();
      this->_gameMode = oth.getGameMode();
      this->_cheat = oth.getCheat();
      this->_players = oth.getPlayers();
      this->_teams = oth.getTeams();
    }
  return *this;
}

const Map &	Save::getMap(void) const
{
  return this->_map;
}

size_t		Save::getId(void) const
{
  return this->_id;
}

size_t		Save::getGameMode(void) const
{
  return this->_gameMode;
}

bool		Save::getCheat(void) const
{
  return this->_cheat;
}

const std::vector<APlayer *> &	Save::getPlayers(void) const
{
  return this->_players;
}

APlayer *	Save::getPlayersByNum(size_t id) const
{
  if (this->_players.size() > id)
    return static_cast<APlayer *>(this->_players[id]);
  return 0;
}

const std::vector<Team *> &	Save::getTeams(void) const
{
  return this->_teams;
}

Team *		Save::getTeamsByNum(size_t id) const
{
  if (this->_teams.size() > id)
    return static_cast<Team *>(this->_teams[id]);
  return 0;
}

void		Save::setMap(const Map & value)
{
  this->_map = value;
}

void		Save::setId(size_t value)
{
  this->_id = value;
}

void		Save::setGameMode(size_t value)
{
  this->_gameMode = value;
}

void		Save::setCheat(bool value)
{
  this->_cheat = value;
}

void		Save::setPlayers(const std::vector<APlayer *> & value)
{
  this->_players = value;
}

void		Save::addPlayer(APlayer * value)
{
  this->_players.push_back(value);
}

void		Save::setTeams(const std::vector<Team *> & value)
{
  this->_teams = value;
}

void		Save::addTeam(Team * value)
{
  this->_teams.push_back(value);
}

void		Save::setAllSave(const Map & map, size_t id, size_t gameMode, bool cheat,
				 const std::vector<APlayer *> & players, const std::vector<Team *> & teams)
{
  this->_map = map;
  this->_id = id;
  this->_gameMode = gameMode;
  this->_cheat = cheat;
  this->_players = players;
  this->_teams = teams;
}
