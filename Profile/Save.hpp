//
// Save.hpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 17:40:53 2012 nicolas magere
// Last update Thu May 10 19:07:06 2012 nicolas magere
//

#ifndef		__SAVE_HPP__
#define		__SAVE_HPP__

#include <list>
#include <vector>
#include "Map.hpp"
#include "APlayer.hpp"

struct	Team
{
  size_t		_id;
  size_t		_color;
  std::string		_name;
  std::list<APlayer *>	_list;
};

class	Save
{
private:
  Map				_map;
  size_t			_id;
  size_t			_gameMode;
  bool				_cheat;
  std::vector<APlayer *>	_players;
  std::vector<Team *>		_teams;

public:
  Save();
  ~Save();
  Save(const Save &);
  const Save & operator=(const Save &);

  const Map &				getMap(void) const;
  size_t				getId(void) const;
  size_t				getGameMode(void) const;
  bool					getCheat(void) const;
  const std::vector<APlayer *> &	getPlayers(void) const;
  APlayer *				getPlayersByNum(size_t) const;
  const std::vector<Team *> &		getTeams(void) const;
  Team *				getTeamsByNum(size_t) const;

  void		setMap(const Map &);
  void		setId(size_t);
  void		setGameMode(size_t);
  void		setCheat(bool);
  void		setPlayers(const std::vector<APlayer *> &);
  void		addPlayer(APlayer *);
  void		setTeams(const std::vector<Team *> &);
  void		addTeam(Team *);
  void		setAllSave(const Map &, size_t, size_t, bool,
			   const std::vector<APlayer *> &, const std::vector<Team *> &);
};

#endif		/* __SAVE_HPP__*/
