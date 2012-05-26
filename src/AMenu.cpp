/*
 * Nicow
 * 15.05.12
 */

#include <algorithm>
#include "AMenu.hpp"

AMenu::AMenu()
{
}

static void		deleteTags(Tag * obj)
{
  delete obj;
  obj = 0;
}

AMenu::~AMenu()
{
  delete this->_background;
  for_each(this->_tags.begin(), this->_tags.end(), deleteTags);
}

void			AMenu::addTag(Tag * toAdd)
{
  if (toAdd != 0)
    this->_tags.push_back(toAdd);
}

void				AMenu::setTagAt(int _pos, bool _stat)
{
  _tags[_pos]->setStatus(_stat);
}

void				AMenu::setBackground(Tag * bg)
{
  this->_background = bg;
}


const std::vector<Tag *>&	AMenu::getTags(void) const
{
  return (this->_tags);
}

static void		drawTag(Tag * obj)
{
  if (obj != 0)
    obj->draw();
}

void			AMenu::draw(void)
{
  this->_background->draw();
  if (!this->_tags.empty())
    for_each(this->_tags.begin(), this->_tags.end(), drawTag);
}

void			AMenu::initialize(void)
{
}

void			AMenu::update(gdl::GameClock const&, gdl::Input&)
{
}
