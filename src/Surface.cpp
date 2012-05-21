/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include "Surface.hpp"

Surface::Surface(double w, double h, double x, double y, gdl::Image& img)
  : _w(w),
    _h(h),
    _x(x),
    _y(y),
    _txt(img)
{
}

Surface::~Surface()
{
}

void	Surface::initialize()
{
}

void	Surface::draw()
{
  glEnable(GL_TEXTURE_2D);
  this->_txt.bind();
  glBegin(GL_QUADS);

  glTexCoord2d(0, 0);
  glVertex3f(this->_x, this->_y, 0.0f);
  glTexCoord2d(0, 1);
  glVertex3f(this->_x, this->_h + this->_y, 0.0f);
  glTexCoord2d(1, 1);
  glVertex3f(this->_w + this->_x, this->_h + this->_y, 0.0f);
  glTexCoord2d(1, 0);
  glVertex3f(this->_w + this->_x, this->_y, 0.0f);

  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void	Surface::update(gdl::GameClock const&, gdl::Input&)
{
}
