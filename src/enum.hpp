/***********************************************************************
 * Module:  enum.hpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:17 PM
 * Purpose: Declaration of the class enum
 ***********************************************************************/

#ifndef __ENUM_HPP__
#define __ENUM_HPP__

struct Bomb
{
  enum eBomb
    {
      NORMAL,
      MEGABOMB,
      LAST
    };
};

struct Skin
{
  enum eSkin
    {
      NORMAL,
      LAST
    };
};

struct State
{
  enum eState
    {
      RUN,
      WALK,
      STATIC,
      LAST
    };
};

struct Dir
{
  enum eDir
    {
      NORTH,
      SOUTH,
      WEST,
      EAST,
      LAST
    };
};

struct Bonus
{
  enum eBonus
    {
      SOMETHING,
      LAST
    };
};

struct GameMode
{
  enum eGameMode
    {
      HISTORY,
      ARCADE,
      DEATH,
      CAPT_FLAG,
      NETWORK,
      LAST
    };
};

#endif
