/*
 * NicoW
 * 15.05.12
 */

#ifndef		__AMENU_HPP__
#define		__AMENU_HPP__

#include <vector>
#include "Tag.hpp"
#include "enum.hpp"
#include "AObj.hpp"

class		AMenu : public AObj
{
public:
  AMenu();
  virtual ~AMenu();

protected:
  std::vector<Tag *>	_tags;

public:
  void		addTag(Tag *);

  /*
    Boucle principale du Menu :
    - gestion des events avec la GDL
    - analyser le mvt
    - action (quitter, changer de Menu, etc)
  */
  virtual TokenMenu::eMenu	run(void);

  /*
    Refresh : display le Menu
    - iteration sur chaque Tag du vector
    - faire un Tag.draw()
  */
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#endif		/* __AMENU_HPP__ */
