/*
 * NicoW
 * 15.05.12
 */

#ifndef		__AMENU_HPP__
#define		__AMENU_HPP__

#include <vector>
#include "Tag.hpp"
// #include "enum.hpp"

struct Menu			// Move dans enum.hpp dans src quand pret
{
  enum eMenu
    {
      MAIN,
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

class		AMenu
{
public:
  AMenu();
  virtual ~AMenu();

private:
  AMenu(const AMenu &);
  const AMenu & operator=(const AMenu &);

protected:
  eMenu			_curMenu;
  std::vector<Tag>	_tags;

public:
  /*
    Boucle principale du Menu :
    - gestion des events avec la GDL
    - analyser le mvt
    - action (quitter, changer de Menu, etc)
  */
  void		run(void);

  /*
    Refresh : display le Menu
    - iteration sur chaque Tag du vector
    - faire un Tag.draw()
  */
  void		refresh(void);
};

#endif		/* __AMENU_HPP__ */
