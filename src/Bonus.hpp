/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bonus_h)
#define __Bomberman_Bonus_h

#include <Model.hpp>
#include "enum.hpp"
#include "AObj.hpp"

class Bonus : public AObj
{
public:
  Bonus(BonusType::eBonus t, Point const&, gdl::Model&);
  virtual ~Bonus();

private:
  BonusType::eBonus	_type;
  gdl::Model&		_model;

public:
  BonusType::eBonus	getType(void) const;

  void		initialize(void);
  void		draw();
  void		update(gdl::GameClock const&, gdl::Input&);
};

#endif
