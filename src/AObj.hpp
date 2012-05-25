/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_AObj_h)
#define __Bomberman_AObj_h

#include <GameClock.hpp>
#include <Input.hpp>
#include "Point.hpp"

class AObj
{
public:
  AObj();
  ~AObj();

private:
   AObj(const AObj& oldAObj);

protected:
   Point	_pos;

public:
  virtual void	initialize(void) = 0;
  virtual void	draw(void) = 0;
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input) = 0;

  void		setPos(int, int);
  void		setPos(double, double, double);
  void		setScale(double);
  Point const&	getPos() const;
};

#endif
