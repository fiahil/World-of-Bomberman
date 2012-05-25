/*
 * Fiahil
 * 12.05.2012
 */

/* TMP */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "APlayer.hpp"

static const char*	g_refSkin[Skin::LAST] = {
  "models/Character_thrall.FBX",
  "models/Character_sylvanas.FBX",
  "models/Character_varian.FBX",
  "models/Character_ennemy_low.FBX"
};

static const char*	g_refBomb[BombType::LAST] = {
  "models/Bomb_blue.FBX",
  "models/Bomb_red.FBX",
  "models/Bomb_orange.FBX"
};

static const infoAnim	g_refAnim[State::LAST] = {
  {3, 137, 186, 206, 418, 548, 331, 368, 256, 281},
  {144, 410, 3, 19, 535, 584, 69, 94, 460, 485},
  {169, 236, 3, 19, 69, 119, 285, 310, 360, 385},
  {69, 103, 3, 19, 302, 364, 227, 252, 152, 177},
  {69, 119, 3, 19, 244, 269, 319, 344, 169, 194},
};

static const char*	g_refAnimName[State::LAST] = {
  "stand",
  "run",
  "death",
  "attack",
  "hit"
};

APlayer::APlayer(Map & map)
  : _map(map),
    _pv(100),
    _id(0),
    _teamId(0),
    _color(0),
    _attack(false),
    _canAttack(true),
    _shield(false),
    _shieldTimer(-1.0f),
    _tpTimer(-1.0f),
    _lustStack(0),
    _powerStack(0),
    _nbKills(0),
    _timers(5, -1.0),
    _weapon(BombType::NORMAL),
    _skin(Skin::THRALL),
    _state(State::STAND),
    _dir(Dir::SOUTH),
    _indic(0.5f, 0.5f, 0.8f, _color),
    _curEffect(0),
    _rotFuncMap(Dir::LAST, 0)
{
  this->_rotFuncMap[Dir::NORTH] = &APlayer::NORTHFunction;
  this->_rotFuncMap[Dir::SOUTH] = &APlayer::SOUTHFunction;
  this->_rotFuncMap[Dir::WEST] = &APlayer::WESTFunction;
  this->_rotFuncMap[Dir::EAST] = &APlayer::EASTFunction;
  this->_bombEffect[BombType::NORMAL] = &APlayer::normalBombEffect;
  this->_bombEffect[BombType::BIGBOMB] = &APlayer::bigBombEffect;
  this->_bombEffect[BombType::MEGABOMB] = &APlayer::megaBombEffect;
  this->_bonusEffect[BonusType::LIFE] = &APlayer::lifeBonusEffect;
  this->_bonusEffect[BonusType::BOMB] = &APlayer::BombBonusEffect;
  this->_bonusEffect[BonusType::LUST] = &APlayer::LustBonusEffect;
  this->_bonusEffect[BonusType::POWER] = &APlayer::PowerBonusEffect;
  this->_bonusEffect[BonusType::SHIELD] = &APlayer::ShieldBonusEffect;
  this->_pos._scale = 2.0f;
  this->setPos(1, 1);
  this->_k = 0.2f;
  this->_originPos = this->_pos._pos;
  this->_realPos = this->_pos._pos;
  this->_indic.setScale(2.0f);
  this->_indic.setPos(1, 1);
}

APlayer::~APlayer()
{
}

void		APlayer::initialize(void)
{
  this->_model = gdl::Model::load(g_refSkin[this->_skin]);
  gdl::Model::cut_animation(this->_model, "Take 001",
			    g_refAnim[this->_skin].stand_s, g_refAnim[this->_skin].stand_e, g_refAnimName[State::STAND]);
  gdl::Model::cut_animation(this->_model, "Take 001",
			    g_refAnim[this->_skin].run_s, g_refAnim[this->_skin].run_e, g_refAnimName[State::RUN]);
  gdl::Model::cut_animation(this->_model, "Take 001",
			    g_refAnim[this->_skin].death_s, g_refAnim[this->_skin].death_e, g_refAnimName[State::DEATH]);
  gdl::Model::cut_animation(this->_model, "Take 001",
			    g_refAnim[this->_skin].attack_s, g_refAnim[this->_skin].attack_e, g_refAnimName[State::ATTACK]);
  gdl::Model::cut_animation(this->_model, "Take 001",
			    g_refAnim[this->_skin].hit_s, g_refAnim[this->_skin].hit_e, g_refAnimName[State::HIT]);
  this->_Mbomb = gdl::Model::load(g_refBomb[this->_weapon]);
  this->_MExplodedBomb = gdl::Model::load("models/Bomb_dart.FBX");
}

void		APlayer::draw(void)
{
  glPushMatrix();
  glTranslatef(this->_realPos.x, this->_realPos.y - 1.0f, this->_realPos.z);
  (this->*_rotFuncMap[this->_dir])();
   // glScalef(0.05f, 0.05f, 0.05f);
  glScalef(1.5f, 1.5f, 1.5f);
  this->_model.draw();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0f, 3.0f, 0.0f);
  this->_indic.draw();
  glPopMatrix();
}

