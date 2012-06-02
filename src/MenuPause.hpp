/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MENUPAUSE_HPP__
#define __MENUPAUSE_HPP__

#include "AMenu.hpp"

class MenuPause : public AMenu
{
private:
  std::vector<Map*> const&	_maps;
  gdl::Text			_text;
  std::string			_msg;

private:
  void			clearOriginMap(void);
  void			clearMatch(void);
  void			restartGame(void);
  void			saveCurGame(void);

public:
  MenuPause(GameManager&, std::vector<Map*> const&);
  virtual ~MenuPause();

public:
  virtual double	getCenterX(void) const;
  virtual double	getCenterY(void) const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void		draw(void);
};

#else

class MenuPause;

#endif
