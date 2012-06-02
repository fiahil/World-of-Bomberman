/*
 * lemonn_v
 * 15.05.12
 */

#include <sstream>
#include "MenuStats.hpp"

MenuStats::MenuStats(GameManager& game)
  : AMenu("menu/background/backgroundStat.jpg", "menu/background/backgroundStat.jpg", 4800.0f, -1.0f, 800.0f, game)
{
  this->_tags.push_back(new Tag("menu/tags/BackSmallNormal.png", "menu/tags/BackSmallHighlit.png", true, false, TokenMenu::PROFILE, 6200.0f, 0.0f, 1500.0f));
  this->_tags.push_back(new Tag("textures/one_kill_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 5700.0f, 0.0f, 1000.0f));
  this->_tags.push_back(new Tag("textures/bonus_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 5700.0f, 0.0f, 1083.0f));
  this->_tags.push_back(new Tag("textures/five_kill_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 5700.0f, 0.0f, 1166.0f));
  this->_tags.push_back(new Tag("textures/power_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 5700.0f, 0.0f, 1249.0f));
  this->_tags.push_back(new Tag("textures/lust_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 6002.0f, 0.0f, 1000.0f));
  this->_tags.push_back(new Tag("textures/tp_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 6002.0f, 0.0f, 1083.0f));
  this->_tags.push_back(new Tag("textures/die_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 6002.0f, 0.0f, 1166.0f));
  this->_tags.push_back(new Tag("textures/fabulous_success.png", "textures/locked_success.png", false, false, TokenMenu::LAST, 6002.0f, 0.0f, 1249.0f));
}

MenuStats::~MenuStats()
{

}

double	MenuStats::getCenterX() const
{
  return 5600.0f;
}

double	MenuStats::getCenterY() const
{
  return 1200.0f;
}

void	MenuStats::drawText()
{
  std::stringstream	ss;
  Profile*	tmp = this->_gameManager._mainProfile;

  this->_text.setSize(20);
  this->_text.setText(tmp->getName());
  this->_text.setPosition(400, 140);
  this->_text.draw();

  this->_text.setText(tmp->getSkinName());
  this->_text.setPosition(400, 195);
  this->_text.draw();

  this->_text.setText(tmp->getSkillName());
  this->_text.setPosition(400, 247);
  this->_text.draw();

  ss << tmp->getStat().getKills();
  this->_text.setText(ss.str());
  this->_text.setPosition(400, 300);
  this->_text.draw();

  ss.str("");
  ss.clear();
  ss << tmp->getStat().getMaxKill();
  this->_text.setText(ss.str());
  this->_text.setPosition(400, 351);
  this->_text.draw();

  ss.str("");
  ss.clear();
  ss << tmp->getStat().getVictories();
  this->_text.setText(ss.str());
  this->_text.setPosition(400, 403);
  this->_text.draw();

  ss.str("");
  ss.clear();
  ss << tmp->getStat().getDefeats();
  this->_text.setText(ss.str());
  this->_text.setPosition(400, 456);
  this->_text.draw();

  ss.str("");
  ss.clear();
  ss << tmp->getStat().getScore();
  this->_text.setText(ss.str());
  this->_text.setPosition(400, 508);
  this->_text.draw();

  ss.str("");
  ss.clear();
}

void	MenuStats::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (input.isKeyDown(this->_keyEvent[2].first))
    (this->*_keyEvent[2].second)(clock);
  this->_tags[1]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::ONE_KILL]);
  this->_tags[2]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::BONUS]);
  this->_tags[3]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::FIVE_KILL]);
  this->_tags[4]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::POWER]);
  this->_tags[5]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::LUST]);
  this->_tags[6]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::TP]);
  this->_tags[7]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::DIE]);
  this->_tags[8]->setStatus(!this->_gameManager._mainProfile->getAchievement()[Success::FABULOUS]);
}

void	MenuStats::draw()
{
  AMenu::draw();
  if (this->_textDraw)
  this->drawText();
}
