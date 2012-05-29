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
  Camera(int, int,  APlayer const* = 0, APlayer const* = 0);
  virtual ~Camera();

private:
  int			_height;
  int			_width;
  int			_h;
  int			_w;
  Vector		_origin;
  double		_k;
  Vector		_final;
  Vector		_pos;
  Vector		_target;
  APlayer const*	_pl1;
  APlayer const*	_pl2;

private:
  void	draw() const;

public:
  void	update();
  void	setPos(double, double, double);
  void	setPosScroll(double, double, double);
  void	setSplitScreenLeft();
  void	setSplitScreenRight();
  void	setNormalScreen();
  void	setViewHUD() const;
};

#else

class Camera;

#endif
