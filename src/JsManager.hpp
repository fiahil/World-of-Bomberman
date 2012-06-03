/*
 * Fiahil
 * 3.06.2012
 */

#ifndef __JSMANAGER_HPP__
#define __JSMANAGER_HPP__

#include <map>
#include "Input.hpp"
#include "enum.hpp"
#include "Joystick.hpp"

class JsManager
{
  typedef bool		(JsManager::*keyFunc)(void) const;
  
  private:
    JsManager();
    ~JsManager();

  private:
    static JsManager*	_me;

    std::map<gdl::Keys::Key, JsInput::eButton>	_tr;
    std::map<gdl::Keys::Key, keyFunc>		_kf;

  private:
    bool		kLeft(void) const;
    bool		kRight(void) const;
    bool		kUp(void) const;
    bool		kDown(void) const;

  public:
    static JsManager*	getMe(void);
    static void		delMe(void);

    bool	isJsDown(size_t id, gdl::Keys::Key k) const;
};

#endif /* __JSMANAGER_HPP__ */
