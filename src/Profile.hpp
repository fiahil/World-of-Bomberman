
#ifndef		__PROFILE_HPP__
#define		__PROFILE_HPP__

#include <vector>
#include "Config.hpp"
#include "enum.hpp"

class	Profile
{
private:
  size_t		_id;
  size_t		_lvl;
  size_t		_xp;
  bool			_tuto;
  Skin::eSkin		_skin;
  Config		_config;
  std::string		_name;
  std::vector<size_t>	_skill;
  std::vector<size_t>	_stat;	// gobelin : get / set + virer les inutiles
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
  bool				getTuto(void) const;
  Skin::eSkin			getSkin(void) const;
  const Config &		getConfig(void) const;
  const std::string &		getName(void) const;
  const std::vector<size_t> &	getSkill(void) const;
  const std::vector<size_t> &	getAchivement(void) const;
  const std::vector<size_t> &	getSave(void) const;

  void		setId(size_t);
  void		setLvl(size_t);
  void		setXp(size_t);
  void		setTuto(bool);
  void		setSkin(Skin::eSkin);
  void		setConfig(const Config &);
  void		setName(const std::string &);
  void		setSkill(const std::vector<size_t> &);
  void		addSkill(size_t);
  void		setAchivement(const std::vector<size_t> &);
  void		addAchivement(size_t);
  void		setSave(const std::vector<size_t> &);
  void		addSave(size_t);
  void		setAllProfile(size_t, size_t, size_t, // modfifie
			      bool, Skin::eSkin,
			      const Config &,
			      const std::string &,
			      const std::vector<size_t> &,
			      const std::vector<size_t> &,
			      const std::vector<size_t> &);
};


#endif		 /*__PROFILE_HPP__ */