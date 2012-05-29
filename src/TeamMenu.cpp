/*
 * Texan
 * 27.05.2012
 */

#include <sstream>
#include "TeamMenu.hpp"

TeamMenu::TeamMenu(GameManager& game)
  : AMenu("menu/Background5.png", "menu/Background5.png", 0.0f, -1.0f, 2700.0f, game),
    _nb(2, 1),
    _timersLR(2, -1.0f)
{
  this->_tags.push_back(new Tag("menu/NbPlayerNormal.png", "menu/NbPlayerHighlit.png", true, false, TokenMenu::TEAM, 800.0f, 0.0f, 2900.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 1000.0f, 0.0f, 2900.0f));  
  
  this->_tags.push_back(new Tag("menu/NbTeamNormal.png", "menu/NbTeamHighlit.png", false, false, TokenMenu::TEAM, 800.0f, 0.0f, 2950.0f));
  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", false, false, TokenMenu::LAST, 1000.0f, 0.0f, 2950.0f));
  
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", false, false, TokenMenu::MAP, 800.0f, 0.0f, 3000.0f));
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", false, false, TokenMenu::IA, 800.0f, 0.0f, 3050.0f));
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

void	TeamMenu::updateNumber() const
{
  std::stringstream	ss;

  ss << this->_nb[0];
  this->_tags[1]->createText(ss.str(), 20, 1100, 170);
  ss.str("");
  ss.clear();
  ss << this->_nb[1];
  this->_tags[3]->createText(ss.str(), 20, 1100, 220);
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

void	TeamMenu::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->updateNumber();
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
  if (this->_cursor == 1 || this->_cursor == 3)
    {
      this->_tags[this->_cursor]->setStatus(false);
      if (this->_timers[0] < this->_timers[1])
	++this->_cursor;
      else
	--this->_cursor;
      this->_tags[this->_cursor]->setStatus(true);
    }
  else if (this->_cursor == 0 || this->_cursor == 2)
    this->changeNumber(clock, input);
  
  if (this->_curToken == TokenMenu::MAP)
    {
      this->_gameManager._nbPlayers = this->_nb[0];
      this->_gameManager._nbTeams = this->_nb[1];
    }
}

