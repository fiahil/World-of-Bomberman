/*
 * NicoW
 * 15.05.12
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "MenuManager.hpp"
#include "MainMenu.hpp"
#include "MenuProfile.hpp"
#include "NewProfile.hpp"
#include "LoadProfile.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _menu(TokenMenu::LAST, 0),
    _curMenu(TokenMenu::LOADPROFILE),
    _camera(w, h, 0, 0)
{
  // this->_maps = this->_mapManager.getAll();
}

MenuManager::~MenuManager()
{
}

void	MenuManager::initialize(void)
{
  this->_menu[TokenMenu::MAINMENU] = new MainMenu(this->_gameManager);
  this->_menu[TokenMenu::MAINMENU]->initialize();
  this->_menu[TokenMenu::PROFILE] = new MenuProfile(this->_gameManager);
  this->_menu[TokenMenu::PROFILE]->initialize();
  this->_menu[TokenMenu::NEWPROFILE] = new NewProfile(this->_gameManager);
  this->_menu[TokenMenu::NEWPROFILE]->initialize();
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager);
  this->_menu[TokenMenu::LOADPROFILE]->initialize();
  this->_menu[this->_curMenu]->setTextDraw(true);
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), 600.0f,
		       this->_menu[this->_curMenu]->getCenterY());
}

void	MenuManager::draw(void)
{
  std::vector<AMenu *>::iterator	it = this->_menu.begin();

  for (; it != this->_menu.end() ; ++it)
    if ((*it))
      (*it)->draw();
}

void	MenuManager::update(gdl::GameClock const& clock, gdl::Input& input)
{
  TokenMenu::eMenu	tmp;
  
  if ((tmp = this->_menu[this->_curMenu]->getContent()) != TokenMenu::LAST)
    {
      if (tmp == TokenMenu::QUIT) //TODO
	exit(0);
      this->_menu[this->_curMenu]->setTextDraw(false);
      this->_curMenu = tmp;
      this->_menu[this->_curMenu]->setTextDraw(true);
      this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), 600.0f,
			   this->_menu[this->_curMenu]->getCenterY());
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}
