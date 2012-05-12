/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "GameClock.hpp"
#include "Input.hpp"
#include "Vector.hpp"

class Camera
{
public:
  Camera();
  Camera(int, int);
  ~Camera();

private:
  Vector	_pos;
  Vector	_target;
  int		_height;
  int		_width;

public:
  void	initialize();
  void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Camera;

#endif
