
#include <iostream>
#include "ExplodedBomb.hpp"

ExplodedBomb::ExplodedBomb(BombType::eBomb type, Point const& pos, Pattern const& real, Pattern const& final, size_t player, double timer)
  : _type(type),
    _final(final),
    _real(real),
    _player(player),
    _timer(timer),
    _lastTime(-1.0),
    _EOE(false)
{
  this->_pos = pos;
}

ExplodedBomb::~ExplodedBomb()
{

}

void	ExplodedBomb::initialize()
{
  this->_model = gdl::Model::load("models/tuskarr.fbx");
}

void	ExplodedBomb::update(gdl::GameClock const& clock, gdl::Input&)
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
}

void	ExplodedBomb::drawPattern(Point const& pos)
{
  glPushMatrix();
  glTranslatef(pos._pos.x, pos._pos.y, pos._pos.z);
  glScalef(0.5f, 0.5f, 0.5f);
  // glScalef(0.005f, 0.005f, 0.005f);
  this->_model.draw();
  glPopMatrix();
}

void	ExplodedBomb::draw()
{
  Point		pos(this->_pos);
  size_t	i;

  this->drawPattern(pos);
  for (i = 1; i <= this->_real._coefN; ++i)
    {
      pos.setPos(this->_pos._x, this->_pos._y - i);
      this->drawPattern(pos);
    }
  for (i = 1; i <= this->_real._coefS; ++i)
    {
      pos.setPos(this->_pos._x, this->_pos._y + i);
      this->drawPattern(pos);
    }
  for (i = 1; i <= this->_real._coefW; ++i)
    {
      pos.setPos(this->_pos._x - i, this->_pos._y);
      this->drawPattern(pos);
    }
  for (i = 1; i <= this->_real._coefE; ++i)
    {
      pos.setPos(this->_pos._x + i, this->_pos._y);
      this->drawPattern(pos);
    }
}

bool	ExplodedBomb::isEOE() const
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
