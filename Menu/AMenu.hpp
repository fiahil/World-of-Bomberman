/*
 * NicoW
 * 15.05.12
 */

#ifndef		__AMENU_HPP__
#define		__AMENU_HPP__

#include <vector>
#include "Tag.hpp"

class		AMenu
{
public:
  AMenu();
  virtual ~AMenu();

// private:
//   AMenu(const AMenu&);
//   const AMenu& operator=(const AMenu&);

protected:
  std::vector<Tag>	_tags;

public:
  /*
    Boucle principale du Menu :
    - gestion des events avec la GDL
    - analyser le mvt
    - action (quitter, changer de Menu, etc)
  */
  virtual void		run(void); // RETURN Menu::eMenu apres

  /*
    Refresh : display le Menu
    - iteration sur chaque Tag du vector
    - faire un Tag.draw()
  */
  virtual void		refresh(void);
};

#endif		/* __AMENU_HPP__ */
