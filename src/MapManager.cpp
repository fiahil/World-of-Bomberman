/*
 * Texan
 * 25.05.2012
 */

#include <iostream>
#include <algorithm>
#include "DirWalker.hpp"
#include "MapManager.hpp"

MapManager::MapManager(void)
{
  this->_folder = "./Ressources/maps/";
  this->setMaps();
}

bool			MapManager::isNum(std::string str) const
{
  for (int i = 0; str[i]; ++i)
    if ((str[i] < '0') ^ (str[i] > '9'))
      return (false);
  return (true);
}

void			MapManager::setMaps(void)
{
  DirWalker	_texasRanger(this->_folder);

  while (!(_texasRanger.isEnd()))
    {
      if (this->isNum(*_texasRanger.current()))
	{
	  try
	    {
	      if ((*_texasRanger.current() != ".") && (*_texasRanger.current() != ".."))
		this->_maps.push_back(this->getMap(*_texasRanger.current()));
	    }
	  catch (const std::exception& e)
	    {
	    }
	}
      _texasRanger.clean();
      ++_texasRanger;
    }
}

Map*			MapManager::getMap(size_t idx)
{
  if (idx > this->_maps.size())
    return (0);
  return (this->_maps[idx]);
}

Map*			MapManager::getMap(const std::string& file)
{
  Map*	ret = new Map(this->_folder + file);

  return (ret);
}

const std::vector<Map *>&	MapManager::getAll(void) const
{
  return (this->_maps);
}

static void		freeMap(Map *obj)
{
  if (obj)
    {
      delete (obj);
      obj = 0;
    }
}

void			MapManager::unsetMaps(void)
{
  for_each(this->_maps.begin(), this->_maps.end(), freeMap);
}
