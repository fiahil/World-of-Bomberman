/*
 * NicoW
 * 03.05.12
 */

#include <vector>
#include <iostream>
#include "enum.hpp"
#include "Profile.hpp"

static const std::string	g_refSkin[Skin::LAST] = {
  "Warwik",
  "Sylvanas",
  "Variant",
  "Zuljin",
  "Enemy"
};

static const std::string	g_refSkill[Skill::LAST] = {
  "Protective Spirit",
  "Divine Intervention",
  "Berserker's Rage",
  "Quick Jump"
};

Profile::Profile()
  : _id(0),
    _skin(Skin::VARIANT),
    _name("Default_Player"),
    _achievement(Success::LAST, false)
{
}

Profile::~Profile()
{
}

size_t		Profile::getId(void) const
{
  return this->_id;
}

Skin::eSkin	Profile::getSkin(void) const
{
  return this->_skin;
}

std::string const&	Profile::getSkinName(void) const
{
  return g_refSkin[this->_skin];
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

Skill::eSkill			Profile::getSkill(void) const
{
  return this->_skill;
}

std::string const&		Profile::getSkillName(void) const
{
  return g_refSkill[this->_skill];
}

Stat const&			Profile::getStat(void) const 
{
  return this->_stat;
}

const std::vector<bool> &	Profile::getAchievement(void) const
{
  return this->_achievement;
}

std::vector<bool> &		Profile::getAchievement(void)
{
  return this->_achievement;
}

const std::vector<std::string> &	Profile::getSave(void) const
{
  return this->_save;
}

void		Profile::setId(size_t value)
{
  this->_id = value;
}

void		Profile::setSkin(Skin::eSkin value)
{
  this->_skin = value;
}

void		Profile::setConfig(const Config & value)
{
  this->_config = value;
}

void		Profile::setStat(const Stat & s)
{
  this->_stat = s;
}

void		Profile::addConfig(HumGame::eAction a, gdl::Keys::Key k)
{
  this->_config.setConfig(a, k);
}

void		Profile::setName(const std::string & value)
{
  this->_name = value;
}

void		Profile::setSkill(Skill::eSkill value)
{
  this->_skill = value;
}

void		Profile::setAchievement(const std::vector<bool> & value)
{
  this->_achievement = value;
}

void		Profile::setSave(const std::vector<std::string> & value)
{
  this->_save = value;
}

void		Profile::addSave(const std::string & value)
{
  this->_save.push_back(value);
}

void		Profile::removeSave(unsigned int pos)
{
  this->_save.erase(this->_save.begin() + pos);
}
