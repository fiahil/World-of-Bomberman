/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MENUPAUSE_HPP__
#define __MENUPAUSE_HPP__

#include "AMenu.hpp"

class MenuPause : public AMenu
{

  gdl::Text	_text;
  std::string	_msg;

private:
  void	clearMatch();
  void	restartGame();
  void	saveCurGame();

public:
  MenuPause(GameManager&);
  virtual ~MenuPause();

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void		draw();
};

#else

class MenuPause;

#endif
