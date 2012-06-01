/*
 * NicoW
 * 15.05.12
 */

#ifndef		__MENU_MANAGER_HPP__
#define		__MENU_MANAGER_HPP__

#include <string>
#include <vector>
#include "AMenu.hpp"
#include "enum.hpp"
#include "AObj.hpp"
#include "Camera.hpp"
#include "Profile.hpp"
#include "MyGame.hpp"
#include "MapManager.hpp"

#define	CAM_DISTANCE	(570.4f)

class	MenuManager : public AObj
{
public:
  MenuManager(int, int);
  virtual ~MenuManager();

private:
  MenuManager();
  MenuManager(const MenuManager &);
  const MenuManager & operator=(const MenuManager &);

private:
  std::vector<AMenu *>		_menu;
  TokenMenu::eMenu		_curMenu;
  Camera			_camera;

  std::vector<Profile *>	_profile;
  std::vector<std::string>	_names;
  std::vector<Map *>		_map;
  GameManager			_gameManager;
  bool				_createGame;
  bool				_resume;
  bool				_stopGame;

private:
  typedef void	(MenuManager::*fInitGame)();

  void	initGameSolo();
  void	initGameCoop();
  void	initGameVersus();
  std::vector<fInitGame>	_refInitGame;

  /*
    Heritance from AObj
  */
public:
  virtual void			draw(void);
  virtual void			initialize(void);
  virtual void			update(gdl::GameClock const&, gdl::Input&);

  MyGame*			createGame(gdl::GameClock&, gdl::Input&);
  void				initCamera(void);
  bool				isResume();
  bool				isStopGame();
  void				setPause();
  void				setEOG();
};

#endif		/* __MENU_MANAGEMENT_HPP__ */
