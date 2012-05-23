
#ifndef __EXPLODEDBOMB_HPP__
#define __EXPLODEDBOMB_HPP__

#include <Model.hpp>
#include "APlayer.hpp"
#include "enum.hpp"
#include "Pattern.hpp"
#include "AObj.hpp"

class ExplodedBomb : public AObj
{
private:
  BombType::eBomb	_type;		
  Pattern		_final;
  Pattern		_real;
  APlayer*		_player;
  double		_timer;
  double		_lastTime;
  bool			_EOE;
  gdl::Model&		_model;
  
private:
  void	drawPattern(Point const&);

public:
  ExplodedBomb(BombType::eBomb, Point const&, Pattern const&, Pattern const&, APlayer*, double, gdl::Model&);
  virtual ~ExplodedBomb();
  virtual void	initialize();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
  virtual void	draw();
  bool	isEOE() const;
  BombType::eBomb	getType() const;
  Pattern&	getPatternReal();
  Pattern const&	getPatternReal() const;
  Pattern&	getPatternFinal();
  APlayer*	getPlayer() const;
};

#else

class ExplodedBomb;

#endif
