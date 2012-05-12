/*
 * lemonn_v
 * 07.05.12
 */

#include "Vector.hpp"

Vector::Vector()
  : x(0.0f),
    y(0.0f),
    z(0.0f)
{
}

Vector::Vector(double x, double y, double z)
  : x(x),
    y(y),
    z(z)
{
}

Vector::Vector(Vector const& rhs)
{
  if (&rhs != this)
    {
      this->x = rhs.x;
      this->x = rhs.y;
      this->x = rhs.z;
    }
}

Vector&	Vector::operator=(Vector const& rhs)
{
  if (&rhs != this)
    {
      this->x = rhs.x;
      this->x = rhs.y;
      this->x = rhs.z;
    }
  return *this;
}

Vector::~Vector()
{
}
