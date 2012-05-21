/*
 * Fiahil
 * 20 Mai 2012
 */

#ifndef __DIRWALKER_HPP__
#define __DIRWALKER_HPP__

#include <string>
#include <dirent.h>
#include <sys/types.h>

class DirWalker
{
  public:
  DirWalker(std::string const& name);
  ~DirWalker();

  private:
  DirWalker(DirWalker const&);
  DirWalker&	operator=(DirWalker const&);

  private:
  DIR*		_dir;
  std::string*	_current;

  public:
  std::string*	current() const;
  void		next();
  void		clean();
  bool		isEnd() const;
  DirWalker&	operator++();
  std::string*	operator*() const;
};

#endif /* __DIRWALKER_HPP__ */

