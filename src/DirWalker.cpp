/*
 * Fiahil
 * 20 Mai 2012
 */

#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <stdexcept>
#include "DirWalker.hpp"

DirWalker::DirWalker(std::string const& name)
  : _dir(0), _current(0)
{
  this->_dir = opendir(name.c_str());
  if (this->_dir == 0)
    throw std::runtime_error(std::string(strerror(errno)));
  this->next();
}

DirWalker::~DirWalker()
{
  closedir(this->_dir);
}

std::string*	DirWalker::current() const
{
  return this->_current;
}

void		DirWalker::next()
{
  dirent*	val = readdir(this->_dir);

  if (val != 0)
    this->_current = new std::string(val->d_name);
  else
    this->_current = 0;
}

void		DirWalker::clean()
{
  delete this->_current;
  this->_current = 0;
}

bool		DirWalker::isEnd() const
{
  return this->_current == 0;
}

DirWalker&	DirWalker::operator++()
{
  this->next();
  return *this;
}

DirWalker&	DirWalker::operator++(int)
{
  this->next();
  return *this;
}

std::string*	DirWalker::operator*() const
{
  return this->current();
}
