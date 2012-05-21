/*
 * Fiahil
 * 21 Mai 2012
 */

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Unpackman.hpp"
#include "Packman.hpp"
#include "Scanner.hpp"
#include "DirWalker.hpp"
#include "ProfileManager.hpp"

size_t		ProfileManager::maxId = ProfileManager::getMax();

size_t		ProfileManager::getMax()
{
  size_t	max = 0;

  DirWalker	ranger("./Ressources/profiles/");
  while (!ranger.isEnd())
  {
    if (ranger.current() != 0)
    {
      std::stringstream	ss;
      size_t		tmp;

      ss << *ranger.current();
      ss >> tmp;
      if (max < tmp)
	max = tmp;
    }
    ranger.clean();
    ++ranger;
  }
  return max;
}

bool		ProfileManager::isHere(size_t id)
{
  std::stringstream	ss;
  ss << id;
  DirWalker		ranger("./Ressources/profiles/");

  while (!ranger.isEnd())
  {
    if (ranger.current() != 0 && *ranger.current() == ss.str())
    {
      ranger.clean();
      return true;
    }
    ranger.clean();
    ++ranger;
  }
  return false;
}

Profile*	ProfileManager::getProfile(size_t id)
{
  std::stringstream	ss;
  std::string		root("./Ressources/profiles/");
  ss << id;
  DirWalker		ranger(root);

  while (!ranger.isEnd())
  {
    if (ranger.current() != 0 && *ranger.current() == ss.str())
    {
      Profile*			profile = new Profile();
      Match			ma;
      std::ifstream		input((root + ss.str()).c_str());

      if (!input.good())
	throw std::runtime_error("Bad profile file.");

      Serializer::Unpackman	unpackman(*profile, ma);
      Serializer::Scanner	scanner(input);
      Serializer::Loader	loader(scanner, unpackman);

      loader.parse();
      ranger.clean();
      return profile;
    }
    ranger.clean();
    ++ranger;
  }
  return 0;
}

void		ProfileManager::setProfile(size_t id, Profile const& p)
{
  std::stringstream	ss;
  std::string		root("./Ressources/profiles/");
  ss << id;
  Serializer::Packman	packman(root + ss.str());

  packman.packProfile(p);
}
