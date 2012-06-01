 /*
 * Fiahil
 * 12.05.2012
 */

#include <sstream>
#include "Human.hpp"
#include "Sound.hpp"

Human::Human(Map & map, const Config& conf, std::vector<bool>* success)
  : APlayer(map, success),
    _mode(Input::GAME),
    _start(4),
    _startTimer(-1.0f),
    _text("Ressources/Police/DejaVuSansMono.ttf"),
    _skillUp(true),
    _skillTimer(-1.0f),
    _skill(Skill::HALLU),
    _skillFunc(Skill::LAST, 0),
    _HUD(HUD::LAST, 0),
    _bombAff(BombType::LAST, 0),
    _jumpDir(Dir::LAST, 0),
    _lastSuccess(Success::LAST),
    _successTimer(-1.0f),
    _hallu(0),
    _halluLifeTimer(-1.0f)

{
  this->_event._nb = 7;
  this->_event.
    _event.push_back(initStruct(conf.getConfig(HumGame::UP),
				HumGame::UP,
				&Human::UPFunction));

  this->_event.
    _event.push_back(initStruct(conf.getConfig(HumGame::DOWN),
				HumGame::DOWN,
				&Human::DOWNFunction));

  this->_event.
    _event.push_back(initStruct(conf.getConfig(HumGame::LEFT),
				HumGame::LEFT,
				&Human::LEFTFunction));

  this->_event.
    _event.push_back(initStruct(conf.getConfig(HumGame::RIGHT),
				HumGame::RIGHT,
				&Human::RIGHTFunction));

  this->_event.
    _event.push_back(initStruct(conf.getConfig(HumGame::ATTACK),
				HumGame::ATTACK,
				&Human::ATTACKFunction));

  this->_event.
    _event.push_back(initStruct(gdl::Keys::Escape,
				HumGame::PAUSE,
				&Human::PAUSEFunction));

  this->_event.
    _event.push_back(initStruct(gdl::Keys::Return,
				HumGame::CHEAT,
				static_cast<actionFunc>(&Human::SkillFunction))); // SKILL

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

  // review simplification mode de game

}

Human::~Human() {
  if (this->_hallu)
  {
    delete this->_hallu;
    this->_hallu = 0;
  }
}

Human::eventSt	Human::initStruct(gdl::Keys::Key key,
				  HumGame::eAction action,
				  actionFunc f) const
{
  Human::eventSt	nwEl = {key, action, f};
  return nwEl;
}

void            Human::drawSuccess(Success::eSuccess s)
{
  Sound::getMe()->playBack(Audio::SUCCESS);
  this->_lastSuccess = s;
  this->_successTimer = -1.0f;
}

bool		Human::SkillFunction(gdl::GameClock const& clock)
{
  return (this->*(this->_skillFunc[this->_skill]))(clock);
}

void		Human::draw()
{
  APlayer::draw();
  if (this->_hallu)
    this->_hallu->draw();
}

void		Human::play(gdl::GameClock const& clock, gdl::Input& key)
{
  if (this->_hallu)
    {
      if (this->_halluLifeTimer <= clock.getTotalGameTime())
	{
	  delete this->_hallu;
	  this->_hallu = 0;
	  this->_halluLifeTimer = 1.0f;
	}
      else
	this->_hallu->update(clock, key);
    }

  if (this->_successTimer == -1.0f && this->_lastSuccess != Success::LAST)
    this->_successTimer = clock.getTotalGameTime() + 5.0f;
  else if (this->_successTimer <= clock.getTotalGameTime())
    this->_lastSuccess = Success::LAST;

  if (clock.getTotalGameTime() >= this->_skillTimer)
    this->_skillUp = true;
  if (this->_start >= 0 && clock.getTotalGameTime() >= this->_startTimer)
    {
      --this->_start;
      this->_startTimer = clock.getTotalGameTime() + 1.0f;
      if (!this->_start)
	Sound::getMe()->playBack(Audio::START);
      else
	Sound::getMe()->playBack(Audio::TIMER_START);
    }
  else if (this->_start < 0)
    for (size_t i = 0; i < this->_event._nb; ++i) {
      if (key.isKeyDown(this->_event._event[i]._key))
	(this->*(_event._event[i]._f))(clock);
    }
}

