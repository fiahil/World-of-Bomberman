/***********************************************************************
 * Module:  Cube.h
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Cube
 ***********************************************************************/

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

class Cube
{
private:
  Image*	_txt;
  double	scale;

private:
  Cube(Cube const&);
  Cube&	operator=(Cube const&);
  
public:
  Cube(Point const&);
  Cube(Point const&, gdl::Image*, double scale = 1.0f);
  ~Cube();
  virtual void	initialize();
  virtual void	draw();
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);
};

#else

class Cube;

#endif
