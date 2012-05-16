/*
 * lemonn_v
 * 07.05.12
 */

#include <iostream>
#include <GL/gl.h>
#include "Map.hpp"
#include "Human.hpp"
#include "Menu.hpp"

Menu::Menu()
  : _game(0),
    _menu(600, 800)
{
  this->setContentRoot("./Ressources/");
}

Menu::~Menu()
{
}

void		Menu::initialize(void)
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
  Map*	map = new Map(20, 20, 2, 100);
  std::vector<APlayer*>	players;
  Config player1_conf;
  players.push_back(new Human(*map, player1_conf));
  map->setOptimization(&players[0]->getPos());
  Match*	m = new Match(map, false, GameMode::ARCADE, players);
  this->_game = new MyGame(this->gameClock_, this->input_, *m, players[0]); // TODO
  this->_game->initialize();
}

void		Menu::update(void)
{
  if (this->_game)
    {
      this->_menu.run();
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

void		Menu::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  if (this->_game)
    this->_game->draw();
  this->window_.display();
}

void		Menu::unload(void)
{
  this->window_.close();
}

