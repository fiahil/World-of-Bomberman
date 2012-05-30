//
// main.cpp for Bomberman in /home/lemonn_v/Projects/rendu/Bomberman
// 
// Made by vincent lemonnier
// Login   <lemonn_v@epitech.net>
// 
// Started on  Thu May 10 22:24:44 2012 vincent lemonnier
// Last update Wed May 30 20:09:01 2012 nicolas magere
//

#include <cstdlib>
#include <exception>
#include "Sound.hpp"
#include "Menu.hpp"
#include "Error.hpp"

int		main()
{
  Menu		bomberman;
  time_t	now;

  time(&now);
  srandom(now);

  Sound::getMe();

  try
    {
      bomberman.run();
    }
  catch (std::exception & end)
    {
    }
  return 0;
}
