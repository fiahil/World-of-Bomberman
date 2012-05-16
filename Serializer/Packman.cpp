/*
 * Fiahil
 * 14/05/2012
 */

#include <string>
#include <fstream>
#include <cassert>
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
    for (size_t i = 0; i < p.getSave().size(); ++i) {
      this->_os << "\t:" << p.getSave().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#CONFIG" << std::endl;
    for (size_t i = 0; i < HumGame::LAST; ++i) {
      this->_os	<< i
		<< "\t:"
		<< p.getConfig().getConfig(static_cast<HumGame::eAction>(i))
		<< std::endl;
    }
    this->_os	<< "#ENDCONFIG" << std::endl;
  }

  void		Packman::packMatch(Match const& m)
  {
    assert(m._map != 0);

    this->_os	<< "#MAP" << std::endl;
    this->_os	<< "[";
    this->_os	<< m._map->getMap();
    this->_os	<< "]" << std::endl;
    this->_os	<< "#ENDMAP" << std::endl << std::endl;
    this->_os	<< "#HEADER"
      		<< "\t:" << 0
		<< "\t:" << m._gameMode
		<< "\t:" << m._cheat
		<< std::endl << std::endl;
    this->_os	<< "#PLAYERS" << std::endl;
    for (size_t i = 0; i < m._players.size(); ++i) {
      this->_os	<< m._players[i]->getId()
		<< "\t:" << m._players[i]->getTeamId()
		<< "\t:" << m._players[i]->getName()
		<< "\t:" << m._players[i]->getTeamName()
		<< "\t:" << m._players[i]->getType()
		<< "\t:" << m._players[i]->getColor()
		<< "\t:" << m._players[i]->getSkin()
		<< "\t:" << m._players[i]->getState()
		<< "\t:" << m._players[i]->getDir()
		<< "\t:" << m._players[i]->getWeapon()
		<< "\t:" << m._players[i]->getX()
		<< "\t:" << m._players[i]->getY()
		<< "\t:" << m._players[i]->getPv()
		<< std::endl;
    }
    this->_os	<< "#ENDPLAYERS" << std::endl;
  }
}
