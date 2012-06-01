/*
 * NicoW
 * 29.05.12
 */

#include <iostream>
#include <Model.hpp>
#include "ProfileManager.hpp"
#include "SkinChoose.hpp"

static const char*	g_refSkin[Skin::LAST - 1] = {
  "Warwik",
  "Sylvanas",
  "Variant",
  "Zuljin"
};

static const char*	g_refSkill[Skill::LAST] = {
  "Divine Intervention",
  "Protective Spirit",
  "Quick Jump",
  "Berserker's Rage"
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
    _rot(0.0f),
    _timerL(-1.0f),
    _timerR(-1.0f),
    _indexSkin(Skin::LAST),
    _indexSkill(Skill::LAST)
{
  this->_tags.push_back(new Tag("menu/tags/PersonalizationSkinNormal.png", "menu/tags/PersonalizationSkinHighlit.png", true, false, TokenMenu::LAST, 3500.0f, 0.0f, 1955.0f));
  this->_tags.push_back(new Tag("menu/tags/PersonalizationSkillNormal.png", "menu/tags/PersonalizationSkillHighlit.png", false, false, TokenMenu::LAST, 3500.0f, 0.0f, 2020.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::SETTINGSCHOOSE, 3500.0f, 0.0f, 2085.0f));
}

SkinChoose::~SkinChoose()
{
}

void	SkinChoose::initialize()
{
  AMenu::initialize();
  this->_model[0] = gdl::Model::load(g_refModel[0]);
  this->_model[1] = gdl::Model::load(g_refModel[1]);
  this->_model[2] = gdl::Model::load(g_refModel[2]);
  this->_model[3] = gdl::Model::load(g_refModel[3]);
  this->_tp = gdl::Model::load("./models/Set_tp.FBX");
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
  this->_tags[0]->createText(g_refSkin[this->_indexSkin], 20, 700, 370);
  this->_tags[1]->createText(g_refSkill[this->_indexSkill], 20, 650, 435);
}

void	SkinChoose::changeSkin(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_indexSkin;
      if (static_cast<int>(this->_indexSkin) < 0)
	this->_indexSkin = Skin::LAST - 2;
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
	this->_indexSkill = Skill::LAST - 1;
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
  if (this->_indexSkin == Skin::LAST)
    {
      this->_indexSkin = this->_gameManager._mainProfile->getSkin();
      this->_indexSkill = this->_gameManager._mainProfile->getSkill();
    }
  this->_model[this->_indexSkin].update(clock);
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 0) //TODO
    this->changeSkin(clock, input);
  else if (this->_cursor == 1)
    this->changeSkill(clock, input);
  if (this->_curToken == TokenMenu::SETTINGSCHOOSE)
    {
      this->_gameManager._mainProfile->setSkin(static_cast<Skin::eSkin>(this->_indexSkin));
      this->_gameManager._mainProfile->setSkill(static_cast<Skill::eSkill>(this->_indexSkill));
      ProfileManager::setProfile(this->_gameManager._mainProfile->getId(), *this->_gameManager._mainProfile);
    }
}

void	SkinChoose::draw()
{
  AMenu::draw();
  glPushMatrix();
  glTranslatef(4001.2f, 569.0f, 2000.4f);
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(this->_rot, 0.0f, 1.0f, 0.0f);
  this->_rot += 1.0f;
  if (this->_rot >= 360.0f)
    this->_rot = 0.0f;
  glScalef(0.15f, 0.15f, 0.15f);
  if (this->_indexSkin < Skin::LAST - 1)
    this->_model[this->_indexSkin].draw();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(4001.2f, 569.02f, 2000.57f);
  glRotatef(-100.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(7.0f, 0.0f, 0.0f, 1.0f);
  glScalef(0.05f, 0.05f, 0.05f);
  this->_tp.draw();
  glPopMatrix();
}
