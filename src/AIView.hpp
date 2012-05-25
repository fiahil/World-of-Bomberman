/*
 * Fiahil
 * 25.05.2012
 */

#include <vector>
#include "Map.hpp"
#include "enum.hpp"

#ifndef __AIVIEW_HPP__
#define __AIVIEW_HPP__

#define AIPOS(px, py) (((this->_len * (py))) + (px))

struct View
{
  View();
  View(Elt::eElt, size_t);

  Elt::eElt	type;
  size_t	pp;
};

class AIView
{
  public:
    AIView(Map const&);
  
  private:
    size_t		_len;
    std::vector<View>	_view;

  public:
    View const&	at(size_t x, size_t y) const;
    size_t	getLen(void) const;

  private:
    static View		ctor(char const c);
};

#endif /* __AIVIEW_HPP__ */

