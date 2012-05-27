/*
 * Texan
 * 27.05.2012
 */

#ifndef __NEWPROFILE_HPP__
#define __NEWPROFILE_HPP__

#include "AMenu.hpp"

class	NewProfile : public AMenu
{
public:
  NewProfile(GameManager&);
  virtual ~NewProfile(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#endif
