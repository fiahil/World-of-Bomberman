/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bomb_h)
#define __Bomberman_Bomb_h

#include "AObj.h"

class Bomb : public AObj
{
public:
   Bomb(eBomb t);
   ~Bomb();

private:
   eBomb	_type;

public:
   eBomb	get_type(void) const;

   void		initialize(void);
   void		draw(void);
   void		update(gdl::GameClock const& clock, gdl::Input& input);
};

#endif
