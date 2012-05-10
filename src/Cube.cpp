/***********************************************************************
 * Module:  Cube.cpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Cube
 ***********************************************************************/

#include "Cube.hpp"

Cube::Cube(Point const& p) : _pos(p), _txt(0), _scale(1.0f)
{
  
}

Cube::Cube(Point const& p, gdl::Image* txt, double scale) : _pos(p), _txt(txt), _scale(scale)
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
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y, this->_pos._pos.z);
  glColor3ub(255, 255, 255);
  glEnable(GL_TEXTURE_2D);
  this->_txt->bind();
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

void	Cube::update(gdl::GameClock const& clock, gdl::Input& input)
{

}
