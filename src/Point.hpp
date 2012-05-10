/***********************************************************************
 * Module:  Point.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:29:20 PM
 * Purpose: Declaration of the class Point
 ***********************************************************************/

#if !defined(__Bomberman_Point_h)
#define __Bomberman_Point_h

#include "Vector.hpp"

class Point
{
public:
  Point(double scale, int x, int y);
  ~Point();
  void	setPos(int x, int y);
  
  int _x;
  int _y;
  double _scale;
  Vector _pos;

protected:
private:
  void	calcRealpos();

};

#endif
