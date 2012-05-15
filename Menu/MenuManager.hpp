/*
 * NicoW
 * 15.05.12
 */

#ifndef		__MENU_MANAGER_HPP__
#define		__MENU_MANAGER_HPP__

#include <vector>
#include "AMenu.hpp"
// #include "enum.hpp"

struct Menu			// Move dans enum.hpp dans src quand pret
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

class	MenuManager
{
public:
  MenuManager();
  ~MenuManager();

private:
  MenuManager(const MenuManager &);
  const MenuManager & operator=(const MenuManager &);

private:
  std::vector<AMenu>	_menus;
  Menu::eMenu		_curMenu;

public:
  void		run();

private:
  void		buildMainMenu(void);
  void 		buildNewProfileMenu(void);
  void 		buildProfileMenu(void);
  void 		buildSlidingMenu(void);
  void 		buildGameChooseMenu(void);
  void 		buildSettingsMenu(void);
};

#endif		/* __MENU_MANAGEMENT_HPP__ */
