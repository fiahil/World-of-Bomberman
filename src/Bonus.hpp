/***********************************************************************
 * Module:  Bonus.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 5:35:00 PM
 * Purpose: Declaration of the class Bonus
 ***********************************************************************/

#if !defined(__Bomberman_Bonus_h)
#define __Bomberman_Bonus_h

#include <AObj.h>

class Bonus : public AObj
{
public:
   eBonus get_type(void);
   Bonus(eBomb t);
   ~Bonus();
   void initialize(void);
   void draw(gdl::GameClock const& clock, gdl::Input& input);
   void update(void);

protected:
private:
   eBonus _type;


};

#endif