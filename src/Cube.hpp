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
  virtual ~Cube();

private:
  Cube(Cube const&);
  Cube&	operator=(Cube const&);

private:
  Point*	_p;
  gdl::Image&	_txt;

public:
  void	initialize();
  void	update(gdl::GameClock const&, gdl::Input&);
  void	draw(Point&);

private:
  void	draw();

};

#else

class Cube;

#endif
