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

Point::~Point()
{
}

void		Point::setPos(int x, int y)
{
  this->_x = x;
  this->_y = y;
  this->calcRealpos();
}

void		Point::calcRealpos(void)
{
  this->_pos.x = this->_scale / 2.0f + static_cast<double>(this->_x) * this->_scale;
  this->_pos.y = this->_scale / 2.0f;
  this->_pos.z = this->_scale / 2.0f + static_cast<double>(this->_y) * this->_scale;
}
