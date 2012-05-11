/***********************************************************************
 * Module:  Plane.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Plane
 ***********************************************************************/

#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include <Image.hpp>
#include "AObj.hpp"

class Plane : public AObj
{
private:
  double	_w;
  double	_h;
  gdl::Image&	_txt;
  
public:
  Plane(double, double, Point const&, gdl::Image&);
  ~Plane();
  virtual void	initialize();
  virtual void	draw();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Plane;

#endif
