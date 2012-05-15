/*
 * NicoW
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <vector>
#include "MenuManager.hpp"

MenuManager::MenuManager()
  : _curMenu(Menu::MAINMENU)
{
  std::cout << "Creation Menu Manager" << std::endl;
  buildMainMenu();
  buildNewProfileMenu();
  buildProfileMenu();
  buildSlidingMenu();
  buildGameChooseMenu();
  buildSettingsMenu();
}

MenuManager::~MenuManager()
{
  std::cout << "Destruction Menu Manager" << std::endl;
}

void		MenuManager::run(void)
{
  std::cout << "RUN Menu Manager" << std::endl;
}

void		MenuManager::buildMainMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildNewProfileMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildProfileMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildSlidingMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildGameChooseMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}

void 		MenuManager::buildSettingsMenu(void)
{
  AMenu		mew;

  this->_menus.push_back(mew);
}
