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
  this->_text.setPosition(200, 50);
  this->_text.draw();
  this->_text.setText(tmp->getSkinName());
  this->_text.setPosition(200, 100);
  this->_text.draw();
  this->_text.setText(tmp->getSkillName());
  this->_text.setPosition(200, 150);
  this->_text.draw();
  ss << tmp->getStat().getKills();
  this->_text.setText(ss.str());
  this->_text.setPosition(200, 200);
  this->_text.draw();
  ss.str("");
  ss.clear();
  ss << tmp->getStat().getDefeats();
  this->_text.setText(ss.str());
  this->_text.setPosition(200, 250);
  this->_text.draw();
  ss.str("");
  ss.clear();
  ss << tmp->getStat().getVictories();
  this->_text.setText(ss.str());
  this->_text.setPosition(200, 300);
  this->_text.draw();
  ss.str("");
  ss.clear();
  ss << tmp->getStat().getMaxKill();
  this->_text.setText(ss.str());
  this->_text.setPosition(200, 350);
  this->_text.draw();
  ss.str("");
  ss.clear();
  ss << tmp->getStat().getScore();
  this->_text.setText(ss.str());
  this->_text.setPosition(200, 400);
  this->_text.draw();
  ss.str("");
  ss.clear();
}

void	MenuStats::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (input.isKeyDown(this->_keyEvent[2].first))
    (this->*_keyEvent[2].second)(clock);
}

void	MenuStats::draw()
{
  AMenu::draw();
  if (this->_textDraw)
  this->drawText();
}
