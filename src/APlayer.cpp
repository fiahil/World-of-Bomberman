/***********************************************************************
 * Module:  APlayer.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:17 PM
 * Purpose: Implementation of the class APlayer
 ***********************************************************************/

#include "APlayer.hpp"

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::takeDamage(Point origin, Pattern pattern)
// Purpose:    Implementation of APlayer::takeDamage()
// Parameters:
// - origin
// - pattern
// Return:     void
////////////////////////////////////////////////////////////////////////

/*void APlayer::takeDamage(Point origin, Pattern pattern)
{
   // TODO : implement
   }*/

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::initialize()
// Purpose:    Implementation of APlayer::initialize()
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::initialize(void)
{
  std::vector<std::string>	refModel(Skin::LAST, "");
  
  refModel[Skin::NORMAL] = "models/player.fbx";
  this->_model = gdl::Model::load(refModel[this->_skin]);
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::draw()
// Purpose:    Implementation of APlayer::draw()
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::draw(void)
{
  this->_model.draw();
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::update(gdl::GameClock const& clock, gdl::Input& input)
// Purpose:    Implementation of APlayer::update()
// Parameters:
// - clock
// - input
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::update(gdl::GameClock const& clock, gdl::Input& input)
{
  this->play(clock, input);
  this->_model.update(clock);
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::APlayer(std::string const& name)
// Purpose:    Implementation of APlayer::APlayer()
  

// Parameters:
// - name
// Return:     
////////////////////////////////////////////////////////////////////////

APlayer::APlayer()
  : _pv(100), _weapon(Bomb::NORMAL), _skin(Skin::NORMAL),
    _team(0), _id(0), _state(State::STATIC), _dir(Dir::EAST), _name("")
{
 
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::~APlayer()
// Purpose:    Implementation of APlayer::~APlayer()
// Return:     
////////////////////////////////////////////////////////////////////////

APlayer::~APlayer()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::APlayer(const APlayer& oldAPlayer)
// Purpose:    Implementation of APlayer::APlayer()
// Parameters:
// - oldAPlayer
// Return:     
////////////////////////////////////////////////////////////////////////

/*APlayer::APlayer(const APlayer& oldAPlayer)
{
   _pv = oldAPlayer._pv;
   _weapon = oldAPlayer._weapon;
   _skin = oldAPlayer._skin;
   _team = oldAPlayer._team;
   _id = oldAPlayer._id;
   _state = oldAPlayer._state;
   _bombEffect = oldAPlayer._bombEffect;
   _bonusEffect = oldAPlayer._bonusEffect;
   _model = oldAPlayer._model;
   _name = oldAPlayer._name;
   }*/

void	APlayer::setPv(int pv)
{
  this->_pv = pv;
}

int	APlayer::getPv() const
{
  return this->_pv;
}

void	APlayer::setWeapon(Bomb::eBomb weapon)
{
  this->_weapon = weapon;
}

Bomb::eBomb	APlayer::getWeapon() const
{
  return this->_weapon;
}

void	APlayer::setTeam(size_t team)
{
  this->_team = team;
}

size_t	APlayer::getTeam() const
{
  return this->_team;
}

void	APlayer::setId(size_t id)
{
  this->_id = id;
}

size_t	APlayer::getId() const
{
  return this->_id;
}

void	APlayer::setState(State::eState state)
{
  this->_state = state;
}

State::eState	APlayer::getState() const
{
  return this->_state;
}

void	APlayer::setDir(Dir::eDir dir)
{
  this->_dir = dir;
}

Dir::eDir	APlayer::getDir() const
{
  return this->_dir;
}

void	APlayer::setName(std::string const& name)
{
  this->_name = name;
}

std::string const&	APlayer::getName() const
{
  return this->_name;
}
