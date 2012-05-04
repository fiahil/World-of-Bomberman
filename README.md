Bomberman
=========

Kaboum band power plus!

Coding Style
============

file.hpp
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
        void    moveObj(string const&) const;
    };

    #endif

file.cpp
--------------------------------
    /*
     * Fiahil
     *
     * 3 Mai 2012
     */
     
     #include <system>
     
     #include "user.hpp"
     
     File::File() : _myVar(0), _myObject(0) {
     }
     
     File::print(const string & str) {
        int   i = 0;
        
        for (int i = 0; i < 5; ++i) {
            std::cout << "i = " << i << std::endl;
        }
     }
     
     File::moveObj(string const& str) const {
        try {
            str += "Toto";
        }
        catch (...) {
            throw std::runtime_error("Error!");
        }
     }