/*
 * Fiahil
 * 12.05.2012
 */

#if !defined(__Bomberman_APlayer_h)
#define __Bomberman_APlayer_h

#include <map>
#include <string>
#include <Image.hpp>
#include "ExplodedBomb.hpp"
#include "Bomb.hpp"
#include "Map.hpp"
#include "Model.hpp"
#include "enum.hpp"
#include "Pyramid.hpp"
#include "AObj.hpp"

struct	infoAnim
{
  int	stand_s;
  int	stand_e;
  int	run_s;
  int	run_e;
  int	death_s;
  int	death_e;
  int	attack_s;
  int	attack_e;
};

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
  typedef void	(APlayer::*fBomb)(ExplodedBomb const*);
  typedef void	(APlayer::*fBonus)();

protected:
  Vector		_originPos;
  double		_k;
  Vector		_realPos;
  Map &			_map;
  int			_pv;
  size_t		_id;
  size_t		_teamId;
  size_t		_color;
  size_t		_type;
  bool			_attack;
  bool			_canAttack;
  bool			_shield;
  double		_shieldTimer;
  size_t		_lustStack;
  size_t		_powerStack;
  size_t		_nbKills;
  std::vector<double>   _timers;
  std::string		_name;
  std::string		_teamName;
  BombType::eBomb	_weapon;
  Skin::eSkin		_skin;
  State::eState		_state;
  Dir::eDir		_dir;
  gdl::Model		_model;
  Pyramid		_indic;

private:
  gdl::Model		_Mbomb;
  gdl::Model		_MExplodedBomb;
  void	normalBombEffect(ExplodedBomb const*);
  void	bigBombEffect(ExplodedBomb const*);
  void	megaBombEffect(ExplodedBomb const*);
  void		lifeBonusEffect();
  void		BombBonusEffect();
  void		LustBonusEffect();
  void		PowerBonusEffect();
  void		ShieldBonusEffect();
  std::map<BombType::eBomb, fBomb>	_bombEffect;
  std::map<BonusType::eBonus, fBonus>	_bonusEffect;
  ExplodedBomb const*			_curEffect;

protected:
  void UPFunction(gdl::GameClock const&);
  void LEFTFunction(gdl::GameClock const&);
  void RIGHTFunction(gdl::GameClock const&);
  void DOWNFunction(gdl::GameClock const&);
  void ATTACKFunction(gdl::GameClock const&);
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
  virtual void	play(gdl::GameClock const&, gdl::Input&) = 0;
  virtual void	initialize(void);
  virtual void	draw(void);
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);
  virtual void	drawHUD(std::vector<gdl::Image>&, size_t, size_t, bool);

  Bomb*		isAttack();
  void		takeDamage(ExplodedBomb const*);
  bool		takeBonus(Bonus const*);

  Vector const&	getPosReal() const;
  int		getPv() const;
  BombType::eBomb	getWeapon() const;
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
  void		setWeapon(BombType::eBomb);
  void		setSkin(Skin::eSkin);
  void		setId(size_t);
  void		setTeamId(size_t);
  void		setColor(size_t);
  void		setState(State::eState);
  void		setDir(Dir::eDir);
  void		setName(std::string const&);
  void		setTeamName(std::string const&);
  void		setType(size_t);
  void		incNbKills();
  void		slowMotion();
};

#else

class APlayer;

#endif
