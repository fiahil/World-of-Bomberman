/*
 * Fiahil
 * 25.05.2012
 */

#include <vector>
#include <list>
#include "Bomb.hpp"
#include "Map.hpp"
#include "enum.hpp"

#ifndef __AIVIEW_HPP__
#define __AIVIEW_HPP__

#define AIPOS(px, py) (((this->_x * (py))) + (px))

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
  size_t		_x;
  size_t		_y;
  std::vector<View>	_view;

public:
  View const&	at(size_t x, size_t y) const;
  void		setBombAt(size_t x, size_t y);
  void		setBonusAt(size_t x, size_t y, BonusType::eBonus b);
  size_t	getX(void) const;
  size_t	getY(void) const;

private:
  static View	ctor(char const c);
};

#endif /* __AIVIEW_HPP__ */

