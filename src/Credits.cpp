/*
 * NicoW
 * 28.05.12
 */

#include "Credits.hpp"

Credits::Credits(GameManager& game)
  : AMenu("menu/background/backgroundCredits.jpg", "menu/background/backgroundCredits.jpg", -1600.0f, -1.0f, 0.0f, game)
{
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", true, false, TokenMenu::MAINMENU, -800.0f, 0.0f, 450.0f));
}

Credits::~Credits(void)
{
}

double		Credits::getCenterX(void) const
{
  return (-800.0f);
}

double		Credits::getCenterY(void) const
{
  return (450.0f);
}

void		Credits::update(gdl::GameClock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < this->_keyEvent.size(); ++i)
    if (input.isKeyDown(this->_keyEvent[i].first))
      (this->*_keyEvent[i].second)(clock);
}

/*
  A Kaboum Bang Power Plus Developement Team :
  -> busina_b
  -> lachet_s
  -> leffra_q
  -> lemonn_v
  -> magere_n

  Directed		By busina_b
  Game Designer		By busina_b ; leffra_q
  Style Designer	By lachet_s
  Scenario		By busina_b ; lachet_s ; leffra_q ; lemonn_v ; magere_n
  Cameraman		By lemonn_v
  Interface		By lachet_s ; lemonn_v ; magere_n
  Executive Producers	By lachet_s ; leffra_q ; lemonn_v ; magere_n
  Music			By busina_b ; lachet_s ; leffra_q ; lemonn_v ; magere_n
  T pour Tuer		By magere_n

  CAST :
  -> Worgen       : Worgen's role
  -> Sylvanas     : Dark Elf's role
  -> Variant      : Paladin's role
  -> Zuljin	  : Orc's role
  -> Da Chicken   : Chiken's role

  We would like to thank :
  -> Our Moms, whithout whom we would not have been able to create this game

  COPYRITH C 2012 Kaboum Bang Power Plus Studio, All Right Reserved
*/
