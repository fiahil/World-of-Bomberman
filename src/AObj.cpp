/*
 * Fiahil
 * 12.05.2012
 */

#include "AObj.hpp"

AObj::AObj() : _pos(1.0f, 0, 0)
{
}

AObj::AObj(AObj const& oldAObj)
  : _pos(oldAObj._pos)
{
}

AObj::~AObj()
{
  // TODO : implement
}

void		AObj::setPos(int x, int y)
{
  this->_pos.setPos(x, y);
}

void		AObj::setPos(double x, double y, double z)
{
  this->_pos._pos.x = x;
  this->_pos._pos.y = y;
  this->_pos._pos.z = z;
}

void		AObj::setScale(double scale)
{
  this->_pos._scale = scale;
}

Point const&	AObj::getPos() const
{
  return this->_pos;
}
