
#ifndef __EXPLODEDBOMB_HPP__
#define __EXPLODEDBOMB_HPP__

#include <Model.hpp>
#include "Bomb.hpp"
#include "AObj.hpp"

class ExplodedBomb : public AObj
{
private:
  Pattern		_final;
  Pattern		_real;
  size_t		_player;
  double		_timer;
  double		_lastTime;
  bool			_EOE;
  gdl::Model		_model;
  
private:
  void	drawPattern(Point const&);

public:
  ExplodedBomb(Point const&, Pattern const&, Pattern const&, size_t, double);
  virtual ~ExplodedBomb();
  virtual void	initialize();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
  virtual void	draw();
  bool	isEOE() const;
  Pattern&	getPatternReal();
  Pattern&	getPatternFinal();
};

#else

class ExplodedBomb;

#endif
