/*
 * NicoW
 * 27.05.12
 */

#include <iostream>		// REMOVE
#include <sstream>
#include "LoadSave.hpp"

LoadSave::LoadSave(GameManager& game)
  : AMenu("menu/Background2.png", "menu/Background2.png", 3200.0f, -1.0f, 900.0f, game),
    _buildTags(false)
{
}

LoadSave::~LoadSave(void)
{
}

double		LoadSave::getCenterX(void) const
{
  return (4000.0f);
}

double		LoadSave::getCenterY(void) const
{
  return (1350.0f);
}

void		LoadSave::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_buildTags)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
    }
  else
    this->buildTags();
}

void		LoadSave::buildTags(void)
{
  bool		select = true;
  int		i = 0;
  double	yText = 400;
  double	yTag = 1350.0f;
  std::string	str;

  std::stringstream			sstrm;
  std::vector<size_t>			tmpSave = this->_gameManager._mainProfile->getSave();
  std::vector<size_t>::const_iterator	it = tmpSave.begin();

  this->_buildTags = true;
  if (this->_gameManager._mainProfile != 0)
    {
      for ( ; it != tmpSave.end() ; ++it)
	{
	  sstrm << *it;
	  sstrm >> str;

	  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png", select, false, /**/TokenMenu::LOADSAVE, 4000.0f, 0.0f, yTag));
	  this->_tags[i]->createText(str, 20, 800, yText);

	  i++;
	  sstrm.clear();
	  str.clear();
	  yText += 50;
	  yTag += 50.0f;
	  if (select)
	    select = false;
	}
    }
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", select, false, TokenMenu::PROFILE, 4000.0f, 0.0f, yTag));
}
