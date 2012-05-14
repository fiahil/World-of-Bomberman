/*
 * Fiahil
 * 12.05.2012
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.hpp"

Camera::Camera()
  : _pos(0.0f, 50.0f, 50.0f),
    _target(0.0f, 0.0f, 0.0f),
    _height(600.0f),
    _width(800.0f)
{
}

Camera::Camera(int w, int h)
  : _pos(50.5f, 20.0f, 80.0f),
    _target(3.0f, 1.0f, 3.0f),
    _height(h),
    _width(w)
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
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, static_cast<double>(this->_width) / static_cast<double>(this->_height),
		 1.0f, 10000.0f);
  gluLookAt(this->_pos.x, this->_pos.y, this->_pos.z,
	    this->_target.x, this->_target.y, this->_target.z,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
