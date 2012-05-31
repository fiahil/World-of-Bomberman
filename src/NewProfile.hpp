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
  std::vector<Profile *>&	_profiles;
  std::vector<std::string>&	_names;
  bool				_selected;
  bool				_strStatus;
  double			_oneTime;

  bool				alreadyExists(std::string);

public:
  NewProfile(GameManager&, std::vector<Profile *>&, std::vector<std::string>&);
  virtual ~NewProfile(void);

  void			setNewProfile();
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif
