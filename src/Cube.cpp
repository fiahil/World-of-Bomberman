/***********************************************************************
 * Module:  Cube.cpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Cube
 ***********************************************************************/

#include <GL/gl.h>
#include <iostream>
#include "Cube.hpp"

/*Cube::Cube() : _p(0), _txt(0), _scale(1.0f)
{
  
}*/

Cube::Cube(gdl::Image& txt, double scale) : _p(0), _txt(txt), _scale(scale)
{
  
}

Cube::~Cube()
{

}

void	Cube::initialize()
{
  
}

void	Cube::draw()
{
  glPushMatrix();
  glTranslatef(this->_p->_pos.x, this->_p->_pos.y, this->_p->_pos.z);
  glColor3ub(255, 0, 255);
  glEnable(GL_TEXTURE_2D);
  this->_txt.bind();
  glBegin(GL_QUADS);

  // Front
  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, -0.5f, 0.5f);

  //Right
  glNormal3f(1.0f, 0.0f, 0.0f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, -0.5f, -0.5f);
  
  //Left
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  
  //Back
  glNormal3f(0.0f, 0.0f, -1.0f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, -0.5f, -0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, -0.5f, -0.5f);

  //Top
  glNormal3f(0.0f, 1.0f, 0.0f);
  glTexCoord2d(0, 0);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(0.5f, 0.5f, 0.5f);

  //Bottom
  glNormal3f(0.0f, -1.0f, 0.0f);
  glTexCoord2d(0, 0);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glTexCoord2d(0, 1);
  glVertex3f(0.5f, -0.5f, -0.5f);
  glTexCoord2d(1, 1);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glTexCoord2d(1, 0);
  glVertex3f(-0.5f, -0.5f, 0.5f);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void	Cube::draw(Point& p)
{
  this->_p = &p;
  this->draw();
}

void	Cube::update(gdl::GameClock const&, gdl::Input&)
{

}
