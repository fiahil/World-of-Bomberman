/*
 * NicoW
 * 27.05.12
 */

#ifndef		__MENU_MAP_HPP__
#define		__MENU_MAP_HPP__

#include "AMenu.hpp"

class	MenuMap : public AMenu
{
public:
  MenuMap(GameManager&);
  virtual ~MenuMap(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif		/* __MENU_MAP_HPP__ */
