/*
 * Fiahil
 * 12.05.2012
 */

#include <vector>
#include "APlayer.hpp"

APlayer::APlayer(Map & map)
  : _map(map),
    _pv(100),
    _id(0),
    _teamId(0),
    _color(0),
    _weapon(Bomb::NORMAL),
    _skin(Skin::NORMAL),
    _state(State::STATIC),
    _dir(Dir::EAST)
{
}

APlayer::~APlayer()
{
   // TODO : implement
}

/*
 * void		APlayer::takeDamage(Point origin, Pattern pattern)
 * {
 *   // TODO : implement
 * }
 *
 */

void		APlayer::initialize(void)
{
  std::vector<std::string>	refModel(Skin::LAST, "");

  refModel[Skin::NORMAL] = "models/player.fbx";
  this->_model = gdl::Model::load(refModel[this->_skin]);
}

void		APlayer::draw(void)
{
  this->_model.draw();
}

void		APlayer::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->play(clock, input);
  this->_model.update(clock);
}

void		APlayer::setPv(int pv)
{
  this->_pv = pv;
}

int		APlayer::getPv() const
{
  return this->_pv;
}

void		APlayer::setWeapon(Bomb::eBomb weapon)
{
  this->_weapon = weapon;
}

Bomb::eBomb	APlayer::getWeapon() const
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
}

void		APlayer::setState(State::eState state)
{
  this->_state = state;
}

State::eState	APlayer::getState() const
{
  return this->_state;
}

void		APlayer::setDir(Dir::eDir dir)
{
  this->_dir = dir;
}

Dir::eDir	APlayer::getDir() const
{
  return this->_dir;
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

void		APlayer::UPFunction()
{
  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y - 1))
    this->_pos.setPos(this->_pos._x, this->_pos._y - 1);
}

void		APlayer::LEFTFunction()
{
  if (this->_map.canMoveAt(this->_pos._x - 1, this->_pos._y))
    this->_pos.setPos(this->_pos._x - 1, this->_pos._y);
}

void		APlayer::RIGHTFunction()
{
  if (this->_map.canMoveAt(this->_pos._x + 1, this->_pos._y))
    this->_pos.setPos(this->_pos._x + 1, this->_pos._y);
}

void		APlayer::DOWNFunction()
{
  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y + 1))
    this->_pos.setPos(this->_pos._x, this->_pos._y + 1);
}

void		APlayer::ATTACKFunction()
{


}
