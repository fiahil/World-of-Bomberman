
#include "ExplodedBomb.hpp"

ExplodedBomb::ExplodedBomb(BombType::eBomb type,
			   Point const& pos,
			   Pattern const& real,
			   Pattern const& final,
			   APlayer* player,
			   double timer,
			   gdl::Model& model)
  : _type(type),
    _final(final),
    _real(real),
    _player(player),
    _timer(timer),
    _lastTime(-1.0),
    _EOE(false),
    _model(model)
{
  this->_pos = pos;
}

ExplodedBomb::~ExplodedBomb()
{
}

void		ExplodedBomb::initialize()
{
}

void		ExplodedBomb::update(gdl::GameClock const& clock, gdl::Input&)
{
  if (!this->_EOE && this->_lastTime <= clock.getTotalGameTime())
    {
      this->_EOE = true;
      if (this->_real._coefN < this->_final._coefN)
	{
	  ++this->_real._coefN;
	  this->_EOE = false;
	}
      if (this->_real._coefS < this->_final._coefS)
	{
	  ++this->_real._coefS;
	  this->_EOE = false;
	}
      if (this->_real._coefW < this->_final._coefW)
	{
	  ++this->_real._coefW;
	  this->_EOE = false;
	}
      if (this->_real._coefE < this->_final._coefE)
	{
	  ++this->_real._coefE;
	  this->_EOE = false;
	}
      this->_lastTime = clock.getTotalGameTime() + this->_timer;
      if (this->_EOE && this->_timer != -1.0f)
	{
	  this->_EOE = false;
	  this->_timer = -1.0f;
	}
    }
  this->_model.update(clock);
}

void		ExplodedBomb::drawPattern(double dir, Point const& pos)
{
  glPushMatrix();
  glTranslatef(pos._pos.x, pos._pos.y, pos._pos.z);
  glScalef(0.07f, 0.07f, 0.07f);
  glRotatef(dir, 0.0f, 1.0f, 0.0f);
  this->_model.draw();
  glPopMatrix();
}

void		ExplodedBomb::draw()
{
  Point		pos(this->_pos);

  for (size_t i = 1; i <= this->_real._coefN; ++i)
    {
      pos.setPos(this->_pos._x, this->_pos._y - i);
      this->drawPattern(0.0f, pos);
    }
  for (size_t i = 1; i <= this->_real._coefS; ++i)
    {
      pos.setPos(this->_pos._x, this->_pos._y + i);
      this->drawPattern(180.0f, pos);
    }
  for (size_t i = 1; i <= this->_real._coefW; ++i)
    {
      pos.setPos(this->_pos._x - i, this->_pos._y);
      this->drawPattern(90.0f, pos);
    }
  for (size_t i = 1; i <= this->_real._coefE; ++i)
    {
      pos.setPos(this->_pos._x + i, this->_pos._y);
      this->drawPattern(-90.0f, pos);
    }
}

bool		ExplodedBomb::isEOE() const
{
  return this->_EOE;
}

BombType::eBomb	ExplodedBomb::getType() const
{
  return this->_type;
}

Pattern&	ExplodedBomb::getPatternReal()
{
  return this->_real;
}

Pattern const&	ExplodedBomb::getPatternReal() const
{
  return this->_real;
}

Pattern&	ExplodedBomb::getPatternFinal()
{
  return this->_final;
}

APlayer*	ExplodedBomb::getPlayer() const
{
  return this->_player;
}
