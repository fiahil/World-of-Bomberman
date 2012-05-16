/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __ENUM_HPP__
#define __ENUM_HPP__

struct Input
{
  enum eMode {
    CHEAT,
    GAME,
    MENU,
    LAST
  };

};

struct HumGame {

  enum eAction {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    ATTACK,
    PAUSE,
    CHEAT,
    LAST
  };

};

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
