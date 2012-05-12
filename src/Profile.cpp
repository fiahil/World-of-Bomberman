
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

bool		Profile::getTuto(void) const
{
  return this->_tuto;
}

Skin::eSkin		Profile::getSkin(void) const
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


void		Profile::setAllProfile(size_t id, size_t lvl, size_t xp,
				       bool tuto, Skin::eSkin skin,
				       const Config & config,
				       const std::string & name,
				       const std::vector<size_t> & skill,
				       const std::vector<size_t> & achivement,
				       const std::vector<size_t> & save)
{
  this->_id = id;
  this->_lvl = lvl;
  this->_xp = xp;
  this->_tuto = tuto;
  this->_skin = skin;
  this->_name = name;
  this->_skill = skill;
  this->_achivement = achivement;
  this->_save = save;
  this->_config = config;
}
