/*
 * Texan
 * 15.05.2012
 */

#ifndef __TAG_HPP__
#define __TAG_HPP__

#include <string>
#include <vector>
#include "Menu.hpp"

enum	eSprite
  {
    SELECTED,
    DESELECTED
  };

class	Tag
{
public:
  Tag(const std::string&, const std::string&);
  ~Tag();

private:
  Tag();
  Tag(const Tag&);
  Tag&	operator=(const Tag&);

private:
  gdl::Rectangle	_square;
  std::vector<float>	_squareCoord;
  std::string		_spriteHighlit;
  std::string		_spriteNormal;
  gdl::Image		_highlit;
  gdl::Image		_normal;
  bool			_status;
  eMenu			_content;

public:
  const gdl::Image	load(const std::string&);
  const gdl::Image	getImage(const eSprite);
  void			draw(void) const;

  void			setStatus(const bool);
  const bool		getStatus(void) const;
};

#endif
