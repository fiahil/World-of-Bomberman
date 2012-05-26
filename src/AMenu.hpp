/*
 * NicoW
 * 15.05.12
 */

#ifndef		__AMENU_HPP__
#define		__AMENU_HPP__

#include <vector>
#include "enum.hpp"
#include "AObj.hpp"
#include "Tag.hpp"
#include "TextEdit.hpp"
#include "GameManager.hpp"

class		AMenu : public AObj
{
public:
  AMenu();
  virtual ~AMenu();

  typedef void (MenuManager::*keyPtrFunc)(gdl::GameClock const&);
  typedef std::vector< std::pair<gdl::Keys::Key, keyPtrFunc> > vKeyEvent;

protected:
  Tag				_background;
  bool				_textDraw;
  size_t			_cursor;
  double			_timer;
  std::vector<Tag *>		_tags;
  std::vector<TextEdit *>	_textEdit;
  vKeyEvent			_keyEvent;
  GameManager &			_gameManager;

  /*
	INFOS :

    -> Dans Menu Load profile :
    std::vector<Profile *> &	_profiles;
    ProfileLoader		_profileLoader;

    -> Dans le menu LoadMap :
    std::vector<Map *> &	_maps;

  */


  /*
    Keys
  */
private:
  void			UpFunction(gdl::GameClock const &);
  void			LeftFunction(gdl::GameClock const &);
  void			RightFunction(gdl::GameClock const &);
  void			DownFunction(gdl::GameClock const &);
  void			SelectFunction(gdl::GameClock const &);

  /*
    Heritance from AObj
  */
public:
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);

public:
  virtual double	getCenterX(void) const = 0;
  virtual double	getCenterY(void) const = 0;
};

#endif		/* __AMENU_HPP__ */
