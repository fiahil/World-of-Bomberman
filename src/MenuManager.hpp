/*
 * NicoW
 * 15.05.12
 */

#ifndef		__MENU_MANAGER_HPP__
#define		__MENU_MANAGER_HPP__

#include <vector>
#include "AMenu.hpp"
#include "enum.hpp"
#include "AObj.hpp"
#include "Camera.hpp"

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
  std::vector<AMenu *>	_menus;
  TokenMenu::eMenu	_curMenu;
  Camera		_camera;

public:
  void			run();
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);

private:
  void		buildMainMenu(void);
  void 		buildNewProfileMenu(void);
  void 		buildProfileMenu(void);
  void 		buildSlidingMenu(void);
  void 		buildGameChooseMenu(void);
  void 		buildSettingsMenu(void);
};

#endif		/* __MENU_MANAGEMENT_HPP__ */
