/*
 * Fiahil
 * 12.05.2012
 */

#include "Bonus.hpp"

Bonus::Bonus(BonusType::eBonus t, Point const& p, gdl::Model& model)
  : _type(t),
    _model(model)
{
  this->_pos = p;
}

Bonus::~Bonus()
{
}

BonusType::eBonus		Bonus::getType(void) const
{
  return this->_type;
}

void		Bonus::initialize(void)
{
}

void		Bonus::draw()
{
  glPushMatrix();
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y, this->_pos._pos.z);
  glScalef(1.0f, 1.0f, 1.0f);
  this->_model.draw();
  glPopMatrix();
}

void		Bonus::update(gdl::GameClock const& clock, gdl::Input&)
{
  this->_model.play("Take 001");
  this->_model.update(clock);
}
