//
// MyGame.cpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon Apr 23 18:10:08 2012 vincent lemonnier
// Last update Thu May 10 22:11:32 2012 vincent lemonnier
//

#include <GL/gl.h>
#include "Camera.hpp"
#include "MyGame.hpp"

MyGame::MyGame() : _camera(800, 600)
{

}

MyGame::~MyGame()
{

}

void	MyGame::initialize()
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
  this->_camera.initialize();
  this->_test = gdl::Model::load("cube.fbx");
}

void	MyGame::update()
{
  this->_camera.update(this->gameClock_, this->input_);
  this->_test.update(this->gameClock_);
}

void	MyGame::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);

  this->_test.draw();
  this->window_.display();
}

void	MyGame::unload()
{
  this->window_.close();
}
