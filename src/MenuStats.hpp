/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MENUSTATS_HPP__
#define __MENUSTATS_HPP__

#include "AMenu.hpp"

class MenuStats : public AMenu
{
private:
  gdl::Text	_text;

public:
  MenuStats(GameManager&);
  virtual ~MenuStats();

  virtual double	getCenterX(void) const;
  virtual double	getCenterY(void) const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void		draw(void);

private:
  void			drawText(void);
};

#else

class MenuStats;

#endif
