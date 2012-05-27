/*
 * Texan
 * 25.05.2012
 */

#ifndef __MAPMANAGER_HPP__
#define __MAPMANAGER_HPP__

#include <vector>
#include "Map.hpp"

class	MapManager
{
private:
  std::vector<Map *>	_maps;

public:
  MapManager(void);

  void				setMaps(void);
  Map*				getMap(size_t);
  Map*				getMap(const std::string&);
  const std::vector<Map *>&	getAll(void) const;
  void				unsetMaps(void);
};

#endif
