/***********************************************************************
 * Module:  AObj.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Implementation of the class AObj
 ***********************************************************************/

#include "AObj.h"

////////////////////////////////////////////////////////////////////////
// Name:       AObj::AObj()
// Purpose:    Implementation of AObj::AObj()
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::AObj()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       AObj::~AObj()
// Purpose:    Implementation of AObj::~AObj()
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::~AObj()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AObj::AObj(const AObj& oldAObj)
// Purpose:    Implementation of AObj::AObj()
// Parameters:
// - oldAObj
// Return:     
////////////////////////////////////////////////////////////////////////

AObj::AObj(const AObj& oldAObj)
{
   _pos = oldAObj._pos;
}