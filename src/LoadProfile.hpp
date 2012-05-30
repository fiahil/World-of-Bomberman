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
  size_t			_index;
  double			_timerL;
  double			_timerR;

public:
  LoadProfile(GameManager&, std::vector<Profile *>&);
  virtual ~LoadProfile(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);

private:
  void			updateText() const;
  void			changeProfile(gdl::GameClock const&, gdl::Input&);
};

#endif
