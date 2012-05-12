/*
 * Fiahil
 * 12.05.2012
 */

#ifndef		__CONFIG_HPP__
#define		__CONFIG_HPP__

/*
 * TODO: Refaire objet config
 */
class	Config
{
public:
  Config();
  ~Config();

private:
  Config(const Config &);

private:
  size_t	_idEvent;
  size_t	_idKey;
  size_t	_idJoystick;

public:
  size_t	getIdEvent(void) const;
  size_t	getIdKey(void) const;
  size_t	getIdJoystick(void) const;

  void		setIdEvent(size_t);
  void		setIdKey(size_t);
  void		setIdJoystick(size_t);
  void		setAllConfig(size_t, size_t, size_t);
};

#endif		/* __CONFIG_HPP__ */
