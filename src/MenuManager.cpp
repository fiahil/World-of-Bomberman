/*
 * NicoW
 * 15.05.12
 */

#include <string>
#include <vector>
#include <algorithm>
#include "MenuManager.hpp"
#include "MainMenu.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0)
{
  // this->_maps = this->_mapManager.getAll();
}

MenuManager::~MenuManager()
{
}

void	MenuManager::initialize(void)
{
  this->_menu.push_back(new MainMenu(this->_gameManager));
  this->_menu[this->_curMenu]->initialize();
  this->_menu[this->_curMenu]->setTextDraw(true);
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), 600.0f,
		       this->_menu[this->_curMenu]->getCenterY());
}

void	MenuManager::draw(void)
{
  std::vector<AMenu *>::iterator	it = this->_menu.begin();

  for (; it != this->_menu.end() ; ++it)
    (*it)->draw();
}

void	MenuManager::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_menu[this->_curMenu]->getContent() != TokenMenu::LAST)
    {
      
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}
