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

#define	CAM_DISTANCE	(600.0f)

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
  std::vector<Map *>		_map;
  GameManager			_gameManager;
  bool				_createGame;

  /*
    Heritance from AObj
  */
public:
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  MyGame*		createGame(gdl::GameClock&, gdl::Input&);
};

#endif		/* __MENU_MANAGEMENT_HPP__ */
