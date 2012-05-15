/*
 * Fiahil
 * 12.05.2012
 */

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

struct TokenMenu
{
  enum eMenu
    {
      MAINMENU,
      NEWPROFILE,
      PROFILE,
      SLIDING,
      GAMECHOOSE,
      SETTINGS,
      BACK,
      QUIT,
      LAST
    };
};

struct Sprite
{
  enum	eSprite
    {
      SELECTED,
      DESELECTED
    };
};


#endif
