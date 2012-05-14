/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "GameClock.hpp"
#include "Input.hpp"
#include "APlayer.hpp"
#include "Vector.hpp"

class Camera
{
public:
  Camera();
  Camera(int, int,  APlayer const*,  APlayer const* pl2 = 0);
  ~Camera();

private:
  int			_height;
  int			_width;
  APlayer const*	_pl1;
  APlayer const*	_pl2;

public:
  void	initialize();
  void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Camera;

#endif
