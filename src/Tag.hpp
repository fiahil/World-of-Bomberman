/*
 * Texan
 * 15.05.2012
 */

#ifndef __TAG_HPP__
#define __TAG_HPP__

#include <Image.hpp>
#include <string>
#include <vector>
#include "Rectangle.hpp"
#include "enum.hpp"

class	Tag
{
public:
  Tag(const std::string&, const std::string&, bool, TokenMenu::eMenu);
  ~Tag();

private:
  Tag();

private:
  Rectangle *		_square;
  std::vector<float>	_squareCoord; // Voir si ici ou dans Rectangle
  std::string		_spriteHighlit;
  std::string		_spriteNormal;
  gdl::Image *		_highlit;
  gdl::Image *		_normal;
  bool			_status;
  TokenMenu::eMenu	_content;

public:
  const gdl::Image 	load(const std::string&);
  const gdl::Image *	getImage(const Sprite::eSprite&);
  void			draw(void);

  void			setStatus(bool);
  bool		getStatus(void) const;
};

#endif
