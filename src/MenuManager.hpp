/*
 * NicoW
 * 15.05.12
 */

#ifndef		__MENU_MANAGER_HPP__
#define		__MENU_MANAGER_HPP__

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <GL/gl.h>
#include "AMenu.hpp"
#include "enum.hpp"
#include "AObj.hpp"
#include "Camera.hpp"
#include "Profile.hpp"
#include "MapManager.hpp"

class	MenuManager : public AObj
{
public:
  MenuManager(int, int);
  ~MenuManager();

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
  MapManager			_mapManager;

  /*
    Heritance from AObj
  */
public:
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif		/* __MENU_MANAGEMENT_HPP__ */
