/*
 * Texan
 * 15.05.2012
 */

#include <iostream>		// REMOVE
#include <GL/gl.h>
#include "Tag.hpp"

Tag::Tag(const std::string& normal, const std::string& highlit, bool status, TokenMenu::eMenu content)
  : _spriteHighlit(highlit),
    _spriteNormal(normal),
    _status(status),
    _content(content)
{
  gdl::Image	load1 = this->load(this->_spriteHighlit);
  gdl::Image	load2 = this->load(this->_spriteNormal);

  std::cout << "Creation Tag" << std::endl;

  // this->_square = new Rectangle(/*IMAGE*/);
  // this->_squareCoord = ???;
  this->_highlit = &load1;
  this->_normal = &load2;
}

const gdl::Image	Tag::load(const std::string& path)
{
  return (gdl::Image::load(path));
}

const gdl::Image *	Tag::getImage(const Sprite::eSprite& img)
{
  if (img == Sprite::SELECTED)
    return (this->_highlit);
  return (this->_normal);
}

void			Tag::setStatus(bool status)
{
  this->_status = status;
}

bool			Tag::getStatus(void) const
{
  return (this->_status);
}

void			Tag::draw(void)
{
  if (this->_status)
    this->_highlit->bind();
  else
    this->_normal->bind();

  // /* A checker */
  // glTexCoord2f(0, 0);
  // glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  // glTexCoord2f(0, 1);
  // glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  // glTexCoord2f(1, 1);
  // glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
  // glTexCoord2f(1, 0);
  // glVertex3f(this->_squareCoord[0], this->_squareCoord[1], this->_squareCoord[2]);
}

Tag::~Tag()
{
  std::cout << "Destruction Tag" << std::endl;

  delete this->_highlit;
  delete this->_normal;
}
