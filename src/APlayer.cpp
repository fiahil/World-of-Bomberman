/***********************************************************************
 * Module:  APlayer.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:17 PM
 * Purpose: Implementation of the class APlayer
 ***********************************************************************/

#include "APlayer.h"

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::takeDamage(Point origin, Pattern pattern)
// Purpose:    Implementation of APlayer::takeDamage()
// Parameters:
// - origin
// - pattern
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::takeDamage(Point origin, Pattern pattern)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::initialize()
// Purpose:    Implementation of APlayer::initialize()
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::initialize(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::draw(gdl::GameClock const& clock, gdl::Input& input)
// Purpose:    Implementation of APlayer::draw()
// Parameters:
// - clock
// - input
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::draw(gdl::GameClock const& clock, gdl::Input& input)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::update()
// Purpose:    Implementation of APlayer::update()
// Return:     void
////////////////////////////////////////////////////////////////////////

void APlayer::update(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       APlayer::APlayer(std::string const& name)
// Purpose:    Implementation of APlayer::APlayer()
// Parameters:
// - name
// Return:     
////////////////////////////////////////////////////////////////////////

APlayer::APlayer(std::string const& name)
{
   // TODO : implement
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

APlayer::APlayer(const APlayer& oldAPlayer)
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
}