/***********************************************************************
 * Module:  Cube.h
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Cube
 ***********************************************************************/

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include <Image.hpp>
#include <Input.hpp>
#include <GameClock.hpp>
#include "AObj.hpp"
#include "Point.hpp"

class Cube : public AObj
{
private:
  Point*	_p;
  gdl::Image&	_txt;

private:
  Cube(Cube const&);
  Cube&	operator=(Cube const&);
  virtual void	draw();
  
public:
  //Cube();
  Cube(gdl::Image&);
  ~Cube();
  virtual void	initialize();
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);
  void	draw(Point&);
};

#else

class Cube;

#endif
