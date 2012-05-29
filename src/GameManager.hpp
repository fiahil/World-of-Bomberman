/*
 * NicoW
 * 28.05.12
 */

#ifndef		__GAME_MANAGER_HPP__
#define		__GAME_MANAGER_HPP__

#include "enum.hpp"
#include "Profile.hpp"
#include "Config.hpp"
#include "Match.hpp"

struct	GameManager
{

public:
  Profile *		_mainProfile;
  Profile *		_secondProfile;
  Config		_configJ1;
  Config		_configJ2;
  AIType::eAI		_typeAI;
  int			_nbPlayers;
  int			_nbTeams;
  Match			_match;

public:
  GameManager(Profile * = 0);
};

#endif		/* __GAME_MANAGEMENT_HPP__ */
