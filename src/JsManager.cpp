/*
 * Fiahil
 * 03.06.2012
 */

#include "JsManager.hpp"

JsManager*	JsManager::_me = 0;

JsManager::JsManager()
{
  this->_tr[gdl::Keys::W] = JsInput::START; //TODO
  this->_tr[gdl::Keys::A] = JsInput::START; //TODO
  this->_tr[gdl::Keys::S] = JsInput::START; //TODO
  this->_tr[gdl::Keys::D] = JsInput::START; //TODO
  this->_tr[gdl::Keys::E] = JsInput::B;
  this->_tr[gdl::Keys::Space] = JsInput::A;
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

bool		JsManager::isJsDown(size_t, gdl::Keys::Key k) const
{
  std::map<gdl::Keys::Key, JsInput::eButton>::const_iterator it = this->_tr.find(k);
  if (sf::Joystick::isConnected(1) && it != this->_tr.end())
    return sf::Joystick::isButtonPressed(1, it->second);
  return false;
}
