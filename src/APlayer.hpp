/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_APlayer_h)
#define __Bomberman_APlayer_h

#include <map>
#include <string>
#include "Map.hpp"
#include "Model.hpp"
#include "enum.hpp"
#include "Pyramid.hpp"
#include "AObj.hpp"

class APlayer : public AObj
{
public:
  APlayer(Map &);
  virtual ~APlayer();

private:
  APlayer(const APlayer&);

  /*
   * TODO : IMPLEMENT FUNCTION
   */
  typedef void	(*fBomb)();
  typedef void	(*fBonus)();

protected:
  Map &			_map;
  int			_pv;
  size_t		_id;
  size_t		_teamId;
  size_t		_color;
  size_t		_type;
  std::string		_name;
  std::string		_teamName;
  Bomb::eBomb		_weapon;
  Skin::eSkin		_skin;
  State::eState		_state;
  Dir::eDir		_dir;
  gdl::Model		_model;
  Pyramid		_indic;

  std::map<Bomb::eBomb, fBomb>		_bombEffect;
  std::map<Bonus::eBonus, fBonus>	_bonusEffect;

protected:
  void UPFunction();
  void LEFTFunction();
  void RIGHTFunction();
  void DOWNFunction();
  void ATTACKFunction();
  // cheat
  // pause/menu
  // virtual dans APlayer and specialise dans Human
  // TODO implementer + rajouter a la liste des bind a catch

private:
  typedef void	(APlayer::*t_rotFunc)();
  void	NORTHFunction();
  void	SOUTHFunction();
  void	WESTFunction();
  void	EASTFunction();
  std::vector<t_rotFunc>	_rotFuncMap;

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
  size_t	getId() const;
  size_t	getTeamId() const;
  size_t	getColor() const;
  State::eState	getState() const;
  Dir::eDir	getDir() const;
  size_t	getType() const;

  std::string const&	getName() const;
  std::string const&	getTeamName() const;

  void		setPv(int);
  void		setWeapon(Bomb::eBomb);
  void		setSkin(Skin::eSkin);
  void		setId(size_t);
  void		setTeamId(size_t);
  void		setColor(size_t);
  void		setState(State::eState);
  void		setDir(Dir::eDir);
  void		setName(std::string const&);
  void		setTeamName(std::string const&);
  void		setType(size_t);
};

#endif
