/*
 * lemonn_v
 * 15.05.12
 */

#include <iostream>
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
  {450, 250},
  {450, 300},
  {450, 350},
  {450, 400},
  {450, 450},
  {450, 500},
};

Settings::Settings(GameManager& game)
  : AMenu("menu/Background.png", "menu/Background.png", 1600.0f, -1.0f, 1800.0f, game),
    _conf(game._mainProfile->getConfig()),
    _oneTime(-1.0f),
    _selected(false)
{
  this->_tags.push_back(new Tag("menu/ForwardNormal.png", "menu/ForwardHighlit.png", true, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2100.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2100.0f));

  this->_tags.push_back(new Tag("menu/BackwardNormal.png", "menu/BackwardHighlit.png", false, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2150.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2150.0f));

  this->_tags.push_back(new Tag("menu/LeftNormal.png", "menu/LeftHighlit.png", false, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2200.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2200.0f));

  this->_tags.push_back(new Tag("menu/RightNormal.png", "menu/RightHighlit.png", false, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2250.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2250.0f));

  this->_tags.push_back(new Tag("menu/DropBombNormal.png", "menu/DropBombHighlit.png", false, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2300.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2300.0f));

  this->_tags.push_back(new Tag("menu/SkillNormal.png", "menu/SkillHighlit.png", false, false, TokenMenu::SETTINGS, 1700.0f, 0.0f, 2350.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::SETTINGS, 2000.0f, 0.0f, 2350.0f));

  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::PROFILE, 1700.0f, 0.0f, 2400.0f));
}

Settings::~Settings()
{

}

double	Settings::getCenterX() const
{
  return 2400.0f;
}

double	Settings::getCenterY() const
{
  return 2250.0f;
}

void	Settings::update(gdl::GameClock const& clock, gdl::Input& input)
{
  //this->_tags[1]->createText(g_ref[this->_conf.getConfig(HumGame::UP)], 20, 800, 450);

  /*this->_tags[3]->createText(g_ref[this->_conf.getConfig(HumGame::DOWN)], 20, 800, 470);

  this->_tags[5]->createText(g_ref[this->_conf.getConfig(HumGame::LEFT)], 20, 800, 490);

  this->_tags[7]->createText(g_ref[this->_conf.getConfig(HumGame::RIGHT)], 20, 800, 510);

  this->_tags[9]->createText(g_ref[this->_conf.getConfig(HumGame::ATTACK)], 20, 800, 530);

  this->_tags[11]->createText(g_ref[this->_conf.getConfig(HumGame::SKILL)], 20, 800, 550);*/

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
      if (this->_curToken == TokenMenu::SETTINGS)
	{
	  this->_selected = true;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	  this->_curToken = TokenMenu::LAST;
	  this->_tags[this->_cursor + 1]->createText("Please press a button", 20,
						     g_refPos[(this->_cursor + 1) / 2][0],
						     g_refPos[(this->_cursor + 1) / 2][1]);
	}
      if (this->_cursor % 2 == 1)
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
    for (size_t i = 0; i <= gdl::Keys::Count; ++i)
      if (g_ref[i][0] && input.isKeyDown(static_cast<gdl::Keys::Key>(i)))
	{
	  this->_selected = false;
	  this->_oneTime = clock.getTotalGameTime() + 0.15f;
	  this->_tags[this->_cursor + 1]->createText("", 20,
						     g_refPos[(this->_cursor + 1) / 2][0],
						     g_refPos[(this->_cursor + 1) / 2][1]);
	  break;
	}

}
