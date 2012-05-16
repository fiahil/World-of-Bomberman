/*
 * NicoW
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <vector>
#include <algorithm>
#include "MenuManager.hpp"

MenuManager::MenuManager()
  : _curMenu(TokenMenu::MAINMENU)
{
  std::cout << "Creation Menu Manager" << std::endl;
  buildMainMenu();
  buildNewProfileMenu();
  buildProfileMenu();
  buildSlidingMenu();
  buildGameChooseMenu();
  buildSettingsMenu();
}

void		deleteMenus(AMenu * obj)
{
  delete obj;
}

MenuManager::~MenuManager()
{
  std::cout << "Destruction Menu Manager" << std::endl;

  for_each(this->_menus.begin(), this->_menus.end(), deleteMenus);
  /*
    segfault ? :)
  */
}

void		MenuManager::run(void)
{
  std::cout << "RUN Menu Manager" << std::endl;
}

void		MenuManager::buildMainMenu(void)
{
  AMenu	*	mew = new AMenu;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildNewProfileMenu(void)
{
  AMenu *	mew = new AMenu;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildProfileMenu(void)
{
  AMenu *	mew = new AMenu;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildSlidingMenu(void)
{
  AMenu *	mew = new AMenu;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildGameChooseMenu(void)
{
  AMenu *	mew = new AMenu;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildSettingsMenu(void)
{
  AMenu *	mew = new AMenu;

  this->_menus.push_back(mew);
}
