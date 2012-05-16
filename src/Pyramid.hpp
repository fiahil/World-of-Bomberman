/*
 * lemonn_v
 * 15.05.2012
 */

#ifndef __PYRAMID_HPP__
#define __PYRAMID_HPP__

#include "AObj.hpp"

class Pyramid : public AObj
{
public:
  Pyramid(double, double, double, size_t);
  ~Pyramid();

private:
  double	_w;
  double	_h;
  double	_H;
  size_t	_color;

public:
  virtual void	initialize();
  virtual void	draw();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Pyramid;

#endif
