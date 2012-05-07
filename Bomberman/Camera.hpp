//
// Camera.hpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 11:56:59 2012 vincent lemonnier
// Last update Mon May  7 14:27:23 2012 vincent lemonnier
//

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <GameClock.hpp>
#include <Input.hpp>

class Vector
{
public:
  double	x;
  double	y;
  double	z;

public:
  Vector(double, double, double);
  ~Vector();
};

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
