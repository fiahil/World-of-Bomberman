/*
 * Nicow
 * 15.05.12
 */

#include <algorithm>
#include "AMenu.hpp"

AMenu::AMenu(std::string const& normal, std::string const select,
	     double x, double y, double z, GameManager& game)
  : _background(normal, select, false, false, TokenMenu::LAST, x, y, z),
    _textDraw(false),
    _cursor(0),
    _timer(-1.0f),
    _gameManager(game)
{
}

AMenu::~AMenu()
{
}


void			AMenu::initialize(void)
{
}

void			AMenu::draw(void)
{
  this->_background->draw();
}

void			AMenu::update(gdl::GameClock const&, gdl::Input&)
{
}
