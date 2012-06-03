/*
 * lemonn_v
 * 07.05.12
 */

#include <cstdlib>
#include <exception>
#include "Sound.hpp"
#include "JsManager.hpp"
#include "Bomberman.hpp"
#include "Error.hpp"

int		main()
{
  Bomberman	bomberman;
  time_t	now;

  time(&now);
  srandom(now);

  Sound::getMe();
  JsManager::getMe();

  try
    {
      bomberman.run();
    }
  catch (std::exception & end)
    {
      std::cout << end.what() << std::endl;
    }
  Sound::delMe();
  JsManager::delMe();
  return 0;
}