void		Human::drawStart(size_t h, size_t lag, size_t mode)
{
  std::stringstream	ss;

  this->_text.setSize(100);
  if (this->_start > 0)
    {
      ss << this->_start;
      this->_text.setText(ss.str());
      this->_text.setPosition(lag + 390 + mode, h / 2);
      this->_text.draw();
    }
  else if (!this->_start)
    {
      this->_text.setText("Start");
      this->_text.setPosition(lag + 260 + mode, h / 2);
      this->_text.draw();
    }
}

void		Human::drawEnd(size_t h, size_t lag, bool EOG, size_t mode)
{
  this->_text.setSize(80);
  if (!this->_pv)
    {
      if (this->_success && !this->_success->at(Success::DIE))
      	{
      	  this->_success->at(Success::DIE) = true;
      	  this->drawSuccess(Success::DIE);
      	}
      if (EOG)
	this->_text.setText("You Lose !");
      else
	this->_text.setText("You Die !");
      this->_text.setPosition(lag + 200 + mode, h / 2);
      this->_text.draw();
     }
  else if (EOG)
    {
      if (this->_nbKills >= 5 && this->_success && !this->_success->at(Success::FIVE_KILL))
      	{
      	  this->_success->at(Success::FIVE_KILL) = true;
      	  this->drawSuccess(Success::FIVE_KILL);
      	}

      if (this->_pv >= 100 && this->_success && !this->_success->at(Success::FABULOUS))
      	{
      	  this->_success->at(Success::FABULOUS) = true;
      	  this->drawSuccess(Success::FABULOUS);
      	}
      this->_text.setText("You Win !");
      this->_text.setPosition(lag + 200 + mode, h / 2);
      this->_text.draw();

    }
}

void		Human::playBonusSound()
{
      Sound::getMe()->playBack(Audio::BONUS);
}

void		Human::affNormalBomb() const
{
  if (this->_canAttack)
    this->_HUD[HUD::BOMB_OK]->draw();
  else
    this->_HUD[HUD::BOMB_KO]->draw();
}

void		Human::affBigBomb() const
{
  if (this->_canAttack)
    this->_HUD[HUD::BIGBOMB_OK]->draw();
  else
    this->_HUD[HUD::BIGBOMB_KO]->draw();
}

void		Human::affMegaBomb() const
{
  if (this->_canAttack)
    this->_HUD[HUD::MEGABOMB_OK]->draw();
  else
    this->_HUD[HUD::MEGABOMB_KO]->draw();
}

bool		Human::halluSkill(gdl::GameClock const& clock)
{
  double	current;

  if ((current = clock.getTotalGameTime()) >= this->_skillTimer)
    {
      this->_skillTimer = current + 60.0;
      this->_hallu = new AI(AIType::HALLU, this->_map);
      this->_hallu->setSkin(this->_skin);
      this->_hallu->setPos(this->_pos._x, this->_pos._y);
      this->_hallu->setTeamId(_teamId);
      this->_halluLifeTimer = current + 30.0;
      this->_hallu->initialize();
      this->_skillUp = false;
      return true;
    }
  return false;
}

bool		Human::healSkill(gdl::GameClock const& clock)
{
  double	current;

  if ((current = clock.getTotalGameTime()) >= this->_skillTimer)
    {
      this->_skillTimer = current + 60.0;
      this->lifeBonusEffect();
      this->ShieldBonusEffect();
      this->_skillUp = false;
      return true;
    }
  return false;
}

bool		Human::berserkSkill(gdl::GameClock const& clock)
{
  double	current;

  if ((current = clock.getTotalGameTime()) >= this->_skillTimer)
    {
      this->_skillTimer = current + 120.0;
      this->LustBonusEffect();
      this->LustBonusEffect();
      this->PowerBonusEffect();
      this->PowerBonusEffect();
      this->ShieldBonusEffect();
      this->_skillUp = false;
      return true;
    }
  return false;
}

