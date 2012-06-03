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
  std::vector<Profile *>&	_profiles;
  std::vector<std::string>&	_names;
  size_t			_index;
  double			_timerL;
  double			_timerR;

public:
  LoadProfile(GameManager&, std::vector<Profile *>&, std::vector<std::string>&);
  virtual ~LoadProfile(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);

private:
  static bool		notGuest(const std::string&);
  void			updateText();
  void			changeProfile(gdl::GameClock const&, gdl::Input&);
};

#endif
