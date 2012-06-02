/*
 * Texan
 * 25.05.12
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include "Common.hpp"
#include "DirWalker.hpp"
#include "ProfileLoader.hpp"
#include "SaveManager.hpp"

ProfileLoader::ProfileLoader(void)
{
  this->_folder = "./Ressources/profiles/";
  this->setProfiles();
}

bool				ProfileLoader::isNum(std::string str) const
{
  for (int i = 0; str.at(i); ++i)
    if ((str.at(i) < '0') ^ (str.at(i) > '9'))
      return (false);
  return (true);
}

int				ProfileLoader::idToInt(std::string str) const
{
  std::stringstream	os(str);
  int			id;

  os >> id;
  return (id);
}

void				ProfileLoader::checkSaves(void)
{
  bool	isOk = true;

  for (unsigned int i = 0; i < this->_profiles.back()->getSave().size(); ++i)
    {
      std::stringstream	ss(this->_profiles.back()->getSave().at(i));
      size_t		id;

      ss >> id;
      if (!SaveManager::isHere(id))
	{
	  this->_profiles.back()->removeSave(i);
	  isOk = false;
	}
    }
  if (!isOk)
    ProfileManager::setProfile(this->_profiles.back()->getId(), *this->_profiles.back());
}

void				ProfileLoader::setProfiles(void)
{
  DirWalker	_texasRanger(this->_folder);

  while (!(_texasRanger.isEnd()))
    {
      if (this->isNum(*_texasRanger.current()))
	{
	  try
	    {
	      if ((*_texasRanger.current() != ".") && (*_texasRanger.current() != ".."))
		{
		  size_t	id;

		  this->_profiles.push_back(this->_pm.getProfile((id = idToInt(*_texasRanger.current()))));
		  this->_profiles.back()->setId(id);
		  this->_names.push_back(this->_profiles.back()->getName());
		  this->checkSaves();
		}
	    }
	  catch (const std::runtime_error& e)
	    {
	      std::cerr << e.what() << std::endl;
	    }
	}
      _texasRanger.clean();
      ++_texasRanger;
    }
}

const std::vector<Profile *>&	ProfileLoader::getProfiles(void) const
{
  return this->_profiles;
}

const std::vector<std::string>&	ProfileLoader::getNames(void) const
{
  return (this->_names);
}

void				ProfileLoader::unsetProfiles(void)
{
  std::for_each(this->_profiles.begin(), this->_profiles.end(), deleteItem<Profile*>);
}
