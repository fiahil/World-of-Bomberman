/*
 * Texan
 * 15.05.2012
 */

#ifndef __TAG_HPP__
#define __TAG_HPP__

#include <string>
#include <vector>
#include "Rectangle.hpp"
// #include "Image.hpp"

struct Sprite
{
  enum	eSprite			// mettre dans enum.hpp si valide
    {
      SELECTED,
      DESELECTED
    };
};

class	Tag
{
public:
  Tag(const std::string&, const std::string&);
  Tag();			// REMOVE
  ~Tag();

private:
  //   Tag();
  // Tag(const Tag&);
  // const Tag&	operator=(const Tag&);

private:
  // Rectangle		_square;
  std::vector<float>	_squareCoord;
  std::string		_spriteHighlit;
  std::string		_spriteNormal;
  // gdl::Image		_highlit;
  // gdl::Image		_normal;
  bool			_status;
  // Menu::eMenu		_content;	// ADD
  int			_content;		// REMOVE

public:
  // const gdl::Image	load(const std::string&);
  // const gdl::Image	getImage(const eSprite);
  void			draw(void) const;

  void			setStatus(bool);
  bool			getStatus(void) const;
};

#endif
