//
// Camera.cpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 13:48:17 2012 vincent lemonnier
// Last update Thu May 10 11:59:05 2012 vincent lemonnier
//

#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.hpp"

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z)
{

}

Vector::~Vector()
{

}

Camera::Camera() : _pos(0.0f, 100.0f, 800.0f), _target(0.0f, 0.0f, 0.0f), _height(600.0f), _width(800.0f)
{
  
}

Camera::Camera(int w, int h) : _pos(0.0f, 100.0f, 800.0f), _target(0.0f, 100.0f, 0.0f), _height(h), _width(w)
{
  
}

Camera::~Camera()
{
  
}

void	Camera::initialize()
{
  /*  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, static_cast<double>(this->_width) / static_cast<double>(this->_height),
		 1.0f, 10000.0f);
  gluLookAt(this->_pos.x, this->_pos.y, this->_pos.z,
	    this->_target.x, this->_target.y, this->_target.z,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);*/
}

void	Camera::update(gdl::GameClock const&, gdl::Input&)
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
