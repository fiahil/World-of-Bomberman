/*
 * lemonn_v
 * 16.05.2012
 */

#ifndef __CONTENTCOLOR_HPP__
#define __CONTENTCOLOR_HPP__

#include <unistd.h>

class ContentColor
{
public:
  struct Color
  {
    unsigned char	R;
    unsigned char	G;
    unsigned char	B;
  };
  static Color const	getColorFromId(size_t id);
};

#else

class ContentColor;

#endif
