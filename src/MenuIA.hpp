/*
 * NicoW
 * 27.05.12
 */

#ifndef		__MENU_IA_HPP__
#define		__MENU_IA_HPP__

#include "AMenu.hpp"

class	MenuIA : public AMenu
{
public:
  MenuIA(GameManager&);
  virtual ~MenuIA(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#endif		/* __MENU_IA_HPP__ */
