/***********************************************************************
 * Module:  APlayer.h
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:17 PM
 * Purpose: Declaration of the class APlayer
 ***********************************************************************/

#if !defined(__Bomberman_APlayer_h)
#define __Bomberman_APlayer_h

#include <map>
#include <string>
#include <Model.hpp>
#include "enum.hpp"
#include "AObj.hpp"

class APlayer : public AObj
{
public:
  APlayer();
  virtual ~APlayer();
  virtual void play(gdl::GameClock const&, gdl::Input&)=0;
  // void takeDamage(Point origin, Pattern pattern);
  virtual void initialize(void);
  virtual void draw(void);
  virtual void update(gdl::GameClock const& clock, gdl::Input& input);
  void		setPv(int);
  int		getPv() const;
  void		setWeapon(Bomb::eBomb);
  Bomb::eBomb	getWeapon() const;
  void		setSkin(Skin::eSkin);
  Skin::eSkin	getSkin() const;
  void		setTeam(size_t);
  size_t	getTeam() const;
  void		setId(size_t);
  size_t	getId() const;
  void		setState(State::eState);
  State::eState	getState() const;
  void		setDir(Dir::eDir);
  Dir::eDir	getDir() const;
  void		setName(std::string const&);
  std::string const&	getName() const;

private:
  typedef void	(*fBomb)();
  typedef void	(*fBonus)();
  
protected:
  int _pv;
  Bomb::eBomb _weapon;
  Skin::eSkin _skin;
  size_t _team;
  size_t _id;
  State::eState _state;
  Dir::eDir	_dir;
  std::map<Bomb::eBomb, fBomb> _bombEffect;
  std::map<Bonus::eBonus, fBonus> _bonusEffect;
  gdl::Model _model;
  std::string _name;

private:
  APlayer(const APlayer& oldAPlayer);

};

#endif
