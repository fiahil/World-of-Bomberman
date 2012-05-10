//
// Profile.hpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 11:19:00 2012 nicolas magere
// Last update Thu May 10 16:55:40 2012 nicolas magere
//

#ifndef		__INFO_HPP__
#define		__INFO_HPP__

#include <vector>
#include "Config.hpp"

// To do : faire l'enum de skin : la stocker ou ?
// REMOVE LE TYPEDEF

typedef int t_skin;

class	Profile
{
private:
  size_t		_id;
  size_t		_lvl;
  size_t		_xp;
  size_t		_strength;
  size_t		_endurance;
  size_t		_agility;
  size_t		_intelligence;
  size_t		_spirit;
  bool			_tuto;
  t_skin		_skin;
  Config		_config;
  std::string		_name;
  std::vector<size_t>	_skill;
  std::vector<size_t>	_achivement;
  std::vector<size_t>	_save;

public:
  Profile();
  ~Profile();
  Profile(const Profile &);
  const Profile & operator=(const Profile &);

  size_t			getId(void) const;
  size_t			getLvl(void) const;
  size_t			getXp(void) const;
  size_t			getStrength(void) const;
  size_t			getEndurance(void) const;
  size_t			getAgility(void) const;
  size_t			getIntelligence(void) const;
  size_t			getSpirit(void) const;
  bool				getTuto(void) const;
  t_skin			getSkin(void) const;
  const Config &		getConfig(void) const;
  const std::string &		getName(void) const;
  const std::vector<size_t> &	getSkill(void) const;
  const std::vector<size_t> &	getAchivement(void) const;
  const std::vector<size_t> &	getSave(void) const;

  void		setId(size_t);
  void		setLvl(size_t);
  void		setXp(size_t);
  void		setStrength(size_t);
  void		setEndurance(size_t);
  void		setAgility(size_t);
  void		setIntelligence(size_t);
  void		setSpirit(size_t);
  void		setTuto(bool);
  void		setSkin(t_skin);
  void		setConfig(const Config &);
  void		setName(const std::string &);
  void		setSkill(const std::vector<size_t> &);
  void		setAchivement(const std::vector<size_t> &);
  void		setSave(const std::vector<size_t> &);
};


#endif		 /*__INFO_HPP__ */
