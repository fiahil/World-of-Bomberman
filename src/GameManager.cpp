/*
 * NicoW
 * 28.05.12
 */

#include <Input.hpp>
#include "GameManager.hpp"

GameManager::GameManager(Profile * p)
  : _mainProfile(p),
    _secondProfile(0),
    _typeAI(AIType::LAST)
{
  this->_configJ1.setConfig(HumGame::UP, gdl::Keys::W);
  this->_configJ1.setConfig(HumGame::DOWN, gdl::Keys::S);
  this->_configJ1.setConfig(HumGame::LEFT, gdl::Keys::A);
  this->_configJ1.setConfig(HumGame::RIGHT, gdl::Keys::D);
  this->_configJ1.setConfig(HumGame::ATTACK, gdl::Keys::Space);
  this->_configJ1.setConfig(HumGame::SKILL, gdl::Keys::E);

  this->_configJ2.setConfig(HumGame::UP, gdl::Keys::Up);
  this->_configJ2.setConfig(HumGame::DOWN, gdl::Keys::Down);
  this->_configJ2.setConfig(HumGame::LEFT, gdl::Keys::Left);
  this->_configJ2.setConfig(HumGame::RIGHT, gdl::Keys::Right);
  this->_configJ2.setConfig(HumGame::ATTACK, gdl::Keys::RControl);
  this->_configJ2.setConfig(HumGame::SKILL, gdl::Keys::RShift);
}


