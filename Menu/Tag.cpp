/*
 * Texan
 * 15.05.2012
 */

#include "Tag.hpp"

Tag::Tag(const std::string& normal, const std::string& highlit)
{
  this->_status = false;
  this->_spriteNormal = normal;
  this->_spriteHighlit = highlit;
  this->_normal = this->load(this->_spriteNormal);
  this->_highlit = this->load(this->_spriteHighlit);
}

const gdl::Image	Tag::load(const std::string& path)
{
  return (gdl::Image::load(path));
}

const gdl::Image	Tag::getImage(const eSprite img)
{
  if (img == SELECTED)
    return (this->_highlit);
  else
    return (this->_normal);
}

void			Tag::setStatus(const bool status)
{
  this->_status = status;
}

const bool		Tag::getStatus(void) const
{
  return (this->_status);
}

void	Tag::draw(void) const
{
  if (this->_selected)
    this->_highlit.bind();
  else
    this->_normal.bind();

  /* A checker */
  glTexCoord2f(0.0, 0.0);
  glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
}
