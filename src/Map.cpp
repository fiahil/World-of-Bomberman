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
    _y(y),
    _modelBonus(BonusType::LAST)
{
  /* TODO Move */
  time_t now;

  time(&now);
  srandom(now);
  /* TODO Move */

  this->_expFunc['1'] = &Map::explodeUnBreakable;
  this->_expFunc['2'] = &Map::explodeBreakable;

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
  this->_map[POS(1, 1)] = '0'; //TODO
}

Map::Map(std::string const& file)
  : _x(0),
    _y(0),
    _modelBonus(BonusType::LAST)
{
  std::string swap;
  std::ifstream infile;
  std::stringstream ss;

  this->_expFunc['1'] = &Map::explodeUnBreakable;
  this->_expFunc['2'] = &Map::explodeBreakable;

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
  this->_map[POS(1, 1)] = '0'; //TODO
}

Map::Map(size_t x, size_t y, std::string const& map)
  : _x(x),
    _y(y),
    _map(map),
    _modelBonus(BonusType::LAST)
{
  this->_expFunc['1'] = &Map::explodeUnBreakable;
  this->_expFunc['2'] = &Map::explodeBreakable;
  this->_map[POS(1, 1)] = '0'; //TODO
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
  this->_modelBonus[BonusType::LIFE] = gdl::Model::load("models/rock.fbx");
  this->_modelBonus[BonusType::BIGBOMB] = gdl::Model::load("models/stump.fbx");
  this->_modelBonus[BonusType::MEGABOMB] = gdl::Model::load("models/stump.fbx");
  this->_modelBonus[BonusType::LUST] = gdl::Model::load("models/stump.fbx");
  this->_modelBonus[BonusType::POWER] = gdl::Model::load("models/stump.fbx");
  this->_modelBonus[BonusType::SHIELD] = gdl::Model::load("models/stump.fbx");
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

void		Map::explodeUnBreakable(size_t &r, size_t &f, size_t, std::list<Bonus*>&)
{
  --r;
  f = r;
}

void		Map::explodeBreakable(size_t &r, size_t &f, size_t pos, std::list<Bonus*>& bonus)
{
  f = r;
  this->_map[pos] = '0';
  int rand = random() % (BonusType::LAST + 3);
  if (rand < BonusType::LAST)
    {
      Point	p(*this->_opti);
      p.setPos(pos % this->_y, pos / this->_y);
      bonus.push_back(new Bonus(static_cast<BonusType::eBonus>(rand), p, this->_modelBonus[rand]));
    }
}

void		Map::explode(Pattern& real, Pattern& final, std::list<Bonus*>& bonus)
{
  char elem;

  if ((elem = this->_map[POS(final._x, final._y - real._coefN)]) != '0')
    (this->*(this->_expFunc[elem]))(
				    real._coefN,
				    final._coefN,
				    POS(final._x, final._y - real._coefN),
				    bonus
				    );
  if ((elem = this->_map[POS(final._x, final._y + real._coefS)]) != '0')
    (this->*(this->_expFunc[elem]))(
				    real._coefS,
				    final._coefS,
				    POS(final._x, final._y + real._coefS),
				    bonus
				    );
  if ((elem = this->_map[POS(final._x + real._coefE, final._y)]) != '0')
    (this->*(this->_expFunc[elem]))(
				    real._coefE,
				    final._coefE,
				    POS(final._x + real._coefE, final._y),
				    bonus
				    );
  if ((elem = this->_map[POS(final._x - real._coefW, final._y)]) != '0')
    (this->*(this->_expFunc[elem]))(
				    real._coefW,
				    final._coefW,
				    POS(final._x - real._coefW, final._y),
				    bonus
				    );
}
