/***********************************************************************
 * Module:  Map.h
 * Author:  Fiahil
 * Modified: Thursday, May 10, 2012 10:28:54 AM
 * Purpose: Declaration of the class Map
 ***********************************************************************/

#if !defined(__Bomberman_Map_h)
#define __Bomberman_Map_h

#include <Image.hpp>
#include "AObj.hpp"

#define POS(px, py) ((((this->_y * (py)) - 1)) + (px) + 1)

class Pattern; // TO REMOVE
class Bonus; // TO REMOVE

class Map : public AObj
{
public:
  //  Pattern explode(Pattern origin, std::list<Bonus>& bonus);
  Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity);
  Map(std::string const& file);
  Map(size_t x, size_t y, std::string const& map);
  ~Map();
  void initialize(void);
  void draw(void);
  void update(gdl::GameClock const& clock, gdl::Input& input);

protected:
private:
  Map(const Map& oldMap);

  size_t _x;
  size_t _y;
  std::string _map;
  gdl::Image	_unbreak;
  gdl::Image	_break;
  gdl::Image	_background;

};

#endif
