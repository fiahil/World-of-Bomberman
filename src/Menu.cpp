/*
 * lemonn_v
 * 07.05.12
 */

#include <GL/gl.h>
#include "Map.hpp"
#include "Human.hpp"
#include "Menu.hpp"

Menu::Menu()
  : _game(0)
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
  Map*	map = new Map(100, 100, 100, 100);
  std::vector<APlayer*>	players;
  players.push_back(new Human(*map));
  Match*	m = new Match(map, false, GameMode::ARCADE, players);
  this->_game = new MyGame(this->gameClock_, this->input_, *m);
  this->_game->initialize();
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

