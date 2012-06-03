/*
 * Fiahil
 * 03.06.2012
 */

#include "JsManager.hpp"

JsManager*	JsManager::_me = 0;

JsManager::JsManager()
{
  this->_tr[gdl::Keys::W] = JsInput::UP;
  this->_tr[gdl::Keys::A] = JsInput::LEFT;
  this->_tr[gdl::Keys::S] = JsInput::DOWN;
  this->_tr[gdl::Keys::D] = JsInput::RIGHT;
  this->_tr[gdl::Keys::E] = JsInput::B;
  this->_tr[gdl::Keys::Space] = JsInput::A;
  this->_tr[gdl::Keys::Escape] = JsInput::START;

  this->_kf[gdl::Keys::W] = &JsManager::kUp;
  this->_kf[gdl::Keys::A] = &JsManager::kLeft;
  this->_kf[gdl::Keys::S] = &JsManager::kDown;
  this->_kf[gdl::Keys::D] = &JsManager::kRight;
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

bool		JsManager::kLeft(void) const
{
  return sf::Joystick::getAxisPosition(1, sf::Joystick::PovX) < 0 ||
    sf::Joystick::getAxisPosition(1, sf::Joystick::X) < -50;
}

bool		JsManager::kRight(void) const
{
  return sf::Joystick::getAxisPosition(1, sf::Joystick::PovX) > 0 ||
    sf::Joystick::getAxisPosition(1, sf::Joystick::X) > 50;
}

bool		JsManager::kUp(void) const
{
  return sf::Joystick::getAxisPosition(1, sf::Joystick::PovY) < 0 ||
    sf::Joystick::getAxisPosition(1, sf::Joystick::Y) < -50;
}

bool		JsManager::kDown(void) const
{
  return sf::Joystick::getAxisPosition(1, sf::Joystick::PovY) > 0 ||
    sf::Joystick::getAxisPosition(1, sf::Joystick::Y) > 50;
}

bool		JsManager::isJsDown(size_t, gdl::Keys::Key k) const
{
  std::map<gdl::Keys::Key, JsInput::eButton>::const_iterator it = this->_tr.find(k);
  if (sf::Joystick::isConnected(1) && it != this->_tr.end() &&
      k != gdl::Keys::W && k != gdl::Keys::A && k != gdl::Keys::S && k != gdl::Keys::D)
    return sf::Joystick::isButtonPressed(1, it->second);
  else if (k == gdl::Keys::W ||
      k == gdl::Keys::A ||
      k == gdl::Keys::S ||
      k == gdl::Keys::D)
    return (this->*(this->_kf.find(k)->second))();
  return false;
}
