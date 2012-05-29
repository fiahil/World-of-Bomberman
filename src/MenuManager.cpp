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
    _camera(w, h, 0, 0),
    _createGame(false)
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
  this->_menu[TokenMenu::CREDITS] = new Credits(this->_gameManager);
  this->_menu[TokenMenu::CREDITS]->initialize();
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
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager, this->_profile);
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

void		doBilan(const GameManager & game)
{
  std::cout << "\nBilan Menu :" << std::endl;
  std::cout << "*Main Profile : ";
  if (game._mainProfile != 0)
    std::cout << "Existe : Nom = " << game._mainProfile->getName() << std::endl;
  else
    std::cout << "N'existe Pas !" << std::endl;

  std::cout << "*Map : ";
  if (game._match._map != 0)
    std::cout << "Existe :)" << std::endl;
  else
    std::cout << "N'existe Pas !" << std::endl;

  std::cout << "*Cheat : ";
  if (game._match._cheat)
    std::cout << "Active :)" << std::endl;
  else
    std::cout << "Inactif !" << std::endl;

  std::cout << "*Mode de jeu : ";
  if (game._match._gameMode == GameMode::SOLO)
    std::cout << "Solo" << std::endl;
  else if (game._match._gameMode == GameMode::COOP)
    std::cout << "Coop" << std::endl;
  else if (game._match._gameMode == GameMode::VERSUS)
    std::cout << "Versus" << std::endl;
  else
    std::cout << "Pas set !" << std::endl;

  std::cout << "*Nb Joueurs : " << game._match._players.size() << std::endl;
}

void	MenuManager::update(gdl::GameClock const& clock, gdl::Input& input)
{
  TokenMenu::eMenu	tmp;

  if ((tmp = this->_menu[this->_curMenu]->getContent()) != TokenMenu::LAST)
    {
      if (tmp == TokenMenu::QUIT) //TODO
	exit(0);
      else if (tmp == TokenMenu::CREATEGAME)
	{
	  std::cout << "Creation de la partie !" << std::endl;
	  this->_createGame = true;
	  return ;
	}
      this->_menu[this->_curMenu]->setTextDraw(false);
      this->_curMenu = tmp;
      this->_menu[this->_curMenu]->setTextDraw(true);
      this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
			   this->_menu[this->_curMenu]->getCenterY());
      /**/doBilan(this->_gameManager);
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}

MyGame*	MenuManager::createGame(gdl::GameClock& clock, gdl::Input& input)
{
  APlayer*	pl1 = 0;
  APlayer*	pl2 = 0;

  if (this->_createGame)
    {
      this->_createGame = false;
      pl1 = this->_gameManager._match._players[0];
      if (this->_gameManager._match._gameMode != GameMode::SOLO)
	pl2 = this->_gameManager._match._players[1];
      return new MyGame(clock, input, this->_gameManager._match, pl1, pl2);
    }
  return 0;
}
