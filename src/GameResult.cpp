/*
 * NicoW
 * 31.05.12
 */

#include <iostream>		// REMOVE
#include <algorithm>
#include <sstream>
#include <vector>
#include "Match.hpp"
#include "GameResult.hpp"
#include "GameManager.hpp"

GameResult::GameResult(GameManager & game, Match & match)
  : AMenu("menu/background/backgroundResult.jpg", "menu/background/backgroundResult.jpg", 4800.0f, -1.0f, 0.0f, game),
    _isBuilt(false),
    _match(match)
{
  this->_tags.push_back(new Tag("menu/tags/BackSmallNormal.png", "menu/tags/BackSmallHighlit.png", true, false, TokenMenu::PROFILE, 5950.0f, 0.0f, 700.0f));
}

GameResult::~GameResult(void)
{
}

double		GameResult::getCenterX() const
{
  return 5600.0f;
}

double		GameResult::getCenterY() const
{
  return 400.0f;
}

static bool		orderKill(APlayer *one, APlayer *two)
{
  return (one && two && one->getNbKills() >= two->getNbKills());
}

void		GameResult::buildPlayerScore()
{
  this->_playerScore = this->_match._players;
  for (std::list<APlayer*>::iterator deadIt = this->_match._dead.begin() ; deadIt != this->_match._dead.end() ; ++deadIt)
    this->_playerScore.push_back(*deadIt);
  for (std::list<APlayer*>::iterator cadaverIt = this->_match._cadaver.begin() ; cadaverIt != this->_match._cadaver.end() ; ++cadaverIt)
    this->_playerScore.push_back(*cadaverIt);
}

void		GameResult::buildGameResult()
{
  this->buildPlayerScore();
  std::sort(_playerScore.begin(), _playerScore.end(), orderKill);
  this->_isBuilt = true;
}

void		GameResult::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_isBuilt)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
      if (this->_curToken == TokenMenu::PROFILE)
	{
	  this->_isBuilt = false;
	  /* DESTORY TOUT SKIL FAUT BIATCH*/
	}
    }
  else
    this->buildGameResult();
}

void		GameResult::draw()
{
  int	y = 358;

  AMenu::draw();

  for (unsigned int i = 0; i < this->_playerScore.size() && i < 5; ++i)
    {
      int		x = 400;
      gdl::Text		text;
      std::string	str;
      std::stringstream	sstrm;
      APlayer*		playerScore;

      std::vector<APlayer*>::iterator	it = this->_match._players.begin();

      for ( ; it != this->_match._players.end() ; ++it)
	{
	  APlayer*	realPlayer = *it;

	  playerScore = this->_playerScore[i];
	  if (realPlayer == playerScore)
	    str.assign(this->_match._players[i]->getName());
	}
      if (str.empty())
	str.assign("Computer");

      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 310;
      sstrm << playerScore->getTeamId();
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 170;
      sstrm << playerScore->getNbKills();
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 250;
      sstrm << playerScore->getNbKills() * 26;
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      y += 54;
    }
}
