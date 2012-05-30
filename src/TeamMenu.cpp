/*
 * Texan
 * 27.05.2012
 */

#include <iostream>
#include <sstream>
#include "TeamMenu.hpp"

TeamMenu::TeamMenu(GameManager& game, std::vector<Profile*>& pro)
  : AMenu("menu/Background5.png", "menu/Background5.png", 0.0f, -1.0f, 2700.0f, game),
    _profiles(pro),
    _nb(3, 1),
    _timersLR(2, -1.0f)
{
  this->_nb[2] = -1;
  this->_tags.push_back(new Tag("menu/NbPlayerNormal.png", "menu/NbPlayerHighlit.png", true, false, TokenMenu::TEAM, 800.0f, 0.0f, 2900.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 1000.0f, 0.0f, 2900.0f));

  this->_tags.push_back(new Tag("menu/NbTeamNormal.png", "menu/NbTeamHighlit.png", false, false, TokenMenu::TEAM, 800.0f, 0.0f, 2950.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 1000.0f, 0.0f, 2950.0f));

  this->_tags.push_back(new Tag("menu/Player2Normal.png", "menu/Player2Highlit.png", false, false, TokenMenu::TEAM, 800.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 1000.0f, 0.0f, 3000.0f));

  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::MAP, 800.0f, 0.0f, 3050.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 3100.0f));
}

TeamMenu::~TeamMenu()
{
}

double	TeamMenu::getCenterX(void) const
{
  return (800.0f);
}

double	TeamMenu::getCenterY(void) const
{
  return (3150.0f);
}

void	TeamMenu::updateText() const
{
  std::stringstream	ss;

  ss << this->_nb[0];
  this->_tags[1]->createText(ss.str(), 20, 1100, 170);
  ss.str("");
  ss.clear();
  ss << this->_nb[1];
  this->_tags[3]->createText(ss.str(), 20, 1100, 220);
  ss.str("");
  ss.clear();
  ss << this->_nb[2];
  if (this->_gameManager._match._gameMode != GameMode::SOLO)
    this->_tags[5]->createText(this->_profiles[this->_nb[2]]->getName(), 20, 1100, 270);
  else
    this->_tags[5]->createText("", 20, 1100, 270);
}

void	TeamMenu::changeNumber(gdl::GameClock const& clock, gdl::Input& input)
{
  if (clock.getTotalGameTime() >= this->_timersLR[0] && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_nb[this->_cursor / 2];
      if ((this->_gameManager._match._gameMode == GameMode::SOLO ||
	   this->_gameManager._match._gameMode == GameMode::COOP) &&
	  this->_nb[this->_cursor / 2] < 1)
	this->_nb[this->_cursor / 2] = 1;
      else if (this->_gameManager._match._gameMode == GameMode::VERSUS && this->_nb[this->_cursor / 2] < 0)
	this->_nb[this->_cursor / 2] = 0;
      this->_timersLR[0] = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timersLR[1] && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_nb[this->_cursor / 2];
      if (this->_nb[this->_cursor / 2] > 30)
	this->_nb[this->_cursor / 2] = 30;
      this->_timersLR[1] = clock.getTotalGameTime() + 0.15f;
    }
}

void	TeamMenu::changeProfile(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_profiles.size() <= 2)
    return ;
  if (clock.getTotalGameTime() >= this->_timersLR[0] && input.isKeyDown(gdl::Keys::Left))
    {
      --this->_nb[2];
      if (this->_nb[2] >= 0 && this->_profiles[this->_nb[2]] == this->_gameManager._mainProfile)
	--this->_nb[2];
      if (this->_nb[2] < 0)
	this->_nb[2] = this->_profiles.size() - 1;
      this->_timersLR[0] = clock.getTotalGameTime() + 0.15f;
    }
  else if (clock.getTotalGameTime() >= this->_timersLR[1] && input.isKeyDown(gdl::Keys::Right))
    {
      ++this->_nb[2];
      if (static_cast<unsigned int>(this->_nb[2]) < this->_profiles.size() && this->_gameManager._mainProfile == this->_profiles[this->_nb[2]])
	++this->_nb[2];
      if (static_cast<unsigned int>(this->_nb[2]) >= this->_profiles.size())
	this->_nb[2] = 0;
      this->_timersLR[1] = clock.getTotalGameTime() + 0.15f;
    }
}

void	TeamMenu::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_nb[2] < 0)
    {
      this->_nb[2] = 0;
      for (std::vector<Profile*>::iterator it =  this->_profiles.begin();
	   it != this->_profiles.end() && (*it) == this->_gameManager._mainProfile; ++it)
	++this->_nb[2];
    }
  this->updateText();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 1 || this->_cursor == 3 || this->_cursor == 5)
    {
      this->_tags[this->_cursor]->setStatus(false);
      if (this->_timers[0] < this->_timers[1])
	++this->_cursor;
      else
	--this->_cursor;
      this->_tags[this->_cursor]->setStatus(true);
    }
  else if (this->_cursor == 0 || this->_cursor == 2)
    this->changeNumber(clock, input); //TODO
  else if (this->_cursor == 4)
    this->changeProfile(clock, input);

  if (this->_curToken == TokenMenu::MAP)
    {
      this->_gameManager._nbPlayers = this->_nb[0];
      this->_gameManager._nbTeams = this->_nb[1];
      if (this->_gameManager._match._gameMode != GameMode::SOLO)
	this->_gameManager._secondProfile = this->_profiles[this->_nb[2]];
    }
}

