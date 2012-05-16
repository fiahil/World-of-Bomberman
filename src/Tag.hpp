/*
 * Texan
 * 15.05.2012
 */

#ifndef __TAG_HPP__
#define __TAG_HPP__

#include <Image.hpp>
#include <string>
#include <vector>
#include "Plane.hpp"
#include "enum.hpp"
#include "AObj.hpp"

class	Tag : public AObj
{
public:
  Tag(const std::string&, const std::string&, bool, TokenMenu::eMenu);
  ~Tag();

private:
  Tag();

private:
  Point			_spritePos;
  gdl::Image		_spriteHighlit;
  gdl::Image		_spriteNormal;
  Plane 		_highlit;
  Plane 		_normal;
  bool			_status;
  TokenMenu::eMenu	_content;

public:
  void		setStatus(bool);
  virtual void	draw(void);
  // virtual void	initialize(void);
  // virtual void	update(gdl::GameClock const&, gdl::Input&);
};

#endif
