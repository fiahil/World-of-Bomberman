/*
 * lemonn_v
 * 15.05.12
 */

#include <sstream>
#include <iostream>
#include <algorithm>
#include "SaveManager.hpp"
#include "ProfileManager.hpp"
#include "MenuPause.hpp"

MenuPause::MenuPause(GameManager& game)
  : AMenu("menu/background/backgroundPause.jpg", "menu/background/backgroundPause.jpg", 3200.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/ResumeNormal.png", "menu/tags/ResumeHighlit.png", true, false, TokenMenu::PAUSE, 3629.0f, 0.0f, 250.0f));
  this->_tags.push_back(new Tag("menu/tags/RestartNormal.png", "menu/tags/RestartHighlit.png", false, false, TokenMenu::CREATEGAME, 3629.0f, 0.0f, 315.0f));
  this->_tags.push_back(new Tag("menu/tags/SaveNormal.png", "menu/tags/SaveHighlit.png", false, false, TokenMenu::LOADSAVE, 3629.0f, 0.0f, 380.0f));
  this->_tags.push_back(new Tag("menu/tags/MainMenuNormal.png", "menu/tags/MainMenuHighlit.png", false, false, TokenMenu::PROFILE, 3629.0f, 0.0f, 445.0f));
  this->_tags.push_back(new Tag("menu/tags/QuitNormal.png", "menu/tags/QuitHighlit.png", false, false, TokenMenu::QUIT, 3629.0f, 0.0f, 510.0f));
}

MenuPause::~MenuPause()
{

}

double	MenuPause::getCenterX() const
{
  return 4000.0f;
}

double	MenuPause::getCenterY() const
{
  return 400.0f;
}

void	MenuPause::clearMatch()
{
  delete this->_gameManager._match._map;
  this->_gameManager._match._map = 0;
  while (this->_gameManager._match._players.size())
    {
      delete this->_gameManager._match._players.back();
      this->_gameManager._match._players.pop_back();
    }
  while (this->_gameManager._match._dead.size())
    {
      delete _gameManager._match._dead.back();
      this->_gameManager._match._dead.pop_back();
    }
  while (this->_gameManager._match._cadaver.size())
    {
      delete _gameManager._match._cadaver.back();
      this->_gameManager._match._cadaver.pop_back();
    }
  while (this->_gameManager._match._bombs.size())
    {
      delete this->_gameManager._match._bombs.back();
      this->_gameManager._match._bombs.pop_back();
    }
  while (this->_gameManager._match._bonus.size())
    {
      delete this->_gameManager._match._bonus.back();
      this->_gameManager._match._bonus.pop_back();
    }
  while (this->_gameManager._match._explodedBombs.size())
    {
      delete this->_gameManager._match._explodedBombs.back();
      this->_gameManager._match._explodedBombs.pop_back();
    }
  delete this->_gameManager._match._map;
  this->_gameManager._match._map = 0;
}

void	MenuPause::restartGame()
{
  if (this->_gameManager._nbTeams < 0)
    this->_curToken = TokenMenu::LAST;
  else
    {
      this->clearMatch();
      this->_gameManager._match._map = new Map(this->_gameManager._originMap->getX(),
					       this->_gameManager._originMap->getY(),
					       this->_gameManager._originMap->getMap());
    }
}

void	MenuPause::saveCurGame()
{
  std::stringstream	ss;

  this->_curToken = TokenMenu::LAST;
  ++SaveManager::maxId;
  ss << SaveManager::maxId;
  SaveManager::setSave(SaveManager::maxId, this->_gameManager._match);
  this->_gameManager._mainProfile->addSave(ss.str());
  ProfileManager::setProfile(this->_gameManager._mainProfile->getId(), *this->_gameManager._mainProfile);
}

void	MenuPause::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::CREATEGAME)
    this->restartGame();
  else if (this->_curToken == TokenMenu::LOADSAVE)
    this->saveCurGame();
  else if (this->_curToken == TokenMenu::PROFILE)
    this->clearMatch();
}

void		MenuPause::clearMatchMap(const std::vector<Map *> & loadedMap)
{
  if (std::find(loadedMap.begin(), loadedMap.end(), this->_gameManager._originMap) == loadedMap.end())
    {
      delete this->_gameManager._originMap;
      this->_gameManager._originMap = 0;
    }
}
