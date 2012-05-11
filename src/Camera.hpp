/***********************************************************************
 * Module:  Camera.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Camera
 ***********************************************************************/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <GameClock.hpp>
#include <Input.hpp>
#include "Vector.hpp"

class Camera
{
private:
  Vector	_pos;
  Vector	_target;
  int		_height;
  int		_width;

public:
  Camera();
  Camera(int, int);
  ~Camera();
  void	initialize();
  void	update(gdl::GameClock const&, gdl::Input&);
};

#else

class Camera;

#endif
