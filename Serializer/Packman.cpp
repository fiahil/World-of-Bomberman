/*
 * Fiahil
 * 14/05/2012
 */

#include <string>
#include <fstream>
#include <cassert>
#include <ctime>
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
      << "\t:" << p.getName()
      << "\t:" << p.getSkin()
      << "\t:" << p.getSkill()
      << std::endl << std::endl;
    this->_os	<< "#STAT"
      << "\t:" << p.getStat().getKills()
      << "\t:" << p.getStat().getDefeats()
      << "\t:" << p.getStat().getVictories()
      << "\t:" << p.getStat().getMaxKill()
      << std::endl << std::endl;
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#ACHIEVEMENTS";
    for (size_t i = 0; i < 3; ++i) {
      this->_os << "\t:" << p.getAchievement().at(i);
    }
    this->_os	<< std::endl << std::endl;
    this->_os	<< "#SAVES";
    for (size_t i = 0; i < p.getSave().size(); ++i) {
      this->_os << "\t:[" << p.getSave().at(i) << "]";
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
		<< "\t:" << m._gameMode
		<< "\t:" << time(0)
		<< "\t:" << m._players.size()
		<< std::endl << std::endl;
    this->_os	<< "#PLAYERS" << std::endl;
    for (size_t i = 0; i < m._players.size(); ++i) {
      this->_os	<< m._players[i]->getId()
		<< "\t:" << m._players[i]->getTeamId()
		<< "\t:" << m._players[i]->getType()
		<< "\t:" << m._players[i]->getColor()
		<< "\t:" << m._players[i]->getSkin()
		<< "\t:" << m._players[i]->getState()
		<< "\t:" << m._players[i]->getDir()
		<< "\t:" << m._players[i]->getWeapon()
		<< "\t:" << m._players[i]->getPos()._x
		<< "\t:" << m._players[i]->getPos()._y
		<< "\t:" << m._players[i]->getPv()
		<< std::endl;
    }
    this->_os	<< "#ENDPLAYERS" << std::endl;
  }
}
