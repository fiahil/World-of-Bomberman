/*
 * lemonn_v
 * 16.05.2012
 */

#include "ContentColor.hpp"

static const unsigned char g_refColor[9][3] = {
  {255, 0, 0},
  {0, 255, 0},
  {0, 0, 255},
  {0, 255, 255},
  {255, 255, 0},
  {127, 0, 0},
  {127, 0, 127},
  {0, 0, 0},
  {127, 127, 127},
};

ContentColor::Color const	ContentColor::getColorFromId(size_t id)
{
  ContentColor::Color	ret;

  ret.R = g_refColor[id % 9][0];
  ret.G = g_refColor[id % 9][1];
  ret.B = g_refColor[id % 9][2];
  return ret;
}
