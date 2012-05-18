
#include "ExplodedBomb.hpp"

ExplodedBomb::ExplodedBomb(Pattern const& real, Pattern const& final, size_t player, double timer)
  : _final(final),
    _real(real),
    _player(player),
    _timer(timer),
    _lastTime(-1.0),
    _EOE(false)
{
  
}

ExplodedBomb::~ExplodedBomb()
{

}

void	ExplodedBomb::initialize()
{
  
}

void	ExplodedBomb::update(gdl::GameClock const& clock, gdl::Input&)
{
  if (!this->_EOE && this->_lastTime + this->_timer >= clock.getTotalGameTime())
    {
      this->_EOE = true;
      if (this->_real._coefN < this->_final._coefN)
	++this->_real._coefN;
      else
	this->_EOE = false;
      if (this->_real._coefS < this->_final._coefS)
	++this->_real._coefS;
      else
	this->_EOE = false;
      if (this->_real._coefW < this->_final._coefW)
	++this->_real._coefS;
      else
	this->_EOE = false;
      if (this->_real._coefE < this->_final._coefE)
	++this->_real._coefE;
      else
	this->_EOE = false;
      this->_lastTime = clock.getTotalGameTime();
    }
}

void	ExplodedBomb::draw()
{

}

bool	ExplodedBomb::isEOE() const
{
  return this->_EOE;
}

Pattern const&	ExplodedBomb::getPattern() const
{
  return this->_real;
}