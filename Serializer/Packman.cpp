/*
 * Fiahil
 * 14/05/2012
 */

#include <string>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <ctime>
#include "APlayer.hpp"
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
    for (size_t i = 0; i < Success::LAST; ++i) {
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

  void		Packman::operator()(APlayer const* p)
  {
    this->_os	<< p->getId()
      << "\t:" << p->getTeamId()
      << "\t:" << p->getType()
      << "\t:" << p->getPv()
      << "\t:" << p->getPos()._x
      << "\t:" << p->getPos()._y
      << "\t:" << p->getColor()
      << "\t:" << p->getLust()
      << "\t:" << p->getPower()
      << "\t:" << p->getNbKills()
      << "\t:" << p->getSpeed()
      << "\t:" << p->getWeapon()
      << "\t:" << p->getSkin()
      << "\t:" << p->getState()
      << "\t:" << p->getDir()
      << std::endl;
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
      << "\t:" << m._players.size() + m._cadaver.size() + m._dead.size()
      << std::endl << std::endl;
    this->_os	<< "#PLAYERS" << std::endl;
    std::for_each<std::vector<APlayer*>::const_iterator, Packman&>(m._players.begin(),
    m._players.end(), *this);
    this->_os	<< "#ENDPLAYERS" << std::endl;
    this->_os	<< "#DEADS" << std::endl;
    std::for_each<std::list<APlayer*>::const_iterator, Packman&>(m._dead.begin(),
    m._dead.end(), *this);
    std::for_each<std::list<APlayer*>::const_iterator, Packman&>(m._cadaver.begin(),
    m._cadaver.end(), *this);
    this->_os	<< "#ENDDEADS" << std::endl;
  }
}
