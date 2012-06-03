/*
 * Texan
 * 25.05.2012
 */

#include <algorithm>
#include "DirWalker.hpp"
#include "MapManager.hpp"
#include "Common.hpp"

MapManager::MapManager()
 : _folder("./Ressources/maps/")
{
  this->setMaps();
}

void			MapManager::setMaps(void)
{
  DirWalker	_texasRanger(this->_folder);

  while (!(_texasRanger.isEnd()))
    {
      try
	{
	  if ((*_texasRanger.current() != ".") && (*_texasRanger.current() != ".."))
		this->_maps.push_back(this->getMap(*_texasRanger.current()));
	}
      catch (const std::exception& e)
	{
	  std::cerr << e.what() << std::endl;
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
  return new Map(this->_folder + file, file);
}

const std::vector<Map *>&	MapManager::getAll(void) const
{
  return (this->_maps);
}

void			MapManager::unsetMaps(void)
{
  std::for_each(this->_maps.begin(), this->_maps.end(), deleteItem<Map *>);
}
