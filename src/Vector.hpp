/***********************************************************************
 * Module:  Vector.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Vector
 ***********************************************************************/

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

class Vector
{
public:
  double	x;
  double	y;
  double	z;

public:
  Vector();
  Vector(double, double, double);
  Vector(Vector const&);
  Vector&	operator=(Vector const&);
  ~Vector();
};

#else

class Vector;

#endif
