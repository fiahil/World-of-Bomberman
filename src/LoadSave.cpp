/*
 * NicoW
 * 27.05.12
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "Human.hpp"
#include "SaveManager.hpp"
#include "LoadSave.hpp"

static const char*	g_refGameMode[GameMode::LAST] = {
  "Solo",
  "Coop",
  "Versus"
};

LoadSave::LoadSave(GameManager& game, std::vector<Profile*>& profiles, Profile* guest)
  : AMenu("menu/background/backgroundLoadSave.jpg", "menu/background/backgroundLoadSave.jpg", 3200.0f, -1.0f, 800.0f, game),
    _profiles(profiles),
    _guest(guest),
    _index(0),
    _timerL(-1.0f),
    _timerR(-1.0f)
 {
  this->_tags.push_back(new Tag("menu/tags/LoadNormal.png", "menu/tags/LoadHighlit.png", true, false, TokenMenu::LAST, 3629.0f, 0.0f, 1150.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::CREATEGAME, 3629.0f, 0.0f, 1265.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::PROFILE, 3629.0f, 0.0f, 1330.0f));
}

LoadSave::~LoadSave(void)
{
}

double		LoadSave::getCenterX(void) const
{
  return (4000.0f);
}

double		LoadSave::getCenterY(void) const
{
  return (1200.0f);
}

void		LoadSave::initGameManager(void)
{
  this->_gameManager._originMap = 0;
  this->_gameManager._typeAI = AIType::LAST;
  this->_gameManager._nbPlayers = -1;
  this->_gameManager._nbTeams = -1;
  this->_gameManager._secondProfile = 0;
}

void		LoadSave::setConfigs(APlayer *pl1, APlayer *pl2)
{
  if (this->_gameManager._match._gameMode == GameMode::SOLO)
    {
      if (dynamic_cast<Human*>(pl1) != 0)
	dynamic_cast<Human*>(pl1)->setConfig(this->_gameManager._mainProfile->getConfig());
    }
  else
    {
      if (dynamic_cast<Human*>(pl1) != 0)
	dynamic_cast<Human*>(pl1)->setConfig(this->_gameManager._configJ1);
      if (dynamic_cast<Human*>(pl2) != 0)
	dynamic_cast<Human*>(pl2)->setConfig(this->_gameManager._configJ2);
    }
}

void		LoadSave::loadSave()
{
  size_t		id;
  bool			flag = false;
  std::stringstream	ss;
  APlayer*		pl1 = 0;
  APlayer*		pl2 = 0;

  ss << this->_save.at(this->_index);
  ss >> id;
  if (!SaveManager::getSave(id, this->_gameManager._match))
    this->_curToken = TokenMenu::LAST;
  else
    {
      this->initGameManager();
      for (std::vector<APlayer*>::iterator it = this->_gameManager._match._players.begin();
	   it != this->_gameManager._match._players.end(); ++it)
	{
	  if ((*it)->getId() == this->_gameManager._mainProfile->getId())
	    pl1 = (*it);
	  else if ((*it)->getId() != static_cast<size_t>(-1))
	    {
	      for (std::vector<Profile*>::iterator it2 = this->_profiles.begin();
		   it2 != this->_profiles.end(); ++it2)
		if ((*it2)->getId() == (*it)->getId())
		  {
		    this->_gameManager._secondProfile = (*it2);
		    pl2 = (*it);
		    flag = true;
		    break;
		  }
	      if (!flag && this->_gameManager._match._gameMode != GameMode::SOLO)
		{
		  this->_gameManager._secondProfile = this->_guest;
		  (*it)->setId(this->_guest->getId());
		  pl2 = (*it);
		}
	    }
	}
      this->setConfigs(pl1, pl2);
    }
}

static bool	isPoint(int i)
{
  return (i == ':');
}

void		LoadSave::loadAllSaves()
{
  std::string		root("./Ressources/saves/");
  std::string		line;
  std::ifstream		input;

  this->_infos.clear();
  for (std::vector<std::string>::iterator it = this->_save.begin();
       it != this->_save.end(); ++it)
    {
      input.open((root + (*it)).c_str());

      if (input.is_open())
	{
	  while (std::getline(input, line))
	    {
	      std::stringstream	ss;
	      std::string	tmp;

	      std::remove_if(line.begin(), line.end(), isPoint);
	      ss << line;
	      ss >> tmp;
	      if (!tmp.compare("#HEADER"))
		{
		  std::stringstream	ret;
		  int			type;
		  size_t		time;
		  std::string		timeStr;
		  size_t		nbP;

		  ss >> type >> time >> nbP;
		  type %= GameMode::LAST;
		  timeStr = ctime(reinterpret_cast<time_t const*>(&time));
		  timeStr.resize(timeStr.size() - 1);
		  ret << "Game Mode : " << g_refGameMode[type] << " Date : " << timeStr << " Nb players : " << nbP;
		  this->_infos.push_back(ret.str());
		  break;
		}
	    }
	  input.close();
	}
    }
}

void		LoadSave::updateText() const
{
  if (this->_save.size())
    {
      this->_tags.at(0)->createText(this->_save.at(this->_index), 20, 750, 364);
      this->_tags.at(1)->createText(this->_infos.at(this->_index), 18, 500, 415);
    }
  else
    {
      this->_tags.at(0)->createText("", 20, 750, 364);
      this->_tags.at(1)->createText("", 20, 500, 415);
    }
}

void		LoadSave::changeSave(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && (input.isKeyDown(gdl::Keys::Left)||
      JsManager::getMe()->isJsDown(JsMode::MENU, gdl::Keys::Left)))
    {
      --this->_index;
      if (static_cast<int>(this->_index) < 0)
	this->_index = this->_save.size() - 1;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && (input.isKeyDown(gdl::Keys::Right) || JsManager::getMe()->isJsDown(JsMode::MENU, gdl::Keys::Right)))
    {
      ++this->_index;
      if (this->_index >= this->_save.size())
	this->_index = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void		LoadSave::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (!this->_save.size())
    {
      this->_save = this->_gameManager._mainProfile->getSave();
      this->loadAllSaves();
    }
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent.at(i).first) ||
	JsManager::getMe()->isJsDown(JsMode::MENU, this->_keyEvent[i].first))
      (this->*_keyEvent.at(i).second)(clock);
  if (this->_cursor == 0)
    this->changeSave(clock, input);
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      if (this->_save.size())
	this->loadSave();
      else
	this->_curToken = TokenMenu::LAST;
    }
}

void		LoadSave::setTextDraw(bool flag)
{
  if (flag)
    {
      this->_save = this->_gameManager._mainProfile->getSave();
      this->loadAllSaves();
    }
  AMenu::setTextDraw(flag);
}
