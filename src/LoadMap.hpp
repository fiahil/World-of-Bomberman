/*
 * NicoW
 * 28.05.12
 */

#ifndef		__LOAD_MAP_HPP__
#define		__LOAD_MAP_HPP__

#include "AMenu.hpp"

class	LoadMap : public AMenu
{
public:
  LoadMap(GameManager&, std::vector<Map *> &);
  virtual ~LoadMap(void);

private:
  std::vector<Map *> & _map;

  /*
    Heritance from AObj
  */
public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);

  /*
    Pure virtual functions
  */
public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
};

#endif		/* __LOAD_MAP_HPP__ */
