/*
 * NicoW
 * 29.05.12
 */

#ifndef	__SETTINGS_CHOOSE_HPP__
#define	__SETTINGS_CHOOSE_HPP__

#include "AMenu.hpp"

class SettingsChoose : public AMenu
{
public:
  SettingsChoose(GameManager&);
  virtual ~SettingsChoose();

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#else

class SettingsChoose;

#endif		/* __SETTINGS_CHOOSE_HPP__ */
