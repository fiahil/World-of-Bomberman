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
    _highlit(_spriteHighlit./*get sprite x (gdl::Image)*/, _spriteHighlit./*get sprite y (gdl::Image)*/, _spritePos, _spriteHighlit),
    _normal(_spriteNormal./*get sprite x (gdl::Image)*/, _spriteNormal./*get sprite y (gdl::Image)*/, _spritePos, _spriteNormal),
    _status(status),
    _text(0)
    _content(content),
{
}

TokenMenu::eMenu	Tag::getContent(void) const
{
  return (this->_content);
}

bool			Tag::getStatus(void) const
{
  return (this->_status);
}

const Point &		Tag::getSpritePos(void) const
{
  return this->_spritePos;
}

void			Tag::setStatus(bool status)
{
  this->_status = status;
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
  if (this->_text != 0)
    this->drawText();
}

void			Tag::drawText(void)
{
  if (this->_text != 0)
    {
      this->pushMatrix();
      this->_text->draw();
      this->popMatrix();
    }
}

void			deleteText(gdl::Text * obj)
{
  if (obj != 0)
    {
      delete obj;
      obj = 0;
    }
}

Tag::~Tag()
{
  deleteText(this->_text);
}

void		Tag::initialize(void)
{
}

void		Tag::update(gdl::GameClock const&, gdl::Input&)
{
}
