/***********************************************************************
 * Module:  AObj.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Implementation of the class AObj
 ***********************************************************************/

#include "AObj.hpp"

////////////////////////////////////////////////////////////////////////
// Name:       AObj::AObj()
// Purpose:    Implementation of AObj::AObj()
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::AObj() : _pos(1.0f, 0, 0)
{
}

////////////////////////////////////////////////////////////////////////
// Name:       AObj::~AObj()
// Purpose:    Implementation of AObj::~AObj()
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::~AObj()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AObj::AObj(const AObj& oldAObj)
// Purpose:    Implementation of AObj::AObj()
// Parameters:
// - oldAObj
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::AObj(AObj const& oldAObj) : _pos(oldAObj._pos)
{
}

void	AObj::setPos(int x, int y)
{
  this->_pos.setPos(x, y);
}

Point const&	AObj::getPos() const
{
  return this->_pos;
}
