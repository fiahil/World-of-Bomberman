/***********************************************************************
 * Module:  Bomb.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 5:27:47 PM
 * Purpose: Declaration of the class Bomb
 ***********************************************************************/

#if !defined(__Bomberman_Bomb_h)
#define __Bomberman_Bomb_h

#include <AObj.h>

class Bomb : public AObj
{
public:
   eBomb get_type(void);
   Bomb(eBomb t);
   ~Bomb();
   void initialize(void);
   void draw(void);
   void update(gdl::GameClock const& clock, gdl::Input& input);

protected:
private:
   eBomb _type;


};

#endif