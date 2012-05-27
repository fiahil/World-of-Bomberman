/*
 * Texan
 * 15.05.2012
 */

#ifndef __TAG_HPP__
#define __TAG_HPP__

#include <Image.hpp>
#include <Text.hpp>
#include <string>
#include <vector>
#include "Plane.hpp"
#include "enum.hpp"
#include "AObj.hpp"

class	Tag : public AObj
{
public:
  Tag(const std::string&,
      const std::string&,
      bool, bool, TokenMenu::eMenu,
      double, double, double);
  virtual ~Tag();

private:
  Tag();

private:
  Point			_spritePos;
  gdl::Image		_spriteHighlit;
  gdl::Image		_spriteNormal;
  Plane 		_highlit;
  Plane 		_normal;
  bool			_status;
  bool			_textDraw;
  gdl::Text		_text;
  TokenMenu::eMenu	_content;

private:
  void			pushMatrix(void) const;
  void			popMatrix(void) const;

  /*
    Heritance from AObj
  */
public:
  virtual void		draw(void);
  virtual void		initialize(void);
  virtual void		update(gdl::GameClock const&, gdl::Input&);

  /*
    Others
  */
public:
  TokenMenu::eMenu	getContent(void) const;
  void			setStatus(bool);
  void			setTextDraw(bool);
  void			createText(const std::string &, int, int, int);
  void			drawText(void);
};

#endif
