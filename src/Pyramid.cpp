/*
 * lemonn_v
 * 15.05.2012
 */

#include <GL/gl.h>
#include "ContentColor.hpp"
#include "Pyramid.hpp"

Pyramid::Pyramid(double w, double h, double H, size_t color)
  : _w(w),
    _h(h),
    _H(H),
    _color(color)
{
}

Pyramid::~Pyramid()
{
}

void	Pyramid::initialize()
{
}

void	Pyramid::draw()
{
  glPushMatrix();
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y + 1.0f, this->_pos._pos.z);
  glScalef(this->_w, this->_H, this->_h);
  glColor3ub(ContentColor::getColorFromId(this->_color).R,
	     ContentColor::getColorFromId(this->_color).G,
	     ContentColor::getColorFromId(this->_color).B);

  glBegin(GL_QUADS);

  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);

  glEnd();

  glBegin(GL_TRIANGLES);

  glNormal3f(0.0f, -0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(0.0f, -0.5f, 0.0f);

  glNormal3f(-0.5f, -0.5f, 0.0f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(0.0f, -0.5f, 0.0f);

  glNormal3f(0.0f, -0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(0.0f, -0.5f, 0.0f);

  glNormal3f(0.5f, -0.5f, 0.0f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(0.0f, -0.5f, 0.0f);

  glEnd();

  glPopMatrix();
}

void	Pyramid::update(gdl::GameClock const&, gdl::Input&)
{
}

void	Pyramid::setColor(size_t id)
{
  this->_color = id;
}
