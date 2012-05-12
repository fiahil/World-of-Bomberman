//
// MyGame.cpp for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Mon Apr 23 18:10:08 2012 vincent lemonnier
// Last update Mon May  7 10:51:23 2012 benjamin businaro
//

#include <unistd.h>
#include <iostream>
/* TODO erase */
#include <stdlib.h>
/* TODO */
#include "MyGame.hpp"

void MyGame::UPFunction() {
  std::cout << "I go up !!" << std::endl;
}

void MyGame::LEFTFunction() {
  std::cout << "I go left !!" << std::endl;
}

void MyGame::RIGHTFunction() {
  std::cout << "I go right !!" << std::endl;
}

void MyGame::DOWNFunction() {
  std::cout << "I go down !!" << std::endl;
}

void MyGame::ATTACKFunction() {
  std::cout << "I Attack !!" << std::endl;
}

void MyGame::QUITFunction() {
  std::cout << "-- QUIT --" << std::endl;
  /* TODO moche */ exit (1); /* TODO */
}

void MyGame::PAUSEFunction() {
  std::cout << "-- PAUSE ---" << std::endl;
}

void MyGame::SELECTFunction() {
  std::cout << "-- SELECT --" << std::endl;
}

MyGame::eventSt	MyGame::initStruct(gdl::Keys::Key key, Action action, actionFunc f) const
{
 MyGame::eventSt nwEl = { key, action, f };
 return nwEl;
}

MyGame::MyGame() : _mode(MENU)
{
  this->_event[MENU]._freq = 2;
  this->_event[MENU]._nb = 5;
  this->_event[MENU].
    _event.push_back(initStruct(gdl::Keys::Up, UP, &MyGame::UPFunction));
  this->_event[MENU].
    _event.push_back(initStruct(gdl::Keys::Down, DOWN, &MyGame::DOWNFunction));
  this->_event[MENU].
    _event.push_back(initStruct(gdl::Keys::Left, LEFT, &MyGame::LEFTFunction));
  this->_event[MENU].
    _event.push_back(initStruct(gdl::Keys::Right, RIGHT, &MyGame::DOWNFunction));
  this->_event[MENU].
    _event.push_back(initStruct(gdl::Keys::Return, SELECT, &MyGame::SELECTFunction));
}

MyGame::~MyGame()
{

}

void	MyGame::initialize()
{
  this->window_.setTitle("Bomberman v1.0");
  this->window_.create();
}

void	MyGame::update()
{
  // TODO : OLD
  // gdl::Input key(this->window_);

  // for (int i = 0; i < MyGame::CountGA; ++i) {
  //   mapGA::iterator it = this->_eventSet.find((MyGame::GameAction)i);
  //   if (it != this->_eventSet.end()) {
  //     if (key.isKeyDown(it->second.first)) {
  // 	std::cout << ".:: A key was pressed ::." << std::endl;
  // 	(this->*(it->second.second))();
  //     }
  //   }
  //   usleep(10000);
  // }

  // TODO : Ici le mode (MENU) est en dur mais aspire a etre dans la classe
  gdl::Input key(this->window_);

  for (size_t i = 0; i < this->_event[this->_mode]._nb; ++i) {
      if (key.isKeyDown(this->_event[this->_mode]._event[i]._key)) {
  	std::cout << ".:: A key was pressed ::." << std::endl;
  	(this->*(_event[this->_mode]._event[i]._f))();
      }
    usleep(10000 * this->_event[MENU]._freq);
  }

}

void	MyGame::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->window_.display();
}

void	MyGame::unload()
{
  this->window_.close();
}
