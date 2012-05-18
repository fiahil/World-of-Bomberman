/*
 * busina_b
 * 10.05.12
 */

#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "Cube.hpp"
#include "Plane.hpp"
#include "Map.hpp"


Map::Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity)
  : _x(x),
    _y(y)
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
      else if ((!(ty % 2) && !(tx % 2))) {
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

Map::Map(std::string const& file)
  : _x(0),
    _y(0)
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

Map::Map(size_t x, size_t y, std::string const& map)
  : _x(x),
    _y(y),
    _map(map)
{
}

Map::~Map()
{
}

/*
  Map::Map(Map const& oldMap)
  {
  _map = oldMap._map;
  _x = oldMap._x;
  _y = oldMap._y;
  }
*/

void		Map::initialize(void)
{
  this->_break = gdl::Image::load("textures/break.jpg");
  this->_unbreak = gdl::Image::load("textures/unbreak.jpg");
  this->_background = gdl::Image::load("textures/background.jpg");
}

void		Map::draw(void)
{
  Point		p(2.0f, 0, 0);
  Cube		w_break(this->_break);
  Cube		w_unbreak(this->_unbreak);
  Plane		background(this->_x, this->_y, p, this->_background);
  size_t	x0 = 0;
  size_t	y0 = 0;
  size_t	xf = this->_x;
  size_t	yf = this->_y;

  background.draw();
  if (this->_opti)
    {
      x0 = this->_opti->_x - 45;
      if (static_cast<int>(x0) < 0)
	x0 = 0;
      y0 = this->_opti->_y - 50;
      if (static_cast<int>(y0) < 0)
     	y0 = 0;
      xf = this->_opti->_x + 45;
      if (xf > this->_x)
	xf = this->_x;
      yf = this->_opti->_y + 10;
      if (yf > this->_y)
	yf = this->_y;
    }
  for (size_t y = y0; y < yf; ++y)
    for (size_t x = x0; x < xf; ++x) {
      p.setPos(x, y);
      if (this->_map[POS(x, y)] == '1')
	w_unbreak.draw(p);
      else if (this->_map[POS(x, y)] == '2')
	w_break.draw(p);
    }
}

void		Map::update(gdl::GameClock const&, gdl::Input&)
{
  // TODO : implement
}

bool Map::canMoveAt(size_t x, size_t y)
{
  return (this->_map[POS(x, y)] == '0');
}

void		Map::setOptimization(Point const* p)
{
  this->_opti = p;
}

std::string const&	Map::getMap(void) const
{
  return this->_map;
}

void		Map::explode(Pattern& real, Pattern& final)
{
  // if (this->_map[POS(final._x, final._y + real._coefN)] != '0')
  //   {
  //     --real._coefN;
  //     final._coefN = real._coefN;
  //   }
  // if (this->_map[POS(final._x, final._y - real._coefS)] != '0')
  //   {
  //     --real._coefS;
  //     final._coefS = real._coefS;
  //   }
  // if (this->_map[POS(final._x + real._coefE, final._y)] != '0')
  //   {
  //     --real._coefE;
  //    final._coefE = real._coefE;
  //   }
  // if (this->_map[POS(final._x - real._coefW, final._y)] != '0')
  //   {
  //     --real._coefW;
  //     final._coefW = real._coefW;
  //   }
  std::cout << ".:: Explode MAP ::." << std::endl;
  std::cout << "coef N : real = " << real._coefN << " | final = " << final._coefN << std::endl;
  std::cout << "coef S : real = " << real._coefS << " | final = " << final._coefS << std::endl;
  std::cout << "coef E : real = " << real._coefE << " | final = " << final._coefE << std::endl;
  std::cout << "coef W : real = " << real._coefW << " | final = " << final._coefW << std::endl;
}
