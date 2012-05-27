/*
 * Fiahil
 * 25.05.2012
 */

#include <algorithm>
#include "AIView.hpp"

View::View(Elt::eElt elt, size_t i)
  : type(elt), pp(i)
{
}

View::View()
  : type(Elt::EMPTY), pp(0)
{
}

AIView::AIView(Map const& m, std::list<Bomb*> const& eb)
  : _x(m.getX()),
    _y(m.getY())
{
  this->_view.resize(m.getMap().size());
  std::transform(m.getMap().begin(), m.getMap().end(), this->_view.begin(), &AIView::ctor);
  for (std::list<Bomb*>::const_iterator it = eb.begin();
       it != eb.end();
       ++it)
    {
      this->_view[AIPOS((*it)->getPos()._x, (*it)->getPos()._y)].type = Elt::BOMB;
      this->_view[AIPOS((*it)->getPos()._x, (*it)->getPos()._y)].pp = 0;
    }
}

View		AIView::ctor(char const c)
{
  return View(Elt::WALL, c - '0');
}

size_t		AIView::getX(void) const
{
  return this->_x;
}

size_t		AIView::getY(void) const
{
  return this->_y;
}

View const&	AIView::at(size_t x, size_t y) const
{
  x = (x > 0) ? x : 0;
  x = (x < this->_x) ? x : this->_x - 1;
  y = (y > 0) ? y : 0;
  y = (y < this->_y) ? y : this->_y - 1;
  return this->_view.at(AIPOS(x, y));
}
