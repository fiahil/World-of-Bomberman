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


Tp::Tp()
  : _pos1(2, 0, 0),
    _pos2(2, 0, 0)
{}

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
  this->_expFunc['3'] = &Map::explodeBreakable;

  this->_modelBreak['t'] = gdl::Model::load("models/Set_tp.FBX"); // tp
  this->_modelBreak['2'] = gdl::Model::load("models/Set_barrel.FBX");
  this->_modelBreak['3'] = gdl::Model::load("models/Set_crate4.FBX");

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
	  this->_map[POS(tx, ty)] = ((random() % 2) + 2) + 48;
      }
      else if (!iwallDensity || !(random() % iwallDensity))
	this->_map[POS(tx, ty)] = ((random() % 2) + 2) + 48;
    }
  }
  this->_map[POS(1, 1)] = '0'; //TODO
  this->_tp._pos1.setPos(random() % (this->_x - 2) + 1, random() % (this->_y - 2) + 1);
  this->_tp._pos2.setPos(random() % (this->_x - 2) + 1, random() % (this->_y - 2) + 1);
  this->_map[POS(this->_tp._pos1._x, this->_tp._pos1._y)] = '0';
  this->_map[POS(this->_tp._pos2._x, this->_tp._pos2._y)] = '0';
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
  this->_expFunc['3'] = &Map::explodeBreakable;

  this->_modelBreak['t'] = gdl::Model::load("models/Bomb_rox.FBX");
  this->_modelBreak['2'] = gdl::Model::load("models/Set_barrel.FBX");
  this->_modelBreak['3'] = gdl::Model::load("models/Set_crate4.FBX");

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

  this->_tp._pos1.setPos(random() % (this->_x - 2) + 1, random() % (this->_y - 2) + 1);
  this->_tp._pos2.setPos(random() % (this->_x - 2) + 1, random() % (this->_y - 2) + 1);
  this->_map[POS(this->_tp._pos1._x, this->_tp._pos1._y)] = '0';
  this->_map[POS(this->_tp._pos2._x, this->_tp._pos2._y)] = '0';
}

Map::Map(size_t x, size_t y, std::string const& map)
  : _x(x),
    _y(y),
    _map(map),
    _modelBonus(BonusType::LAST)
{

  this->_expFunc['1'] = &Map::explodeUnBreakable;
  this->_expFunc['2'] = &Map::explodeBreakable;
  this->_expFunc['3'] = &Map::explodeBreakable;

  this->_modelBreak['t'] = gdl::Model::load("models/Bomb_rox.FBX");
  this->_modelBreak['2'] = gdl::Model::load("models/Set_barrel.FBX");
  this->_modelBreak['3'] = gdl::Model::load("models/Set_crate4.FBX");

  this->_tp._pos1.setPos(random() % this->_x, random() % this->_y);
  this->_tp._pos2.setPos(random() % this->_x, random() % this->_y);
  this->_map[POS(this->_tp._pos1._x, this->_tp._pos1._y)] = '0';
  this->_map[POS(this->_tp._pos2._x, this->_tp._pos2._y)] = '0';
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

void		Map::teleport(Point & pos) const
{
  if (pos == this->_tp._pos1)
    pos = this->_tp._pos2;
  else if (pos == this->_tp._pos2)
    pos = this->_tp._pos1;
}

void		Map::initialize(void)
{
  this->_break = gdl::Image::load("textures/break.jpg");
  this->_unbreak = gdl::Image::load("textures/unbreak.jpg");
  this->_background = gdl::Image::load("textures/background.jpg");
  this->_modelBonus[BonusType::LIFE] = gdl::Model::load("models/Bonus_life.FBX");
  this->_modelBonus[BonusType::BOMB] = gdl::Model::load("models/Bonus_bomb.FBX");
  this->_modelBonus[BonusType::LUST] = gdl::Model::load("models/Bonus_fury.FBX");
  this->_modelBonus[BonusType::POWER] = gdl::Model::load("models/Bonus_power.FBX");
  this->_modelBonus[BonusType::SHIELD] = gdl::Model::load("models/Bonus_shield.FBX");
}

void		Map::draw(void)
{
  Point		p(2.0f, 0, 0);
  Cube		w_unbreak(this->_unbreak);
  Plane		background(this->_x, this->_y, p, this->_background);
  size_t	x0 = 0;
  size_t	y0 = 0;
  size_t	xf = this->_x;
  size_t	yf = this->_y;

  background.draw();
  if (this->_opti)
    {
      x0 = this->_opti->_x - 20;
      if (static_cast<int>(x0) < 0)
	x0 = 0;
      y0 = this->_opti->_y - 15;
      if (static_cast<int>(y0) < 0)
     	y0 = 0;
      xf = this->_opti->_x + 20;
      if (xf > this->_x)
	xf = this->_x;
      yf = this->_opti->_y + 8;
      if (yf > this->_y)
	yf = this->_y;
    }

  for (size_t y = y0; y < yf; ++y)
    for (size_t x = x0; x < xf; ++x) {
      p.setPos(x, y);
      if (this->_map[POS(x, y)] == '1')
	w_unbreak.draw(p);
      else if (this->_map[POS(x, y)] != '0')
	{
	  glPushMatrix();
	  glTranslatef(p._pos.x, p._pos.y - 1.0f, p._pos.z);
	  glScalef(0.4f, 0.4f, 0.4f);
	  this->_modelBreak[this->_map[POS(x, y)]].draw();
	  glPopMatrix();
	}
    }
  glPushMatrix();
  glTranslatef(this->_tp._pos1._pos.x, this->_tp._pos1._pos.y - 1.0f, this->_tp._pos1._pos.z);
  glScalef(0.155f, 0.155f, 0.155f);
  this->_modelBreak['t'].draw();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(this->_tp._pos2._pos.x, this->_tp._pos2._pos.y - 1.0f, this->_tp._pos2._pos.z);
  glScalef(0.155f, 0.155f, 0.155f);
  this->_modelBreak['t'].draw();
  glPopMatrix();
}

void		Map::update(gdl::GameClock const&, gdl::Input&)
{
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

size_t		Map::getWidth() const
{
  return this->_x;
}

size_t		Map::getHeight() const
{
  return this->_y;
}
