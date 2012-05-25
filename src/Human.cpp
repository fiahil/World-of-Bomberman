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
    _skillUp(true),
    _skillTimer(-1.0f),
    _skill(Skill::JUMP),
    _skillFunc(Skill::LAST, 0),
    _HUD(HUD::LAST, 0),
    _bombAff(BombType::LAST, 0),
    _jumpDir(Dir::LAST, 0)
{
  this->_event[Input::GAME]._freq = 2; // TODO TMP
  this->_event[Input::GAME]._nb = 7;
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
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Escape,
				HumGame::PAUSE, &Human::PAUSEFunction)); // TODO
  this->_event[Input::GAME].
    _event.push_back(initStruct(gdl::Keys::Return,
				HumGame::CHEAT, static_cast<actionFunc>(&Human::SkillFunction))); // TODO

  this->_bombAff[BombType::NORMAL] = &Human::affNormalBomb;
  this->_bombAff[BombType::BIGBOMB] = &Human::affBigBomb;
  this->_bombAff[BombType::MEGABOMB] = &Human::affMegaBomb;

  this->_skillFunc[Skill::HALLU] = &Human::halluSkill;
  this->_skillFunc[Skill::HEAL] = &Human::healSkill;
  this->_skillFunc[Skill::BERSERK] = &Human::berserkSkill;
  this->_skillFunc[Skill::JUMP] = &Human::jumpSkill;

  this->_jumpDir[Dir::NORTH] = &Human::northJumpFunction;
  this->_jumpDir[Dir::SOUTH] = &Human::southJumpFunction;
  this->_jumpDir[Dir::WEST] = &Human::westJumpFunction;
  this->_jumpDir[Dir::EAST] = &Human::eastJumpFunction;
 // TODO implement other mode
}

Human::~Human() {

}

void Human::SkillFunction(gdl::GameClock const& clock)
{
  (this->*(this->_skillFunc[this->_skill]))(clock);
}

void Human::play(gdl::GameClock const& clock, gdl::Input& key)
{
  // for each ?

  if ((static_cast<double>(clock.getTotalGameTime())) >=
      this->_skillTimer)
    this->_skillUp = true;
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

void Human::drawEnd(size_t h, size_t lag, bool EOG)
{
  this->_text.setSize(40);
  if (!this->_pv)
    {
      this->_text.setText("You Lose !");
      this->_text.setPosition(lag + 90, h / 2);
      this->_text.draw();
    }
  else if (EOG)
    {
      this->_text.setText("You Win !");
      this->_text.setPosition(lag + 90, h / 2);
      this->_text.draw();
    }
}

void Human::affNormalBomb()
{
  if (this->_canAttack)
    this->_HUD[HUD::BOMB_OK]->draw();
  else
    this->_HUD[HUD::BOMB_KO]->draw();
}

void  Human::affBigBomb()
{
  if (this->_canAttack)
    this->_HUD[HUD::BIGBOMB_OK]->draw();
  else
    this->_HUD[HUD::BIGBOMB_KO]->draw();
}

void  Human::affMegaBomb() // TODO const ?
{
  if (this->_canAttack)
    this->_HUD[HUD::MEGABOMB_OK]->draw();
  else
    this->_HUD[HUD::MEGABOMB_KO]->draw();
}

void Human::halluSkill(gdl::GameClock const&)
{
}

void  Human::healSkill(gdl::GameClock const& clock)
{
  double current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_skillTimer)
    {
      this->_skillTimer = current + 60.0;
      this->lifeBonusEffect();
      this->ShieldBonusEffect();
      this->_skillUp = false;
    }
}

void  Human::berserkSkill(gdl::GameClock const& clock)
{
  double current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_skillTimer)
    {
      this->_skillTimer = current + 120.0;
      this->LustBonusEffect();
      this->LustBonusEffect();
      this->PowerBonusEffect();
      this->PowerBonusEffect();
      this->ShieldBonusEffect();
      this->_skillUp = false;
    }
}

bool	Human::northJumpFunction()
{
  return true;
}

bool	Human::southJumpFunction()
{
  return true;
}

bool	Human::westJumpFunction()
{
  return true;
}

bool	Human::eastJumpFunction()
{
  return true;
}

