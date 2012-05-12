/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_APlayer_h)
#define __Bomberman_APlayer_h

#include <map>
#include <string>
#include "Model.hpp"
#include "enum.hpp"
#include "AObj.hpp"

class APlayer : public AObj
{
public:
  APlayer();
  virtual ~APlayer();

private:
  APlayer(const APlayer&);

  /*
   * TODO : IMPLEMENT FUNCTION
   */
  typedef void	(*fBomb)();
  typedef void	(*fBonus)();

protected:
  int			_pv;
  size_t		_id;
  size_t		_teamId;
  std::string		_name;
  std::string		_teamName;
  Bomb::eBomb		_weapon;
  Skin::eSkin		_skin;
  State::eState		_state;
  Dir::eDir		_dir;
  gdl::Model		_model;

  std::vector<size_t>*			_achivement;	// modified : implement
  std::vector<size_t> const		_skill;		// modified : implement
  std::map<Bomb::eBomb, fBomb>		_bombEffect;
  std::map<Bonus::eBonus, fBonus>	_bonusEffect;

public:
  /*
   * TODO : IMPLEMENT PATTERN
   * virtual void	takeDamage(Point, Pattern);
   */
  virtual void	play(gdl::GameClock const&, gdl::Input&) = 0;
  virtual void	initialize(void);
  virtual void	draw(void);
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);

  int		getPv() const;
  Bomb::eBomb	getWeapon() const;
  Skin::eSkin	getSkin() const;
  size_t	getTeam() const;
  size_t	getId() const;
  State::eState	getState() const;
  Dir::eDir	getDir() const;

  std::string const&	getName() const;
  std::string const&	getTeamName() const;

  void		setPv(int);
  void		setWeapon(Bomb::eBomb);
  void		setSkin(Skin::eSkin);
  void		setTeam(size_t);
  void		setId(size_t);
  void		setState(State::eState);
  void		setDir(Dir::eDir);
  void		setName(std::string const&);
  void		setTeamName(std::string const&);
};

#endif
