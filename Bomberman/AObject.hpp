//
// AObject.hpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon May  7 15:28:27 2012 vincent lemonnier
// Last update Mon May  7 15:36:22 2012 vincent lemonnier
//

#ifndef __AOBJECT_HPP__
#define __AOBJECT_HPP__

class AObject
{
protected:
  Vector	_pos;
  Vector	_rot;
public:
  AObject();
  AObject(Vector const&, Vector const&);
  ~AObject();
  virtual void initialize(void) = 0;
  virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void draw(void) = 0;
};

#else

class AObject;

#endif
