//
// main.cpp for test in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 11:33:49 2012 nicolas magere
// Last update Sat May 12 15:26:29 2012 nicolas magere
//

#include <iostream>
#include "Profile.hpp"
#include "Config.hpp"

int		main(void)
{
  Profile	one;

  size_t id = 0;
  size_t lvl = 0;
  size_t xp = 0;
  bool tuto = false;
  t_skin skin = 2;
  const Config config;
  const std::string name("Pedobear");
  const std::vector<size_t> skill;
  const std::vector<size_t> achivement;
  const std::vector<size_t> save;

  one.setAllProfile(id, lvl, xp, tuto, skin, config, name, skill, achivement, save);

  std::cout << "Coucou main" << std::endl;
  return 0;
}
