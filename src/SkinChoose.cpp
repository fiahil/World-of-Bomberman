/*
 * NicoW
 * 29.05.12
 */

#include "ProfileManager.hpp"
#include "SkinChoose.hpp"

static const char*	g_refSkin[Skin::LAST - 1] = {
  "Warwik",
  "Sylvanas",
  "Variant",
  "Zuljin"
};

static const char*	g_refModel[Skin::LAST - 1] = {
  "models/Character_ennemy.FBX",
  "models/Character_sylvanas.FBX",
  "models/Character_varian.FBX",
  "models/Character_zuljin.FBX",
};

SkinChoose::SkinChoose(GameManager& game)
  : AMenu("menu/background/backgroundPersonnalization.jpg", "menu/background/backgroundPersonnalization.jpg", 3200.0f, -1.0f, 1600.0f, game),
    _model(Skin::LAST - 1),
    _timerL(-1.0f),
    _timerR(-1.0f),
    _indexSkin(0),
    _indexSkill(0)
{
  this->_tags.push_back(new Tag("menu/tags/PersonalizationSkinNormal.png", "menu/tags/PersonalizationSkinHighlit.png", true, false, TokenMenu::LAST, 3500.0f, 0.0f, 1955.0f));
  this->_tags.push_back(new Tag("menu/tags/PersonalizationSkillNormal.png", "menu/tags/PersonalizationSkillHighlit.png", false, false, TokenMenu::LAST, 3500.0f, 0.0f, 2020.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3500.0f, 0.0f, 2085.0f));
  this->_model[0] = gdl::Model::load(g_refModel[0]);
  this->_model[1] = gdl::Model::load(g_refModel[1]);
  this->_model[2] = gdl::Model::load(g_refModel[2]);
  this->_model[3] = gdl::Model::load(g_refModel[3]);
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

void	SkinChoose::updateText()
{

}

void	SkinChoose::changeSkin(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_indexSkin;
      if (static_cast<int>(this->_indexSkin) < 0)
	this->_indexSkin = Skin::LAST - 1;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_indexSkin;
      if (this->_indexSkin >= Skin::LAST - 1)
	this->_indexSkin = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void	SkinChoose::changeSkill(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_indexSkill;
      if (static_cast<int>(this->_indexSkill) < 0)
	this->_indexSkill = Skill::LAST;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_indexSkill;
      if (this->_indexSkill >= Skill::LAST)
	this->_indexSkill = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void	SkinChoose::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_curToken == TokenMenu::SETTINGSCHOOSE)
    {
      this->_gameManager._mainProfile->setSkin(static_cast<Skin::eSkin>(this->_indexSkin));
      ProfileManager::setProfile(this->_gameManager._mainProfile->getId(), *this->_gameManager._mainProfile);
    }
}
