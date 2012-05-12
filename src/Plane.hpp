/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include <Image.hpp>
#include "AObj.hpp"

class Plane : public AObj
{
public:
  Plane(double, double, Point const&, gdl::Image&);
  ~Plane();

private:
  double	_w;
  double	_h;
  gdl::Image&	_txt;

public:
  virtual void	initialize();
  virtual void	draw();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Plane;

#endif /* __PLANE_HPP__ */
