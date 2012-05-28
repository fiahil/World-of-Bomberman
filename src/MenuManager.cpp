/*
 * NicoW
 * 15.05.12
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "ProfileManager.hpp"
#include "MenuManager.hpp"
#include "MainMenu.hpp"
#include "Credits.hpp"
#include "LoadProfile.hpp"
#include "LoadSave.hpp"
#include "LoadMap.hpp"
#include "GameChoose.hpp"
#include "MenuIA.hpp"
#include "TeamMenu.hpp"
#include "MenuMap.hpp"
#include "NewProfile.hpp"
#include "MenuProfile.hpp"
#include "Settings.hpp"
#include "NewProfile.hpp"
#include "LoadProfile.hpp"
#include "TeamMenu.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _menu(TokenMenu::LAST, 0),
    _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0)
{
  // this->_maps = this->_mapManager.getAll();
}

MenuManager::~MenuManager()
{
}

void	MenuManager::initialize(void)
{
  MapManager	mapManager;

  this->_map = mapManager.getAll();

  this->_menu[TokenMenu::MAINMENU] = new MainMenu(this->_gameManager);
  this->_menu[TokenMenu::MAINMENU]->initialize();
<<<<<<< HEAD
  this->_menu[TokenMenu::CREDITS] = new Credits(this->_gameManager);
  this->_menu[TokenMenu::CREDITS]->initialize();
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager);
  this->_menu[TokenMenu::LOADPROFILE]->initialize();
=======
>>>>>>> 6abecf67b1127dae24a14bfe20e145c72fea8ddc
  this->_menu[TokenMenu::LOADSAVE] = new LoadSave(this->_gameManager);
  this->_menu[TokenMenu::LOADSAVE]->initialize();
  this->_menu[TokenMenu::LOADMAP] = new LoadMap(this->_gameManager, this->_map);
  this->_menu[TokenMenu::LOADMAP]->initialize();
  this->_menu[TokenMenu::GAMECHOOSE] = new GameChoose(this->_gameManager);
  this->_menu[TokenMenu::GAMECHOOSE]->initialize();
  this->_menu[TokenMenu::IA] = new MenuIA(this->_gameManager);
  this->_menu[TokenMenu::IA]->initialize();
  this->_menu[TokenMenu::MAP] = new MenuMap(this->_gameManager);
  this->_menu[TokenMenu::MAP]->initialize();
  this->_menu[TokenMenu::PROFILE] = new MenuProfile(this->_gameManager);
  this->_menu[TokenMenu::PROFILE]->initialize();
  this->_menu[TokenMenu::SETTINGS] = new Settings(this->_gameManager);
  this->_menu[TokenMenu::SETTINGS]->initialize();
  this->_menu[TokenMenu::NEWPROFILE] = new NewProfile(this->_gameManager);
  this->_menu[TokenMenu::NEWPROFILE]->initialize();
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager);
  this->_menu[TokenMenu::LOADPROFILE]->initialize();
  this->_menu[TokenMenu::TEAM] = new TeamMenu(this->_gameManager);
  this->_menu[TokenMenu::TEAM]->initialize();
  this->_menu[this->_curMenu]->setTextDraw(true);
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
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
<<<<<<< HEAD
      this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
			   this->_menu[this->_curMenu]->getCenterY());
=======

      /*this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), 2500.0f600.0f,
			   this->_menu[this->_curMenu]->getCenterY());*/

      this->_camera.setPosScroll(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
				 this->_menu[this->_curMenu]->getCenterY());
>>>>>>> 6abecf67b1127dae24a14bfe20e145c72fea8ddc
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}
