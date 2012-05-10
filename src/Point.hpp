/***********************************************************************
 * Module:  Point.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:29:20 PM
 * Purpose: Declaration of the class Point
 ***********************************************************************/

#if !defined(__Bomberman_Point_h)
#define __Bomberman_Point_h

class Point
{
public:
  Point(double scale, int x, int y)
  Point(double scale, int i, int j, Vector const& rot);
  ~Point();
  
  int _x;
  int _y;
  double _scale;
  Vector _pos;
  Vector _rot;

protected:
private:
  void	calcRealpos();

};

#endif
