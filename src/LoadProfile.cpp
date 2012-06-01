/*
 * Texan
 * 27.05.12
 */

#include <iostream>
#include <sstream>
#include "LoadProfile.hpp"

LoadProfile::LoadProfile(GameManager& game, std::vector<Profile *>& profiles, std::vector<std::string>& names)
  : AMenu("menu/background/backgroundLoadProfile.jpg", "menu/background/backgroundLoadProfile.jpg", 0.0f, -1.0f, 800.0f, game),
    _profiles(profiles),
    _names(names),
    _index(0),
    _timerL(-1.0f),
    _timerR(-1.0f)
{
  this->_tags.push_back(new Tag("menu/tags/LoadNormal.png", "menu/tags/LoadHighlit.png", true, false, TokenMenu::LAST, 429.0f, 0.0f, 1100.0f));
  this->_tags.push_back(new Tag("menu/tags/EmptyNormal.png", "menu/tags/EmptyHighlit.png", false, false, TokenMenu::LAST, 429.0f, 0.0f, 1165.0f));
  this->_tags.push_back(new Tag("menu/tags/DoneNormal.png", "menu/tags/DoneHighlit.png", false, false, TokenMenu::PROFILE, 429.0f, 0.0f, 1230.0f));
  this->_tags.push_back(new Tag("menu/tags/BackNormal.png", "menu/tags/BackHighlit.png", false, false, TokenMenu::MAINMENU, 429.0f, 0.0f, 1295.0f));

}

LoadProfile::~LoadProfile(void)
{
}

double	LoadProfile::getCenterX() const
{
  return (800.0f);
}

double	LoadProfile::getCenterY() const
{
  return (1200.0f);
}

void		LoadProfile::updateText() const
{
  std::stringstream	ss;
  
  if (this->_profiles.size())
    {
      this->_tags[0]->createText(this->_names[this->_index], 20, 850, 315);
      ss << " Skin : " << this->_profiles[this->_index]->getSkin();
      this->_tags[1]->createText(ss.str(), 20, 500, 380);
    }
  else
    {
      this->_tags[0]->createText("", 20, 950, 270);
      this->_tags[1]->createText("", 20, 950, 310);
    }
}

void		LoadProfile::changeProfile(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timerL && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_index;
      if (static_cast<int>(this->_index) < 0)
	this->_index = this->_profiles.size() - 1;
      this->_timerL = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timerR && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_index;
      if (this->_index >= this->_profiles.size())
	this->_index = 0;
      this->_timerR = clock.getTotalGameTime() + 0.15f;
    }
}

void	LoadProfile::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 0)
    this->changeProfile(clock, input);
  else if (this->_cursor == 1)
    {
      this->_tags[this->_cursor]->setStatus(false);
      if (this->_timers[0] > this->_timers[1])
	--this->_cursor;
      else
	++this->_cursor;
      this->_tags[this->_cursor]->setStatus(true);
    }

  if (this->_curToken == TokenMenu::PROFILE)
    {
      if (this->_profiles.size())
	this->_gameManager._mainProfile = this->_profiles[this->_index];
      else
	this->_curToken = TokenMenu::LAST;
    }
}
