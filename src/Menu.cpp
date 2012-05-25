/*
 * lemonn_v
 * 07.05.12
 */

#include <iostream>
#include <GL/gl.h>
#include "Map.hpp"
#include "Human.hpp"
#include "AI.hpp"
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
  this->window_.setHeight(800);
  this->window_.setWidth(1600);
  this->window_.create();
  Map*	map = new Map(100, 100, 1, 5);
  std::vector<APlayer*>	players;
  Config conf;
  APlayer *newHum1 = new Human(*map, conf);
  newHum1->setSkin(Skin::THRALL);
  newHum1->setTeamId(6);
  players.push_back(newHum1);
  conf.setConfig(HumGame::UP, gdl::Keys::W);
  conf.setConfig(HumGame::LEFT, gdl::Keys::A);
  conf.setConfig(HumGame::DOWN, gdl::Keys::S);
  conf.setConfig(HumGame::RIGHT, gdl::Keys::D);
  conf.setConfig(HumGame::ATTACK, gdl::Keys::R);
  /*APlayer *newHum2 = new Human(*map, conf);
  newHum2->setColor(6);
  newHum2->setTeamId(6);
  newHum2->setSkin(Skin::VARIANT);
  players.push_back(newHum2);*/
  APlayer *newAI = new AI(AIType::EASY, *map);
  newAI->setColor(7);
  newAI->setTeamId(7);
  players.push_back(newAI);
  Match*	m = new Match(map, false, GameMode::SOLO, players);
  this->_game = new MyGame(this->gameClock_, this->input_, *m, players[0], 0); // TODO
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

