/*
 * Fiahil
 * 12.05.2012
 */

#include <iostream>
#include <vector>
#include "APlayer.hpp"

APlayer::APlayer(Map & map)
  : _map(map),
    _pv(100),
    _id(0),
    _teamId(0),
    _color(0),
    _attack(false),
    _canAttack(true),
    _timers(5, -1.0),
    _weapon(BombType::NORMAL),
    _skin(Skin::NORMAL),
    _state(State::STATIC),
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
  this->_bombEffect[BombType::MEGABOMB] = &APlayer::megaBombEffect;
  this->_bonusEffect[BonusType::LIFE] = &APlayer::lifeBonusEffect;
  this->_bonusEffect[BonusType::WEAPON] = &APlayer::weaponBonusEffect;
  this->_pos._scale = 2.0f;
  this->setPos(1, 1);
  this->_indic.setScale(2.0f);
  this->_indic.setPos(1, 1);
}

APlayer::~APlayer()
{
}

void		APlayer::initialize(void)
{
  std::vector<std::string>	refSkin(Skin::LAST, "");
  std::vector<std::string>	refBomb(BombType::LAST, "");

  refSkin[Skin::NORMAL] = "models/Man.fbx";
  refBomb[BombType::NORMAL] = "models/normalBomb.fbx";
  this->_model = gdl::Model::load(refSkin[this->_skin]);
  this->_Mbomb = gdl::Model::load(refBomb[this->_weapon]);
  this->_MExplodedBomb = gdl::Model::load("models/normalBomb.fbx");
}

void		APlayer::draw(void)
{
  glPushMatrix();
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y - 1.0f, this->_pos._pos.z);
  (this->*_rotFuncMap[this->_dir])();
   glScalef(0.05f, 0.05f, 0.05f);
  // glScalef(2.0f, 2.0f, 2.0f);
  this->_model.draw();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0f, 3.0f, 0.0f);
  this->_indic.draw();
  glPopMatrix();
}

void		APlayer::drawHUD(std::vector<gdl::Image>&, size_t)
{
}

void		APlayer::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->play(clock, input);
  this->_model.update(clock);
  this->_indic.setPos(this->_pos._x, this->_pos._y);
  if ((static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::ATTACK])
    this->_canAttack = true;
  else
    this->_canAttack = false;
}

void		APlayer::normalBombEffect(ExplodedBomb const* cur)
{
  if (this->_curEffect != cur)
    {
      this->_pv -= 40;
      if (this->_pv < 0)
	this->_pv = 0;
      this->_curEffect = cur;
    }
}

void		APlayer::megaBombEffect(ExplodedBomb const* cur)
{
  if (this->_curEffect != cur)
    {
      this->_pv -= 70;
      if (this->_pv < 0)
	this->_pv = 0;
      this->_curEffect = cur;
    }
}

void		APlayer::lifeBonusEffect()
{
  this->_pv += 50;
}

void		APlayer::weaponBonusEffect()
{
  
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
    (this->*_bombEffect[cur->getType()])(cur);
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

void		APlayer::UPFunction(gdl::GameClock const& clock)
{
  double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::UP])
    {
      this->_timers[HumGame::UP] = current + 0.15;
      this->_dir = Dir::NORTH;
      if (this->_map.canMoveAt(this->_pos._x, this->_pos._y - 1))
	this->_pos.setPos(this->_pos._x, this->_pos._y - 1);
      this->_model.play("Take 001");
    }
}

void		APlayer::LEFTFunction(gdl::GameClock const& clock)
{
  double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::LEFT])
    {
      this->_timers[HumGame::LEFT] = current + 0.15;
      this->_dir = Dir::WEST;
      if (this->_map.canMoveAt(this->_pos._x - 1, this->_pos._y))
	this->_pos.setPos(this->_pos._x - 1, this->_pos._y);
      this->_model.play("Take 001");
    }
}

void		APlayer::RIGHTFunction(gdl::GameClock const& clock)
{
   double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::RIGHT])
    {
      this->_timers[HumGame::RIGHT] = current + 0.15;
      this->_dir = Dir::EAST;
      if (this->_map.canMoveAt(this->_pos._x + 1, this->_pos._y))
	this->_pos.setPos(this->_pos._x + 1, this->_pos._y);
      this->_model.play("Take 001");
    }
}

void		APlayer::DOWNFunction(gdl::GameClock const& clock)
{
   double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::DOWN])
    {
      this->_timers[HumGame::DOWN] = current + 0.15;
      this->_dir = Dir::SOUTH;
      if (this->_map.canMoveAt(this->_pos._x, this->_pos._y + 1))
	this->_pos.setPos(this->_pos._x, this->_pos._y + 1);
      this->_model.play("Take 001");
    }
}

void		APlayer::ATTACKFunction(gdl::GameClock const& clock)
{
   double	current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_timers[HumGame::ATTACK])
    {
      this->_timers[HumGame::ATTACK] = current + 3;
      this->_attack = true;
    }
}

Bomb*		APlayer::isAttack()
{
  if (!this->_attack)
    return 0;
  Bomb	*ret = new Bomb(this->_weapon, this->_pos, this->_id, this->_Mbomb, this->_MExplodedBomb);
  this->_attack = false;
  return ret;
}


void		APlayer::NORTHFunction()
{
  glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
}

void		APlayer::SOUTHFunction()
{
 glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

}

void		APlayer::WESTFunction()
{
  glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
 }

void		APlayer::EASTFunction()
{
}
