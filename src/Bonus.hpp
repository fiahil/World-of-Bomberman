/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bonus_h)
#define __Bomberman_Bonus_h

#include "AObj.h"

class Bonus : public AObj
{
public:
   Bonus(eBomb t);
   ~Bonus();

private:
   eBonus _type;

public:
   eBonus	get_type(void) const;

   void		initialize(void);
   void		draw(gdl::GameClock const& clock, gdl::Input& input);
   void		update(void);
};

#endif
