/*
 * Texan
 * 25.05.12
 */

#ifndef __PROFILELOADER_HPP__
#define __PROFILELOADER_HPP__

#include <vector>
#include "Profile.hpp"
#include "ProfileManager.hpp"

class	ProfileLoader
{
private:
  std::string			_folder;
  ProfileManager		_pm;
  std::vector<Profile *>	_profiles;
  std::vector<std::string>	_names;

  bool	isNum(std::string) const;
  int	idToInt(std::string);

public:
  ProfileLoader(void);

  void					setProfiles(void);
  const std::vector<Profile *>&		getProfiles(void);
  const std::vector<std::string>&	getNames(void) const;
  void					unsetProfiles(void);
};

#endif
