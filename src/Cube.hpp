/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include <Image.hpp>
#include <Input.hpp>
#include <GameClock.hpp>
#include "AObj.hpp"
#include "Point.hpp"

class Cube : public AObj
{
public:
  Cube(gdl::Image&);
  ~Cube();

private:
  Cube(Cube const&);
  Cube&	operator=(Cube const&);

private:
  Point*	_p;
  gdl::Image&	_txt;

private:
  virtual void	draw();

public:
  virtual void	initialize();
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);
  void		draw(Point&);
};

#else

class Cube;

#endif
