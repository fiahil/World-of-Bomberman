/*
 * Fiahil
 * 21 Mai 2012
 */

#ifndef	__PROFILEMANAGER_HPP__
#define	__PROFILEMANAGER_HPP__

#include "Profile.hpp"

class ProfileManager
{
public:
  static size_t		maxId;

public:
  static bool		isHere(size_t);
  static size_t		getMax(void);
  static Profile*	getProfile(size_t);
  static void		setProfile(size_t, Profile const&);
};

#endif		/* __PROFILEMANAGER_HPP__ */
