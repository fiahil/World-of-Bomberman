/*
 * NicoW
 * 27.05.12
 */

#include "Scanner.hpp"
#include "Unpackman.hpp"
#include "LoadSave.hpp"
#include <fstream>

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

void		LoadSave::loadSave()
{
  Serializer::Unpackman up(*this->_gameManager._mainProfile, this->_gameManager._match);
  std::string	path("Ressources/saves/" + this->_gameManager._mainProfile->getSave()[this->_cursor]);
  std::ifstream	file(path.c_str());

  if (!file.good())
    this->_curToken = TokenMenu::MAINMENU;
  else
    {
      Serializer::Scanner	scanner(file);
      Serializer::Loader	loader(scanner, up);

      loader.parse();
    }
}

void		LoadSave::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_buildTags)
    {
      for (size_t i = 0; i < this->_keyEvent.size(); ++i)
	if (input.isKeyDown(this->_keyEvent[i].first))
	  (this->*_keyEvent[i].second)(clock);
      if (this->_curToken == TokenMenu::CREATEGAME)
	this->loadSave();
    }
  else
    this->buildTags();
}

void		LoadSave::buildTags(void)
{
  bool		select = true;
  double	yText = 400;
  double	yTag = 1350.0f;

  std::vector<std::string>			tmpSave = this->_gameManager._mainProfile->getSave();
  std::vector<std::string>::const_iterator	it = tmpSave.begin();

  this->_buildTags = true;
  if (this->_gameManager._mainProfile != 0)
    {
      for ( ; it != tmpSave.end() ; ++it)
	{
	  this->_tags.push_back(new Tag("menu/BlackNormal.png", "menu/BlackHighlit.png",
					select, true, TokenMenu::CREATEGAME, 4000.0f, 0.0f, yTag));
	  this->_tags.back()->initialize();
	  this->_tags.back()->createText(*it, 20, 800, yText);

	  yText += 50;
	  yTag += 50.0f;
	  if (select)
	    select = false;
	}
    }
  this->_tags.push_back(new Tag("menu/BackNormal.png", "menu/BackHighlit.png", select, true, TokenMenu::PROFILE, 4000.0f, 0.0f, yTag));
  this->_tags.back()->initialize();
}
