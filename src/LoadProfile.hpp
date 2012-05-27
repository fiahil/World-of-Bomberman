/*
 * Texan
 * 27.05.2012
 */

#ifndef __LOADPROFILE_HPP__
#define __LOADPROFILE_HPP__

#include <vector>
#include "AMenu.hpp"
#include "ProfileLoader.hpp"

class	LoadProfile : public AMenu
{
  private:
  std::vector<Profile *>	_profiles;
  ProfileLoader			_profileLoader;

public:
  LoadProfile(GameManager&);
  virtual ~LoadProfile(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		doAction(gdl::GameClock const&, gdl::Input&);
};

#endif
