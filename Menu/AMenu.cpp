/*
 * Nicow
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include "AMenu.hpp"

AMenu::AMenu()
{
  std::cout << "Construction AMenu" << std::endl;
}

AMenu::~AMenu()
{
  std::cout << "Destruction AMenu" << std::endl;
}

void		AMenu::run(void)
{
  std::cout << "RUN AMenu" << std::endl;
}

void		AMenu::refresh(void)
{
  std::cout << "REFRESH AMenu" << std::endl;
}
