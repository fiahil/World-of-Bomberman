/***********************************************************************
 * Module:  GamePlay.cpp
 * Author:  Fiahil
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class GamePlay
 ***********************************************************************/

#include <GL/gl.h>
#include <iostream>
#include "GamePlay.hpp"

GamePlay::GamePlay() : _camera(800, 600), _map(20, 20, 1, 2)
{
  this->setContentRoot("./Ressources");
}

GamePlay::~GamePlay()
{

}

void	GamePlay::initialize()
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
  this->_camera.initialize();
  this->_map.initialize();
 }

void	GamePlay::update()
{
   this->_camera.update(this->gameClock_, this->input_);
   this->_map.update(this->gameClock_, this->input_);
}

void	GamePlay::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  this->_map.draw();
  this->window_.display();
}

void	GamePlay::unload()
{
   this->window_.close();
}
