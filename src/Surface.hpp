/*
 * lemonn_v
 * 07.05.12
 */

#ifndef __SURFACE_HPP__
#define __SURFACE_HPP__

#include <Image.hpp>
#include "AObj.hpp"

class Surface : public AObj
{
public:
  Surface(double, double, double, double, gdl::Image&);
  virtual ~Surface();

private:
  double	_w;
  double	_h;
  double	_x;
  double	_y;
  gdl::Image&	_txt;

public:
  virtual void	initialize();
  virtual void	draw();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Surface;

#endif /* __PLANE_HPP__ */
