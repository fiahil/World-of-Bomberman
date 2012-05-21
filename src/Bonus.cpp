/*
 * Fiahil
 * 12.05.2012
 */

#include "Bonus.hpp"

Bonus::Bonus(eBomb t)
  : _type(t)
{
}

Bonus::~Bonus()
{
}

eBonus		Bonus::get_type(void) const
{
  return this->_type;
}

void		Bonus::initialize(void)
{
}

void		Bonus::draw(gdl::GameClock const& clock, gdl::Input& input)
{
}

void		Bonus::update(void)
{
}
