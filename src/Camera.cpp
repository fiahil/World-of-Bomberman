/*
 * Fiahil
 * 12.05.2012
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include "Camera.hpp"

Camera::Camera()
  : _height(600.0f),
    _width(800.0f),
    _pl1(0),
    _pl2(0)
{
}

Camera::Camera(int w, int h,  APlayer const* pl1,  APlayer const* pl2)
  : _height(h),
    _width(w),
    _pl1(pl1),
    _pl2(pl2)
{
}

Camera::~Camera()
{
}

void		Camera::initialize()
{
}

void		Camera::update(gdl::GameClock const&, gdl::Input&)
{
  Vector	pos;
  Vector	target;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, static_cast<double>(this->_width) / static_cast<double>(this->_height),
		 1.0f, 10000.0f);
  pos = this->_pl1->getPos()._pos;
  pos.y += 10.0f * this->_pl1->getPos()._scale;
  pos.z += 10.0f * this->_pl1->getPos()._scale;;
  target = this->_pl1->getPos()._pos;
  gluLookAt(pos.x, pos.y, pos.z,
	    target.x, target.y, target.z,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
