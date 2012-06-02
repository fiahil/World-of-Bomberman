/*
 * NicoW
 * 03.05.12
 */

#ifndef	__PROFILE_HPP__
#define	__PROFILE_HPP__

#include <vector>
#include "Config.hpp"
#include "enum.hpp"
#include "Stat.hpp"

class	Profile
{
public:
  Profile();
  ~Profile();

private:
  Profile(const Profile &);
  const Profile & operator=(const Profile &);

private:
  size_t	_id;
  Config	_config;
  Stat		_stat;
  Skin::eSkin	_skin;
  Skill::eSkill	_skill;
  std::string	_name;

  std::vector<bool>		_achievement;
  std::vector<std::string>	_save;

public:
  size_t				getId(void) const;
  Skin::eSkin				getSkin(void) const;
  std::string const&			getSkinName(void) const;
  Skill::eSkill				getSkill(void) const;
  std::string const&			getSkillName(void) const;
  const Config &			getConfig(void) const;
  Config&				getConfig(void);
  Stat const&				getStat(void) const;
  const std::string &			getName(void) const;
  const std::vector<bool> &		getAchievement(void) const;
  std::vector<bool> &			getAchievement(void);
  const std::vector<std::string> &	getSave(void) const;

public:
  void		setId(size_t);
  void		setSkin(Skin::eSkin);
  void		setConfig(const Config &);
  void		addConfig(HumGame::eAction, gdl::Keys::Key);
  void		setName(const std::string &);
  void		setSkill(Skill::eSkill);
  void		setStat(const Stat &);
  void		setAchievement(const std::vector<bool> &);
  void		setSave(const std::vector<std::string> &);
  void		addSave(const std::string &);
  void		removeSave(unsigned int);
};

#endif	 /*__PROFILE_HPP__ */

