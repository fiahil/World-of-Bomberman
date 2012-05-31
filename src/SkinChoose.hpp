/*
 * NicoW
 * 29.05.12
 */

#ifndef		__SKIN_CHOICE_HPP__
#define		__SKIN_CHOICE_HPP__

#include "AMenu.hpp"

class SkinChoose : public AMenu
{
private:
  std::vector<gdl::Model>	_model;
  double	_timerL;
  double	_timerR;
  size_t	_indexSkin;
  size_t	_indexSkill;

private:
  void		updateText();
  void		changeSkin(gdl::GameClock const&, gdl::Input&);
  void		changeSkill(gdl::GameClock const&, gdl::Input&);

public:
  SkinChoose(GameManager&);
  virtual ~SkinChoose();

  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
};

#else

class SkinChoose;

#endif		/* __SKIN_CHOICE_HPP__ */
