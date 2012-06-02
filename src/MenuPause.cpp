/*
 * lemonn_v
 * 15.05.12
 */

#include <sstream>
#include <algorithm>
#include "Common.hpp"
#include "SaveManager.hpp"
#include "ProfileManager.hpp"
#include "MenuPause.hpp"

MenuPause::MenuPause(GameManager& game, std::vector<Map*> const& maps)
  : AMenu("menu/background/backgroundPause.jpg", "menu/background/backgroundPause.jpg",
	  3200.0f, -1.0f, 0.0f, game),
    _maps(maps)
{
  this->_tags.push_back(new Tag("menu/tags/ResumeNormal.png", "menu/tags/ResumeHighlit.png",
				true, false, TokenMenu::PAUSE, 3629.0f, 0.0f, 250.0f));
  this->_tags.push_back(new Tag("menu/tags/RestartNormal.png", "menu/tags/RestartHighlit.png",
				false, false, TokenMenu::CREATEGAME, 3629.0f, 0.0f, 315.0f));
  this->_tags.push_back(new Tag("menu/tags/SaveNormal.png", "menu/tags/SaveHighlit.png",
				false, false, TokenMenu::LOADSAVE, 3629.0f, 0.0f, 380.0f));
  this->_tags.push_back(new Tag("menu/tags/MainMenuNormal.png", "menu/tags/MainMenuHighlit.png",
				false, false, TokenMenu::PROFILE, 3629.0f, 0.0f, 445.0f));
  this->_tags.push_back(new Tag("menu/tags/QuitNormal.png", "menu/tags/QuitHighlit.png",
				false, false, TokenMenu::QUIT, 3629.0f, 0.0f, 510.0f));
  this->_text.setSize(20);
  this->_text.setPosition(650, 200);
}

MenuPause::~MenuPause()
{
}

double		MenuPause::getCenterX() const
{
  return 4000.0f;
}

double		MenuPause::getCenterY() const
{
  return 400.0f;
}

void		MenuPause::clearOriginMap(void)
{
  if (std::find(this->_maps.begin(), this->_maps.end(),
		this->_gameManager._originMap) == this->_maps.end())
    {
      delete this->_gameManager._originMap;
      this->_gameManager._originMap = 0;
    }
}

void		MenuPause::clearMatch(void)
{
  delete this->_gameManager._match._map;
  this->_gameManager._match._map = 0;

  std::for_each(this->_gameManager._match._players.begin(),
		this->_gameManager._match._players.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._players.clear();

  std::for_each(this->_gameManager._match._dead.begin(),
		this->_gameManager._match._dead.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._dead.clear();
 
  std::for_each(this->_gameManager._match._cadaver.begin(),
		this->_gameManager._match._cadaver.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._cadaver.clear();

  std::for_each(this->_gameManager._match._bombs.begin(),
		this->_gameManager._match._bombs.end(),
		deleteItem<Bomb* >);
  this->_gameManager._match._bombs.clear();

  std::for_each(this->_gameManager._match._bonus.begin(),
		this->_gameManager._match._bonus.end(),
		deleteItem<Bonus* >);
  this->_gameManager._match._bonus.clear();

  std::for_each(this->_gameManager._match._explodedBombs.begin(),
		this->_gameManager._match._explodedBombs.end(),
		deleteItem<ExplodedBomb* >);
  this->_gameManager._match._explodedBombs.clear();
}

void		MenuPause::restartGame(void)
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

void		MenuPause::draw()
{
  AMenu::draw();
  if (this->_textDraw)
    {
      this->_text.setText(this->_msg);
      this->_text.draw();
    }
  else if (this->_msg != "")
    this->_msg = "";
}

void		MenuPause::saveCurGame()
{
  std::stringstream	ss;

  this->_curToken = TokenMenu::LAST;
  ++SaveManager::maxId;
  ss << SaveManager::maxId;
  SaveManager::setSave(SaveManager::maxId, this->_gameManager._match);
  this->_gameManager._mainProfile->addSave(ss.str());
  ProfileManager::setProfile(this->_gameManager._mainProfile->getId(),
			     *this->_gameManager._mainProfile);
}

void		MenuPause::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_cursor != 2)
    this->_msg = "";
  for (vKeyEvent::iterator it = this->_keyEvent.begin();
       it != this->_keyEvent.end(); ++it)
    if (input.isKeyDown(it->first))
      (this->*it->second)(clock);
  if (this->_curToken == TokenMenu::CREATEGAME)
    this->restartGame();
  if (this->_curToken == TokenMenu::LOADSAVE)
    {
      this->_msg = "The game was successfully saved";
      this->saveCurGame();
    }
  if (this->_curToken == TokenMenu::PROFILE)
    {
      this->clearMatch();
      this->clearOriginMap();
    }
}
