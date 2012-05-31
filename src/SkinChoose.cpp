/*
 * NicoW
 * 29.05.12
 */

#include "SkinChoose.hpp"

SkinChoose::SkinChoose(GameManager& game)
  : AMenu("menu/background/backgroundPersonnalization.jpg", "menu/background/backgroundPersonnalization.jpg", 3200.0f, -1.0f, 1600.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/WorgenNormal.png", "menu/tags/WorgenHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3649.0f, 0.0f, 1955.0f));
  this->_tags.push_back(new Tag("menu/tags/SylvanasNormal.png", "menu/tags/SylvanasHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3649.0f, 0.0f, 2020.0f));
  this->_tags.push_back(new Tag("menu/tags/VariantNormal.png", "menu/tags/VariantHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3649.0f, 0.0f, 2085.0f));
  this->_tags.push_back(new Tag("menu/tags/ZuljinNormal.png", "menu/tags/ZuljinHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3649.0f, 0.0f, 2150.0f));
}

SkinChoose::~SkinChoose()
{
}

double	SkinChoose::getCenterX() const
{
  return 4000.0f;
}

double	SkinChoose::getCenterY() const
{
  return 2000.0f;
}

void	SkinChoose::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::SETTINGSCHOOSE)
    {
      if (this->_cursor == 0)
	this->_gameManager._mainProfile->setSkin(Skin::WORGEN);
      else if (this->_cursor == 1)
	this->_gameManager._mainProfile->setSkin(Skin::SYLVANAS);
      else if (this->_cursor == 2)
	this->_gameManager._mainProfile->setSkin(Skin::VARIANT);
      else if (this->_cursor == 3)
	this->_gameManager._mainProfile->setSkin(Skin::ZULJIN);
    }
}
