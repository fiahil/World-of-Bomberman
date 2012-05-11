/***********************************************************************
 * Module:  AObj.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class AObj
 ***********************************************************************/

#if !defined(__Bomberman_AObj_h)
#define __Bomberman_AObj_h

#include <GameClock.hpp>
#include <Input.hpp>
#include "Point.hpp"

class AObj
{
public:
   virtual void initialize(void)=0;
   virtual void draw(void)=0;
   virtual void update(gdl::GameClock const& clock, gdl::Input& input)=0;
   AObj();
   ~AObj();

protected:
   Point _pos;

private:
   AObj(const AObj& oldAObj);


};

#endif
