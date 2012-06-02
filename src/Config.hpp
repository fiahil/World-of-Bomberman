/*
 * Fiahil
 * 12.05.2012
 */

#ifndef		__CONFIG_HPP__
#define		__CONFIG_HPP__

#include <utility>
#include <map>
#include <GL/gl.h>
#include <Input.hpp>
#include "enum.hpp"

class	Config
{
public:
  Config();
  ~Config();

private:
  Config(Config &);
  static bool	feIsAllSet(std::pair<HumGame::eAction, gdl::Keys::Key>);

private:
  std::map<HumGame::eAction, gdl::Keys::Key> _conf;

public:
  HumGame::eAction	setConfig(HumGame::eAction, gdl::Keys::Key);
  gdl::Keys::Key	getConfig(HumGame::eAction) const;
  bool			isAllSet() const;
  bool			operator==(Config const & ) const;
  bool			operator!=(Config const & ) const;
};

#endif		/* __CONFIG_HPP__ */
