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

void		deleteTags(Tag * obj)
{
  delete obj;
}

AMenu::~AMenu()
{
  std::cout << "Destruction AMenu" << std::endl;

  for_each(this->_tags.begin(), this->_tags.end(), deleteTags);
  /*
    segfault ? :)
  */
}

TokenMenu::eMenu	AMenu::run(void)
{
  std::cout << "RUN AMenu" << std::endl;

  return TokenMenu::QUIT;
}

void			AMenu::refresh(void)
{
  std::cout << "REFRESH AMenu" << std::endl;
}
