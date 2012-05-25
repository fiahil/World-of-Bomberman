/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

class	Vector
{
public:
  Vector();
  Vector(double, double, double);
  Vector(Vector const&);
  Vector&	operator=(Vector const&);
  ~Vector();
  bool	operator==(Vector const&) const;

public:
  double	x;
  double	y;
  double	z;
};

#else

class Vector;

#endif /* __VECTOR_HPP__ */
