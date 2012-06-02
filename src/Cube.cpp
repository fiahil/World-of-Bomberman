/*
 * Fiahil
 * 12.05.2012
 */

#include <GL/gl.h>
#include "Cube.hpp"

Cube::Cube(gdl::Image& txt)
  : _p(0),
    _txt(txt)
{
}

Cube::~Cube()
{
}

void		Cube::initialize()
{
}

void		Cube::draw()
{
  glPushMatrix();
  glTranslatef(this->_p->_pos.x, this->_p->_pos.y, this->_p->_pos.z);
  glScalef(this->_p->_scale, this->_p->_scale, this->_p->_scale);
  glColor3ub(255, 255, 255);
  glEnable(GL_TEXTURE_2D);
  this->_txt.bind();
  glBegin(GL_QUADS);

  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, -0.5f, 0.5f);

  glNormal3f(1.0f, 0.0f, 0.0f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, -0.5f, -0.5f);

  glNormal3f(-1.0f, 0.0f, 0.0f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, -0.5f, 0.5f);

  glNormal3f(0.0f, 0.0f, -1.0f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, -0.5f, -0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, -0.5f, -0.5f);

  glNormal3f(0.0f, 1.0f, 0.0f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, 0.5f, 0.5f);

  glNormal3f(0.0f, -1.0f, 0.0f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, -0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, -0.5f, 0.5f);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void		Cube::draw(Point& p)
{
  this->_p = &p;
  this->draw();
}

void		Cube::update(gdl::GameClock const&, gdl::Input&)
{
}
