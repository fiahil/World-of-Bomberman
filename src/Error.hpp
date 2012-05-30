/*
 * NicoW
 * 30.05.12
 */

#ifndef		__ERROR_HPP__
#define		__ERROR_HPP__

class		Error : public std::exception {};

class		EndOfGame : public Error
{
public:
  const char *what() const throw() { return ("The game finished"); }
};

#endif		/* __ERROR_HPP__ */
