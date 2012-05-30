/*
 * Nicow
 * 15.05.12
 */

#include <iostream>
#include <algorithm>
#include "AMenu.hpp"

AMenu::AMenu(std::string const& normal, std::string const select,
	     double x, double y, double z, GameManager& game)
  : _background(normal, select, false, false, TokenMenu::LAST, x, y, z),
    _textDraw(false),
    _cursor(0),
    _timers(3, -1.0f),
    _gameManager(game),
    _curToken(TokenMenu::LAST),
    _changeMenu(false)
{
  this->_keyEvent.push_back(std::make_pair(gdl::Keys::Up, &AMenu::UpFunction));
  this->_keyEvent.push_back(std::make_pair(gdl::Keys::Down, &AMenu::DownFunction));
  this->_keyEvent.push_back(std::make_pair(gdl::Keys::Return, &AMenu::SelectFunction));
}

AMenu::~AMenu()
{
}


void			AMenu::initialize(void)
{
  for (std::vector<Tag *>::iterator it = this->_tags.begin(); it != this->_tags.end(); ++it)
    (*it)->initialize();
  if (!this->_tags.empty())
    this->_tags[this->_cursor]->setStatus(true);
}

void			AMenu::draw(void)
{
  this->_background.draw();
  for (std::vector<Tag *>::iterator it = this->_tags.begin(); it != this->_tags.end(); ++it)
    (*it)->draw();
  if (this->_textDraw)
   for (std::vector<TextEdit *>::iterator it = this->_textEdit.begin(); it != this->_textEdit.end(); ++it)
      (*it)->draw();
}

void			AMenu::update(gdl::GameClock const&, gdl::Input&)
{
}

void			AMenu::setChangeMenu(bool flag)
{
  this->_changeMenu = flag;
}

void			AMenu::setTextDraw(bool flag)
{
  this->_textDraw = flag;
  this->_changeMenu = true;
  this->_curToken = TokenMenu::LAST;
  for (std::vector<Tag *>::iterator it = this->_tags.begin(); it != this->_tags.end(); ++it)
    (*it)->setTextDraw(flag);
}

TokenMenu::eMenu	AMenu::getContent() const
{
  return this->_curToken;
}

void			AMenu::UpFunction(gdl::GameClock const& clock)
{
  if (clock.getTotalGameTime() >= this->_timers[0])
    {
      this->_tags[this->_cursor]->setStatus(false);
      if (!this->_cursor)
	this->_cursor = this->_tags.size();
      --this->_cursor;
      this->_tags[this->_cursor]->setStatus(true);
      this->_timers[0] = clock.getTotalGameTime() + 0.15f;
    }
}

void			AMenu::DownFunction(gdl::GameClock const& clock)
{
  if (clock.getTotalGameTime() >= this->_timers[1])
    {
      this->_tags[this->_cursor]->setStatus(false);
      ++this->_cursor;
      if (this->_cursor == this->_tags.size())
	this->_cursor = 0;
      this->_tags[this->_cursor]->setStatus(true);
      this->_timers[1] = clock.getTotalGameTime() + 0.15f;
    }
}

void			AMenu::SelectFunction(gdl::GameClock const& clock)
{
  if (clock.getTotalGameTime() >= this->_timers[2])
    {
      if (!this->_changeMenu)
	this->_curToken = this->_tags[this->_cursor]->getContent();
      else
	this->_changeMenu = false;
      this->_timers[2] = clock.getTotalGameTime() + 0.15f;
    }
}
