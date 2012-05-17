/*
 * Fiahil
 * 12.05.2012
 */

#ifndef		__CONFIG_HPP__
#define		__CONFIG_HPP__

#include <map>
#include <GL/gl.h>
#include <Input.hpp>
#include "enum.hpp"

/*
 * TODO: Refaire objet config
 */
class	Config
{
public:
  Config();
  ~Config();

private:
  Config(Config &);

private:
  std::map<HumGame::eAction, gdl::Keys::Key> _conf;
public:
  /***********************************************************************
   ** Function : setConfig
   ** Comment  :
   **   - return HumGame::LAST si aucun problem rencontre
   **   - return l'action a laquelle la touche etait deja assigne si problem
   **     et reassigne gdl::Keys::Count (unset) a l'ancienne
   ***********************************************************************/
  HumGame::eAction	setConfig(HumGame::eAction, gdl::Keys::Key);
  gdl::Keys::Key	getConfig(HumGame::eAction) const;
  bool			isAllSet() const;
  bool			operator==(Config const & ) const;
  bool			operator!=(Config const & ) const;
};

#endif		/* __CONFIG_HPP__ */
