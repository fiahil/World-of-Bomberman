/*
 * Fiahil
 * 12.05.2012
 */

#include "Bomb.hpp"

Bomb::Bomb(eBomb t) : _type(t)
{
}

Bomb::~Bomb()
{
}

eBomb		Bomb::get_type(void) const
{
   return _type;
}

void		Bomb::initialize(void)
{
}

void		Bomb::draw(void)
{
}

void		Bomb::update(gdl::GameClock const& clock, gdl::Input& input)
{
}
