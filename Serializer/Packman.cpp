/*
 * Fiahil
 * 14/05/2012
 */

#include <string>
#include <fstream>
#include "Profile.hpp"
#include "Match.hpp"
#include "Packman.hpp"

namespace Serializer
{
  Packman::Packman(std::string const& filename)
    : _os(filename.c_str())
  {
  }

  void		Packman::packProfile(Profile const& p)
  {
    this->_os	<< "#INFO"
      << "\t:" << p.getId()
      << "\t:" << p.getName()
      << "\t:" << p.getLvl()
      << "\t:" << p.getXp()
      << "\t:" << p.getTuto()
      << "\t:" << p.getSkin()
      << std::endl << std::endl;
    this->_os	<< "#STAT";
    for (size_t i = 0; i < 6; ++i) {
      this->_os << "\t:" << p.getStat().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#SKILLS";
    for (size_t i = 0; i < 3; ++i) {
      this->_os << "\t:" << p.getSkill().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#ACHIEVEMENT";
    for (size_t i = 0; i < 3; ++i) {
      this->_os << "\t:" << p.getAchievement().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#SAVES";
    for (size_t i = 0; i < 5; ++i) {
      this->_os << "\t:" << p.getSave().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#CONFIG" << std::endl;
    //TODO: Implement config serialization
    this->_os	<< "#ENDCONFIG" << std::endl;
  }

  void		Packman::packMatch(Match const& m)
  {
    this->_os	<< "#MAP" << std::endl;
    this->_os	<< "[";
    //TODO: Getters coordonees
    this->_os	<< "]" << std::endl;
    this->_os	<< "#ENDMAP" << std::endl << std::endl;
    this->_os	<< "#HEADER"
      		<< "\t:" << 0
		<< "\t:" << m._gameMode
		<< "\t:" << m._cheat
		<< std::endl << std::endl;
    this->_os	<< "#PLAYERS" << std::endl;
    for (size_t i = 0; i < m._players.size(); ++i) {
      //TODO: Implement Player serialization
      m._players[i];
    }
    this->_os	<< "#ENDPLAYERS" << std::endl;
  }
}
