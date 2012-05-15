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
    _weapon(Bomb::NORMAL),
    _skin(Skin::NORMAL),
    _state(State::STATIC),
    _dir(Dir::SOUTH),
    _rotFuncMap(Dir::LAST, 0)
{
  this->_rotFuncMap[Dir::NORTH] = &APlayer::NORTHFunction;
  this->_rotFuncMap[Dir::SOUTH] = &APlayer::SOUTHFunction;
  this->_rotFuncMap[Dir::WEST] = &APlayer::WESTFunction;
  this->_rotFuncMap[Dir::EAST] = &APlayer::EASTFunction;
  this->_pos._scale = 2.0f;
  this->setPos(1, 1);
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

  refModel[Skin::NORMAL] = "models/marvin.fbx";
  this->_model = gdl::Model::load(refModel[this->_skin]);
}

void		APlayer::draw(void)
{
  glPushMatrix();
  glTranslatef(this->_pos._pos.x, this->_pos._pos.y, this->_pos._pos.z);
  (this->*_rotFuncMap[this->_dir])();
  glScalef(0.005f, 0.005f, 0.005f);
  this->_model.draw();
  glPopMatrix();
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
  this->_dir = Dir::NORTH;
  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y - 1))
    this->_pos.setPos(this->_pos._x, this->_pos._y - 1);
}

void		APlayer::LEFTFunction()
{
  this->_dir = Dir::WEST;
  if (this->_map.canMoveAt(this->_pos._x - 1, this->_pos._y))
    this->_pos.setPos(this->_pos._x - 1, this->_pos._y);
}

void		APlayer::RIGHTFunction()
{
  this->_dir = Dir::EAST;
  if (this->_map.canMoveAt(this->_pos._x + 1, this->_pos._y))
    this->_pos.setPos(this->_pos._x + 1, this->_pos._y);
}

void		APlayer::DOWNFunction()
{
  this->_dir = Dir::SOUTH;
  if (this->_map.canMoveAt(this->_pos._x, this->_pos._y + 1))
    this->_pos.setPos(this->_pos._x, this->_pos._y + 1);
}

void		APlayer::ATTACKFunction()
{


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
