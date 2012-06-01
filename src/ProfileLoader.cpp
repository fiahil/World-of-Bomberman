#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "DirWalker.hpp"
#include "ProfileLoader.hpp"

ProfileLoader::ProfileLoader(void)
{
  this->_folder = "./Ressources/profiles/";
  this->setProfiles();
}

bool				ProfileLoader::isNum(std::string str) const
{
  for (int i = 0; str[i]; ++i)
    if ((str[i] < '0') ^ (str[i] > '9'))
      return (false);
  return (true);
}

int				ProfileLoader::idToInt(std::string str)
{
  std::stringstream	os(str);
  int			id;

  os >> id;
  return (id);
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
  return (this->_profiles);
}

static void	freeProfile(Profile *_profile)
{
  if (_profile)
    {
      delete (_profile);
      _profile = 0;
    }
}

const std::vector<std::string>&	ProfileLoader::getNames(void) const
{
  return (this->_names);
}

void				ProfileLoader::unsetProfiles(void)
{
  for_each(this->_profiles.begin(), this->_profiles.end(), freeProfile);
}
