/*
 * Fiahil
 *
 * 3 mai 2012
 */

#include "Scanner.hpp"
#include "Packman.hpp"
#include "Unpackman.hpp"
#include "Profile.hpp"
#include "Match.hpp"

#include <iostream>
#include <fstream>

int	main(int argc, char** argv) {
  std::cout << "Serializer loaded." << std::endl;

  Profile		pp;
  Match			ma;
  Serializer::Unpackman	up(pp, ma);

  for (int i = 1; i < argc; ++i) {
    std::ifstream	input(argv[i]);

    if (!input.good()) {
      std::cerr << "Cannot open file: " << argv[i] << std::endl;
      continue;
    }
    Serializer::Scanner	scanner(input);
    Serializer::Loader	loader(scanner, up);

    loader.parse();
  }

  std::cout << "=============================" << std::endl << std::endl;

  Serializer::Packman	p("log");

  p.packProfile(pp);

  //Serializer::Packman	k("slog");
  //std::vector<APlayer*>	ap;

  //k.packMatch(ma);
  return 0;
}
