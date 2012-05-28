/*
 * Texan
 *
 */

#include <iostream>
#include "ProfileManager.hpp"
#include "NewProfile.hpp"

NewProfile::NewProfile(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background2.png", 1600.0f, -1.0f, 0.0f, game)
{
  this->_oneTime = -1.0;
  this->_selected = false;
  this->_textEdit.push_back(new TextEdit(965, 360, "[Press Enter to type your name]"));
  this->_tags.push_back(new Tag("menu/NameNormal.png", "menu/NameHighlit.png", false, false, TokenMenu::NEWPROFILE, 2400.0f, 0.0f, 400.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::NEWPROFILE, 2550.0f, 0.0f, 400.0f));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::PROFILE, 2400.0f, 0.0f, 450.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::MAINMENU, 2400.0f, 0.0f, 500.0f));
}

NewProfile::~NewProfile(void)
{
}

void	NewProfile::setNewProfile(void)
{
  ProfileManager	_pm;
  Config		_cfg;
  size_t		_id = 0;
  std::vector<size_t>	_six(6, 0);
  std::vector<size_t>	_three(3, 0);
  
  if ((_id = _pm.getMax()))
    ++_id;
  this->_gameManager._mainProfile = new Profile;
  this->_gameManager._mainProfile->setId(_id);
  this->_gameManager._mainProfile->setLvl(1);
  this->_gameManager._mainProfile->setXp(0);
  this->_gameManager._mainProfile->setTuto(false);
  this->_gameManager._mainProfile->setSkin(Skin::VARIANT);
  this->_gameManager._mainProfile->setConfig(_cfg);
  this->_gameManager._mainProfile->setName(this->_textEdit[0]->getStr());
  this->_gameManager._mainProfile->setSkill(_three);
  this->_gameManager._mainProfile->setStat(_six);
  this->_gameManager._mainProfile->setAchievement(_three);
  _pm.setProfile(_id, *this->_gameManager._mainProfile);
	    this->_textEdit[0]->setStr("[Press enter to type your name]");
}

double	NewProfile::getCenterX(void) const
{
  return (2400.0f);
}

double	NewProfile::getCenterY(void) const
{
  return (450.0f);
}

void	NewProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_oneTime > 0.0f)
    {
      if (clock.getTotalGameTime() >= this->_oneTime)
	this->_oneTime = -1.0f;
    }
  else if (!this->_selected)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);

      if (this->_curToken == TokenMenu::NEWPROFILE)
	{
	  this->_textEdit[0]->setStr("");
	  this->_selected = true;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	  this->_curToken = TokenMenu::LAST;
	}
      else if (input.isKeyDown(gdl::Keys::Return))
	{
	  if (this->_curToken == TokenMenu::PROFILE)
	    {
	      if (!this->_textEdit[0]->getStr().empty())
		this->setNewProfile();
	      else
		this->_curToken = TokenMenu::LAST;
	    }
	  else if (this->_curToken == TokenMenu::MAINMENU)
	    this->_textEdit[0]->setStr("[Press enter to type your name]");
	}

      if (this->_cursor == 1)
	{
	  this->_tags[this->_cursor]->setStatus(false);
	  if (this->_timers[0] < this->_timers[1])
	    ++this->_cursor;
	  else
	    --this->_cursor;
	  this->_tags[this->_cursor]->setStatus(true);
	}
    }
  else
    {
      if (input.isKeyDown(gdl::Keys::Return))
	{
	  this->_selected = false;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	}
      else
	this->_textEdit[0]->update(clock, input);
    }
}
