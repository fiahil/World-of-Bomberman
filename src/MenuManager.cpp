/*
 * NicoW
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <string>
#include <vector>
#include <algorithm>
#include "MenuManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0)
{
  std::cout << "Creation Menu Manager" << std::endl;
  buildMainMenu();
  // buildNewProfileMenu();
  // buildProfileMenu();
  // buildSlidingMenu();
  // buildGameChooseMenu();
  // buildSettingsMenu();
}

void		deleteMenus(AMenu * obj)
{
  delete obj;
}

MenuManager::~MenuManager()
{
  std::cout << "Destruction Menu Manager" << std::endl;

  for_each(this->_menus.begin(), this->_menus.end(), deleteMenus);
}

void		MenuManager::run(void)
{
  std::cout << "RUN Menu Manager" << std::endl;
}

void		MenuManager::buildMainMenu(void)
{
  AMenu	*	newMenu = new AMenu;
  Tag	*	newProfile = new Tag("menu/NewProfileNormal.png", "menu/NewProfileHighlit.png", true, TokenMenu::NEWPROFILE);
  Tag	*	loadProfile = new Tag("menu/LoadProfileNormal.png", "menu/LoadProfileHighlit.png", true, TokenMenu::SLIDING);
  Tag	*	quit = new Tag("menu/QuitNormal.png", "menu/QuitHighlit.png", true, TokenMenu::QUIT);

  newMenu->addTag(newProfile);
  newMenu->addTag(loadProfile);
  newMenu->addTag(quit);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildNewProfileMenu(void)
{
  AMenu *	newMenu = new AMenu;

  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildProfileMenu(void)
{
  AMenu *	newMenu = new AMenu;

  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildSlidingMenu(void)
{
  AMenu *	newMenu = new AMenu;

  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildGameChooseMenu(void)
{
  AMenu *	newMenu = new AMenu;

  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildSettingsMenu(void)
{
  AMenu *	newMenu = new AMenu;

  this->_menus.push_back(newMenu);
}

void			MenuManager::draw(void)
{
  std::cout << "DRAW MenuManager" << std::endl;
}

void			MenuManager::initialize(void)
{
}

void			MenuManager::update(gdl::GameClock const&, gdl::Input&)
{
}
