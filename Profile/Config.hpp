//
// Config.hpp for Bomberman in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile
// 
// Made by nicolas magere
// Login   <magere_n@epitech.net>
// 
// Started on  Thu May 10 16:32:20 2012 nicolas magere
// Last update Thu May 10 16:46:32 2012 nicolas magere
//

#ifndef		__CONFIG_HPP__
#define		__CONFIG_HPP__

class		Config
{
private:
  size_t	_idEvent;
  size_t	_idKey;
  size_t	_idJoystick;

public:
  Config();
  ~Config();
  Config(const Config &);
  const Config & operator=(const Config &);

  size_t	getIdEvent(void) const;
  size_t	getIdKey(void) const;
  size_t	getIdJoystick(void) const;

  void		setIdEvent(size_t);
  void		setIdKey(size_t);
  void		setIdJoystick(size_t);
};

#endif		/* __CONFIG_HPP__ */

