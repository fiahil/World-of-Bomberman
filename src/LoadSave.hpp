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
  LoadSave(GameManager&, std::vector<Profile*>&, Profile*);
  virtual ~LoadSave(void);

private:
  std::vector<Profile*>&	_profiles;
  Profile*			_guest;
  std::vector<std::string>	_save;
  size_t			_index;
  double			_timerL;
  double			_timerR;

public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;

  /*
    Others
  */
private:
  void			loadSave();
  void			changeSave(gdl::GameClock const&, gdl::Input&);
  void			updateText() const;
};

#endif		/* __LOAD_SAVE_HPP__ */
