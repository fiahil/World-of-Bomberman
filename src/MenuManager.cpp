/*
 * NicoW
 * 15.05.12
 */

#include <iostream>		// REMOVE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "MenuManager.hpp"
#include "ProfileManager.hpp"

MenuManager::MenuManager(int w, int h)
  : _run(true),
    _path("Ressources/menu/"),
    _curMenu(TokenMenu::MAINMENU),
    _camera(w, h, 0, 0),
    _timer(MenuKey::LAST, -1.0)
{
  /**/std::cout << "Creation Menu Manager" << std::endl;

  /*
    Keys
  */
  this->_event.push_back(std::make_pair(gdl::Keys::Up, &MenuManager::UpFunction));
  this->_event.push_back(std::make_pair(gdl::Keys::Left, &MenuManager::LeftFunction));
  this->_event.push_back(std::make_pair(gdl::Keys::Right, &MenuManager::RightFunction));
  this->_event.push_back(std::make_pair(gdl::Keys::Down, &MenuManager::DownFunction));
  this->_event.push_back(std::make_pair(gdl::Keys::Return, &MenuManager::SelectFunction));

  /*
    Actions : BE CAREFUL -> respect order of enum in enum.hpp
  */
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::MAINMENU, &MenuManager::jumpMainMenu));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::NEWPROFILE, &MenuManager::jumpNewProfile));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::PROFILE, &MenuManager::jumpProfile));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::GAMECHOOSE, &MenuManager::jumpGameChoose));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::SETTINGS, &MenuManager::jumpSettings));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::IA, &MenuManager::jumpIA));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::TEAM, &MenuManager::jumpTeam));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::MAP, &MenuManager::jumpMap));

  /* TO DO !!! */
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::LOADMAP, &MenuManager::jumpLoadMap));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::LOADPROFILE, &MenuManager::jumpLoadProfile));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::LOADSAVE, &MenuManager::jumpLoadSave));


  this->_jumpMenu.push_back(std::make_pair(TokenMenu::BACK, &MenuManager::jumpBack));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::QUIT, &MenuManager::jumpQuit));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::TO_DO, &MenuManager::jumpToDo));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::SOLO, &MenuManager::jumpSolo));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::COOP, &MenuManager::jumpCoop));
  this->_jumpMenu.push_back(std::make_pair(TokenMenu::VERSUS, &MenuManager::jumpVersus));

  /*
    Profiles Fetching
  */
  this->_profiles = this->_profileLoader.getProfiles();
  this->_profileNames = this->_profileLoader.getNames();
  // this->_maps = this->_mapManager.getAll();

  /*
    Menu construction
  */
  this->buildMainMenu();
  this->buildNewProfileMenu();
  this->buildProfileMenu();
  this->buildGameChooseMenu();
  this->buildSettingsMenu();
  this->buildIAMenu();
  this->buildTeamMenu();
  this->buildMapMenu();

  /* TO DO */
  this->buildLoadMapMenu();

  /* OK */
  this->buildLoadProfileMenu();

  /* TO DO !!!*/
  this->buildLoadSaveMenu();
  // this->buildLoadMapMenu();
  this->_camera.setPos(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0));
}

void		deleteMenus(AMenu * obj)
{
  if (obj != 0)
    {
      delete obj;
      obj = 0;
    }
}

MenuManager::~MenuManager()
{
  /**/std::cout << "Destruction Menu Manager" << std::endl;
  for_each(this->_menus.begin(), this->_menus.end(), deleteMenus);
}

const std::string	MenuManager::addPath(const std::string & concatPath)
{
  return this->_path + concatPath;
}

/*
  Building Menus
*/

