//
// AObject.cpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 15:33:45 2012 vincent lemonnier
// Last update Mon May  7 15:38:04 2012 vincent lemonnier
//

#include "AObject.hpp"

AObject::AObject() : _pos(0.0f, 0.0f, 0.0f), _rot(0.0f, 0.0f, 0.0f)
{
}

AObject::AObject(Vector const& pos, Vector const& rot)
  : _pos(pos.x, pos.y, pos.z), _rot(rot.x, rot.y, rot.z)
{
}

AObject::~AObject()
{

}
