/*
 * Texan
 * 15.05.2012
 */

#include <iostream>		// REMOVE
#include <GL/gl.h>
#include "Tag.hpp"
#include "Point.hpp"
#include "Plane.hpp"

Tag::Tag(const std::string& normal, const std::string& highlit, bool status, TokenMenu::eMenu content)
  : _spritePos(1.0, 20, 20),				// Mettre en param
    _spriteHighlit(gdl::Image::load(highlit)),
    _spriteNormal(gdl::Image::load(normal)),
    _highlit(50.0, 50.0, _spritePos, _spriteHighlit),	// Mettre en param
    _normal(50.0, 50.0, _spritePos, _spriteNormal),	// Mettre en param
    _status(status),
    _content(content)
{
  std::cout << "Creation Tag" << std::endl;
}

void			Tag::setStatus(bool status)
{
  this->_status = status;
}

void			Tag::draw(void)
{
  if (this->_status)
    this->_highlit.draw();
  else
    this->_normal.draw();
}

Tag::~Tag()
{
  std::cout << "Destruction Tag" << std::endl;
}

void		Tag::initialize(void)
{
}

void		Tag::update(gdl::GameClock const&, gdl::Input&)
{
}
