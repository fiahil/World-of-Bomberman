/*
 * lemonn_v
 * 15.05.12
 */

#include <iostream>
#include <sstream>
#include "ProfileManager.hpp"
#include "Settings.hpp"

static const char*	g_ref[gdl::Keys::Count + 1] = {
  "Bouton A", "Bouton B", "Bouton C", "Bouton D", "Bouton E", "Bouton F", "Bouton G", "Bouton H", "Bouton I",
  "Bouton J", "Bouton K", "Bouton L", "Bouton M", "Bouton N", "Bouton O", "Bouton P", "Bouton Q", "Bouton R",
  "Bouton S", "Bouton T", "Bouton U", "Bouton V", "Bouton W", "Bouton X", "Bouton Y", "Bouton Z",
  "Bouton Num0", "Bouton Num1", "Bouton Num2", "Bouton Num3", "Bouton Num4",
  "Bouton Num5", "Bouton Num6", "Bouton Num7", "Bouton Num8", "Bouton Num9",
  "", "Bouton LControl", "Bouton LShift", "Bouton LAlt",
  "", "Bouton RControl", "Bouton RShift", "Bouton RAlt",
  "", "", "", "", "", "", "", "", "", "", "", "", "",
  "Bouton Space", "Bouton Return","Bouton Back",
  "", "", "", "", "", "", "", "", "", "", "",
  "Bouton Left", "Bouton Right", "Bouton Up", "Bouton Down",
  "Bouton Numpad0", "Bouton Numpad1", "Bouton Numpad2", "Bouton Numpad3", "Bouton Numpad4",
  "Bouton Numpad5", "Bouton Numpad6", "Bouton Numpad7", "Bouton Numpad8", "Bouton Numpad9",
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
  "Bouton not set",
};

static const int	g_refPos[6][2] = {
  {750, 165},
  {750, 230},
  {750, 295},
  {750, 360},
  {750, 425},
  {750, 490},
};

static const HumGame::eAction	g_refAction[6] = {
  HumGame::UP,
  HumGame::DOWN,
  HumGame::LEFT,
  HumGame::RIGHT,
  HumGame::ATTACK,
  HumGame::SKILL
};

Settings::Settings(GameManager& game)
  : AMenu("menu/background/backgroundConfiguration.jpg", "menu/background/backgroundConfiguration.jpg", 3200.0f, -1.0f, 2400.0f, game),
    _oneTime(-1.0f),
    _selected(false)
{
  this->_tags.push_back(new Tag("menu/tags/ForwardNormal.png", "menu/tags/ForwardHighlit.png", true, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2550.0f));
  this->_tags.push_back(new Tag("menu/tags/BackConfNormal.png", "menu/tags/BackConfHighlit.png", false, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2615.0f));
  this->_tags.push_back(new Tag("menu/tags/LeftNormal.png", "menu/tags/LeftHighlit.png", false, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2680.0f));
  this->_tags.push_back(new Tag("menu/tags/RightNormal.png", "menu/tags/RightHighlit.png", false, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2745.0f));
  this->_tags.push_back(new Tag("menu/tags/BombNormal.png", "menu/tags/BombHighlit.png", false, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2810.0f));
  this->_tags.push_back(new Tag("menu/tags/SkillConfNormal.png", "menu/tags/SkillConfHighlit.png", false, false, TokenMenu::SETTINGS, 3629.0f, 0.0f, 2875.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3629.0f, 0.0f, 2940.0f));
}

Settings::~Settings()
{

}

double	Settings::getCenterX() const
{
  return 4000.0f;
}

double	Settings::getCenterY() const
{
  return 2800.0f;
}

void	Settings::update(gdl::GameClock const& clock, gdl::Input& input)
{
  Config&	conf = this->_gameManager._mainProfile->getConfig();

  if (this->_oneTime > 0.0f)
    {
      if (clock.getTotalGameTime() >= this->_oneTime)
	this->_oneTime = -1.0f;
    }
  else if (!this->_selected)
    {
      this->_tags[0]->createText(g_ref[conf.getConfig(g_refAction[0])], 20, g_refPos[0][0], g_refPos[0][1]);
      this->_tags[1]->createText(g_ref[conf.getConfig(g_refAction[1])], 20, g_refPos[1][0], g_refPos[1][1]);
      this->_tags[2]->createText(g_ref[conf.getConfig(g_refAction[2])], 20, g_refPos[2][0], g_refPos[2][1]);
      this->_tags[3]->createText(g_ref[conf.getConfig(g_refAction[3])], 20, g_refPos[3][0], g_refPos[3][1]);
      this->_tags[4]->createText(g_ref[conf.getConfig(g_refAction[4])], 20, g_refPos[4][0], g_refPos[4][1]);
      this->_tags[5]->createText(g_ref[conf.getConfig(g_refAction[5])], 20, g_refPos[5][0], g_refPos[5][1]);
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
      if (this->_curToken == TokenMenu::SETTINGS)
	{
	  this->_selected = true;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	  this->_curToken = TokenMenu::LAST;
	  this->_tags[this->_cursor]->createText("Please press a button", 20,
						     g_refPos[(this->_cursor)][0],
						     g_refPos[(this->_cursor)][1]);
	}
      else if (this->_curToken == TokenMenu::SETTINGSCHOOSE)
	ProfileManager::setProfile(this->_gameManager._mainProfile->getId(), *this->_gameManager._mainProfile);
    }
  else
    for (size_t i = 0; i <= gdl::Keys::Count; ++i)
      if (g_ref[i][0] && input.isKeyDown(static_cast<gdl::Keys::Key>(i)))
	{
	  this->_selected = false;
	  conf.setConfig(g_refAction[(this->_cursor)], static_cast<gdl::Keys::Key>(i));
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	  break;
	}
}
