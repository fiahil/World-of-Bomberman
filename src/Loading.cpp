/*
 * lemonn_v
 * 15.05.12
 */

#include "Loading.hpp"

Loading::Loading(GameManager& game)
  : AMenu("menu/background/LoadingNormal.jpg", "menu/background/LoadingNormal1.jpg", 4800.0f, -2.0f, 1600.0f, game),
    _timer(-1.0f)
{
  this->_tags.push_back(new Tag("menu/background/LoadingNormal.jpg", "menu/background/LoadingNormal1.jpg", true, false, TokenMenu::LAST, 4800.0f, -1.0f, 1600.0f));
}

Loading::~Loading()
{

}

double	Loading::getCenterX() const
{
  return 5600.0f;
}

double	Loading::getCenterY() const
{
  return 2000.0f;
}

void	Loading::update(gdl::GameClock const& clock, gdl::Input&)
{
  if (clock.getTotalGameTime() >= this->_timer)
    {
      if (this->_tags[0]->getStatus())
	this->_tags[0]->setStatus(false);
      else
	this->_tags[0]->setStatus(true);
      this->_timer = clock.getTotalGameTime() + 0.5f;
    }
}
