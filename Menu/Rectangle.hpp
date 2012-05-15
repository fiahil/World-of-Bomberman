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
  Rectangle();
  Rectangle(const Rectangle&);
  Rectangle&	operator=(const Rectangle&);

private:
  Point*	_p;
  gdl::Image&	_txt;

public:
  virtual void initialize(void);
  virtual void draw(void);
  virtual void update(const gdl::GameClock& clock, gdl::Input& input);
};

#endif		/* __RECTANGLE_HPP__ */
