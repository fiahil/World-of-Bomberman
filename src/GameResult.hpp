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
  GameResult(GameManager &, Match &);
  virtual ~GameResult(void);

public:
  bool			_isBuilt;
  Match &		_match;

private:
  std::vector<APlayer*>	_playerScore;

private:
  void			buildPlayerScore();

private:
  virtual void		draw();

public:
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
  virtual void		update(gdl::GameClock const&, gdl::Input&);
  void			buildGameResult();
};

#endif		/* __GAME_RESULT_HPP__ */
