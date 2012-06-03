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
  std::vector<Map *> &	_map;
  double		_timerL;
  double		_timerR;
  size_t		_index;

public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;

private:
  void			changeMap(gdl::GameClock const&, gdl::Input&);
  void			updateText() const;
};

#endif		/* __LOAD_MAP_HPP__ */
