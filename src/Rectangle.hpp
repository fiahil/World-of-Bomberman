/*
 * Nicow
 * 15.05.12
 */

#ifndef		__RECTANGLE_HPP__
#define		__RECTANGLE_HPP__

#include <Image.hpp>
#include <Input.hpp>
#include <GameClock.hpp>
#include "AObj.hpp"
#include "Point.hpp"

class		Rectangle : public AObj
{
public:
  Rectangle(gdl::Image&);
  ~Rectangle();

private:
  Rectangle(Rectangle const&);
  Rectangle&	operator=(Rectangle const&);

private:
  Point*	_p;
  gdl::Image&	_txt;

private:
  virtual void	draw();

public:
  virtual void	initialize();
  virtual void	update(gdl::GameClock const&, gdl::Input&);
  void		draw(Point&);
};

#endif		/* __RECTANGLE_HPP__ */
