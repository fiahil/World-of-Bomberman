/*
 * Texan
 * 27.05.2012
 */

#ifndef __TEAMMENU_HPP__
#define __TEAMMENU_HPP__

#include <vector>
#include "GameManager.hpp"
#include "AMenu.hpp"

class	TeamMenu : public AMenu
{
private:
  std::vector<Profile*>&	_profiles;
  std::vector<int>	_nb;
  std::vector<double>	_timersLR;

private:
  void	updateText() const;
  void	changeProfile(gdl::GameClock const&, gdl::Input&);
  void	changeNumber(gdl::GameClock const&, gdl::Input&);

public:
  TeamMenu(GameManager&, std::vector<Profile*>&);
  virtual ~TeamMenu(void);

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif
