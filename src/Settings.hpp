/*
 * lemonn_v
 * 15.05.12
 */

#ifndef		__SETTINGS_HPP__
#define		__SETTINGS_HPP__

#include "AMenu.hpp"

class Settings : public AMenu
{
private:
  double	_oneTime;
  bool		_selected;

public:
  Settings(GameManager&);
  virtual ~Settings();

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#else

class Settings;

#endif		/* __SETTINGS_HPP__ */
