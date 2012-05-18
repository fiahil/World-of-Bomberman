/*
 * Fiahil
 * 12.05.2012
 */

#include "Bomb.hpp"

static const std::string g_bombModel [] =
  {
    "models/normalBomb.fbx",
    "models/megaBomb.fbx"
  };

static const double g_bombTimer [] =
  {
    5.0,
    7.0
  };

static const size_t g_bombRange [] =
  {
    2,
    4
  };


Bomb::Bomb(BombType::eBomb t, Point const & pos, size_t id)
  : _type(t), _player(id), _timer(-1.0), _exploded(false)
{
  this->_pos = pos;
  this->_pattern._x = this->_pos._pos.x;
  this->_pattern._y = this->_pos._pos.y;
  this->_pattern._coefN = g_bombRange[t];
  this->_pattern._coefS = g_bombRange[t];
  this->_pattern._coefE = g_bombRange[t];
  this->_pattern._coefW = g_bombRange[t];
}

Bomb::~Bomb()
{
}

BombType::eBomb		Bomb::get_type(void) const
{
  return _type;
}

void		Bomb::initialize(void)
{
  this->_model = gdl::Model::load(g_bombModel[this->_type]);
}

void		Bomb::draw(void)
{
  if (!this->_exploded)
    {
      glPushMatrix();
      glTranslatef(this->_pos._pos.x, this->_pos._pos.y, this->_pos._pos.z);
      glScalef(this->_pos._scale, this->_pos._scale, this->_pos._scale);
      this->_model.draw();
      glPopMatrix();
    }
}

void		Bomb::update(gdl::GameClock const& clock, gdl::Input&)
{
  if (!this->_exploded && this->_timer == (-1.0))
    this->_timer = static_cast<double>(clock.getTotalGameTime()) +
      g_bombTimer[this->_type];
  else if (!this->_exploded && static_cast<double>(clock.getTotalGameTime()) >= this->_timer)
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

ExplodedBomb*	Bomb::createExplodedBomb(Pattern const& final)
{
  Pattern	tmp(final);

  tmp._coefN = 0;
  tmp._coefS = 0;
  tmp._coefW = 0;
  tmp._coefE = 0;
  return new ExplodedBomb(tmp, final, this->_player, this->_timer);
}
