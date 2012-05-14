/*
 * Fiahil
 * 10.05.12
 */

#ifndef __Bomberman_Map_h
#define __Bomberman_Map_h

#include <Image.hpp>
#include "AObj.hpp"

#define POS(px, py) ((((this->_y * (py)) - 1)) + (px) + 1)

class Pattern; //TODO: TO REMOVE
class Bonus; //TODO: TO REMOVE

class Map : public AObj
{
public:
  Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity);
  Map(std::string const& file);
  Map(size_t x, size_t y, std::string const& map);
  ~Map();

private:
  Map(const Map& oldMap);

private:
  size_t	_x;
  size_t	_y;
  std::string	_map;
  gdl::Image	_unbreak;
  gdl::Image	_break;
  gdl::Image	_background;

public:
  void initialize(void);
  void draw(void);
  void update(gdl::GameClock const& clock, gdl::Input& input);
  //  Pattern explode(Pattern origin, std::list<Bonus>& bonus);
};

#endif /* __Bomberman_Map_h */
