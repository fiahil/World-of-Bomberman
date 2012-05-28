/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __ENUM_HPP__
#define __ENUM_HPP__

struct Success
{
  enum eSuccess {
    ONE_KILL,
    TUTO,
    BONUS,
    FIVE_KILL,
    HARD_AI,
    POWER,
    LUST,
    TP,
    DIE,
    FABULOUS,
    LAST
  };

};

struct Input
{
  enum eMode {
    CHEAT,
    GAME,
    MENU,
    LAST
  };

};

struct HumGame
{
  enum eAction {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    ATTACK,
    PAUSE,
    CHEAT,
    SKILL,
    LAST
  };

};

struct BombType
{
  enum eBomb {
      NORMAL,
      BIGBOMB,
      MEGABOMB,
      LAST
    };
};

struct Skin
{
  enum eSkin
    {
      THRALL,
      SYLVANAS,
      VARIANT,
      ZULJIN,
      ENNEMY_HIGH,
      ENNEMY_LOW,
      LAST
    };
};

struct Skill
{
  enum eSkill
    {
      HALLU,
      HEAL,
      BERSERK,
      JUMP,
      LAST
    };
};

struct State
{
  enum eState
    {
      RUN,
      STAND,
      ATTACK,
      DEATH,
      HIT,
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

struct BonusType
{
  enum eBonus
    {
      LIFE,
      BOMB,
      LUST,
      POWER,
      SHIELD,
      LAST
    };
};

struct GameMode
{
  enum eGameMode
    {
      SOLO,
      COOP,
      VERSUS,
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

struct HUD
{
  enum eHUD {
    LIFE_BAR,
    LIFE,
    SHIELD,
    POWER,
    LUST,
    BOMB_OK,
    BOMB_KO,
    SKILL_OK,
    SKILL_KO,
    BIGBOMB_OK,
    BIGBOMB_KO,
    MEGABOMB_OK,
    MEGABOMB_KO,
    SUCCESS_ONE_KILL,
    SUCCESS_TUTO,
    SUCCESS_BONUS,
    SUCCESS_FIVE_KILL,
    SUCCESS_HARD_AI,
    SUCCESS_POWER,
    SUCCESS_LUST,
    SUCCESS_TP,
    SUCCESS_DIE,
    SUCCESS_FABULOUS,
    LAST
  };
};

struct AIType
{
  enum eAI {
    EASY,
    MEDIUM,
    HARD,
    LAST
  };
};

struct Elt
{
  enum eElt {
    EMPTY,
    WALL,
    BOMB,
    EXBOMB,
    BONUS,
    PLAYER
  };
};

#endif
