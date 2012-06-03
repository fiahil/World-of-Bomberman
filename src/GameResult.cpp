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
#include "ProfileManager.hpp"
#include "Common.hpp"

static const std::string	g_refTeam[] = {
  "Red",
  "Green",
  "Blue",
  "Cyan",
  "Yellow",
  "Brown",
  "Purple",
  "Black",
  "Grey"
};

GameResult::GameResult(GameManager & game,
		       Match & match,
		       std::vector<Map*> const & maps)
  : AMenu("menu/background/backgroundResult.jpg",
	  "menu/background/backgroundResult.jpg",
	  4800.0f, -1.0f, 0.0f, game),
    _isBuilt(false),
    _match(match),
    _maps(maps)
{
  this->_tags.push_back(new Tag("menu/tags/BackSmallNormal.png",
				"menu/tags/BackSmallHighlit.png",
				true, false, TokenMenu::GAMERESULT,
				5950.0f, 0.0f, 700.0f));
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

void		GameResult::buildPlayerScore()
{
  this->_playerScore = this->_match._players;
  this->_playerScore.insert(this->_playerScore.begin(),
			    this->_match._dead.begin(),
			    this->_match._dead.end());
  this->_playerScore.insert(this->_playerScore.begin(),
			    this->_match._cadaver.begin(),
			    this->_match._cadaver.end());
}

static bool		orderKill(APlayer *one, APlayer *two)
{
  return (one && two && one->getNbKills() > two->getNbKills());
}

void		GameResult::buildGameResult()
{
  this->buildPlayerScore();
  std::sort(_playerScore.begin(), _playerScore.end(), orderKill);
  this->_isBuilt = true;
}

void		GameResult::saveStats(APlayer* p, Profile* pr)
{
  if (p && pr)
    {
      Stat		stat = pr->getStat();
      size_t		kills = p->getNbKills();

      if (kills > stat.getMaxKill())
	stat.setMaxKills(kills);
      stat.addKills(kills);
      if (!this->_playerScore.empty())
	{
	  if (this->_match._players.front() == p)
	    stat.addVictories(1);
	  else
	    stat.addDefeats(1);
	}
      pr->setStat(stat);
      ProfileManager::setProfile(p->getId(), *pr);
    }
}

void		GameResult::clearGame()
{
  for (std::vector<APlayer*>::iterator it = this->_playerScore.begin();
       it != this->_playerScore.end(); ++it)
    {
      if ((*it)->getId() == this->_gameManager._mainProfile->getId())
	this->saveStats((*it), this->_gameManager._mainProfile);
      else if (this->_gameManager._secondProfile &&
	       (*it)->getId() == this->_gameManager._secondProfile->getId())
     	this->saveStats((*it), this->_gameManager._secondProfile);
    }

  std::for_each(this->_gameManager._match._players.begin(),
		this->_gameManager._match._players.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._players.clear();

  std::for_each(this->_gameManager._match._dead.begin(),
		this->_gameManager._match._dead.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._dead.clear();
  std::for_each(this->_gameManager._match._cadaver.begin(),
		this->_gameManager._match._cadaver.end(),
		deleteItem<APlayer* >);
  this->_gameManager._match._cadaver.clear();

  std::for_each(this->_gameManager._match._bombs.begin(),
		this->_gameManager._match._bombs.end(),
		deleteItem<Bomb* >);
  this->_gameManager._match._bombs.clear();

  std::for_each(this->_gameManager._match._bonus.begin(),
		this->_gameManager._match._bonus.end(),
		deleteItem<Bonus* >);
  this->_gameManager._match._bonus.clear();

  std::for_each(this->_gameManager._match._explodedBombs.begin(),
		this->_gameManager._match._explodedBombs.end(),
		deleteItem<ExplodedBomb* >);
  this->_gameManager._match._explodedBombs.clear();
  delete this->_gameManager._match._map;
  this->_gameManager._match._map = 0;
  if (std::find(this->_maps.begin(), this->_maps.end(),
		this->_gameManager._originMap) == this->_maps.end())
    {
      delete this->_gameManager._originMap;
      this->_gameManager._originMap = 0;
    }
}

void		GameResult::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_isBuilt)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first) ||
	    JsManager::getMe()->isJsDown(JsMode::MENU, this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
      if (this->_curToken == TokenMenu::GAMERESULT)
	{
	  this->_isBuilt = false;
	  this->clearGame();
	}
    }
  else
    this->buildGameResult();
}

static std::string const	createPlayerName(APlayer* player,
						 GameManager const& gameManager)
{
  if (player->getType() == AIType::HUMAN)
    {
      if (gameManager._mainProfile
	  && (player->getId() == gameManager._mainProfile->getId()))
	return gameManager._mainProfile->getName();
      else if (gameManager._secondProfile
	       && (player->getId() == gameManager._secondProfile->getId()))
	return gameManager._secondProfile->getName();
    }
  return "Furious Chiken";
}

void		GameResult::draw()
{
  int			y = 358;
  gdl::Text		text;
  std::stringstream	sstrm;

  AMenu::draw();
  if (this->_textDraw == true)
    {
      if (this->_match._players.size())
	{
	  sstrm << this->_match._players.front()->getTeamId() + 1;
	  text.setText("Team " + sstrm.str()
		       + "  --  " + g_refTeam[this->_match._players.front()->getTeamId()]);
	  text.setSize(20);
	  text.setPosition(850, 196);
	  text.draw();
	}
      for (unsigned int i = 0 ; i < this->_playerScore.size() && i < 5; ++i)
	{
	  int		x = 400;
	  std::string	str;
	  APlayer*	playerScore = this->_playerScore[i];

	  sstrm.str("");
	  str.assign(createPlayerName(playerScore, this->_gameManager));
	  text.setText(str);
	  text.setSize(20);
	  text.setPosition(x, y);
	  text.draw();

	  x += 310;
	  sstrm.str("");
	  sstrm << playerScore->getTeamId() + 1;
	  text.setText(sstrm.str());
	  text.setSize(20);
	  text.setPosition(x, y);
	  text.draw();

	  x += 170;
	  sstrm.str("");
	  sstrm << playerScore->getNbKills();
	  text.setText(sstrm.str());
	  text.setSize(20);
	  text.setPosition(x, y);
	  text.draw();

	  x += 250;
	  sstrm.str("");
	  sstrm << playerScore->getNbKills() * 26;
	  text.setText(sstrm.str());
	  text.setSize(20);
	  text.setPosition(x, y);
	  text.draw();

	  y += 53;
	}
    }
}

