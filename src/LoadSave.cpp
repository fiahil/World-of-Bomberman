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
  this->_tags.push_back(new Tag("menu/tags/LoadNormal.png", "menu/tags/LoadHighlit.png", true, false, TokenMenu::LAST, 3629.0f, 0.0f, 1150.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::CREATEGAME, 3629.0f, 0.0f, 1265.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::PROFILE, 3629.0f, 0.0f, 1330.0f));
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

#include <iostream>

void		LoadSave::loadSave()
{
  size_t		id;
  std::stringstream	ss;

  ss << this->_save[this->_cursor - 1];
  ss >> id;
  if (SaveManager::getSave(id, this->_gameManager._match))
    this->_curToken = TokenMenu::LAST;
}

void		LoadSave::updateText() const
{
  if (this->_save.size())
    {
      this->_tags[0]->createText(this->_save[this->_index], 20, 850, 360);
      this->_tags[0]->createText("info", 20, 500, 411);
    }
  else
    {
      this->_tags[0]->createText("", 20, 850, 360);
      this->_tags[1]->createText("", 20, 500, 411);
    }
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
  if (this->_curToken == TokenMenu::CREATEGAME)
    {
      if (this->_save.size())
	this->loadSave();
      else
	this->_curToken = TokenMenu::LAST;
    }
}
