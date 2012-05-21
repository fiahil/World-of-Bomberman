/*
 * Fiahil
 * 07.05.12
 */

#ifndef	__Bomberman_Point_h
#define __Bomberman_Point_h

#include "Vector.hpp"

class	Point
{
public:
  Point(double, int, int);
  Point(double, double, double); // Pour MenuManager
  ~Point();

public:
  int		_x;
  int		_y;
  double	_scale;
  Vector	_pos;

public:
  void		setPos(int, int);
  void		setPos(double, double, double);
  void		calcRealpos(void);
};

#endif /* __Bomberman_Point_h */
