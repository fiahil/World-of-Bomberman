/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bomb_h)
#define __Bomberman_Bomb_h

#include "AObj.h"

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

class Bomb : public AObj
{
public:
   Bomb(eBomb t, Point const &, size_t id);
   ~Bomb();

private:
   eBomb	_type;
   size_t	_player;
   double	_timer;
   bool		_eploded;
   gdl::Model	_model;
   Pattern	_pattern;
  
public:
   eBomb	get_type(void) const;

   void		initialize(void);
   void		draw(void);
   bool		explode() const;
   Pattern	getPattern() const;
   void		update(gdl::GameClock const& clock, gdl::Input& input);
};

#endif
