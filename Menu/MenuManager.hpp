/*
 * NicoW
 * 15.05.12
 */

#indef		__MENU_MANAGER_HPP__
#define		__MENU_MANAGER_HPP__

#include <vector>
#include "AMenu.hpp"

class	MenuManager
{
public:
  MenuManager();
  ~MenuManager();

private:
  MenuManager(const MenuManager &);
  const MenuManager & operator=(const MenuManager &);

private:
  std::vector<AMenu>		_menus;
}



#endif		/* __MENU_MANAGEMENT_HPP__ */
