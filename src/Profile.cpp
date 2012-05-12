//
// Profile.cpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 11:54:48 2012 nicolas magere
// Last update Thu May 10 17:33:09 2012 nicolas magere
//

#include <vector>
#include <iostream>
#include "Profile.hpp"

Profile::Profile()
{
  /**/std::cout << "Construction Profile" << std::endl;
  this->_tuto = false;
  this->_name = "Default_Player";
}

Profile::~Profile()
{
  /**/std::cout << "Destruction Profile" << std::endl;
}

Profile::Profile(const Profile & oth)
{
  /**/std::cout << "Construction Profile" << std::endl;
  this->_id = oth.getId();
  this->_lvl = oth.getLvl();
  this->_xp = oth.getXp();
  this->_strength = oth.getStrength();
  this->_endurance = oth.getEndurance();
  this->_agility = oth.getAgility();
  this->_intelligence = oth.getIntelligence();
  this->_spirit = oth.getSpirit();
  this->_tuto = oth.getTuto();
  this->_skin = oth.getSkin();
  this->_name = oth.getName();
  this->_skill = oth.getSkill();
  this->_achivement = oth.getAchivement();
  this->_save = oth.getSave();
  this->_config = oth.getConfig();
}

const Profile & Profile::operator=(const Profile & oth)
{
  if (this != &oth)
    {
      this->_id = oth.getId();
      this->_lvl = oth.getLvl();
      this->_xp = oth.getXp();
      this->_strength = oth.getStrength();
      this->_endurance = oth.getEndurance();
      this->_agility = oth.getAgility();
      this->_intelligence = oth.getIntelligence();
      this->_spirit = oth.getSpirit();
      this->_tuto = oth.getTuto();
      this->_skin = oth.getSkin();
      this->_name = oth.getName();
      this->_skill = oth.getSkill();
      this->_achivement = oth.getAchivement();
      this->_save = oth.getSave();
      this->_config = oth.getConfig();
    }
  return *this;
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

size_t		Profile::getStrength(void) const
{
  return this->_strength;
}

size_t		Profile::getEndurance(void) const
{
  return this->_endurance;
}

size_t		Profile::getAgility(void) const
{
  return this->_agility;
}

size_t		Profile::getIntelligence(void) const
{
  return this->_intelligence;
}

size_t		Profile::getSpirit(void) const
{
  return this->_spirit;
}

bool		Profile::getTuto(void) const
{
  return this->_tuto;
}

t_skin		Profile::getSkin(void) const
{
  return this->_skin;
}

const Config &			Profile::getConfig(void) const
{
  return this->_config;
}

const std::string &	Profile::getName(void) const
{
  return this->_name;
}

const std::vector<size_t> &	Profile::getSkill(void) const
{
  return this->_skill;
}

const std::vector<size_t> &	Profile::getAchivement(void) const
{
  return this->_achivement;
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
}

void		Profile::setStrength(size_t value)
{
  this->_strength = value;
}

void		Profile::setEndurance(size_t value)
{
  this->_endurance = value;
}

void		Profile::setAgility(size_t value)
{
  this->_agility = value;
}

void		Profile::setIntelligence(size_t value)
{
  this->_intelligence = value;
}

void		Profile::setSpirit(size_t value)
{
  this->_spirit = value;
}

void		Profile::setTuto(bool value)
{
  this->_tuto = value;
}

void		Profile::setSkin(t_skin value)
{
  this->_skin = value;
}

void		Profile::setConfig(const Config & value)
{
  this->_config = value;
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

void		Profile::setAchivement(const std::vector<size_t> & value)
{
  this->_achivement = value;
}

void		Profile::addAchivement(size_t value)
{
  this->_achivement.push_back(value);
}

void		Profile::setSave(const std::vector<size_t> & value)
{
  this->_save = value;
}

void		Profile::addSave(size_t value)
{
  this->_save.push_back(value);
}


void		Profile::setAllProfile(size_t id, size_t lvl, size_t xp, size_t strength,
				       size_t endurance, size_t agility, size_t intelligence, size_t spirit,
				       bool tuto, t_skin skin,
				       const Config & config,
				       const std::string & name,
				       const std::vector<size_t> & skill,
				       const std::vector<size_t> & achivement,
				       const std::vector<size_t> & save)
{
  this->_id = id;
  this->_lvl = lvl;
  this->_xp = xp;
  this->_strength = strength;
  this->_endurance = endurance;
  this->_agility = agility;
  this->_intelligence = intelligence;
  this->_spirit = spirit;
  this->_tuto = tuto;
  this->_skin = skin;
  this->_name = name;
  this->_skill = skill;
  this->_achivement = achivement;
  this->_save = save;
  this->_config = config;
}
