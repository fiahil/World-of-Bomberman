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
   Point(int i, int j, int x, int y, int z, int rx, int ry, int rz);
   ~Point();

   int _x;
   int _y;
   Vector _pos;
   Vector _rot;

protected:
private:

};

#endif