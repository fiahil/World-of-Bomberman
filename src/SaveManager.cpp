/*
 * lemonn_v
 * 21 Mai 2012
 */

#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Unpackman.hpp"
#include "Scanner.hpp"
#include "Packman.hpp"
#include "DirWalker.hpp"
#include "SaveManager.hpp"

size_t		SaveManager::maxId = SaveManager::getMax();

size_t		SaveManager::getMax()
{
  size_t	max = 0;
  size_t	tmp;
  std::stringstream	ss;
  
  DirWalker	ranger("./Ressources/saves/");
  
  while (!ranger.isEnd())
    {
      if (ranger.current())
	{
	  ss << *ranger.current();
	  ss >> tmp;
	  if (max < tmp)
	    max = tmp;
	  ss.str("");
	  ss.clear();
	}
      ranger.clean();
      ++ranger;
    }
  return max;
}

bool		SaveManager::isHere(size_t id)
{
  std::stringstream	ss;
  ss << id;
  DirWalker		ranger("./Ressources/saves/");

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

bool		SaveManager::getSave(size_t id, Match& ma)
{
  std::stringstream	ss;
  std::string		root("./Ressources/saves/");
  ss << id;
  DirWalker		ranger(root);
  
  while (!ranger.isEnd())
    {
      if (ranger.current() != 0 && *ranger.current() == ss.str())
	{
	  Profile	profile;
	  std::ifstream		input((root + ss.str()).c_str());
	  
	  if (!input.good())
	    throw std::runtime_error("Bad save file.");
	  
	  Serializer::Unpackman	unpackman(profile, ma);
	  Serializer::Scanner	scanner(input);
	  Serializer::Loader	loader(scanner, unpackman);
	  
	  loader.parse();
	  ranger.clean();
	  return true;
	}
      ranger.clean();
      ++ranger;
    }
  return false;
}

void		SaveManager::setSave(size_t id, Match const& p)
{
  std::stringstream	ss;
  std::string		root("./Ressources/saves/");
  ss << id;
  Serializer::Packman	packman(root + ss.str());

  packman.packMatch(p);
}
