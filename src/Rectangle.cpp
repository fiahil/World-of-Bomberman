/*
 * NicoW
 * 15.05.12
 */

#include "Rectangle.hpp"

Rectangle::Rectangle(gdl::Image& txt)
  : _p(0),
    _txt(txt)
{
}

Rectangle::~Rectangle()
{
}

void		Rectangle::initialize(void)
{
}

void		Rectangle::draw(void)
{
}

void		Rectangle::draw(Point& p)
{
  this->_p = &p;
  this->draw();
}
void		Rectangle::update(gdl::GameClock const&, gdl::Input&)
{
}
