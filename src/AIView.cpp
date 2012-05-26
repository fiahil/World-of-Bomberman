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

AIView::AIView(Map const& m)
  : _len(m.getX())
{
  this->_view.resize(m.getMap().size());
  std::transform(m.getMap().begin(), m.getMap().end(), this->_view.begin(), &AIView::ctor);
}

View		AIView::ctor(char const c)
{
  return View(Elt::WALL, c - '0');
}

size_t		AIView::getLen(void) const
{
  return this->_len;
}

View const&	AIView::at(size_t x, size_t y) const
{
  return this->_view.at(AIPOS(x, y));
}
