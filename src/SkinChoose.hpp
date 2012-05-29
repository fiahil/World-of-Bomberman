/*
 * NicoW
 * 29.05.12
 */

#ifndef		__SKIN_CHOICE_HPP__
#define		__SKIN_CHOICE_HPP__

#include "AMenu.hpp"

class SkinChoose : public AMenu
{
public:
  SkinChoose(GameManager&);
  virtual ~SkinChoose();

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#else

class SkinChoose;

#endif		/* __SKIN_CHOICE_HPP__ */
