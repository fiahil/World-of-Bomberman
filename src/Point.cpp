/***********************************************************************
 * Module:  Point.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:29:20 PM
 * Purpose: Implementation of the class Point
 ***********************************************************************/

#include "Point.hpp"

////////////////////////////////////////////////////////////////////////
// Name:       Point::Point(int x, int y)
// Purpose:    Implementation of Point::Point()
// Parameters:
// - x
// - y
// Return:     
////////////////////////////////////////////////////////////////////////

Point::Point(double scale, int x, int y) : _x(x), _y(y), _scale(scale), _rot(0.0f, 0.0f, 0.0f)
{
  this->calcRealpos();
}

////////////////////////////////////////////////////////////////////////
// Name:       Point::Point(int x, int y, Vector const& rot)
// Purpose:    Implementation of Point::Point()
// Parameters:
// - x
// - y
// - rot
// Return:     
////////////////////////////////////////////////////////////////////////

Point::~Point()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Point::calcRealPos()
// Purpose:    Implementation of Point::calcRealPos()
// Return:     
////////////////////////////////////////////////////////////////////////

void	Point::calcRealpos()
{
  this->_pos.x = this->_scale / 2 + this->_x * this->_scale;
  this->_pos.y = this->_scale / 2;
  this->_pos.z = this->_scale / 2 + this->_y * this->_scale;
}
