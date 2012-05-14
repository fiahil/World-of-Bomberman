/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include <iostream>
#include "Plane.hpp"

Plane::Plane(double w, double h, Point const& p, gdl::Image& img)
  : _w(w),
    _h(h),
    _txt(img)
{
  this->_pos = p;
  this->_pos._pos.x -= this->_pos._scale / 2;
  this->_pos._pos.y -= this->_pos._scale / 2;
  this->_pos._pos.z -= this->_pos._scale / 2;
}

Plane::~Plane()
{
}

void	Plane::initialize()
{
}

void	Plane::draw()
{
  double x = static_cast<double>(this->_txt.getWidth()) / this->_w;
  double y = static_cast<double>(this->_txt.getHeight()) / this->_h;

  if (x > 1.0f)
    x = 1.0f;
  if (y > 1.0f)
    y = 1.0f;
  glPushMatrix();
  std::cout << 
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y, this->_pos._pos.z);
  glScalef(this->_pos._scale, this->_pos._scale, this->_pos._scale);
  glColor3ub(255, 255, 255);
  glEnable(GL_TEXTURE_2D);
  this->_txt.bind();
  glBegin(GL_QUADS);

  glNormal3f(0.0f, 1.0f, 0.0f);
  glTexCoord2d(0, 0);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2d(0, y);
  glVertex3f(0.0f, 0.0f, this->_h);
  glTexCoord2d(x, y);
  glVertex3f(this->_w, 0.0f, this->_h);
  glTexCoord2d(x, 0);
  glVertex3f(this->_w, 0.0f, 0.0f);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void	Plane::update(gdl::GameClock const&, gdl::Input&)
{
}
