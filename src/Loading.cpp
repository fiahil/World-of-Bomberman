/*
 * lemonn_v
 * 15.05.12
 */

#include "Loading.hpp"
#include "enum.hpp"

Loading::Loading(GameManager& game)
  : AMenu("menu/background/LoadingNormal.jpg", "menu/background/LoadingNormal1.jpg", 4800.0f, -2.0f, 1600.0f, game),
    _timer(-1.0f),
    _model(Skin::LAST)
{
  this->_tags.push_back(new Tag("menu/background/LoadingNormal.jpg",
				"menu/background/LoadingNormal1.jpg", true, false,
				TokenMenu::LAST, 4800.0f, -1.0f, 1600.0f));
}

Loading::~Loading()
{
}

double	Loading::getCenterX() const
{
  return 5600.0f;
}

double	Loading::getCenterY() const
{
  return 2000.0f;
}

void          Loading::initialize()
{
  AMenu::initialize();

  this->_model[Skin::WORGEN]	 = gdl::Model::load("models/Character_ennemy.FBX");
  this->_model[Skin::SYLVANAS]	 = gdl::Model::load("models/Character_sylvanas.FBX");
  this->_model[Skin::VARIANT]	 = gdl::Model::load("models/Character_varian.FBX");
  this->_model[Skin::ZULJIN]	 = gdl::Model::load("models/Character_zuljin.FBX");
  this->_model[Skin::ENNEMY_LOW] = gdl::Model::load("models/Character_ennemy_low.FBX");

  gdl::Model::cut_animation(this->_model.at(Skin::WORGEN), "Take 001", 3, 18, "run");
  gdl::Model::cut_animation(this->_model.at(Skin::SYLVANAS), "Take 001", 3, 18, "run");
  gdl::Model::cut_animation(this->_model.at(Skin::VARIANT), "Take 001", 3, 18, "run");
  gdl::Model::cut_animation(this->_model.at(Skin::ZULJIN), "Take 001", 236, 255, "run");
  gdl::Model::cut_animation(this->_model.at(Skin::ENNEMY_LOW), "Take 001", 3, 18, "run");
}

void          Loading::draw()
{
  AMenu::draw();

  glPushMatrix();
  glTranslatef(5599.4f, 569.0f, 2000.4f);
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glScalef(0.15f, 0.15f, 0.15f);
  if (this->_gameManager._mainProfile)
    this->_model.at(this->_gameManager._mainProfile->getSkin()).draw();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5600.6f, 569.0f, 2000.4f);
  glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glScalef(0.15f, 0.15f, 0.15f);
  this->_model.at(4).draw();
  glPopMatrix();
}


void	Loading::update(gdl::GameClock const& clock, gdl::Input&)
{
  this->_model.at(4).play("run");
  this->_model.at(4).update(clock);
  if (this->_gameManager._mainProfile)
    {
      this->_model.at(this->_gameManager._mainProfile->getSkin()).play("run");
      this->_model.at(this->_gameManager._mainProfile->getSkin()).update(clock);
    }
  if (clock.getTotalGameTime() >= this->_timer)
    {
      this->_tags.at(0)->setStatus(!(this->_tags.at(0)->getStatus()));
      this->_timer = clock.getTotalGameTime() + 0.5f;
    }
}
