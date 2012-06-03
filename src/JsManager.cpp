/*
 * Fiahil
 * 03.06.2012
 */

#include "JsManager.hpp"

JsManager*	JsManager::_me = 0;

JsManager::JsManager()
  : _cf(JsMode::LAST, 0)
{
  this->_current = JsMode::P1;
  this->_p1m[gdl::Keys::W] = std::make_pair(JsInput::UP, &JsManager::kUp);
  this->_p1m[gdl::Keys::A] = std::make_pair(JsInput::LEFT, &JsManager::kLeft);
  this->_p1m[gdl::Keys::S] = std::make_pair(JsInput::DOWN, &JsManager::kDown);
  this->_p1m[gdl::Keys::D] = std::make_pair(JsInput::RIGHT, &JsManager::kRight);
  this->_p1b[gdl::Keys::E] = JsInput::B;
  this->_p1b[gdl::Keys::Space] = JsInput::A;
  this->_p1b[gdl::Keys::Escape] = JsInput::START;

  this->_p2m[gdl::Keys::Up] = std::make_pair(JsInput::UP, &JsManager::kUp);
  this->_p2m[gdl::Keys::Left] = std::make_pair(JsInput::LEFT, &JsManager::kLeft);
  this->_p2m[gdl::Keys::Down] = std::make_pair(JsInput::DOWN, &JsManager::kDown);
  this->_p2m[gdl::Keys::Right] = std::make_pair(JsInput::RIGHT, &JsManager::kRight);
  this->_p2b[gdl::Keys::RShift] = JsInput::B;
  this->_p2b[gdl::Keys::RControl] = JsInput::A;
  this->_p2b[gdl::Keys::Escape] = JsInput::START;

  this->_mnm[gdl::Keys::Up] = std::make_pair(JsInput::UP, &JsManager::kUp);
  this->_mnm[gdl::Keys::Left] = std::make_pair(JsInput::LEFT, &JsManager::kLeft);
  this->_mnm[gdl::Keys::Down] = std::make_pair(JsInput::DOWN, &JsManager::kDown);
  this->_mnm[gdl::Keys::Right] = std::make_pair(JsInput::RIGHT, &JsManager::kRight);
  this->_mnb[gdl::Keys::Return] = JsInput::A;
  this->_mnb[gdl::Keys::Escape] = JsInput::START;
  
  this->_cf.at(JsMode::P1) = &JsManager::P1;
  this->_cf.at(JsMode::P2) = &JsManager::P2;
  this->_cf.at(JsMode::MENU) = &JsManager::Menu;
}

JsManager::~JsManager()
{
}

JsManager*	JsManager::getMe(void)
{
  if (!JsManager::_me)
    JsManager::_me = new JsManager();
  return JsManager::_me;
}

void		JsManager::delMe(void)
{
  delete JsManager::_me;
  JsManager::_me = 0;
}

bool		JsManager::kLeft(JsMode::eMode mode) const
{
  return sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::PovX) < 0 ||
    sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::X) < -50;
}

bool		JsManager::kRight(JsMode::eMode mode) const
{
  return sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::PovX) > 0 ||
    sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::X) > 50;
}

bool		JsManager::kUp(JsMode::eMode mode) const
{
  return sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::PovY) < 0 ||
    sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::Y) < -50;
}

bool		JsManager::kDown(JsMode::eMode mode) const
{
  return sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::PovY) > 0 ||
    sf::Joystick::getAxisPosition(JSMODE(mode), sf::Joystick::Y) > 50;
}

bool		JsManager::P1(JsMode::eMode mode, gdl::Keys::Key k) const
{
  {
    JsButton::const_iterator it = this->_p1b.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_p1b.end())
      return sf::Joystick::isButtonPressed(JSMODE(mode), it->second) ||
	sf::Joystick::isButtonPressed(JSMODE(mode), it->second + 2);
  }

  {
    JsMotion::const_iterator it = this->_p1m.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_p1m.end())
      return (this->*(this->_p1m.find(k)->second.second))(mode);
  }
  return false;
}

bool		JsManager::P2(JsMode::eMode mode, gdl::Keys::Key k) const
{
  {
    JsButton::const_iterator it = this->_p2b.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_p2b.end())
      return sf::Joystick::isButtonPressed(JSMODE(mode), it->second) ||
	sf::Joystick::isButtonPressed(JSMODE(mode), it->second + 2);
  }

  {
    JsMotion::const_iterator it = this->_p2m.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_p2m.end())
      return (this->*(this->_p2m.find(k)->second.second))(mode);
  }
  return false;
}

bool		JsManager::Menu(JsMode::eMode mode, gdl::Keys::Key k) const
{
  {
    JsButton::const_iterator it = this->_mnb.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_mnb.end())
      return sf::Joystick::isButtonPressed(JSMODE(mode), it->second) ||
	sf::Joystick::isButtonPressed(JSMODE(mode), it->second + 2);
  }

  {
    JsMotion::const_iterator it = this->_mnm.find(k);
    if (sf::Joystick::isConnected(JSMODE(mode)) && it != this->_mnm.end())
      return (this->*(this->_mnm.find(k)->second.second))(mode);
  }
  return false;
}

bool		JsManager::isJsDown(JsMode::eMode idx, gdl::Keys::Key k) const
{
  return (this->*_cf.at(idx))(idx, k);
}

JsMode::eMode	JsManager::getCurrent()
{
  JsMode::eMode	tmp = this->_current;
  this->_current = JsMode::P2;
  return tmp;
}

void		JsManager::resetCurrent()
{
  this->_current = JsMode::P1;
}

gdl::Keys::Key	JsManager::getKey(HumGame::eAction a) const
{
  std::map<HumGame::eAction, gdl::Keys::Key>	keyMapping;

  keyMapping[HumGame::UP] = gdl::Keys::W;
  keyMapping[HumGame::LEFT] = gdl::Keys::A;
  keyMapping[HumGame::RIGHT] = gdl::Keys::D;
  keyMapping[HumGame::DOWN] = gdl::Keys::S;
  keyMapping[HumGame::ATTACK] = gdl::Keys::Space;
  keyMapping[HumGame::PAUSE] = gdl::Keys::Escape;
  keyMapping[HumGame::SKILL] = gdl::Keys::E;
  
  return keyMapping.find(a)->second;
}
