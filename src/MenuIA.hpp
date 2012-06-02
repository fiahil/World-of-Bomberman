/*
 * NicoW
 * 27.05.12
 */

#ifndef	__MENU_IA_HPP__
#define	__MENU_IA_HPP__

#include "AMenu.hpp"

class MenuIA : public AMenu
{
public:
  MenuIA(GameManager&);
  virtual ~MenuIA(void);
  
  virtual double	getCenterX(void) const;
  virtual double	getCenterY(void) const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#else

class MenuIA;

#endif	/* __MENU_IA_HPP__ */
