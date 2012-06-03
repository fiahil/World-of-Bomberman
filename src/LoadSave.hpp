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
  std::vector<std::string>	_infos;
  std::vector<Profile*>&	_profiles;
  Profile*			_guest;
  std::vector<std::string>	_save;
  size_t			_index;
  double			_timerL;
  double			_timerR;

public:
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  virtual void		setTextDraw(bool);

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;

private:
  void			loadSave();
  void			loadAllSaves();
  void			changeSave(gdl::GameClock const&, gdl::Input&);
  void			updateText() const;
  void			initGameManager(void);
  void			setConfigs(APlayer *, APlayer *);
};

#endif		/* __LOAD_SAVE_HPP__ */
