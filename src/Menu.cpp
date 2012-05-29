/*
 * lemonn_v
 * 07.05.12
 */

#include <iostream>
#include <GL/gl.h>
#include "Map.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "AIView.hpp"
#include "MainMenu.hpp"
#include "Menu.hpp"

Menu::Menu()
  : _game(0),
    _menu(0)
{
  this->setContentRoot("./Ressources/");
}

Menu::~Menu()
{
}

void		Menu::initialize(void)
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.setHeight(800);
  this->window_.setWidth(1600);
  this->window_.create();
  this->_menu = new MenuManager(1600, 800);
  this->_menu->initialize();
}

void		Menu::update(void)
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
  else if (!(this->_game = this->_menu->createGame(this->gameClock_, this->input_)))
    this->_menu->update(this->gameClock_, this->input_);
}

void		Menu::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  if (this->_game)
    this->_game->draw();
  else
    this->_menu->draw();
  this->window_.display();
}

void		Menu::unload(void)
{
  this->window_.close();
}

