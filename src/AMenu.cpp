/*
 * Nicow
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <algorithm>
#include "AMenu.hpp"

AMenu::AMenu()
{
  std::cout << "Construction AMenu" << std::endl;
}

static void		deleteTags(Tag * obj)
{
  delete obj;
}

AMenu::~AMenu()
{
  std::cout << "Destruction AMenu" << std::endl;

  for_each(this->_tags.begin(), this->_tags.end(), deleteTags);
}

void			AMenu::addTag(Tag * obj)
{
  this->_tags.push_back(obj);
}

TokenMenu::eMenu	AMenu::run(void)
{
  std::cout << "RUN AMenu" << std::endl;

  return TokenMenu::QUIT;
}

void			AMenu::draw(void)
{
  std::cout << "DRAW AMenu" << std::endl;
}

void			AMenu::initialize(void)
{
}

void			AMenu::update(gdl::GameClock const&, gdl::Input&)
{
}
