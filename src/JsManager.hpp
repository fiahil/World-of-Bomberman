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

#define JSMODE(x)	((x == JsMode::MENU) ? (1) : (x))

class JsManager
{
  typedef bool		(JsManager::*keyFunc)(JsMode::eMode) const;
  typedef bool		(JsManager::*confFunc)(JsMode::eMode, gdl::Keys::Key) const; 
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
    JsMode::eMode		_current;

  private:
    bool		kLeft(JsMode::eMode) const;
    bool		kRight(JsMode::eMode) const;
    bool		kUp(JsMode::eMode) const;
    bool		kDown(JsMode::eMode) const;

    bool		P1(JsMode::eMode, gdl::Keys::Key k) const;
    bool		P2(JsMode::eMode, gdl::Keys::Key k) const;
    bool		Menu(JsMode::eMode, gdl::Keys::Key k) const;

  public:
    static JsManager*	getMe(void);
    static void		delMe(void);

    gdl::Keys::Key	getKey(HumGame::eAction) const;
    bool		isJsDown(JsMode::eMode id, gdl::Keys::Key k) const;
    JsMode::eMode	getCurrent();
    void		resetCurrent();
};

#endif /* __JSMANAGER_HPP__ */
