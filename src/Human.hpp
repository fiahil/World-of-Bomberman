/***********************************************************************
 * Module:  Human.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:13:39 PM
 * Purpose: Declaration of the class Human
 ***********************************************************************/

#if !defined(__Bomberman_Human_h)
#define __Bomberman_Human_h

#include <APlayer.h>

class Human : public APlayer
{
public:
  Human(std::string const&);
  virtual ~Human();
  virtual void play(void);
  
protected:
private:

};

#endif
