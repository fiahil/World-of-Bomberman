//
// main.cpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Thu May 10 22:24:44 2012 vincent lemonnier
// Last update Tue May 29 16:16:02 2012 vincent lemonnier
//

#include <cstdlib>
#include "Sound.hpp"
#include "Menu.hpp"

int		main()
{
  time_t	now;

  time(&now);
  srandom(now);

  //Sound::getMe();
  Menu		bomberman;

  bomberman.run();
  return 0;
}
