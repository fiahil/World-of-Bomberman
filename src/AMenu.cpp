/*
 * Nicow
 * 15.05.12
 */

#include <cassert>
#include <algorithm>
#include "Common.hpp"
#include "Sound.hpp"
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
  std::for_each(this->_tags.begin(), this->_tags.end(), deleteItem<Tag *>);
  std::for_each(this->_textEdit.begin(), this->_textEdit.end(), deleteItem<TextEdit *>);
}

void			AMenu::feInitialize(Tag *obj)
{
  assert(obj != 0);
  obj->initialize();
}

void			AMenu::initialize(void)
{
  std::for_each(this->_tags.begin(), this->_tags.end(), feInitialize);
  if (!this->_tags.empty())
    this->_tags[this->_cursor]->setStatus(true);
}

template <class T>
void			AMenu::feDraw(T obj)
{
  assert(obj != 0);
  obj->draw();
}

void			AMenu::draw(void)
{
  this->_background.draw();
  std::for_each(this->_tags.begin(), this->_tags.end(), feDraw<Tag *>);
  if (this->_textDraw)
    std::for_each(this->_textEdit.begin(), this->_textEdit.end(), feDraw<TextEdit *>);
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
  if (clock.getTotalGameTime() >= this->_timers.at(0))
    {
      this->_tags.at(this->_cursor)->setStatus(false);
      if (!this->_cursor)
	this->_cursor = this->_tags.size();
      --this->_cursor;
      this->_tags.at(this->_cursor)->setStatus(true);
      this->_timers.at(0) = clock.getTotalGameTime() + 0.15f;
    }
}

void			AMenu::DownFunction(gdl::GameClock const& clock)
{
  if (clock.getTotalGameTime() >= this->_timers.at(1))
    {
      this->_tags.at(this->_cursor)->setStatus(false);
      ++this->_cursor;
      if (this->_cursor == this->_tags.size())
	this->_cursor = 0;
      this->_tags.at(this->_cursor)->setStatus(true);
      this->_timers.at(1) = clock.getTotalGameTime() + 0.15f;
    }
}

void			AMenu::SelectFunction(gdl::GameClock const& clock)
{
  if (clock.getTotalGameTime() >= this->_timers.at(2))
    {
      Sound::getMe()->playBack(Audio::MENU);
      if (!this->_changeMenu)
	this->_curToken = this->_tags.at(this->_cursor)->getContent();
      else
	this->_changeMenu = false;
      this->_timers.at(2) = clock.getTotalGameTime() + 0.15f;
    }
}
