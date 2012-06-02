/*
 * NicoW
 * 15.05.12
 */

#ifndef		__AMENU_HPP__
#define		__AMENU_HPP__

#include <vector>
#include <utility>
#include "enum.hpp"
#include "AObj.hpp"
#include "Tag.hpp"
#include "TextEdit.hpp"
#include "GameManager.hpp"

class		AMenu : public AObj
{
public:
  AMenu(std::string const&, std::string const, double, double, double, GameManager&);
  virtual ~AMenu();

  typedef void (AMenu::*keyPtrFunc)(gdl::GameClock const&);
  typedef std::vector< std::pair<gdl::Keys::Key, keyPtrFunc> > vKeyEvent;

protected:
  Tag				_background;
  bool				_textDraw;
  size_t			_cursor;
  std::vector<double>		_timers;
  std::vector<Tag *>		_tags;
  std::vector<TextEdit *>	_textEdit;
  vKeyEvent			_keyEvent;
  GameManager &			_gameManager;
  TokenMenu::eMenu		_curToken;
  bool				_changeMenu;

protected:
  void			UpFunction(gdl::GameClock const &);
  void			DownFunction(gdl::GameClock const &);
  void			SelectFunction(gdl::GameClock const &);

public:
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);

public:
  void			setChangeMenu(bool);
  virtual void		setTextDraw(bool);
  TokenMenu::eMenu	getContent() const;

public:
  virtual double	getCenterX(void) const = 0;
  virtual double	getCenterY(void) const = 0;

private:
  template <class T>
  static void		feDraw(T);
  static void		feInitialize(Tag *);
};

#endif		/* __AMENU_HPP__ */
