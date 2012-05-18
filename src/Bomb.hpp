/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bomb_h)
#define __Bomberman_Bomb_h

#include <Model.hpp>
#include "enum.hpp"
#include "AObj.hpp"

class Bomb : public AObj
{
public:
  struct Pattern
  {
    size_t	_x;
    size_t	_y;
    size_t	_coefN;
    size_t	_coefS;
    size_t	_coefW;
    size_t	_coefE;
  };
  
  struct ExplodedBomb
  {
    Pattern		_final;
    Pattern		_real;
    size_t		_player;
    double		_timer;
  };
  
public:
  Bomb(MappedBomb::eBomb t, Point const &, size_t id);
  ~Bomb();
  
private:
  MappedBomb::eBomb	_type;
  size_t	_player;
  double	_timer;
  bool		_exploded;
  gdl::Model	_model;
  Pattern	_pattern;
  
public:
  MappedBomb::eBomb	get_type(void) const;
  
  void		initialize(void);
  void		draw(void);
  bool		explode() const;
  Pattern	getPattern() const;
  ExplodedBomb	createExplodedBomb(Pattern const&);
  void		update(gdl::GameClock const& clock, gdl::Input& input);
};

#endif

/*
Update :
{

  - For each Bombe update -> explode
              = si true :
	          - get [Pattern]
		  - explode de map
		  - recup du new [Pattern] et stock la [BombExploded] dans la liste [recentExplosion]
                  - delete de la bomb
  - For each player
                - Update du joueur (move ...)
		- test des bonus + application
		- test des [Pattern] d'explosion (de [recentExplosion]) si degat appel de la blablabla

   - clean des explosion termine de [recentEsxplosion]

}

[BombExploded] {

  - [Pattern]
  - timer
  - id joueur

}

[Pattern] {

  - size_t x;
  - size_t y;
  - size_t coefNorth;
  - size_t coefSouth;
  - size_t coefWest;
  - size_t coefEast;

}

 */
