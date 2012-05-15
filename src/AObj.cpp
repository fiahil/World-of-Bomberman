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

Point const&	AObj::getPos() const
{
  return this->_pos;
}
