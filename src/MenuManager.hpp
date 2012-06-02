/*
 * NicoW
 * 15.05.12
 */

#ifndef	__MENU_MANAGER_HPP__
#define	__MENU_MANAGER_HPP__

#include <string>
#include <vector>
#include "AMenu.hpp"
#include "enum.hpp"
#include "Profile.hpp"
#include "MyGame.hpp"

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
  Profile *			_guest;
  double			_timerLoading;

private:
  typedef void	(MenuManager::*fInitGame)();
  std::vector<fInitGame>	_refInitGame;

private:
  void				initGameSolo(void);
  void				initGameCoop(void);
  void				initGameVersus(void);

public:
  virtual void			draw(void);
  virtual void			initialize(void);
  virtual void			update(gdl::GameClock const&, gdl::Input&);

public:
  MyGame*			createGame(gdl::GameClock&, gdl::Input&);
  void				initCamera(void);
  bool				isResume(void);
  bool				isStopGame(void);
  void				setPause(void);
  void				setEOG(void);
  bool				operator()(size_t);
};

#else

class MenuManager;

#endif	/* __MENU_MANAGEMENT_HPP__ */
