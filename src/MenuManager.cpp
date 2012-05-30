/*
 * NicoW
 * 15.05.12
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "ProfileManager.hpp"
#include "MapManager.hpp"
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
#include "SettingsChoose.hpp"
#include "SkinChoose.hpp"
#include "NewProfile.hpp"
#include "LoadProfile.hpp"
#include "TeamMenu.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _menu(TokenMenu::LAST, 0),
    _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0),
    _createGame(false),
    _refInitGame(GameMode::LAST, 0)
{
  MapManager	mapManager;

  this->_refInitGame[GameMode::SOLO] = &MenuManager::initGameSolo;
  this->_refInitGame[GameMode::COOP] = &MenuManager::initGameCoop;
  this->_refInitGame[GameMode::VERSUS] = &MenuManager::initGameVersus;
  this->_map = mapManager.getAll();
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
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager, this->_profile);
  this->_menu[TokenMenu::LOADPROFILE]->initialize();
  this->_menu[TokenMenu::LOADSAVE] = new LoadSave(this->_gameManager);
  this->_menu[TokenMenu::LOADSAVE]->initialize();
  this->_menu[TokenMenu::LOADMAP] = new LoadMap(this->_gameManager, this->_map);
  this->_menu[TokenMenu::LOADMAP]->initialize();
  this->_menu[TokenMenu::GAMECHOOSE] = new GameChoose(this->_gameManager);
  this->_menu[TokenMenu::GAMECHOOSE]->initialize();
  this->_menu[TokenMenu::IA] = new MenuIA(this->_gameManager);
  this->_menu[TokenMenu::IA]->initialize();
  this->_menu[TokenMenu::TEAM] = new TeamMenu(this->_gameManager, this->_profile);
  this->_menu[TokenMenu::TEAM]->initialize();
  this->_menu[TokenMenu::MAP] = new MenuMap(this->_gameManager);
  this->_menu[TokenMenu::MAP]->initialize();
  this->_menu[TokenMenu::NEWPROFILE] = new NewProfile(this->_gameManager);
  this->_menu[TokenMenu::NEWPROFILE]->initialize();
  this->_menu[TokenMenu::PROFILE] = new MenuProfile(this->_gameManager);
  this->_menu[TokenMenu::PROFILE]->initialize();
  this->_menu[TokenMenu::SETTINGSCHOOSE] = new SettingsChoose(this->_gameManager);
  this->_menu[TokenMenu::SETTINGSCHOOSE]->initialize();
  this->_menu[TokenMenu::SETTINGS] = new Settings(this->_gameManager);
  this->_menu[TokenMenu::SETTINGS]->initialize();
  this->_menu[TokenMenu::SKINCHOOSE] = new SkinChoose(this->_gameManager);
  this->_menu[TokenMenu::SKINCHOOSE]->initialize();

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
      else if (tmp == TokenMenu::CREATEGAME)
	{
	  this->_createGame = true;
	  return ;
	}
      this->_menu[this->_curMenu]->setTextDraw(false);
      this->_curMenu = tmp;
      this->_menu[this->_curMenu]->setTextDraw(true);
      this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
			   this->_menu[this->_curMenu]->getCenterY());
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}

void	MenuManager::initGameSolo()
{
  int	id = 0;

  this->_gameManager._match._players.push_back(new Human(*this->_gameManager._match._map,
							 this->_gameManager._mainProfile->getConfig()));
  this->_gameManager._match._players.back()->setTeamId(id);
  this->_gameManager._match._players.back()->setSkin(this->_gameManager._mainProfile->getSkin());
  this->_gameManager._match._players.back()->setColor(id++);
  for (int i = 0; i < this->_gameManager._nbTeams; ++i, ++id)
    for (int c = 0; c < this->_gameManager._nbPlayers; ++c)
      {
	this->_gameManager._match._players.push_back(new AI(this->_gameManager._typeAI,
							    *this->_gameManager._match._map));
	this->_gameManager._match._players.back()->setTeamId(id);
	this->_gameManager._match._players.back()->setColor(id);
      }
}

void	MenuManager::initGameCoop()
{
  int	id = 0;
  
  this->_gameManager._match._players.push_back(new Human(*this->_gameManager._match._map,
							 this->_gameManager._configJ1));
  this->_gameManager._match._players.back()->setTeamId(id);
  this->_gameManager._match._players.back()->setSkin(this->_gameManager._mainProfile->getSkin());
  this->_gameManager._match._players.back()->setColor(id);
  this->_gameManager._match._players.push_back(new Human(*this->_gameManager._match._map,
							 this->_gameManager._configJ2));
  this->_gameManager._match._players.back()->setTeamId(id);
  this->_gameManager._match._players.back()->setSkin(this->_gameManager._secondProfile->getSkin());
  this->_gameManager._match._players.back()->setColor(id++);
  for (int i = 0; i < this->_gameManager._nbTeams; ++i, ++id)
    for (int c = 0; c < this->_gameManager._nbPlayers; ++c)
      {
	this->_gameManager._match._players.push_back(new AI(this->_gameManager._typeAI,
							    *this->_gameManager._match._map));
	this->_gameManager._match._players.back()->setTeamId(id);
	this->_gameManager._match._players.back()->setColor(id);
      }
}

void	MenuManager::initGameVersus()
{
  int	id = 0;
  
  this->_gameManager._match._players.push_back(new Human(*this->_gameManager._match._map,
							 this->_gameManager._configJ1));
  this->_gameManager._match._players.back()->setTeamId(id);
  this->_gameManager._match._players.back()->setSkin(this->_gameManager._mainProfile->getSkin());
this->_gameManager._match._players.back()->setColor(id++);
  this->_gameManager._match._players.push_back(new Human(*this->_gameManager._match._map,
							 this->_gameManager._configJ2));
  this->_gameManager._match._players.back()->setTeamId(id);
  this->_gameManager._match._players.back()->setSkin(this->_gameManager._secondProfile->getSkin());
  this->_gameManager._match._players.back()->setColor(id++);
  for (int i = 0; i < this->_gameManager._nbTeams; ++i, ++id)
    for (int c = 0; c < this->_gameManager._nbPlayers; ++c)
      {
	this->_gameManager._match._players.push_back(new AI(this->_gameManager._typeAI,
							    *this->_gameManager._match._map));
	this->_gameManager._match._players.back()->setTeamId(id);
	this->_gameManager._match._players.back()->setColor(id);
      }
}

MyGame*	MenuManager::createGame(gdl::GameClock& clock, gdl::Input& input)
{
  APlayer*	pl1 = 0;
  APlayer*	pl2 = 0;
  MyGame*	game = 0;

  if (this->_createGame)
    {
      this->_createGame = false;
      (this->*_refInitGame[this->_gameManager._match._gameMode])();
      pl1 = this->_gameManager._match._players[0];
      if (this->_gameManager._match._gameMode != GameMode::SOLO)
	pl2 = this->_gameManager._match._players[1];
      game = new MyGame(clock, input, this->_gameManager._match, pl1, pl2);
      game->initialize();
      return game;
    }
  return 0;
}

void	MenuManager::initCamera(void)
{         
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
      this->_menu[this->_curMenu]->getCenterY());
}
