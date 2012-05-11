/***********************************************************************
 * Module:  Map.cpp
 * Author:  Fiahil
 * Modified: Thursday, May 10, 2012 10:28:54 AM
 * Purpose: Implementation of the class Map
 ***********************************************************************/

#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Cube.hpp"
#include "Plane.hpp"
#include "Map.hpp"

////////////////////////////////////////////////////////////////////////
// Name:       Map::break(Pattern origin, std::list<Bonus>& bonus)
// Purpose:    Implementation of Map::break()
// Parameters:
// - origin
// - bonus
// Return:     Pattern
////////////////////////////////////////////////////////////////////////

/*Pattern Map::explode(Pattern origin, std::list<Bonus>& bonus)
{
   // TODO : implement
   }*/

////////////////////////////////////////////////////////////////////////
// Name:       Map::Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity)
// Purpose:    Implementation of Map::Map()
// Parameters:
// - x
// - y
// - dwallDensity
// - iwallDensity
////////////////////////////////////////////////////////////////////////

Map::Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity)
  : _x(x), _y(y), _map("")
{
  /* TODO Move */
  time_t now;

  time(&now);
  srandom(now);
  /* TODO Move */
  for (size_t i = 0; i < (x * y); ++i)
    this->_map += "0";
  for (size_t ty = 0; ty < y; ++ty) {
    for (size_t tx = 0; tx < x; ++tx) {
      if ((tx == 0) || (ty == 0) ||
          (tx == (x - 1)) || (ty == (y - 1)))
        this->_map[POS(tx, ty)] = '1';
      else if ((!(ty % 2) && !(tx % 2)))
        {
          if (!dwallDensity || !(random() % dwallDensity))
            this->_map[POS(tx, ty)] = '1';
	  else
            this->_map[POS(tx, ty)] = '2';
        }
      else if (!iwallDensity || !(random() % iwallDensity))
	this->_map[POS(tx, ty)] = '2';
    }
  }
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::Map(std::string file)
// Purpose:    Implementation of Map::Map()
// Parameters:
// - file
////////////////////////////////////////////////////////////////////////

Map::Map(std::string const& file)
  : _x(0), _y(0), _map("")
{
  std::string swap;
  std::ifstream infile;
  std::stringstream ss;

  infile.open (file.c_str(), std::ifstream::in);
  if (!infile)
    throw std::exception(); /* TODO BETTER */
  std::getline(infile, swap);
  ss << swap;
  ss >> this->_x;
  ss >> this->_y;
  while (!infile.eof()) {
    std::getline(infile, swap);
    this->_map += swap;
  }
  if (this->_map.size() != (this->_x * this->_y))
    throw std::exception(); /* TODO BETTER */
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::Map(size_t x, size_t y, std::string map)
// Purpose:    Implementation of Map::Map()
// Parameters:
// - x
// - y
// - map
////////////////////////////////////////////////////////////////////////

Map::Map(size_t x, size_t y, std::string const& map)
  : _x(x), _y(y), _map(map)
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::~Map()
// Purpose:    Implementation of Map::~Map()
////////////////////////////////////////////////////////////////////////

Map::~Map()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::Map(const Map& oldMap)
// Purpose:    Implementation of Map::Map()
// Parameters:
// - oldMap
////////////////////////////////////////////////////////////////////////

/*Map::Map(Map const& oldMap)
{
   _map = oldMap._map;
   _x = oldMap._x;
   _y = oldMap._y;
   }*/

////////////////////////////////////////////////////////////////////////
// Name:       Map::initialize()
// Purpose:    Implementation of Map::initialize()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Map::initialize(void)
{
  this->_break = gdl::Image::load("break.jpg");
  this->_unbreak = gdl::Image::load("unbreak.jpg");
  this->_background = gdl::Image::load("background.jpg");
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::draw()
// Purpose:    Implementation of Map::draw()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Map::draw(void)
{
  Point	p(2.0f, 0, 0);
  Cube	w_break(this->_break);
  Cube	w_unbreak(this->_unbreak);
  Plane	background(this->_x, this->_y, p, this->_background);

  background.draw();
  for (size_t y = 0; y < this->_y; ++y)
    for (size_t x = 0; x < this->_x; ++x)
      {
	p.setPos(x, y);
	if (this->_map[POS(x, y)] == '1')
	  w_unbreak.draw(p);
	else if (this->_map[POS(x, y)] == '2')
	  w_break.draw(p);
      }
}

////////////////////////////////////////////////////////////////////////
// Name:       Map::update(gdl::GameClock const& clock, gdl::Input& input)
// Purpose:    Implementation of Map::update()
// Parameters:
// - clock
// - input
// Return:     void
////////////////////////////////////////////////////////////////////////

void Map::update(gdl::GameClock const&, gdl::Input&)
{
   // TODO : implement
}
