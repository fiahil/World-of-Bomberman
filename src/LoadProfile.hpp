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
  ProfileLoader			_profileLoader;

  int		getCurTagPos(void) const;

public:
  LoadProfile(GameManager&, std::vector<Profile *>&);
  virtual ~LoadProfile(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif
