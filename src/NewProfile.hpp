/*
 * Texan
 * 27.05.2012
 */

#ifndef __NEWPROFILE_HPP__
#define __NEWPROFILE_HPP__

#include "AMenu.hpp"

class	NewProfile : public AMenu
{
private:
  bool		_selected;
  bool		_strStatus;
  double	_oneTime;

public:
  NewProfile(GameManager&);
  virtual ~NewProfile(void);

  void			setNewProfile();
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif