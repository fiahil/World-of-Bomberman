/***********************************************************************
 * Module:  Menu.cpp
 * Author:  lemonn_v
 * Modified: Monday, May 07, 2012 6:23:48 PM
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#include <GL/gl.h>
#include "Menu.hpp"

Menu::Menu() : _game(0)
{
  this->setContentRoot("./Ressources");
}

Menu::~Menu()
{

}

void	Menu::initialize()
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
  this->_game = new MyGame(this->gameClock_, this->input_);
  this->_game->initialize();
}

void	Menu::update()
{
  if (this->_game)
    {
      if (this->_game->isEOG())
	{
	  this->_game->unload();
	  delete this->_game;
	  this->_game = 0;
	}
      else
	this->_game->update();
    }
}

void	Menu::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  
  if (this->_game)
    this->_game->draw();
  this->window_.display();
}

void	Menu::unload()
{
  this->window_.close();
}

