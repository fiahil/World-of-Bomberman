/*
 * lemonn_v
 * 15.05.12
 */

#ifndef __MAINMENU_HPP__
#define __MAINMENU_HPP__

class MainMenu : public AMenu
{
public:
  MainMenu(GameManager&);
  virtual ~MainMenu();
  
  virtual double	getCenterX() const;
  virtual double	getCenterY() const;
};

#else

class MainMenu;

#endif