bool		Human::northJumpFunction()
{
  if (this->_map.safeCanMoveAt(this->_pos._x, this->_pos._y - 2))
    {
      this->_pos.setPos(this->_pos._x, this->_pos._y - 2);
      return true;
    }
  return false;
}

bool		Human::southJumpFunction()
{
  if (this->_map.safeCanMoveAt(this->_pos._x, this->_pos._y + 2))
    {
      this->_pos.setPos(this->_pos._x, this->_pos._y + 2);
      return true;
    }
  return false;
}

bool		Human::westJumpFunction()
{
  if (this->_map.safeCanMoveAt(this->_pos._x - 2, this->_pos._y))
    {
      this->_pos.setPos(this->_pos._x - 2, this->_pos._y);
      return true;
    }
  return false;
}

bool		Human::eastJumpFunction()
{
  if (this->_map.safeCanMoveAt(this->_pos._x + 2, this->_pos._y))
    {
      this->_pos.setPos(this->_pos._x + 2, this->_pos._y);
      return true;
    }
  return false;
}

bool		Human::jumpSkill(gdl::GameClock const& clock)
{
  double current;

  if ((current = clock.getTotalGameTime()) >= this->_skillTimer)
    if ((this->*(this->_jumpDir[this->_dir]))())
      {
	this->_skillUp = false;
	this->_skillTimer = current + 30.0;
	return true;
      }
  return false;
}

