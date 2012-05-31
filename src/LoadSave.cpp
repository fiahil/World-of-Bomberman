/*
 * NicoW
 * 27.05.12
 */

#include <sstream>
#include "SaveManager.hpp"
#include "LoadSave.hpp"

LoadSave::LoadSave(GameManager& game)
  : AMenu("menu/background/backgroundLoadSave.jpg", "menu/background/backgroundLoadSave.jpg", 3200.0f, -1.0f, 800.0f, game),
    _index(0),
    _timerL(-1.0f),
    _timerR(-1.0f)
{
  this->_tags.push_back(new Tag("menu/LoadNormal.png", "menu/LoadHighlit.png", true, false, TokenMenu::LAST, 3900.0f, 0.0f, 1200.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 4100.0f, 0.0f, 1200.0f));
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::CREATEGAME, 3900.0f, 0.0f, 1250.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::PROFILE, 3900.0f, 0.0f, 1300.0f));
}

LoadSave::~LoadSave(void)
{
}

double		LoadSave::getCenterX(void) const
{
  return (4000.0f);
}

double		LoadSave::getCenterY(void) const
{
  return (1200.0f);
}

void		LoadSave::loadSave()
{
  size_t		id;
  std::stringstream	ss;

  ss << this->_save[this->_cursor];
  ss >> id;
  SaveManager::getSave(id);
}

void		LoadSave::updateText() const
{
  if (this->_save.size())
    this->_tags[1]->createText(this->_save[this->_index], 20, 950, 270);
  else
    this->_tags[1]->createText("", 20, 950, 270);
}

void		LoadSave::changeSave(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_index;
      if (static_cast<int>(this->_index) < 0)
	this->_index = this->_save.size() - 1;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_index;
      if (this->_index >= this->_save.size())
	this->_index = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void		LoadSave::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (!this->_save.size())
    this->_save = this->_gameManager._mainProfile->getSave();
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 0)
    this->changeSave(clock, input);
  else if (this->_cursor == 1)
    {
      this->_tags[this->_cursor]->setStatus(false);
      if (this->_timers[0] > this->_timers[1])
	--this->_cursor;
      else
	++this->_cursor;
      this->_tags[this->_cursor]->setStatus(true);
    }
  if (this->_curToken == TokenMenu::CREATEGAME)
    this->loadSave();
}
