/*
 * Fiahil
 * 31.05.2012
 */

#ifndef __STAT_HPP__
#define __STAT_HPP__

#include <string>

class Stat
{
public:
  Stat();

private:
  size_t	_nbKills;
  size_t	_nbDefeats;
  size_t	_nbVictories;
  size_t	_nbMaxKills;

public:
  size_t	getKills(void) const;
  size_t	getDefeats(void) const;
  size_t	getVictories(void) const;
  size_t	getMaxKill(void) const;
  size_t	getScore(void) const;

  void	addKills(size_t);
  void	addDefeats(size_t);
  void	addVictories(size_t);
  void	addMaxKills(size_t);

  void	setKills(size_t);
  void	setDefeats(size_t);
  void	setVictories(size_t);
  void	setMaxKills(size_t);
};

#endif /* __STAT_HPP__ */
