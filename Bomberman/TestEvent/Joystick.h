#ifndef JOYSTICK_H
#define JOYSTICK_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <linux/joystick.h>
#include <string>
#include <sigc++-2.0/sigc++/sigc++.h>
#include <glibmm/thread.h>

using std::string;

// for more info about the Linux Joystick API read
// /usr/src/linux/Documentation/input/joystick-api.txt

struct EventJoystick
{
  int32_t time;
  int16_t value;
  int8_t number;
  bool synthetic;
};

// TODO: configurable joystick device; best a manager for autodetect...
class Joystick //: public sigc::trackable
{
public:
  sigc::signal <void, const EventJoystick&> signalAxis;
  sigc::signal <void, const EventJoystick&> signalButton;

  Joystick ();
  virtual ~Joystick ();

  /* Open a joystick device.
   * @param device A device (e.g. /dev/input/jsX).
   */
  bool open (const string &device);

  /* Close the joystick device.
   */
  bool close ();

  /*
   * @return Number of available buttons.
   * @return -1 Initializing not finished.
   */
  int getNumberOfButtons ();

  /*
   * @return Number of available axis.
   * @return -1 Initializing not finished.
   */
  int getNumberOfAxes ();
  
  /*
   * @return Identifier string of the Joystick
   */
  const string &getIdentifier ();

private: // intentionally not implemented
  Joystick             (const Joystick&);
  Joystick& operator = (const Joystick&);

private:
  struct js_event joy_event;
  int m_fd;
  Glib::Thread *thread;
  bool m_init;
  int m_axes;
  int m_buttons;
  string m_name;
  bool m_run;

  void loop ();
};

#endif // JOYSTICK_H
