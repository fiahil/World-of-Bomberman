/*
 * Texan
 *
 */

#include <algorithm>
#include "ProfileManager.hpp"
#include "NewProfile.hpp"

NewProfile::NewProfile(GameManager& game,
		       std::vector<Profile *>& profiles,
		       std::vector<std::string>& names)
  : AMenu("menu/background/backgroundNewProfile.jpg", "menu/background/backgroundNewProfile.jpg",
	  1600.0f, -1.0f, 0.0f, game),
    _profiles(profiles),
    _names(names),
    _selected(false),
    _strStatus(false),
    _oneTime(-1.0f)
{
  this->_textEdit.push_back(new TextEdit(780, 413, "[Press Enter to type your name]"));
  this->_tags.push_back(new Tag("menu/tags/NameNormal.png", "menu/tags/NameHighlit.png",
				false, false, TokenMenu::NEWPROFILE, 2029.0f, 0.0f, 400.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png",
				false, false, TokenMenu::PROFILE, 2029.0f, 0.0f, 465.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png",
				false, false, TokenMenu::MAINMENU, 2029.0f, 0.0f, 530.0f));
}

NewProfile::~NewProfile(void)
{
}

void		NewProfile::setNewProfile(void)
{
  std::vector<std::string>::const_iterator it =
    std::find(this->_names.begin(), this->_names.end(), this->_textEdit.at(0)->getStr());
  
  if (it != this->_names.end())
    {
      this->_strStatus = false;
      this->_textEdit.at(0)->setStr("[Name already used]");
      this->_curToken = TokenMenu::LAST;
    }
  else
    {
      ProfileManager	_pm;
      Config		_cfg;
      size_t		_id;

      for (_id = 1; _pm.isHere(_id); ++_id);
      this->_gameManager._mainProfile = new Profile;
      this->_gameManager._mainProfile->setId(_id);
      this->_gameManager._mainProfile->setSkin(Skin::VARIANT);
      this->_gameManager._mainProfile->setSkill(Skill::HEAL);
      this->_gameManager._mainProfile->setConfig(_cfg);
      this->_gameManager._mainProfile->setName(this->_textEdit.at(0)->getStr());
      _pm.setProfile(_id, *this->_gameManager._mainProfile);
      this->_profiles.push_back(this->_gameManager._mainProfile);
      this->_names.push_back(this->_gameManager._mainProfile->getName());
      this->_strStatus = false;
      this->_textEdit.at(0)->setStr("[Press Enter to type your name]");
    }
}

double		NewProfile::getCenterX(void) const
{
  return 2400.0f;
}

double		NewProfile::getCenterY(void) const
{
  return 400.0f;
}

void		NewProfile::updateStr(gdl::GameClock const& clock)
{
  if (this->_curToken == TokenMenu::NEWPROFILE)
    {
      this->_textEdit.at(0)->setStr("");
      this->_selected = true;
      this->_oneTime = clock.getTotalGameTime() + 0.15f;
      this->_curToken = TokenMenu::LAST;
    }
  else if (this->_curToken == TokenMenu::PROFILE)
    {
      if (!this->_textEdit.at(0)->getStr().empty() && _strStatus)
	this->setNewProfile();
      else
	{
	  this->_curToken = TokenMenu::LAST;
	  this->_strStatus = false;
	  this->_textEdit.at(0)->setStr("[Press Enter to type your name]");
	}
    }
  else
    {
      this->_strStatus = false;
      this->_textEdit.at(0)->setStr("[Press Enter to type your name]");
    }  
}

void		NewProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_oneTime > 0.0f)
    {
      if (clock.getTotalGameTime() >= this->_oneTime)
	this->_oneTime = -1.0f;
    }
  else if (!this->_selected)
    {
      for (vKeyEvent::const_iterator it = this->_keyEvent.begin();
	   it != this->_keyEvent.end(); ++it)
	if (input.isKeyDown(it->first) ||
	    JsManager::getMe()->isJsDown(JsMode::MENU, it->first))
	  (this->*(it->second))(clock);

      if (this->_curToken != TokenMenu::LAST)
	this->updateStr(clock);
    }
  else
    {
      if (input.isKeyDown(gdl::Keys::Return) ||
	  JsManager::getMe()->isJsDown(JsMode::MENU, gdl::Keys::Return))
	{
	  if (!this->_textEdit.at(0)->getStr().empty())
	    this->_strStatus = true;
	  else
	    this->_textEdit.at(0)->setStr("[Press Enter to type your name]");
	  this->_selected = false;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	}
      else
	this->_textEdit.at(0)->update(clock, input);
    }
}
