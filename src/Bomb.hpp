/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_Bomb_h)
#define __Bomberman_Bomb_h

#include <Model.hpp>
#include "enum.hpp"
#include "Pattern.hpp"
#include "APlayer.hpp"
#include "ExplodedBomb.hpp"
#include "AObj.hpp"

class Bomb : public AObj
{
public:
  Bomb(BombType::eBomb,
       Point const &,
       APlayer*,
       gdl::Model&,
       gdl::Model&,
       size_t = 0);
  virtual ~Bomb();

private:
  BombType::eBomb	_type;
  APlayer*		_player;
  double		_timer;
  bool			_exploded;
  gdl::Model&		_model;
  gdl::Model&		_modelExploded;
  Pattern		_pattern;

public:
  void			initialize(void);
  void			draw(void);
  void			update(gdl::GameClock const&, gdl::Input&);

  bool			explode() const;
  Pattern const&	getPattern() const;
  ExplodedBomb*		createExplodedBomb() const;
};

#else

class Bomb;

#endif
