/*
 * Fiahil
 * 10.05.12
 */

#ifndef __Bomberman_Map_h
#define __Bomberman_Map_h

#include <map>
#include <Image.hpp>
#include "Pattern.hpp"
#include "AObj.hpp"

#define POS(px, py) (((this->_x * (py))) + (px))

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
  Point const*	_opti;

private:

  typedef void(Map::*explodeFunc)(size_t&, size_t&, size_t);

  void		explodeUnBreakable(size_t &, size_t &, size_t);
  void		explodeBreakable(size_t &, size_t &, size_t);

  std::map<char, explodeFunc> _expFunc;

public:
  void initialize(void);
  void draw(void);
  void update(gdl::GameClock const& clock, gdl::Input& input);
  bool canMoveAt(size_t x, size_t y);
  void setOptimization(Point const*);
  std::string const&	getMap(void) const;
  void explode(Pattern&, Pattern&);
};

#endif /* __Bomberman_Map_h */