void		MenuManager::buildMainMenu(void)
{
  AMenu	*	newMenu		= new AMenu;
  Tag	*	background	= new Tag(this->addPath("Background.png"), this->addPath("Background.png"), true, TokenMenu::MAINMENU,
					  0.0, -1.0, 0.0, std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	newProfile	= new Tag(this->addPath("NewProfileNormal.png"), this->addPath("NewProfileHighlit.png"), true, TokenMenu::NEWPROFILE,
					  GET_WX(2.0), 0.0, GET_WY(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	loadProfile	= new Tag(this->addPath("LoadProfileNormal.png"), this->addPath("LoadProfileHighlit.png"), false, TokenMenu::LOADPROFILE,
					  GET_WX(2.0), 0.0, GET_WY(3.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	quit		= new Tag(this->addPath("QuitNormal.png"), this->addPath("QuitHighlit.png"), false, TokenMenu::QUIT,
					  GET_WX(2.0), 0.0, GET_WY(3.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(newProfile);
  newMenu->addTag(loadProfile);
  newMenu->addTag(quit);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildNewProfileMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background2.png"), this->addPath("Background2.png"), true, TokenMenu::MAINMENU,
					  WINX(1.0), -1.0, 0.0, std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	newName 	= new Tag(this->addPath("NewNameNormal.png"), this->addPath("NewNameHighlit.png"), true, TokenMenu::NEWPROFILE,
					  MIDWINX(1.0) + WINX(1.0), 0.0, GET_WY(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	create 		= new Tag(this->addPath("CreateNormal.png"), this->addPath("CreateHighlit.png"), false, TokenMenu::PROFILE,
					  MIDWINX(1.0) + WINX(1.0), 0.0, GET_WY(3.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  MIDWINX(1.0) + WINX(1.0), 0.0, GET_WY(3.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(newName);
  newMenu->addTag(create);
  newMenu->addTag(back);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildProfileMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background3.png"), this->addPath("Background3.png"), true, TokenMenu::MAINMENU,
					  WINX(1.0), -1.0, WINY(1.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	newGame 	= new Tag(this->addPath("NewGameNormal.png"), this->addPath("NewGameHighlit.png"), true, TokenMenu::GAMECHOOSE,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(1.0) + GET_WX(5.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	loadGame 	= new Tag(this->addPath("LoadGameNormal.png"), this->addPath("LoadGameHighlit.png"), false, TokenMenu::LOADSAVE,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(1.0) + GET_WX(5.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	settings 	= new Tag(this->addPath("SettingsNormal.png"), this->addPath("SettingsHighlit.png"), false, TokenMenu::SETTINGS,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(1.0) + GET_WX(5.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(1.0) + GET_WX(5.0) + GET_TAG(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	quit 		= new Tag(this->addPath("QuitNormal.png"), this->addPath("QuitHighlit.png"), false, TokenMenu::QUIT,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(1.0) + GET_WX(5.0) + GET_TAG(4.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(newGame);
  newMenu->addTag(loadGame);
  newMenu->addTag(settings);
  newMenu->addTag(back);
  newMenu->addTag(quit);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildGameChooseMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background5.png"), this->addPath("Background5.png"), true, TokenMenu::MAINMENU,
					  0.0, -1.0, WINY(2.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	solo 		= new Tag(this->addPath("SoloNormal.png"), this->addPath("SoloHighlit.png"), true, TokenMenu::SOLO,
					  MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	coop 		= new Tag(this->addPath("CoopNormal.png"), this->addPath("CoopHighlit.png"), false, TokenMenu::COOP,
					  MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	versus 		= new Tag(this->addPath("VersusNormal.png"), this->addPath("VersusHighlit.png"), false, TokenMenu::VERSUS,
					  MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0) + GET_TAG(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(solo);
  newMenu->addTag(coop);
  newMenu->addTag(versus);
  newMenu->addTag(back);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildSettingsMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background6.png"), this->addPath("Background6.png"),
					  true, TokenMenu::MAINMENU, WINX(1.0), -1.0, WINY(2.0),
					  std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	keyboard 	= new Tag(this->addPath("KeyboardNormal.png"), this->addPath("KeyboardHighlit.png"), true, TokenMenu::/**/MAINMENU,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	done 		= new Tag(this->addPath("DoneNormal.png"), this->addPath("DoneHighlit.png"), false, TokenMenu::BACK,
					  WINX(1.0) + MIDWINX(1.0), 0.0, WINY(2.0) + GET_WX(5.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(keyboard);
  newMenu->addTag(done);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildIAMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background7.png"), this->addPath("Background7.png"), true, TokenMenu::MAINMENU,
					  0.0, -1.0, WINY(3.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	nbText 		= new Tag(this->addPath("NbTextNormal.png"), this->addPath("NbTextHighlit.png"), true, TokenMenu::/**/IA,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	level 		= new Tag(this->addPath("LevelNormal.png"), this->addPath("LevelHighlit.png"), false, TokenMenu::/**/IA,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	easy 		= new Tag(this->addPath("EasyNormal.png"), this->addPath("EasyHighlit.png"), false, TokenMenu::TO_DO,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	normal 		= new Tag(this->addPath("NormalNormal.png"), this->addPath("NormalHighlit.png"), false, TokenMenu::TO_DO,
  					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0) + GET_TAG(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
   Tag	*	hard 		= new Tag(this->addPath("HardNormal.png"), this->addPath("HardHighlit.png"), false, TokenMenu::TO_DO,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0) + GET_TAG(4.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(6.0) + GET_TAG(5.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(nbText);
  newMenu->addTag(level);
  newMenu->addTag(easy);
  newMenu->addTag(normal);
  newMenu->addTag(hard);
  newMenu->addTag(back);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildTeamMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background8.png"), this->addPath("Background8.png"), true, TokenMenu::MAINMENU,
					  0.0, -1.0, WINY(3.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	nbText 		= new Tag(this->addPath("NbTextNormal.png"), this->addPath("NbTextHighlit.png"), true, TokenMenu::/**/TEAM,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	done 		= new Tag(this->addPath("DoneNormal.png"), this->addPath("DoneHighlit.png"), false, TokenMenu::/**/MAP,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(nbText);
  newMenu->addTag(done);
  newMenu->addTag(back);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildMapMenu(void)
{
  AMenu	*	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background9.png"), this->addPath("Background9.png"), true, TokenMenu::MAINMENU,
					  0.0, -1.0, WINY(3.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  Tag	*	random 		= new Tag(this->addPath("RandomNormal.png"), this->addPath("RandomHighlit.png"), true, TokenMenu::/**/MAP,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	load 		= new Tag(this->addPath("LoadNormal.png"), this->addPath("LoadHighlit.png"), false, TokenMenu::/**/MAP,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0) + GET_TAG(1.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  Tag	*	back 		= new Tag(this->addPath("BackNormal.png"), this->addPath("BackHighlit.png"), false, TokenMenu::BACK,
					  MIDWINX(1.0), 0.0, WINY(3.0) + GET_WX(3.0) + GET_TAG(2.0), std::make_pair(145.0, 50.0), std::make_pair(145.0, 50.0));
  newMenu->setBackground(background);
  newMenu->addTag(random);
  newMenu->addTag(load);
  newMenu->addTag(back);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildLoadMapMenu(void)
{
  // TO DO !!
  AMenu *	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background.png"), this->addPath("Background.png"), true, TokenMenu::/**/LOADPROFILE,
					  0.0, -1.0, WINY(1.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  newMenu->setBackground(background);
  this->_menus.push_back(newMenu);
  /* THIS IS NOT CORRECT */
}

void 		MenuManager::buildLoadProfileMenu(void)
{
  AMenu *	newMenu 	= new AMenu;
  Tag	*	background 	= new Tag(this->addPath("Background.png"), this->addPath("Background.png"), true, TokenMenu::/**/LOADPROFILE,
					  0.0, -1.0, WINY(1.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
  int		size = 20;
  int		y = 50;
  double	count = 0.0;
  double	selected = true;
  double	getTag = 1.0;

  for (unsigned int i = 0 ; i < this->_profileNames.size() ; ++i)
    {
      Tag * 	tmp = new Tag(this->addPath("BlankNormal.png"), this->addPath("BlankHighlit.png"), selected, TokenMenu::TO_DO,
			      0.0, 0.0, WINY(1.0) + (getTag * 80.0), std::make_pair(200.0, 80.0), std::make_pair(200.0, 80.0));
      tmp->createText(this->_profileNames[i], size, 0, y);
      newMenu->addTag(tmp);
      y += 55;
      count++;
      getTag++;
      if (selected == true)
	selected = false;
    }
  newMenu->setBackground(background);
  this->_menus.push_back(newMenu);
}

void 		MenuManager::buildLoadSaveMenu(void)
{
  AMenu *	newMenu 	= new AMenu;

  this->_menus.push_back(newMenu);
}

// THIS IS A SAVE
//
// void 		MenuManager::buildLoadSaveMenu(void)
// {
//   AMenu *	newMenu 	= new AMenu;
//   Tag	*	background 	= new Tag(this->addPath("Background.png"), this->addPath("Background.png"), true, TokenMenu::/**/LOADPROFILE,
//   					  0.0, -1.0, WINY(1.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
//   int		size = 20;
//   int		y = 50;
//   double	count = 0.0;
//   double	selected = true;
//   double	getTag = 1.0;
//   const Profile *	pro = this->_gameManager.getMainProfile();

//   if (pro != 0)
//     {
//       std::vector<size_t>	vSave = pro->getSave();

//       for (unsigned int i = 0 ; i < vSave.size() ; ++i)
//   	{
//   	  Tag *	tmp = new Tag(this->addPath("BlankNormal.png"), this->addPath("BlankHighlit.png"), selected, /**/TokenMenu::TO_DO,
//       	  		      0.0, 0.0, WINY(1.0) + (getTag * 80.0), std::make_pair(200.0, 80.0), std::make_pair(200.0, 80.0));
//   	  size_t	mapId = vSave[i];
//   	  std::stringstream sstrm;
//   	  std::string name;

//   	  sstrm << mapId;
//   	  sstrm >> name;
//   	  tmp->createText(name, size, 0, y);

//   	  std::cout << "Boucle" << std::endl;


//   	  newMenu->addTag(tmp);
//   	  y += 55;
//   	  count++;
//   	  getTag++;
//   	  name.clear();
//   	  sstrm.clear();
//   	  if (selected == true)
//   	    selected = false;
//   	}
//     }
//   newMenu->setBackground(background);
//   this->_menus.push_back(newMenu);
// }

// void			MenuManager::draw(void)
// {
//   this->_menus[this->_curMenu]->draw();
// }

void			MenuManager::draw(void)
{
  std::vector<AMenu *>::iterator	it = this->_menus.begin();

  for (; it != this->_menus.end() ; ++it)
    (*it)->draw();
}

void			MenuManager::initialize(void)
{
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0));
}

/*
  Update
*/

void			MenuManager::update(gdl::GameClock const& clock, gdl::Input& input)
{
  if (this->_run)
    {
      // TODO : for each ? Cf Human.cpp
      for (unsigned int i = 0 ; i < this->_event.size() ; ++i)
	if (input.isKeyDown(this->_event[i].first))
	  (this->*(this->_event[i].second))(clock);
      this->_camera.update();
    }
}

static bool		isSelected(Tag *_tag)
{
  return _tag->getStatus();
}

TokenMenu::eMenu	MenuManager::fetchMenu(void)
{
  std::vector<Tag *>::const_iterator	it;
  int					idx;

  it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
  idx = it - this->_menus[this->_curMenu]->getTags().begin();
  return (this->_menus[this->_curMenu]->getTags()[idx]->getContent());
}

bool			MenuManager::isHere(const std::string& _name)
{
  if (find(this->_profileNames.begin(), this->_profileNames.end(), _name) == this->_profileNames.end())
    return (false);
  return (true);
}

/*
  Key Functions
*/

void			MenuManager::UpFunction(gdl::GameClock const &clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::UP])
    {
      /**/std::cout << "Up" << std::endl;
      std::vector<Tag *>::const_iterator	it;
      int					idx;

      it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
      this->_menus[this->_curMenu]->setTagAt((idx = (it - this->_menus[this->_curMenu]->getTags().begin())), false);
      if ((idx - 1) < 0)
	this->_menus[this->_curMenu]->setTagAt(this->_menus[this->_curMenu]->getTags().size() - 1, true);
      else
	this->_menus[this->_curMenu]->setTagAt(--idx, true);
      this->_timer[MenuKey::UP] = current + 0.15;
    }
}

void			MenuManager::DownFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::DOWN])
    {
      /**/std::cout << "Down" << std::endl;
      std::vector<Tag *>::const_iterator	it;
      int					idx;

      it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
      this->_menus[this->_curMenu]->setTagAt((idx = (it - this->_menus[this->_curMenu]->getTags().begin())), false);
      if ((idx + 1) >= this->_menus[this->_curMenu]->getTags().size())
	this->_menus[this->_curMenu]->setTagAt(0, true);
      else
	this->_menus[this->_curMenu]->setTagAt(++idx, true);
      this->_timer[MenuKey::DOWN] = current + 0.15;
    }
}

void			MenuManager::LeftFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::LEFT])
    {
      /**/std::cout << "Left" << std::endl;
      this->_timer[MenuKey::LEFT] = current + 0.15;
    }
}

void			MenuManager::RightFunction(gdl::GameClock const & clock)
{
  double current = static_cast<double>(clock.getTotalGameTime());

  if (current >= this->_timer[MenuKey::RIGHT])
    {
      /**/std::cout << "Right" << std::endl;
      this->_timer[MenuKey::RIGHT] = current + 0.15;
    }
}


void			MenuManager::SelectFunction(gdl::GameClock const & clock)
{
  double		current = static_cast<double>(clock.getTotalGameTime());
  int			token;

  if (current >= this->_timer[MenuKey::SELECTED])
    {
      if ((token = this->fetchMenu()) < TokenMenu::LAST)
	{
	  /* ResetCursor : TO DO*/
	  (this->*(this->_jumpMenu[token].second))();
	}
      this->_timer[MenuKey::SELECTED] = current + 0.15;
    }
}

/*
  Jump Functions (Key = Enter)
*/

void			MenuManager::jumpMainMenu(void)
{
  std::cout << "Token = MAINMENU" << std::endl;
  this->_curMenu = TokenMenu::MAINMENU;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0));
}

void			MenuManager::jumpNewProfile(void)
{
  std::cout << "Token = NEWPROFILE" << std::endl;
  this->_curMenu = TokenMenu::NEWPROFILE;
  this->_camera.setPosScroll(MIDWINX(1.0) + WINX(1.0), CAMDISTANCE, MIDWINY(1.0));

  /*
    Input form for the name.
    Skin choice ?
  */

  /*
    IF user submits profile
    THEN object fulfillment
    ELSE back to main menu
  */

  ProfileManager        _pm;
  Profile*		_new = new Profile;
  Config                _cfg;
  size_t                _id;
  std::vector<size_t>   _six(6, 0);
  std::vector<size_t>   _three(3, 0);

  for (_id = 0; _pm.isHere(_id); ++_id);
  _new->setId(_id);
  _new->setLvl(1);
  _new->setXp(0);
  _new->setTuto(false);
  _new->setSkin(Skin::NORMAL);
  _new->setConfig(_cfg);
  _new->setName("Default");      // To be replaced by the input name
  _new->setStat(_six);
  _new->setSkill(_three);
  _new->setAchievement(_three);
  _pm.setProfile(_id, *_new);

  this->_profiles.push_back(_new);
  this->_profileNames.push_back(_new->getName());

  double        z = this->_menus[this->_curMenu]->getTags().back()->getSpritePos()._pos.z + GET_TAG(1.0);
  Tag *		newTag = new Tag(this->addPath("Background.png"), this->addPath("Background.png"), false, /**/TokenMenu::TO_DO,
				 0.0, -1.0, z, std::make_pair(200.0, 80.0), std::make_pair(200.0, 80.0));

  // CONSTRUCTION TAG !! pour decaler le tag, utiliser la position du Scale
  // du dernier element du vector, et lui ajouter un GET_TAG(1.0);

  this->addTagToMenu(this->_menus[this->_curMenu], newTag);
  this->_gameManager.setMainProfile(_new);
}

void			MenuManager::jumpProfile(void)
{
  std::cout << "Token = PROFILE" << std::endl;
  this->_curMenu = TokenMenu::PROFILE;
  this->_camera.setPosScroll(MIDWINX(1.0) + WINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(1.0));
}

void			MenuManager::jumpGameChoose(void)
{
  std::cout << "Token = GAMECHOOSE" << std::endl;
  this->_curMenu = TokenMenu::GAMECHOOSE;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(2.0));
}

void			MenuManager::jumpSettings(void)
{
  std::cout << "Token = SETTINGS" << std::endl;
  this->_curMenu = TokenMenu::SETTINGS;
  this->_camera.setPosScroll(MIDWINX(1.0) + WINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(2.0));
}

void			MenuManager::jumpIA(void)
{
  std::cout << "Token = IA" << std::endl;
  this->_curMenu = TokenMenu::IA;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(3.0));
}

void			MenuManager::jumpTeam(void)
{
  std::cout << "Token = TEAM" << std::endl;
  this->_curMenu = TokenMenu::TEAM;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(3.0));
}

void			MenuManager::jumpMap(void)
{
  std::cout << "Token = MAP" << std::endl;
  this->_curMenu = TokenMenu::MAP;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(3.0));
}

void			MenuManager::jumpBack(void)
{
  std::cout << "Token = BACK" << std::endl;
  if (this->_curMenu == TokenMenu::NEWPROFILE ||
      this->_curMenu == TokenMenu::PROFILE)
    this->jumpMainMenu();
  else if (this->_curMenu == TokenMenu::GAMECHOOSE ||
	   this->_curMenu == TokenMenu::SETTINGS)
    this->jumpProfile();
  else if (this->_curMenu == TokenMenu::IA)
    {
      this->_gameManager.setGameMode(GameMode::LAST);
      this->jumpGameChoose();
    }
  else if (this->_curMenu == TokenMenu::TEAM)
    this->jumpIA();
  else if (this->_curMenu == TokenMenu::MAP)
    {
      if (this->_gameManager.getGameMode() == GameMode::SOLO ||
	  this->_gameManager.getGameMode() == GameMode::VERSUS)
	this->jumpIA();
      else if (this->_gameManager.getGameMode() == GameMode::COOP)
	this->jumpTeam();
    }
}

void			MenuManager::jumpQuit(void)
{
  std::cout << "Token = QUIT" << std::endl;
  this->_run = false;
}

void			MenuManager::jumpToDo(void)
{
  std::cout << "Token = TO_DO" << std::endl;
  if (this->_curMenu == TokenMenu::IA)
    {
      if (this->_gameManager.getGameMode() == GameMode::SOLO ||
	  this->_gameManager.getGameMode() == GameMode::VERSUS)
	this->jumpMap();
      else if (this->_gameManager.getGameMode() == GameMode::COOP)
	this->jumpTeam();
    }
  else if (this->_curMenu == TokenMenu::LOADPROFILE)
    {
      /* HERE */

      std::vector<Tag *>::const_iterator	it;
      unsigned int				idx;

      it = std::find_if(this->_menus[this->_curMenu]->getTags().begin(), this->_menus[this->_curMenu]->getTags().end(), isSelected);
      idx = (it - this->_menus[this->_curMenu]->getTags().begin());
      if (idx < this->_profiles.size())
	{
	  this->_gameManager.setMainProfile(this->_profiles[idx]);
	  /**/std::cout << "Profile Selectionne : name = [" << this->_gameManager.getMainProfile()->getName() << "]" << std::endl;
	}
      this->jumpProfile();
    }
  else
    {
      std::cout << "Jump TO_DO pas implemente : retour a main" << std::endl;
      this->jumpMainMenu();
    }
}

void			MenuManager::jumpSolo(void)
{
  std::cout << "Token = SOLO" << std::endl;
  this->_gameManager.setGameMode(GameMode::SOLO);
  this->jumpIA();
}

void			MenuManager::jumpCoop(void)
{
  std::cout << "Token = COOP" << std::endl;
  this->_gameManager.setGameMode(GameMode::COOP);
  this->jumpIA();
}

void			MenuManager::jumpVersus(void)
{
  std::cout << "Token = VERSUS" << std::endl;
  this->_gameManager.setGameMode(GameMode::VERSUS);
  this->jumpIA();
}

void			MenuManager::replaceLoadSaveMenu(void)
{
  const Profile *	pro = this->_gameManager.getMainProfile();

  std::cout << "Replace Load Save Menu" << std::endl;

  if (pro != 0)
    {
      AMenu *	newMenu 	= new AMenu;
      Tag	*	background 	= new Tag(this->addPath("Background.png"), this->addPath("Background.png"), true, TokenMenu::/**/LOADPROFILE,
						  0.0, -1.0, WINY(1.0), std::make_pair(WINX(1.0), WINY(1.0)), std::make_pair(WINX(1.0), WINY(1.0)));
      int		size = 20;
      int		y = 50;
      double	count = 0.0;
      double	selected = true;
      double	getTag = 1.0;

      std::vector<size_t>	vSave = pro->getSave();

      if (!vSave.empty())
	for (unsigned int i = 0 ; i < vSave.size() ; ++i)
	  {
	    Tag *	tmp = new Tag(this->addPath("BlankNormal.png"), this->addPath("BlankHighlit.png"), selected, /**/TokenMenu::TO_DO,
	    			      0.0, 0.0, WINY(1.0) + (getTag * 80.0), std::make_pair(200.0, 80.0), std::make_pair(200.0, 80.0));
	    size_t	mapId = vSave[i];
	    std::stringstream sstrm;
	    std::string name;

	    sstrm << mapId;
	    sstrm >> name;
	    tmp->createText(name, size, 0, y);

	    std::cout << "Boucle" << std::endl;

	    newMenu->addTag(tmp);
	    y += 55;
	    count++;
	    getTag++;
	    name.clear();
	    sstrm.clear();
	    if (selected == true)
	      selected = false;
	  }
      else
	std::cout << "ERROR : Vector vide" << std::endl;
      newMenu->setBackground(background);
      this->_menus[TokenMenu::LOADSAVE] = newMenu;
    }
  else
    std::cout << "ERROR : Profile * Inexistant" << std::endl;
}

void			MenuManager::jumpLoadProfile(void)
{
  std::cout << "LOAD PROFILE" << std::endl;
  this->_curMenu = TokenMenu::LOADPROFILE;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(1.0));
}

void			MenuManager::jumpLoadSave(void)
{
  std::cout << "LOAD SAVE" << std::endl;
  this->_curMenu = TokenMenu::LOADSAVE;
  this->_camera.setPos(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(1.0));
  this->replaceLoadSaveMenu();
}

void			MenuManager::jumpLoadMap(void)
{
  std::cout << "LOAD MAP" << std::endl;
  this->_curMenu = TokenMenu::LOADMAP;
  this->_camera.setPosScroll(MIDWINX(1.0), CAMDISTANCE, MIDWINY(1.0) + WINY(1.0));
}

bool			MenuManager::isRunning(void)
{
  return this->_run;
}

void			MenuManager::addTagToMenu(AMenu *menu, Tag *toAdd)
{
  if (menu != 0 && toAdd != 0)
    menu->addTag(toAdd);
}
