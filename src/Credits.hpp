/*
 * NicoW
 * 28.05.2012
 */

#ifndef		__CREDITS_HPP__
#define		__CREDITS_HPP__

#include "AMenu.hpp"

class	Credits : public AMenu
{
public:
  Credits(GameManager&);
  virtual ~Credits(void);

public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
};

#endif		/* __CREDITS_HPP__ */
