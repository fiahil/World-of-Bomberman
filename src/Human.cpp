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


Human::Human(Map & map, const Config& conf)//, std::vector<size_t>&, std::vector<size_t> const&)
  : APlayer(map), _mode(Input::GAME)
{
  this->_event[Input::GAME]._freq = 2; // TODO TMP
  this->_event[Input::GAME]._nb = 5;
  this->_event[Input::GAME].
    _event.push_back(initStruct(conf.getConfig(HumGame::UP),
				HumGame::UP, &Human::UPFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(conf.getConfig(HumGame::DOWN),
				HumGame::DOWN, &Human::DOWNFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(conf.getConfig(HumGame::LEFT),
				HumGame::LEFT, &Human::LEFTFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(conf.getConfig(HumGame::RIGHT),
				HumGame::RIGHT, &Human::RIGHTFunction));
  this->_event[Input::GAME].
    _event.push_back(initStruct(conf.getConfig(HumGame::ATTACK),
				HumGame::ATTACK, &Human::ATTACKFunction));
  // TODO implement other mode
}

Human::~Human() {

}

void Human::play(gdl::GameClock const& clock, gdl::Input& key)
{
  // for each ?

  for (size_t i = 0; i < this->_event[this->_mode]._nb; ++i) {
    if (key.isKeyDown(this->_event[this->_mode]._event[i]._key))
      (this->*(_event[this->_mode]._event[i]._f))(clock);
  }
}
