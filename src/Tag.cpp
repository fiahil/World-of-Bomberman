/*
 * Texan
 * 15.05.2012
 */

#include <GL/gl.h>
#include <utility>
#include "Tag.hpp"
#include "Point.hpp"
#include "Plane.hpp"

Tag::Tag(const std::string& normal,
	 const std::string& highlit,
	 bool status, bool textDraw, TokenMenu::eMenu content,
	 double posX, double posY, double posZ)
  : _spritePos(posX, posY, posZ),
    _spriteHighlit(gdl::Image::load(highlit)),
    _spriteNormal(gdl::Image::load(normal)),
    _highlit(_spriteHighlit.getWidth(), _spriteHighlit.getHeight(), _spritePos, _spriteHighlit),
    _normal(_spriteNormal.getWidth(), _spriteNormal.getHeight(), _spritePos, _spriteNormal),
    _status(status),
    _content(content),
{
}

Tag::~Tag()
{
}

TokenMenu::eMenu	Tag::getContent(void) const
{
  return (this->_content);
}

const Point &		Tag::getSpritePos(void) const
{
  return this->_spritePos;
}

void			Tag::setStatus(bool status)
{
  this->_status = status;
}

void			Tag::setTextDraw(bool status)
{
  this->_textDraw = status;
}

void			Tag::pushMatrix(void)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
}

void			Tag::popMatrix(void)
{
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

void			Tag::createText(const std::string & name, int size, int x, int y)
{
  gdl::Text *		text = new gdl::Text;

  text->setText(name);
  text->setSize(size);
  text->setPosition(x, y);
  this->_text = text;
}

void			Tag::draw(void)
{
  if (this->_status)
    this->_highlit.draw();
  else
    this->_normal.draw();
  if (this->_textDraw)
    this->drawText();
}

void			Tag::drawText(void)
{
  this->pushMatrix();
  this->_text->draw();
  this->popMatrix();
}

void		Tag::initialize(void)
{
}

void		Tag::update(gdl::GameClock const&, gdl::Input&)
{
}
