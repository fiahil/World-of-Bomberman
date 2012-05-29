/*
 * NicoW
 * 27.05.2012
 */

#ifndef		__LOAD_SAVE_HPP__
#define		__LOAD_SAVE_HPP__

#include "AMenu.hpp"

class	LoadSave : public AMenu
{
public:
  LoadSave(GameManager&);
  virtual ~LoadSave(void);

private:
  bool		_buildTags;

public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;

  /*
    Others
  */
private:
  void			buildTags(void);
  void			loadSave();
};

#endif		/* __LOAD_SAVE_HPP__ */
