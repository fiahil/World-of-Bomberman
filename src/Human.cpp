 /*
 * Fiahil
 * 12.05.2012
 */

#include <sstream>
#include "Text.hpp"
#include "Human.hpp"

Human::eventSt Human::initStruct(gdl::Keys::Key key, HumGame::eAction action, actionFunc f) const
{
  Human::eventSt nwEl = { key, action, f };
  return nwEl;
}


Human::Human(Map & map, const Config& conf)//, std::vector<size_t>&, std::vector<size_t> const&)
  : APlayer(map), _mode(Input::GAME), _HUD(HUD::LAST, 0)
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

void Human::drawHUD(std::vector<gdl::Image>& img, size_t hi, size_t lag)
{
  std::stringstream ss;

  gdl::Text text("Ressources/Police/DejaVuSansMono.ttf");
  if (!this->_HUD[0])
    {
      this->_HUD[HUD::LIFE_BAR] = new Surface(310.0f, 40.0f, 10.0f, 10.0f, img[HUD::LIFE_BAR]);
      this->_HUD[HUD::SHIELD] = new Surface(40.0f, 40.0f, 30.0f, 60.0f, img[HUD::SHIELD]);
      this->_HUD[HUD::LUST] = new Surface(40.0f, 40.0f, 80.0f, 60.0f, img[HUD::LUST]);
      this->_HUD[HUD::POWER] = new Surface(40.0f, 40.0f, 130.0f, 60.0f, img[HUD::POWER]);
      this->_HUD[HUD::BOMB_OK] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BOMB_OK]);
      this->_HUD[HUD::BOMB_KO] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BOMB_KO]);
    }
  this->_HUD[HUD::LIFE_BAR]->draw();

  Surface pvIndic((this->_pv / 100.0f * 250.0f), 20.0f, 40.0f, 20.0f, img[HUD::LAST]);
  pvIndic.draw();

  // TODO si buff
  this->_HUD[HUD::SHIELD]->draw();
  // TODO si buff
  this->_HUD[HUD::LUST]->draw();
  // TODO si buff
  this->_HUD[HUD::POWER]->draw();

  if (this->_canAttack)
    this->_HUD[HUD::BOMB_OK]->draw();
  else
    this->_HUD[HUD::BOMB_KO]->draw();

  text.setSize(30);
  // TODO si buff
  text.setText("3");
  text.setPosition(85 + lag, 65);
  text.draw();
  // TODO si buff
  text.setText("2");
  text.setPosition(135 + lag, 65);
  text.draw();
  text.setText("10");
  text.setPosition(10.0f + lag, hi - 120.0f);
  text.draw();
  text.setSize(10);
  text.setText("kill");
  text.setPosition(55.0f + lag, hi - 100.0f);
  text.draw();
}
