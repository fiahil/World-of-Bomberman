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
  private:
    JsManager();
    ~JsManager();

  private:
    static JsManager*	_me;

    std::map<gdl::Keys::Key, JsInput::eButton>	_tr;

  public:
    static JsManager*	getMe(void);
    static void		delMe(void);

    bool	isJsDown(size_t id, gdl::Keys::Key k) const;
};

#endif /* __JSMANAGER_HPP__ */
