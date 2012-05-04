Bomberman
=========

Kaboum band power plus!

Coding Style
============

- file.hpp

--------------------------------
/*
 * Fiahil
 * 
 * 3 Mai 2012
 */

#include <system>

#include "user.hpp"

#ifndef __FILE_HPP_
#define __FILE_HPP_

class File : public IFile {
  public: /* Ctor */
    File();
    ~File();
    
  private: /* Attributes */
    File(File const&);
  
    int     _myVar;
    Object  _myObject;
    
  public: /* Methodes */
    void    print(const string &);
    void    moveObj(string const&);
};

#endif