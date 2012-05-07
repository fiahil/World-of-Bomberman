/***********************************************************************
 * Module:  Map.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:26 PM
 * Purpose: Declaration of the class Map
 ***********************************************************************/

#if !defined(__Bomberman_Map_h)
#define __Bomberman_Map_h

#include <AObj.h>

class Map : public AObj
{
public:
   Pattern break(Pattern origin, std::list<Bonus>& bonus);
   Map(std::string map, size_t x, size_t y);
   Map(std::string file);
   ~Map();
   void initialize(void);
   void draw(gdl::GameClock const& clock, gdl::Input& input);
   void update(void);

protected:
private:
   Map(const Map& oldMap);

   std::string _map;
   size_t _x;
   size_t _y;
   int Attribut_4;


};

#endif