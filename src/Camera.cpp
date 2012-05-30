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

Camera::Camera(int w, int h,  APlayer const* pl1, APlayer const* pl2)
  : _height(h),
    _width(w),
    _pl1(pl1),
    _pl2(pl2)
{
}

Camera::~Camera()
{
}

void		Camera::update()
{
  if (this->_k < 1.0f && !(this->_pos == this->_final))
    {
      this->_k += 0.01f;
      this->_pos.x = this->_origin.x + this->_k * (this->_final.x - this->_origin.x);
      this->_pos.z = this->_origin.z + this->_k * (this->_final.z - this->_origin.z);
      this->_target.x = this->_pos.x;
      this->_target.z = this->_pos.z - 0.1f;
    }
  else
    this->_origin = this->_final;
  this->draw();
}

void		Camera::draw() const
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, static_cast<double>(this->_w) / static_cast<double>(this->_h),
		 1.0f, 10000.0f);
  gluLookAt(this->_pos.x, this->_pos.y, this->_pos.z,
	    this->_target.x, this->_target.y, this->_target.z,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::setPos(double x, double y, double z)
{
  this->_pos.x = x;
  this->_pos.y = y;
  this->_pos.z = z;
  this->_origin.x = x;
  this->_origin.y = y;
  this->_origin.z = z;
  this->_final.x = x;
  this->_final.y = y;
  this->_final.z = z;
  this->_target.x = x;
  this->_target.y = 0.0f;
  this->_target.z = z - 0.1f;
  this->_w = this->_width;
  this->_h = this->_height;
  this->draw();
}

void		Camera::setPosScroll(double x, double y, double z)
{
  this->_pos.x = this->_origin.x;
  this->_pos.y = this->_origin.y;
  this->_pos.z = this->_origin.z;
  this->_target.x = this->_pos.x;
  this->_target.y = 0.0f;
  this->_target.z = this->_pos.z - 0.1f;
  this->_final.x = x;
  this->_final.y = y;
  this->_final.z = z;
  this->_k = 0.0f;
  this->_w = this->_width;
  this->_h = this->_height;
  this->draw();
}

void		Camera::setSplitScreenLeft()
{
  if (this->_pl1)
    {
      this->_w = this->_width / 2 - 10;
      this->_h = this->_height;
      glViewport(0, 0, this->_w, this->_h);
      this->_pos = this->_pl1->getPosReal();
      this->_pos.y += 7.0f * this->_pl1->getPos()._scale;
      this->_pos.z += 4.0f * this->_pl1->getPos()._scale;
      this->_target = this->_pl1->getPosReal();
      this->draw();
    }
}

void		Camera::setSplitScreenRight()
{
  if (this->_pl2)
    {
      this->_w = this->_width / 2 - 10;
      this->_h = this->_height;
      glViewport(this->_w + 20, 0, this->_w, this->_h);
      this->_pos = this->_pl2->getPosReal();
      this->_pos.y += 7.0f * this->_pl2->getPos()._scale;
      this->_pos.z += 4.0f * this->_pl2->getPos()._scale;
      this->_target = this->_pl2->getPosReal();
      this->draw();
    }
}

void		Camera::setNormalScreen()
{
  if (this->_pl1)
    {
      this->_w = this->_width;
      this->_h = this->_height;
      this->_pos = this->_pl1->getPosReal();
      this->_pos.y += 7.0f * this->_pl1->getPos()._scale;
      this->_pos.z += 4.0f * this->_pl1->getPos()._scale;
      this->_target = this->_pl1->getPosReal();
      this->draw();
  }
}

void		Camera::setViewHUD() const
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, this->_w, 0, this->_h);
  glScalef(1, -1, 1);
  glTranslatef(0, -this->_h, 0);
  glMatrixMode(GL_MODELVIEW);
}
