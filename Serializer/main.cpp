/*
 * Fiahil
 *
 * 3 mai 2012
 */

#include "Scanner.hpp"
#include "Packman.hpp"
#include "Profile.hpp"
#include "Match.hpp"

#include <iostream>
#include <fstream>

int	main(int argc, char** argv) {
  std::cout << "Serializer loaded." << std::endl;

  for (int i = 1; i < argc; ++i) {
    std::ifstream	input(argv[i]);

    if (!input.good()) {
      std::cerr << "Cannot open file: " << argv[i] << std::endl;
      continue;
    }
    Serializer::Scanner	scanner(input);
    Serializer::Loader	loader(scanner);

    loader.parse();
  }

  std::cout << "=============================" << std::endl << std::endl;

  Serializer::Packman	p("log");
  Profile		profile;

  profile.setId(0);
  profile.setLvl(666);
  profile.setName("John");
  profile.setXp(5555);
  profile.setTuto(true);
  profile.addStat(0);
  profile.addStat(1);
  profile.addStat(2);
  profile.addStat(3);
  profile.addStat(4);
  profile.addStat(5);
  profile.addSkill(11);
  profile.addSkill(22);
  profile.addSkill(33);
  profile.addAchievement(444);
  profile.addAchievement(555);
  profile.addAchievement(666);
  profile.addSave(1);
  profile.addSave(0);
  profile.addSave(1);
  profile.addSave(0);
  profile.addSave(1);

  p.packProfile(profile);

  Serializer::Packman	k("slog");
  std::vector<APlayer*>	ppp;
  Match			match (0, true, GameMode::ARCADE, ppp);

  k.packMatch(match);
  return 0;
}
