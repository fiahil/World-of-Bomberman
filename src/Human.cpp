/*
 * Fiahil
 * 12.05.2012
 */

#include "Human.hpp"

Human::eventSt Human::initStruct(gdl::Keys::Key key, HumGame::eAction action, actionFunc f) const
{
  Human::eventSt nwEl = { key, action, f };
  return nwEl;
}


Human::Human(Map & map)//, const Config&, std::vector<size_t>&, std::vector<size_t> const&)
  : APlayer(map), _mode(Input::GAME)
{
  this->_event[Input::GAME]._freq = 2; // TODO TMP
  this->_event[Input::GAME]._nb = 5;
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Up, HumGame::UP, &Human::UPFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Down, HumGame::DOWN, &Human::DOWNFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Left, HumGame::LEFT, &Human::LEFTFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Right, HumGame::RIGHT, &Human::DOWNFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Space, HumGame::ATTACK, &Human::ATTACKFunction));
  // TODO implement other mode
}

Human::~Human() {

}

void Human::play(gdl::GameClock const&, gdl::Input& key)
{
  for (size_t i = 0; i < this->_event[this->_mode]._nb; ++i) {
    if (key.isKeyDown(this->_event[this->_mode]._event[i]._key)) {
      (this->*(_event[this->_mode]._event[i]._f))();
    }
  }
}
