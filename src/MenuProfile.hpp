/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MENUPROFILE_HPP__
#define __MENUPROFILE_HPP__

#include "AMenu.hpp"

class MenuProfile : public AMenu
{
public:
  MenuProfile(GameManager&);
  virtual ~MenuProfile();
  
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#else

class MenuProfile;

#endif
