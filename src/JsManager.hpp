/*
 * Fiahil
 * 3.06.2012
 */

#ifndef __JSMANAGER_HPP__
#define __JSMANAGER_HPP__

#include <map>
#include <vector>
#include <utility>
#include "Input.hpp"
#include "enum.hpp"
#include "Joystick.hpp"

class JsManager
{
  typedef bool		(JsManager::*keyFunc)(void) const;
  typedef bool		(JsManager::*confFunc)(gdl::Keys::Key) const;

  typedef std::map<gdl::Keys::Key, std::pair<JsInput::eButton, keyFunc> > JsMotion;
  typedef std::map<gdl::Keys::Key, JsInput::eButton>			  JsButton;
  
  private:
    JsManager();
    ~JsManager();

  private:
    static JsManager*	_me;

    JsButton			_p1b;
    JsMotion			_p1m;
    JsButton			_p2b;
    JsMotion			_p2m;
    JsButton			_mnb;
    JsMotion			_mnm;
    std::vector<confFunc>	_cf;

  private:
    bool		kLeft(void) const;
    bool		kRight(void) const;
    bool		kUp(void) const;
    bool		kDown(void) const;

    bool		P1(gdl::Keys::Key k) const;
    bool		P2(gdl::Keys::Key k) const;
    bool		Menu(gdl::Keys::Key k) const;

  public:
    static JsManager*	getMe(void);
    static void		delMe(void);

    bool		isJsDown(JsMode::eMode id, gdl::Keys::Key k) const;
};

#endif /* __JSMANAGER_HPP__ */