void		APlayer::drawHUD(std::vector<gdl::Image>&, size_t, size_t, bool)
{
}

void		APlayer::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_pv)
    this->play(clock, input);
  if ((this->_state == State::RUN || this->_state == State::STAND || this->_state == State::HIT)
      && this->_model.anim_is_ended(g_refAnimName[this->_state]))
    {
      this->_state = State::STAND;
      this->_model.play(g_refAnimName[this->_state]);
    }
  this->_model.update(clock);
  this->slowMotion();
  this->_indic.setPos(this->_realPos.x, this->_realPos.y, this->_realPos.z);
  if (this->_shield)
    {
      if (this->_shieldTimer < 0.0f)
	this->_shieldTimer = static_cast<double>(clock.getTotalGameTime() + 10.0f);
      else if (this->_shieldTimer <= static_cast<double>(clock.getTotalGameTime()))
	{
	  this->_shield = false;
	  this->_shieldTimer = -1.0f;
	}
    }
  if ((static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::ATTACK])
    this->_canAttack = true;
  else
    this->_canAttack = false;
  if (this->_tpTimer <= static_cast<double>(clock.getTotalGameTime()))
    {
      this->_tpTimer = static_cast<double>(clock.getTotalGameTime() + 3.0f);
      this->_map.teleport(this->_pos);
    }
}

void		APlayer::slowMotion()
{
  if (!(this->_realPos == this->_pos._pos))
    {
      this->_realPos.x = this->_originPos.x + this->_k * (this->_pos._pos.x - this->_originPos.x);
      this->_realPos.z = this->_originPos.z + this->_k * (this->_pos._pos.z - this->_originPos.z);
      this->_k += 0.2f;
      if (this->_k > 1.2f)
	{
	  this->_originPos = this->_pos._pos;
	  this->_realPos = this->_pos._pos;
	  this->_k = 0.2f;
	}
    }
}

void		APlayer::normalBombEffect(ExplodedBomb const* cur)
{
  if (this->_curEffect != cur)
    {
      if (this->_shield)
	this->_pv -= 15;
      else
	this->_pv -= 30;
      if (this->_pv < 0)
	this->_pv = 0;
      this->_curEffect = cur;
    }
}

void		APlayer::bigBombEffect(ExplodedBomb const* cur)
{
  if (this->_curEffect != cur)
    {
      if (this->_shield)
	this->_pv -= 22;
      else
	this->_pv -= 45;
      if (this->_pv < 0)
	this->_pv = 0;
      this->_curEffect = cur;
    }
}

void		APlayer::megaBombEffect(ExplodedBomb const* cur)
{
  if (this->_curEffect != cur)
    {
      if (this->_shield)
	this->_pv -= 30;
      else
	this->_pv -= 60;
      if (this->_pv < 0)
	this->_pv = 0;
      this->_curEffect = cur;
    }
}

void		APlayer::lifeBonusEffect()
{
  this->_pv += 25;
  if (this->_pv >= 100)
    this->_pv = 100;
}

void		APlayer::BombBonusEffect()
{
  if (this->_weapon < BombType::MEGABOMB)
    {
      this->_weapon = static_cast<BombType::eBomb>(this->_weapon + 1);
      this->_Mbomb = gdl::Model::load(g_refBomb[this->_weapon]);
    }
}

void		APlayer::LustBonusEffect()
{
  if (this->_lustStack < 6)
    ++this->_lustStack;
}

void		APlayer::PowerBonusEffect()
{
  if (this->_powerStack < 6)
    ++this->_powerStack;
}

void		APlayer::ShieldBonusEffect()
{
  this->_shield = true;
  this->_shieldTimer = -1.0f;
}

void		APlayer::takeDamage(ExplodedBomb const* cur)
{
  Pattern	pattern = cur->getPatternReal();

  if ((this->_pos._x >= (pattern._x - pattern._coefW) &&
       this->_pos._x <= (pattern._x + pattern._coefE) &&
       this->_pos._y == pattern._y) ||
      (this->_pos._y >= (pattern._y - pattern._coefN) &&
       this->_pos._y <= (pattern._y + pattern._coefS) &&
       this->_pos._x == pattern._x))
    {
      (this->*_bombEffect[cur->getType()])(cur);
      if (!this->_pv)
	this->_state = State::DEATH;
      else
	this->_state = State::HIT;
      this->_model.play(g_refAnimName[this->_state]);
    }
}

bool		APlayer::takeBonus(Bonus const* cur)
{
  if (this->_pos._x == cur->getPos()._x && this->_pos._y == cur->getPos()._y)
    {
      (this->*_bonusEffect[cur->getType()])();
      return true;
    }
  return false;
}

Vector const&		APlayer::getPosReal() const
{
  return this->_realPos;
}

void		APlayer::setPv(int pv)
{
  this->_pv = pv;
}

int		APlayer::getPv() const
{
  return this->_pv;
}

void		APlayer::setWeapon(BombType::eBomb weapon)
{
  this->_weapon = weapon;
}

