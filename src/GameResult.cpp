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

static const std::string	g_refTeam[] = {
  "Red",
  "Green",
  "Blue",
  "Cyan",
  "Yellow",
  "Brown",
  "Purple",
  "Black",
  "Red",
  "Grey"
};

GameResult::GameResult(GameManager & game, Match & match)
  : AMenu("menu/background/backgroundResult.jpg", "menu/background/backgroundResult.jpg", 4800.0f, -1.0f, 0.0f, game),
    _isBuilt(false),
    _match(match)
{
  this->_tags.push_back(new Tag("menu/tags/BackSmallNormal.png", "menu/tags/BackSmallHighlit.png", true, false, TokenMenu::GAMERESULT, 5950.0f, 0.0f, 700.0f));
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
  return (one && two && one->getNbKills() > two->getNbKills());
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

/*void		GameResult::saveStats(APlayer* p, Profile* pr)
{
  
}

void		GameResult::clearGame()
{
  for (std::vector<APlayer*>::iterator it = this->_playerScore.begin();
       it != this->_playerScore.end(); ++it)
    if ((*it)->getId() == this->_gameManager._mainProfile->getId())
      this->saveStats((*it), this->_gameManager._mainProfile);
    else if ((*it)->getId() == this->_gameManager._secondProfile->getId())
      this->saveStats((*it), this->_gameManager._secondProfile);
      
  while (this->_gameManager._match._players.size())
    {
      delete _gameManager._match._players.back();
      this->_gameManager._match._players.pop_back();
    }
  while (this->_gameManager._match._dead.size())
    {
      delete _gameManager._match._dead.back();
      this->_gameManager._match._dead.pop_back();
    }
  while (this->_gameManager._match._cadaver.size())
    {
      delete _gameManager._match._cadaver.back();
      this->_gameManager._match._cadaver.pop_back();
    }
  while (this->_gameManager._match._bombs.size())
    {
      delete this->_gameManager._match._bombs.back();
      this->_gameManager._match._bombs.pop_back();
    }
  while (this->_gameManager._match._bonus.size())
    {
      delete this->_gameManager._match._bonus.back();
      this->_gameManager._match._bonus.pop_back();
    }
  while (this->_gameManager._match._explodedBombs.size())
    {
      delete this->_gameManager._match._explodedBombs.back();
      this->_gameManager._match._explodedBombs.pop_back();
    }
    }*/

void		GameResult::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_isBuilt)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
      if (this->_curToken == TokenMenu::GAMERESULT)
	this->_isBuilt = false;
    }
  else
    this->buildGameResult();
}

void		GameResult::draw()
{
  int	y = 358;

  AMenu::draw();

  if (this->_match._players.size())
    {
      gdl::Text		text;
      std::stringstream	sstrm;
      sstrm << this->_match._players.front()->getTeamId() + 1;
      text.setText("Team " + sstrm.str()
		   + "  --  " + g_refTeam[this->_match._players.front()->getTeamId()]);
      text.setSize(20);
      text.setPosition(850, 196);
      text.draw();
    }

  for (unsigned int i = 0 ; this->_textDraw == true && i < this->_playerScore.size() && i < 5; ++i)
    {
      int		x = 400;
      gdl::Text		text;
      std::string	str;
      std::stringstream	sstrm;
      APlayer*		playerScore = this->_playerScore[i];

      if (playerScore->getType() == AIType::HUMAN)
	str.assign("PLAYER");
      else
	str.assign("Computer");

      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 310;
      sstrm.clear();
      sstrm << playerScore->getTeamId() + 1; // MAJ +1 a tout les ID
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 170;
      sstrm.clear();
      sstrm << playerScore->getNbKills();
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      x += 250;

      sstrm.clear();
      sstrm << playerScore->getNbKills() * 26;
      sstrm >> str;
      text.setText(str);
      text.setSize(20);
      text.setPosition(x, y);
      text.draw();

      y += 53;
    }
}
