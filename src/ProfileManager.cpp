/*
 * Fiahil
 * 21 Mai 2012
 */

#include <sstream>
#include "Packman.hpp"
#include "DirWalker.hpp"
#include "ProfileManager.hpp"

size_t		ProfileManager::maxId;

bool		ProfileManager::isHere(size_t id)
{
  std::stringstream	ss;
  ss << id;
  DirWalker		ranger("./Ressources/profiles/");

  while (!ranger.isEnd())
  {
    if (*ranger.current() == ss.str())
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
  ss << id;
  DirWalker		ranger("./Ressources/profiles/");
  return new Profile();
}

void		ProfileManager::setProfile(size_t id, Profile const& p)
{
  std::stringstream	ss;
  ss << id;
  Serializer::Packman	packman(ss.str());

  packman.packProfile(p);
}
