/*
 * Fiahil
 * 12.05.2012
 */

#include "Bomb.hpp"

Bomb::Bomb(BombType::eBomb t,
	   Point const & pos,
	   APlayer* p,
	   gdl::Model& model,
	   gdl::Model& modelE,
	   size_t power)
  : _type(t),
    _player(p),
    _timer(-1.0),
    _exploded(false),
    _model(model),
    _modelExploded(modelE)
{
  this->_pos = pos;
  this->_pattern._x = this->_pos._x;
  this->_pattern._y = this->_pos._y;
  this->_pattern._coefN = 1 + power;
  this->_pattern._coefS = 1 + power;
  this->_pattern._coefE = 1 + power;
  this->_pattern._coefW = 1 + power;
}

Bomb::~Bomb()
{
}

BombType::eBomb	Bomb::get_type(void) const
{
  return _type;
}

void		Bomb::initialize(void)
{
}

void		Bomb::draw(void)
{
  if (!this->_exploded)
    {
      glPushMatrix();
      glTranslatef(this->_pos._pos.x, this->_pos._pos.y - 0.5f, this->_pos._pos.z);
      glScalef(0.3f, 0.3f, 0.3f);
      this->_model.draw();
      glPopMatrix();
    }
}

void		Bomb::update(gdl::GameClock const& clock, gdl::Input&)
{
  if (!this->_exploded && this->_timer == (-1.0))
    this->_timer = static_cast<double>(clock.getTotalGameTime()) + 2.0f;
  else if (!this->_exploded &&
	   static_cast<double>(clock.getTotalGameTime()) >= this->_timer)
    this->_exploded = true;
}

Pattern const&	Bomb::getPattern() const
{
  return this->_pattern;
}

bool		Bomb::explode() const
{
  return this->_exploded;
}

ExplodedBomb*	Bomb::createExplodedBomb() const
{
  ExplodedBomb	*ret;
  Pattern	tmp(this->_pattern);

  tmp._coefN = 0;
  tmp._coefS = 0;
  tmp._coefW = 0;
  tmp._coefE = 0;
  ret = new ExplodedBomb(this->_type,
			 this->_pos, tmp,
			 this->_pattern,
			 this->_player,
			 0.2f,
			 this->_modelExploded);
  return ret;
}