BombType::eBomb	APlayer::getWeapon() const
{
  return this->_weapon;
}

void		APlayer::setTeamId(size_t team)
{
  this->_teamId = team;
}

size_t		APlayer::getTeamId() const
{
  return this->_teamId;
}

void		APlayer::setId(size_t id)
{
  this->_id = id;
}

size_t		APlayer::getId() const
{
  return this->_id;
}

size_t		APlayer::getColor() const
{
  return this->_color;
}

void		APlayer::setColor(size_t val)
{
  this->_color = val;
  this->_indic.setColor(val);
}

void		APlayer::setState(State::eState state)
{
  this->_state = state;
}

State::eState	APlayer::getState() const
{
  return this->_state;
}

void		APlayer::setSkin(Skin::eSkin skin)
{
  this->_skin = skin;
}

Skin::eSkin	APlayer::getSkin(void) const
{
  return this->_skin;
}

void		APlayer::setDir(Dir::eDir dir)
{
  this->_dir = dir;
}

Dir::eDir	APlayer::getDir() const
{
  return this->_dir;
}

size_t		APlayer::getType() const
{
  return this->_type;
}

void		APlayer::setType(size_t t)
{
  this->_type = t;
}

void		APlayer::setName(std::string const& name)
{
  this->_name = name;
}

void		APlayer::setTeamName(std::string const& name)
{
  this->_teamName = name;
}

std::string const&	APlayer::getName() const
{
  return this->_name;
}

std::string const&	APlayer::getTeamName() const
{
  return this->_teamName;
}

void		APlayer::incNbKills()
{
  ++this->_nbKills;
}

void		APlayer::UPFunction(gdl::GameClock const& clock)
{
  double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::UP] && this->_realPos == this->_pos._pos)
    {
      this->_timers[HumGame::UP] = current + 0.15;
      this->_dir = Dir::NORTH;
      if (this->_map.canMoveAt(this->_pos._x, this->_pos._y - 1))
	{
	  this->_pos.setPos(this->_pos._x, this->_pos._y - 1);
	  this->_state = State::RUN;
	  this->_model.play(g_refAnimName[this->_state]);
	}
    }
}

void		APlayer::LEFTFunction(gdl::GameClock const& clock)
{
  double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::LEFT] && this->_realPos == this->_pos._pos)
    {
      this->_timers[HumGame::LEFT] = current + 0.15;
      this->_dir = Dir::WEST;
      if (this->_map.canMoveAt(this->_pos._x - 1, this->_pos._y))
	{
	  this->_pos.setPos(this->_pos._x - 1, this->_pos._y);
	  this->_state = State::RUN;
	  this->_model.play(g_refAnimName[this->_state]);
	}
    }
}

void		APlayer::RIGHTFunction(gdl::GameClock const& clock)
{
   double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::RIGHT] && this->_realPos == this->_pos._pos)
    {
      this->_timers[HumGame::RIGHT] = current + 0.15;
      this->_dir = Dir::EAST;
      if (this->_map.canMoveAt(this->_pos._x + 1, this->_pos._y))
	{
	  this->_pos.setPos(this->_pos._x + 1, this->_pos._y);
	  this->_state = State::RUN;
	  this->_model.play(g_refAnimName[this->_state]);
	}
    }
}

void		APlayer::DOWNFunction(gdl::GameClock const& clock)
{
   double	current;

   if ((current = static_cast<double>(clock.getTotalGameTime())) >=
       this->_timers[HumGame::DOWN] && this->_realPos == this->_pos._pos)
     {
      this->_timers[HumGame::DOWN] = current + 0.15;
      this->_dir = Dir::SOUTH;
      if (this->_map.canMoveAt(this->_pos._x, this->_pos._y + 1))
	{
	  this->_pos.setPos(this->_pos._x, this->_pos._y + 1);
	  this->_state = State::RUN;
	  this->_model.play(g_refAnimName[this->_state]);
	}
    }
}

void		APlayer::ATTACKFunction(gdl::GameClock const& clock)
{
   double	current;
  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::ATTACK])
    {
      double	addTimer = 3.0 - (0.3 * this->_lustStack);
      if (addTimer < 0.00001)
	addTimer = 0.0;
      this->_timers[HumGame::ATTACK] = current + addTimer;
      this->_attack = true;
      this->_state = State::ATTACK;
      this->_model.play(g_refAnimName[this->_state]);
      this->_model.set_anim_speed(g_refAnimName[this->_state], 3.0f);
    }
}

void		APlayer::PAUSEFunction(gdl::GameClock const&)
{
  exit (1);
}

Bomb*		APlayer::isAttack()
{
  if (!this->_attack)
    return 0;

  Bomb	*ret = new Bomb(this->_weapon, this->_pos,
			this, this->_Mbomb, this->_MExplodedBomb, this->_powerStack);
  this->_attack = false;
  return ret;
}


void		APlayer::NORTHFunction()
{
  glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
}

void		APlayer::SOUTHFunction()
{
}

void		APlayer::WESTFunction()
{
 glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
}

void		APlayer::EASTFunction()
{
  glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
}
