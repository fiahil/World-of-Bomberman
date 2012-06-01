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
  int	hit_s;
  int	hit_e;
};

class APlayer : public AObj
{
  typedef void	(APlayer::*fBomb)(ExplodedBomb const*);
  typedef void	(APlayer::*fBonus)();
  typedef void	(APlayer::*t_rotFunc)();
  typedef std::vector< std::pair<Audio::eAudio, Audio::eAudio> > audioVect;
public:
  APlayer(Map &, std::vector<bool>* = 0);
  virtual ~APlayer();

private:
  APlayer(const APlayer&);

protected:
  Vector		_originPos;
  double		_k;
  Vector		_realPos;
  Map &			_map;
  int			_pv;
  size_t		_id;
  size_t		_teamId;
  size_t		_color;
  AIType::eAI		_type;
  bool			_attack; 
  bool			_canAttack;
  bool			_shield;
  bool			_moving;
  double		_shieldTimer;
  double		_tpTimer;
  size_t		_lustStack;
  size_t		_powerStack;
  size_t		_nbKills;
  double		_speed;
  double		_dam;
  std::vector<double>   _timers;
  BombType::eBomb	_weapon;
  Skin::eSkin		_skin;
  State::eState		_state;
  Dir::eDir		_dir;
  gdl::Model		_model;
  Pyramid		_indic;
  std::vector<bool>*	_success;
  APlayer*		_lastHitId;
  bool			_pause;

private:
  gdl::Model		_Mbomb;
  gdl::Model		_MExplodedBomb;

  std::map<BombType::eBomb, fBomb>	_bombEffect;
  std::map<BonusType::eBonus, fBonus>	_bonusEffect;
  ExplodedBomb const*			_curEffect;
  std::vector<t_rotFunc>		_rotFuncMap;
  audioVect				_soundPlayer;

private:
  void	normalBombEffect(ExplodedBomb const*);
  void	bigBombEffect(ExplodedBomb const*);
  void	megaBombEffect(ExplodedBomb const*);

  void	NORTHFunction();
  void	SOUTHFunction();
  void	WESTFunction();
  void	EASTFunction();

protected:
  void		lifeBonusEffect();
  void		BombBonusEffect();
  void		LustBonusEffect();
  void		PowerBonusEffect();
  void		ShieldBonusEffect();
  void		SprintBonusEffect();

  bool		UPFunction(gdl::GameClock const&);
  bool		LEFTFunction(gdl::GameClock const&);
  bool		RIGHTFunction(gdl::GameClock const&);
  bool		DOWNFunction(gdl::GameClock const&);
  bool		ATTACKFunction(gdl::GameClock const&);
  bool		PAUSEFunction(gdl::GameClock const&);
  virtual void	playBonusSound(void);
  /*
  ** TODO :
  ** Cheat
  ** pause/menu
  ** virtual dans APlayer and specialise dans Human
  ** TODO implementer + rajouter a la liste des bind a catch
  */

  virtual void	drawSuccess(Success::eSuccess);

public:
  virtual void	play(gdl::GameClock const&, gdl::Input&) = 0;
  virtual void	initialize(void);
  virtual void	draw(void);
  virtual void	update(gdl::GameClock const& clock, gdl::Input& input);
  virtual void	setTimer(double);
  virtual void	drawHUD(std::vector<gdl::Image>&, size_t, size_t, size_t, bool);

  Bomb*		isAttack();
  void		takeDamage(ExplodedBomb const*);
  bool		takeBonus(Bonus const*);

  void	operator()(ExplodedBomb*);

  Vector const&		getPosReal()	const;
  int			getPv()		const;
  BombType::eBomb	getWeapon()	const;
  Skin::eSkin		getSkin()	const;
  size_t		getId()		const;
  size_t		getTeamId()	const;
  size_t		getColor()	const;
  size_t		getLust()	const;
  size_t		getPower()	const;
  size_t		getNbKills()	const;
  size_t		getSpeed()	const;
  State::eState		getState()	const;
  Dir::eDir		getDir()	const;
  AIType::eAI		getType()	const;
  APlayer*		getLastHitId()	const;
  bool			isUnanim()	const;
  bool			getPause()	const;

  void		setPv(int);
  void		setWeapon(BombType::eBomb);
  void		setSkin(Skin::eSkin);
  void		setId(size_t);
  void		setTeamId(size_t);
  void		setLust(size_t);
  void		setPower(size_t);
  void		setNbKills(size_t);
  void		setSpeed(size_t);
  void		setColor(size_t);
  void		setState(State::eState);
  void		setDir(Dir::eDir);
  void		setType(AIType::eAI);
  void		setPause(bool);
  void		incNbKills();
  void		slowMotion();
};

#else

class APlayer;

#endif
