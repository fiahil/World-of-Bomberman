/*
 * Fiahil
 * 07.05.12
 */

#include "Point.hpp"

Point::Point(double scale, int x, int y)
  : _x(x),
    _y(y),
    _scale(scale)
{
  this->calcRealpos();
}

Point::Point(double x, double y, double z) // Pour MenuManager
  : _scale(1.0),
    _pos(x, y, z)

{
}

Point::~Point()
{
}

void		Point::setPos(int x, int y)
{
  this->_x = x;
  this->_y = y;
  this->calcRealpos();
}

void		Point::setPos(double x, double y, double z)
{
  this->_pos.x = x;
  this->_pos.y = y;
  this->_pos.z = z;
}

void		Point::calcRealpos(void)
{
  this->_pos.x = this->_scale / 2.0f + static_cast<double>(this->_x) * this->_scale;
  this->_pos.y = this->_scale / 2.0f;
  this->_pos.z = this->_scale / 2.0f + static_cast<double>(this->_y) * this->_scale;
}

bool		Point::operator==(Point const & pos) const
{
  return ((this->_x == pos._x) && (this->_y == pos._y));
}
