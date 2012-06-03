/*
 * NicoW
 * 31.05.12
 */

#ifndef		__GAME_RESULT_HPP__
#define		__GAME_RESULT_HPP__

#include "AMenu.hpp"
#include "Match.hpp"

class	GameResult : public AMenu
{
public:
  GameResult(GameManager &, Match &, std::vector<Map*> const &);
  virtual ~GameResult(void);

private:
  bool				_isBuilt;
  Match &			_match;
  std::vector<Map*> const &	_maps;

  std::vector<APlayer*>	_playerScore;

private:
  void			buildPlayerScore();
  void			clearGame();
  void			buildGameResult();
  void			saveStats(APlayer* p, Profile* pr);

private:
  virtual void		draw();

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);

};

#endif		/* __GAME_RESULT_HPP__ */
