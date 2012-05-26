/*
 * NicoW
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "MenuManager.hpp"
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
  
}

void	MenuManager::draw(void)
{
  std::vector<AMenu *>::iterator	it = this->_menus.begin();

  for (; it != this->_menus.end() ; ++it)
    (*it)->draw();
}

void	MenuManager::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->_camera.update();
}

/* TO MOVE
void			MenuManager::UpFunction(gdl::GameClock const &clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::UP])
    {
      std::vector<Tag *>::const_iterator	it;
      int					idx;

      it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
      this->_menus[this->_curMenu]->setTagAt((idx = (it - this->_menus[this->_curMenu]->getTags().begin())), false);
      if ((idx - 1) < 0)
	this->_menus[this->_curMenu]->setTagAt(this->_menus[this->_curMenu]->getTags().size() - 1, true);
      else
	this->_menus[this->_curMenu]->setTagAt(--idx, true);
      this->_timer[MenuKey::UP] = current + 0.15;
    }
}

void			MenuManager::DownFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::DOWN])
    {
       std::vector<Tag *>::const_iterator	it;
      int					idx;

      it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
      this->_menus[this->_curMenu]->setTagAt((idx = (it - this->_menus[this->_curMenu]->getTags().begin())), false);
      if ((idx + 1) >= this->_menus[this->_curMenu]->getTags().size())
	this->_menus[this->_curMenu]->setTagAt(0, true);
      else
	this->_menus[this->_curMenu]->setTagAt(++idx, true);
      this->_timer[MenuKey::DOWN] = current + 0.15;
    }
}

void			MenuManager::LeftFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::LEFT])
    {
       this->_timer[MenuKey::LEFT] = current + 0.15;
    }
}

void			MenuManager::RightFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::RIGHT])
    {
       this->_timer[MenuKey::RIGHT] = current + 0.15;
    }
}


void			MenuManager::SelectFunction(gdl::GameClock const & clock)
{
  double		current = static_cast<double>(clock.getTotalGameTime());
  int			token;

  if (current >= this->_timer[MenuKey::SELECTED])
    {
      if ((token = this->fetchMenu()) < TokenMenu::LAST)
	{
	  (this->*(this->_jumpMenu[token].second))();
	}
      this->_timer[MenuKey::SELECTED] = current + 0.15;
    }
}*/