void		Human::drawHUD(std::vector<gdl::Image>& img,
			       size_t hi,
			       size_t lag,
			       size_t mode,
			       bool EOG)
{

  std::stringstream ss;

  if (!this->_HUD[0])
    {
      this->_HUD[HUD::LIFE_BAR] = new Surface(310.0f,
					      40.0f,
					      10.0f,
					      10.0f,
					      img[HUD::LIFE_BAR]);

      this->_HUD[HUD::SHIELD] = new Surface(40.0f,
					    40.0f,
					    30.0f,
					    60.0f,
					    img[HUD::SHIELD]);

      this->_HUD[HUD::LUST] = new Surface(40.0f,
					  40.0f,
					  80.0f,
					  60.0f,
					  img[HUD::LUST]);

      this->_HUD[HUD::POWER] = new Surface(40.0f,
					   40.0f,
					   130.0f,
					   60.0f,
					   img[HUD::POWER]);

      this->_HUD[HUD::SPRINT] = new Surface(40.0f,
					    40.0f,
					    180.0f,
					    60.0f,
					    img[HUD::SPRINT]);

      this->_HUD[HUD::SKILL_OK] = new Surface(50.0f,
					      50.0f,
					      90.0f,
					      hi - 60.0f,
					      img[HUD::SKILL_OK]);

      this->_HUD[HUD::SKILL_KO] = new Surface(50.0f,
					      50.0f,
					      90.0f,
					      hi - 60.0f,
					      img[HUD::SKILL_KO]);

      this->_HUD[HUD::BOMB_OK] = new Surface(70.0f,
					     70.0f,
					     10.0f,
					     hi - 80.0f,
					     img[HUD::BOMB_OK]);

      this->_HUD[HUD::BOMB_KO] = new Surface(70.0f,
					     70.0f,
					     10.0f,
					     hi - 80.0f,
					     img[HUD::BOMB_KO]);

      this->_HUD[HUD::BIGBOMB_OK] = new Surface(70.0f,
						70.0f,
						10.0f,
						hi - 80.0f,
						img[HUD::BIGBOMB_OK]);

      this->_HUD[HUD::BIGBOMB_KO] = new Surface(70.0f,
						70.0f,
						10.0f,
						hi - 80.0f,
						img[HUD::BIGBOMB_KO]);

      this->_HUD[HUD::MEGABOMB_OK] = new Surface(70.0f,
						 70.0f,
						 10.0f,
						 hi - 80.0f,
						 img[HUD::MEGABOMB_OK]);

      this->_HUD[HUD::MEGABOMB_KO] = new Surface(70.0f,
						 70.0f,
						 10.0f,
						 hi - 80.0f,
						 img[HUD::MEGABOMB_KO]);

      this->_HUD[HUD::SUCCESS_ONE_KILL] = new Surface(300.0f,
						      81.0f,
						      300.0f + mode,
						      hi - 90.0f,
						      img[HUD::SUCCESS_ONE_KILL]);

      this->_HUD[HUD::SUCCESS_TUTO] = new Surface(300.0f,
						  81.0f,
						  300.0f + mode,
						  hi - 90.0f,
						  img[HUD::SUCCESS_TUTO]);

      this->_HUD[HUD::SUCCESS_BONUS] = new Surface(300.0f,
						   81.0f,
						   300.0f + mode,
						   hi - 90.0f,
						   img[HUD::SUCCESS_BONUS]);

      this->_HUD[HUD::SUCCESS_FIVE_KILL] = new Surface(300.0f,
						       81.0f,
						       300.0f + mode,
						       hi - 90.0f,
						       img[HUD::SUCCESS_FIVE_KILL]);

      this->_HUD[HUD::SUCCESS_HARD_AI] = new Surface(300.0f,
						     81.0f,
						     300.0f + mode,
						     hi - 90.0f,
						     img[HUD::SUCCESS_HARD_AI]);

      this->_HUD[HUD::SUCCESS_POWER] = new Surface(300.0f,
						   81.0f,
						   300.0f + mode,
						   hi - 90.0f,
						   img[HUD::SUCCESS_POWER]);

      this->_HUD[HUD::SUCCESS_LUST] = new Surface(300.0f,
						  81.0f,
						  300.0f + mode,
						  hi - 90.0f,
						  img[HUD::SUCCESS_LUST]);

      this->_HUD[HUD::SUCCESS_TP] = new Surface(300.0f,
						81.0f,
						300.0f + mode,
						hi - 90.0f,
						img[HUD::SUCCESS_TP]);

      this->_HUD[HUD::SUCCESS_DIE] = new Surface(300.0f,
						 81.0f,
						 300.0f + mode,
						 hi - 90.0f,
						 img[HUD::SUCCESS_DIE]);

      this->_HUD[HUD::SUCCESS_FABULOUS] = new Surface(300.0f,
						      81.0f,
						      300.0f + mode,
						      hi - 90.0f,
						      img[HUD::SUCCESS_FABULOUS]);
    }

  if (this->_lastSuccess != Success::LAST)
    this->_HUD[this->_lastSuccess + HUD::SUCCESS_ONE_KILL]->draw();

  this->_HUD[HUD::LIFE_BAR]->draw();

  double	size = (this->_pv / 100.0f * 250.0f);

  (this->*(this->_bombAff[this->_weapon]))();

  if (this->_skillUp)
    this->_HUD[HUD::SKILL_OK]->draw();
  else
    this->_HUD[HUD::SKILL_KO]->draw();

  if (size > 250.0f)
    size = 250.0f;

  Surface	pvIndic(size, 20.0f, 40.0f, 20.0f, img[HUD::LIFE]);

  pvIndic.draw();

  if (this->_shield)
    this->_HUD[HUD::SHIELD]->draw();

  if (this->_speed >= 0.20f)
    this->_HUD[HUD::SPRINT]->draw();
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

  this->_text.setSize(30);
  ss << this->_nbKills;
  this->_text.setText(ss.str());
  this->_text.setPosition(10.0f + lag, hi - 120.0f);
  this->_text.draw();
  this->_text.setSize(10);
  this->_text.setText("kills");
  this->_text.setPosition(55.0f + lag, hi - 100.0f);
  this->_text.draw();
  this->drawStart(hi, lag, mode);
  this->drawEnd(hi, lag, EOG, mode);
}

void		Human::setTimer(double timer)
{
  this->_timers.assign(this->_timers.size(), timer);
  if (this->_skillTimer + 0.15f < timer)
    this->_skillTimer = timer;
}

void		Human::setHalluView(AIView const* v)
{
  if (this->_hallu)
    this->_hallu->updateView(v);
}

void		Human::setSkill(Skill::eSkill s)
{
  this->_skill = s;
}
