/*
 * NicoW
 * 03.05.12
 */

#include <vector>
#include <iostream>
#include "Profile.hpp"

Profile::Profile()
{
  this->_tuto = false;
  this->_name = "Default_Player";
}

Profile::~Profile()
{
}

size_t		Profile::getId(void) const
{
  return this->_id;
}

size_t		Profile::getLvl(void) const
{
  return this->_lvl;
}

size_t		Profile::getXp(void) const
{
  return this->_xp;
}

bool		Profile::getTuto(void) const
{
  return this->_tuto;
}

Skin::eSkin	Profile::getSkin(void) const
{
  return this->_skin;
}

const Config &	Profile::getConfig(void) const
{
  return this->_config;
}

Config&		Profile::getConfig(void)
{
  return this->_config;
}

const std::string &		Profile::getName(void) const
{
  return this->_name;
}

const std::vector<size_t> &	Profile::getSkill(void) const
{
  return this->_skill;
}

const std::vector<size_t> &	Profile::getStat(void) const
{
  return this->_stat;
}

const std::vector<size_t> &	Profile::getAchievement(void) const
{
  return this->_achievement;
}

const std::vector<size_t> &	Profile::getSave(void) const
{
  return this->_save;
}

void		Profile::setId(size_t value)
{
  this->_id = value;
}

void		Profile::setLvl(size_t value)
{
  this->_lvl = value;
}

void		Profile::setXp(size_t value)
{
  this->_xp = value;
  this->_lvl = value / 100; //TODO: curve
}

void		Profile::setTuto(bool value)
{
  this->_tuto = value;
}

void		Profile::setSkin(Skin::eSkin value)
{
  this->_skin = value;
}

void		Profile::setConfig(const Config & value)
{
  this->_config = value;
}

void		Profile::addConfig(HumGame::eAction a, gdl::Keys::Key k)
{
  this->_config.setConfig(a, k);
}

void		Profile::setName(const std::string & value)
{
  this->_name = value;
}

void		Profile::setSkill(const std::vector<size_t> & value)
{
  this->_skill = value;
}

void		Profile::addSkill(size_t value)
{
  this->_skill.push_back(value);
}

void		Profile::setStat(const std::vector<size_t> & value)
{
  this->_stat = value;
}

void		Profile::addStat(size_t value)
{
  this->_stat.push_back(value);
}

void		Profile::setAchievement(const std::vector<size_t> & value)
{
  this->_achievement = value;
}

void		Profile::addAchievement(size_t value)
{
  this->_achievement.push_back(value);
}

void		Profile::setSave(const std::vector<size_t> & value)
{
  this->_save = value;
}

void		Profile::addSave(size_t value)
{
  this->_save.push_back(value);
}

void		Profile::setAllProfile(size_t id, size_t xp,
			       bool tuto, Skin::eSkin skin,
			       const Config & config,
			       const std::string & name,
			       const std::vector<size_t> & skill,
			       const std::vector<size_t> & stat,
			       const std::vector<size_t> & achievement,
			       const std::vector<size_t> & save)
{
  this->_id = id;
  this->_lvl = xp / 100; //TODO: curve
  this->_xp = xp;
  this->_tuto = tuto;
  this->_skin = skin;
  this->_name = name;
  this->_skill = skill;
  this->_stat = stat;
  this->_achievement = achievement;
  this->_save = save;
  this->_config = config;
}
