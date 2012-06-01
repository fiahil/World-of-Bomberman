/*
 * NicoW
 * 31.05.12
 */

#include <iostream>		// REMOVE
#include <algorithm>
#include <vector>
#include "Match.hpp"
#include "GameResult.hpp"
#include "GameManager.hpp"

void		printKill(const std::vector<APlayer *> & v)
{
  std::vector<APlayer *>::const_iterator	it = v.begin();

  for (; it != v.end() ; ++it)
    if (*it)
      std::cout << "Kill = " << (*it)->getNbKills() << std::endl;
}

bool		orderKill(APlayer *one, APlayer *two)
{
  return (one && two && one->getNbKills() >= two->getNbKills());
}

GameResult::GameResult(GameManager & game, Match & match)
  : AMenu("menu/backgroundCredits.jpg", "menu/backgroundCredits.jpg", 4800.0f, -1.0f, 0.0f, game),
    _match(match)
{
  this->_tags.push_back(new Tag("menu/DoneNormal.png", "menu/DoneHighlit.png", true, false, TokenMenu::PROFILE, 4800.0f, 0.0f, 400.0f));
}

GameResult::~GameResult(void)
{
}

double		GameResult::getCenterX() const
{
  return 4800.0f;
}

double		GameResult::getCenterY() const
{
  return 400.0f;
}

void		GameResult::update(gdl::GameClock const& clock, gdl::Input& input)
{
  std::cout << "Update GameResult" << std::endl;
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}

/*
  bool		selected = true;

  std::cout << "\nNb Players = " << match._players.size() << std::endl;

  std::cout << "\nAvant" << std::endl;
  printKill(match._players);

  std::sort(match._players.begin(), match._players.end(), orderKill);

  std::cout << "\nApres" << std::endl;
  printKill(match._players);
*/