#include <iostream>

void  Human::jumpSkill(gdl::GameClock const& clock)
{
  double current;

  if ((current = static_cast<double>(clock.getTotalGameTime())) >=
      this->_skillTimer)
    if ((this->*(this->_jumpDir[this->_dir]))())
      {
	this->_skillUp = false;
	this->_skillTimer = current + 60.0;
      }
}

void Human::drawHUD(std::vector<gdl::Image>& img, size_t hi, size_t lag, bool EOG) {

  std::stringstream ss;

  if (!this->_HUD[0])
    {
      this->_HUD[HUD::LIFE_BAR] = new Surface(310.0f, 40.0f, 10.0f, 10.0f, img[HUD::LIFE_BAR]);
      this->_HUD[HUD::SHIELD] = new Surface(40.0f, 40.0f, 30.0f, 60.0f, img[HUD::SHIELD]);
      this->_HUD[HUD::LUST] = new Surface(40.0f, 40.0f, 80.0f, 60.0f, img[HUD::LUST]);
      this->_HUD[HUD::POWER] = new Surface(40.0f, 40.0f, 130.0f, 60.0f, img[HUD::POWER]);

      this->_HUD[HUD::SKILL_OK] =
	new Surface(50.0f, 50.0f, 90.0f, hi - 60.0f, img[HUD::SKILL_OK]);
      this->_HUD[HUD::SKILL_KO] =
	new Surface(50.0f, 50.0f, 90.0f, hi - 60.0f, img[HUD::SKILL_KO]);

      this->_HUD[HUD::BOMB_OK] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BOMB_OK]);
      this->_HUD[HUD::BOMB_KO] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BOMB_KO]);

      this->_HUD[HUD::BIGBOMB_OK] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BIGBOMB_OK]);
      this->_HUD[HUD::BIGBOMB_KO] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::BIGBOMB_KO]);
      this->_HUD[HUD::MEGABOMB_OK] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::MEGABOMB_OK]);
      this->_HUD[HUD::MEGABOMB_KO] =
	new Surface(70.0f, 70.0f, 10.0f, hi - 80.0f, img[HUD::MEGABOMB_KO]);
    }
  this->_HUD[HUD::LIFE_BAR]->draw();

  double	size = (this->_pv / 100.0f * 250.0f);

  (this->*(this->_bombAff[this->_weapon]))();

  if (this->_skillUp)
    this->_HUD[HUD::SKILL_OK]->draw();
  else
    this->_HUD[HUD::SKILL_KO]->draw();

  if (size > 250.0f)
    size = 250.0f;
  Surface pvIndic(size, 20.0f, 40.0f, 20.0f, img[HUD::LIFE]);
  pvIndic.draw();

  if (this->_shield)
    this->_HUD[HUD::SHIELD]->draw();
  if (this->_lustStack)
    this->_HUD[HUD::LUST]->draw();
  if (this->_powerStack)
    this->_HUD[HUD::POWER]->draw();

  this->_text.setSize(30);
  if (this->_lustStack)
    {
      ss << this->_lustStack;
      this->_text.setText(ss.str());
      ss.str("");
      ss.clear();
      this->_text.setPosition(85 + lag, 65);
      this->_text.draw();
    }

  if (this->_powerStack)
    {
      ss << this->_powerStack;
      this->_text.setText(ss.str());
      ss.str("");
      ss.clear();
      this->_text.setPosition(135 + lag, 65);
      this->_text.draw();
    }

  ss << this->_pv << "%";
  this->_text.setText(ss.str());
  ss.str("");
  ss.clear();
  this->_text.setSize(18);
  this->_text.setPosition(45 + lag, 18);
  this->_text.draw();

  // TODO nb kill
  this->_text.setSize(30);
  ss << this->_nbKills;
  this->_text.setText(ss.str());
  this->_text.setPosition(10.0f + lag, hi - 120.0f);
  this->_text.draw();
  this->_text.setSize(10);
  this->_text.setText("kills");
  this->_text.setPosition(55.0f + lag, hi - 100.0f);
  this->_text.draw();
  this->drawStart(hi, lag);
  this->drawEnd(hi, lag, EOG);
}
