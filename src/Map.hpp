/*
 * Fiahil
 * 10.05.12
 */

#ifndef __Bomberman_Map_h
#define __Bomberman_Map_h

#include <map>
#include <Image.hpp>
#include "Bonus.hpp"
#include "Cube.hpp"
#include "Plane.hpp"
#include "Pattern.hpp"
#include "APlayer.hpp"
#include "AObj.hpp"

#define POS(px, py) (((this->_x * (py))) + (px))

struct	Tp {

  Point _pos1;
  Point _pos2;
  Tp();
};

class Map : public AObj
{
  typedef void(Map::*explodeFunc)(size_t&, size_t&, size_t, std::list<Bonus*>&);

public:
  Map(size_t x, size_t y, size_t dwallDensity, size_t iwallDensity);
  Map(std::string const& file, std::string const & name);
  Map(size_t x, size_t y, std::string const& map);
  virtual ~Map();


private:
  Map(const Map& oldMap);


private:
  size_t	_x;
  size_t	_y;
  std::string	_map;
  std::string	_name;
  gdl::Image	_unbreak;
  gdl::Image	_break;
  gdl::Image	_background;
  gdl::Image	_landscape;
  Point const*	_opti;
  Tp		_tp;
  Cube		*w_unbreak;
  Plane		*background;
  Plane		*landscape;

  std::vector<gdl::Model>	_modelBonus;
  std::map<char, gdl::Model>	_modelBreak;
  std::map<char, explodeFunc>	_expFunc;

private:
  void		explodeUnBreakable(size_t &, size_t &, size_t, std::list<Bonus*>&);
  void		explodeBreakable(size_t &, size_t &, size_t, std::list<Bonus*>&);

public:
  bool		teleport(Point & pos) const;
  void		initialize(void);
  void		draw(void);
  void		update(gdl::GameClock const& clock, gdl::Input& input);
  bool		canMoveAt(size_t x, size_t y) const;
  bool		safeCanMoveAt(size_t x, size_t y) const;
  void		explode(Pattern&, Pattern&, std::list<Bonus*>&);
  void		setOptimization(Point const*);
  void		setSpawnTeam(std::vector<APlayer*>&);

  std::string const&	getMap(void) const;
  size_t		getX(void) const;
  size_t		getY(void) const;
  const std::string &	getName(void) const;
};

#else

class Map;

#endif /* __Bomberman_Map_h */
