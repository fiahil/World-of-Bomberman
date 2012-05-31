/*
 * lemonn_v
 * 21 Mai 2012
 */

#ifndef __SAVEMANAGER_HPP__
#define __SAVEMANAGER_HPP__

#include "Profile.hpp"
#include "Match.hpp"

class SaveManager
{
public:
  static size_t		maxId;
  
public:
  static bool		isHere(size_t);
  static size_t		getMax(void);
  static Match*		getSave(size_t);
  static void		setSave(size_t, Match const&);
};

#endif /* __SAVEMANAGER_HPP__ */
