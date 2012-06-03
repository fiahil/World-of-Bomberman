/*
 * Fiahil
 * 12.05.2012
 */

#ifndef __ENUM_HPP__
#define __ENUM_HPP__

struct Audio
{
  enum eAudio {
    ENNEMY_HURT,
    ENNEMY_DEATH,
    SYLVANAS_HURT,
    SYLVANAS_DEATH,
    VARIANT_HURT,
    VARIANT_DEATH,
    WORGEN_HURT,
    WORGEN_DEATH,
    ZULJIN_HURT,
    ZULJIN_DEATH,
    TIMER_START,
    START,
    EXPLODE,
    EXPLODE_DIFFUSE,
    BONUS,
    SUCCESS,
    INTRO,
    MENU,
    LAST
  };
};

struct AudioMode
{
  enum eMode
  {
    GAME,
    MENU,
    LAST
  };
};

struct JsInput
{
  enum eButton
  {
    A = 0, B = 1, X = 2, Y = 3,
    SELECT = 6, START = 7,
    UP, DOWN, LEFT, RIGHT,
    LAST
  };
};

struct Success
{
  enum eSuccess {
    ONE_KILL,
    BONUS,
    FIVE_KILL,
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
      WORGEN,
      SYLVANAS,
      VARIANT,
      ZULJIN,
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
      SPRINT,
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
      CREDITS,
      LOADPROFILE,
      LOADSAVE,
      LOADMAP,
      GAMECHOOSE,
      IA,
      TEAM,
      MAP,
      NEWPROFILE,
      PROFILE,
      SETTINGSCHOOSE,
      SETTINGS,
      SKINCHOOSE,
      STATS,
      QUIT,
      CREATEGAME,
      PAUSE,
      GAMERESULT,
      LOADING,
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
    SPRINT,
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
    SUCCESS_BONUS,
    SUCCESS_FIVE_KILL,
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
    NORMAL,
    HARD,
    HALLU,
    HUMAN,
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
