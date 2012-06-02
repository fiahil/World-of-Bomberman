/*
 * NicoW
 * 15.05.12
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Error.hpp"
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
#include "MenuPause.hpp"
#include "GameResult.hpp"
#include "Loading.hpp"
#include "MenuStats.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _menu(TokenMenu::LAST, 0),
    _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0),
    _createGame(false),
    _stopGame(false),
    _timerLoading(-1.0f),
    _refInitGame(GameMode::LAST, 0)
{
  MapManager	mapManager;

  this->_refInitGame[GameMode::SOLO] = &MenuManager::initGameSolo;
  this->_refInitGame[GameMode::COOP] = &MenuManager::initGameCoop;
  this->_refInitGame[GameMode::VERSUS] = &MenuManager::initGameVersus;
  this->_map = mapManager.getAll();

  ProfileLoader	profileLoader;

  this->_profile = profileLoader.getProfiles();
  this->_names = profileLoader.getNames();

  this->_guest = new Profile;
  this->_guest->setId(0);
  this->_guest->setSkin(Skin::VARIANT);
  this->_guest->setSkill(Skill::HEAL);
  this->_guest->setConfig(this->_gameManager._configJ2);
  this->_guest->setName("Guest");
  this->_profile.push_back(this->_guest);
  this->_names.push_back("Guest");
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
  this->_menu[TokenMenu::LOADPROFILE] = new LoadProfile(this->_gameManager, this->_profile, this->_names);
  this->_menu[TokenMenu::LOADPROFILE]->initialize();
  this->_menu[TokenMenu::LOADSAVE] = new LoadSave(this->_gameManager, this->_profile, this->_guest);
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
  this->_menu[TokenMenu::NEWPROFILE] = new NewProfile(this->_gameManager, this->_profile, this->_names);
  this->_menu[TokenMenu::NEWPROFILE]->initialize();
  this->_menu[TokenMenu::PROFILE] = new MenuProfile(this->_gameManager);
  this->_menu[TokenMenu::PROFILE]->initialize();
  this->_menu[TokenMenu::SETTINGSCHOOSE] = new SettingsChoose(this->_gameManager);
  this->_menu[TokenMenu::SETTINGSCHOOSE]->initialize();
  this->_menu[TokenMenu::SETTINGS] = new Settings(this->_gameManager);
  this->_menu[TokenMenu::SETTINGS]->initialize();
  this->_menu[TokenMenu::SKINCHOOSE] = new SkinChoose(this->_gameManager);
  this->_menu[TokenMenu::SKINCHOOSE]->initialize();
  this->_menu[TokenMenu::STATS] = new MenuStats(this->_gameManager);
  this->_menu[TokenMenu::STATS]->initialize();
  this->_menu[TokenMenu::PAUSE] = new MenuPause(this->_gameManager);
  this->_menu[TokenMenu::PAUSE]->initialize();
  this->_menu[TokenMenu::GAMERESULT] = new GameResult(this->_gameManager, this->_gameManager._match);
  this->_menu[TokenMenu::GAMERESULT]->initialize();
  this->_menu[TokenMenu::LOADING] = new Loading(this->_gameManager);
  this->_menu[TokenMenu::LOADING]->initialize();

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
      if (tmp == TokenMenu::QUIT)
	throw EndOfGame();
      else if (tmp == TokenMenu::CREATEGAME)
	{
	  this->_createGame = true;
	  this->_timerLoading = clock.getTotalGameTime() + 3.0f;
	  tmp = TokenMenu::LOADING;
	}
      else if (tmp == TokenMenu::PAUSE)
	this->_resume = true;
      else if (this->_curMenu == TokenMenu::PAUSE && tmp == TokenMenu::PROFILE)
	this->_stopGame = true;
      else if (this->_curMenu == TokenMenu::GAMERESULT)
	tmp = TokenMenu::PROFILE;
      this->_menu[this->_curMenu]->setTextDraw(false);
      this->_curMenu = tmp;
      this->_menu[this->_curMenu]->setTextDraw(true);
      //std::cout << "Token " << this->_curMenu << std::endl;
      this->_camera.setPosScroll(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
				 this->_menu[this->_curMenu]->getCenterY());
    }
  else
    this->_menu[this->_curMenu]->update(clock, input);
  this->_camera.update();
}

void	MenuManager::initGameSolo()
{
  int	id = 0;
  Human*	tmp;

  tmp = new Human(*this->_gameManager._match._map,
		  this->_gameManager._mainProfile->getConfig(),
		  &(this->_gameManager._mainProfile->getAchievement()));
  tmp->setSkill(this->_gameManager._mainProfile->getSkill());
  tmp->setId(this->_gameManager._mainProfile->getId());
  tmp->setTeamId(id);
  tmp->setSkin(this->_gameManager._mainProfile->getSkin());
  tmp->setColor(id++);
  this->_gameManager._match._players.push_back(tmp);
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
  Human*	tmp;

  tmp = new Human(*this->_gameManager._match._map,
		  this->_gameManager._configJ1,
		  &(this->_gameManager._mainProfile->getAchievement()));
  tmp->setSkill(this->_gameManager._mainProfile->getSkill());
  tmp->setId(this->_gameManager._mainProfile->getId());
  tmp->setTeamId(id);
  tmp->setSkin(this->_gameManager._mainProfile->getSkin());
  tmp->setColor(id);
  this->_gameManager._match._players.push_back(tmp);
  tmp = new Human(*this->_gameManager._match._map,
		  this->_gameManager._configJ2,
		  &(this->_gameManager._secondProfile->getAchievement()));
  tmp->setSkill(this->_gameManager._secondProfile->getSkill());
  tmp->setId(this->_gameManager._secondProfile->getId());
  tmp->setTeamId(id);
  tmp->setSkin(this->_gameManager._secondProfile->getSkin());
  tmp->setColor(id++);
  this->_gameManager._match._players.push_back(tmp);
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
  Human*	tmp;

  tmp = new Human(*this->_gameManager._match._map,
		  this->_gameManager._configJ1,
		  &(this->_gameManager._mainProfile->getAchievement()));
  tmp->setSkill(this->_gameManager._mainProfile->getSkill());
  tmp->setId(this->_gameManager._mainProfile->getId());
  tmp->setTeamId(id);
  tmp->setSkin(this->_gameManager._mainProfile->getSkin());
  tmp->setColor(id++);
  this->_gameManager._match._players.push_back(tmp);
  tmp = new Human(*this->_gameManager._match._map,
		  this->_gameManager._configJ2,
		  &(this->_gameManager._secondProfile->getAchievement()));
  tmp->setSkill(this->_gameManager._secondProfile->getSkill());
  tmp->setId(this->_gameManager._secondProfile->getId());
  tmp->setTeamId(id);
  tmp->setSkin(this->_gameManager._secondProfile->getSkin());
  tmp->setColor(id++);
  this->_gameManager._match._players.push_back(tmp);
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
  bool		loadGame = false;

  if (this->_createGame && clock.getTotalGameTime() < this->_timerLoading)
      return 0;
  if (this->_createGame)
    {
      if (this->_gameManager._nbTeams < 0)
	loadGame = true;
      this->_createGame = false;
      if (!loadGame)
	(this->*_refInitGame[this->_gameManager._match._gameMode])();
      for (std::vector<APlayer*>::const_iterator it = this->_gameManager._match._players.begin();
	   it != this->_gameManager._match._players.end(); ++it)
	{
	  std::cout << "Id " << (*it)->getId() << std::endl;
	  if (this->_gameManager._mainProfile->getId() == (*it)->getId())
	    pl1 = (*it);
	  else if (this->_gameManager._match._gameMode != GameMode::SOLO &&
		   this->_gameManager._secondProfile->getId() == (*it)->getId())
	    pl2 = (*it);
	}
      std::cout << "pl1 " << pl1 << " mainProfile " << this->_gameManager._mainProfile->getId() << std::endl;
      if (this->_gameManager._secondProfile)
	std::cout << "pl2 " << pl2 << " secondProfile " << this->_gameManager._secondProfile->getId() << std::endl;
      game = new MyGame(clock, input, this->_gameManager._match, loadGame, pl1, pl2);
      game->initialize();
      std::cout << "Create game end" << std::endl;
      return game;
    }
  return 0;
}

void	MenuManager::initCamera(void)
{
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
		       this->_menu[this->_curMenu]->getCenterY());
}

bool	MenuManager::isStopGame()
{
  bool	tmp = this->_stopGame;

  if (this->_stopGame)
    this->_stopGame = false;
  return tmp;
}

bool	MenuManager::isResume()
{
  bool	tmp = this->_resume;

  if (this->_resume)
    {
      this->_menu[this->_curMenu]->setTextDraw(false);
      this->_resume = false;
    }
  return tmp;
}

void	MenuManager::setPause()
{
  this->_curMenu = TokenMenu::PAUSE;
  this->_resume = false;
  this->_stopGame = false;
  this->_menu[this->_curMenu]->setTextDraw(true);
  this->_menu[this->_curMenu]->setChangeMenu(false);
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
		       this->_menu[this->_curMenu]->getCenterY());
}

void	MenuManager::setEOG()
{
  this->_menu[this->_curMenu]->setTextDraw(false);
  this->_curMenu = TokenMenu::GAMERESULT;
  this->_menu[this->_curMenu]->setTextDraw(true);
  this->_camera.setPos(this->_menu[this->_curMenu]->getCenterX(), CAM_DISTANCE,
		       this->_menu[this->_curMenu]->getCenterY());
}
