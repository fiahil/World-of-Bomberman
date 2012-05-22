 /*
 * Fiahil
 * 12.05.2012
 */

#include <sstream>
#include "Human.hpp"

Human::eventSt Human::initStruct(gdl::Keys::Key key, HumGame::eAction action, actionFunc f) const
{
  Human::eventSt nwEl = { key, action, f };
  return nwEl;
}


Human::Human(Map & map, const Config& conf)//, std::vector<size_t>&, std::vector<size_t> const&)
  : APlayer(map),
    _mode(Input::GAME),
    _start(4),
    _startTimer(-1.0f),
    _text("Ressources/Police/DejaVuSansMono.ttf"),
    _HUD(HUD::LAST, 0)
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

#include <iostream>

void Human::play(gdl::GameClock const& clock, gdl::Input& key)
{
  // for each ?

  if (this->_start >= 0 && clock.getTotalGameTime() >= this->_startTimer)
    {
      --this->_start;
      this->_startTimer = clock.getTotalGameTime() + 1.0f;
    }
  else if (this->_start < 0)
    for (size_t i = 0; i < this->_event[this->_mode]._nb; ++i) {
      if (key.isKeyDown(this->_event[this->_mode]._event[i]._key))
	(this->*(_event[this->_mode]._event[i]._f))(clock);
    }
}

void Human::drawStart(size_t h, size_t lag)
{
  std::stringstream	ss;
  
  this->_text.setSize(70);
  if (this->_start > 0)
    {
      ss << this->_start;
      this->_text.setText(ss.str());
      this->_text.setPosition(lag + 160, h / 2);
      this->_text.draw();
    }
  else if (!this->_start)
    {
      this->_text.setText("Start");
      this->_text.setPosition(lag + 90, h / 2);
      this->_text.draw();
    }
}

void Human::drawEnd(size_t h, size_t lag)
{
  this->_text.setSize(70);
  if (this->_pv)
    {
      this->_text.setText("You Win !");
      this->_text.setPosition(lag + 90, h / 2);
      this->_text.draw();
    }
  else
    {
      this->_text.setText("You Loose !");
      this->_text.setPosition(lag + 90, h / 2);
      this->_text.draw();
    }
}

void Human::drawHUD(std::vector<gdl::Image>& img, size_t hi, size_t lag, bool EOG)
{
  std::stringstream ss;

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

  double	size = (this->_pv / 100.0f * 250.0f);
  
  if (size > 250.0f)
    size = 250.0f;
  Surface pvIndic(size, 20.0f, 40.0f, 20.0f, img[HUD::LAST]);
  pvIndic.draw();

  // TODO si buff
  if (this->_shield)
    this->_HUD[HUD::SHIELD]->draw();
  // TODO si buff
  if (this->_lustStack)
    this->_HUD[HUD::LUST]->draw();
  // TODO si buff
  if (this->_powerStack)
    this->_HUD[HUD::POWER]->draw();
  
  if (this->_canAttack)
    this->_HUD[HUD::BOMB_OK]->draw();
  else
    this->_HUD[HUD::BOMB_KO]->draw();
  
  this->_text.setSize(30);
  // TODO si buff
  if (this->_lustStack)
    {
      ss << this->_lustStack;
      this->_text.setText(ss.str());
      ss.str("");
      ss.clear();
      this->_text.setPosition(85 + lag, 65);
      this->_text.draw();
    }

  // TODO si buff
  if (this->_powerStack)
    {
      ss << this->_powerStack;
      this->_text.setText(ss.str());
      ss.str("");
      ss.clear();
      this->_text.setPosition(135 + lag, 65);
      this->_text.draw();
    }

  // TODO nb kill
  this->_text.setText("10");
  this->_text.setPosition(10.0f + lag, hi - 120.0f);
  this->_text.draw();
  this->_text.setSize(10);
  this->_text.setText("kill");
  this->_text.setPosition(55.0f + lag, hi - 100.0f);
  this->_text.draw();
  this->drawStart(hi, lag);
  if (EOG)
    this->drawEnd(hi, lag);
}
