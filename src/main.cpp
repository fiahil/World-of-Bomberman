/*
 * lemonn_v
 * 07.05.12
 */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "Sound.hpp"
#include "JsManager.hpp"
#include "Bomberman.hpp"
#include "Error.hpp"

int		main()
{
  try
  {
    Bomberman	bomberman;
    time_t	now;

    time(&now);
    srandom(now);

    Sound::getMe();
    JsManager::getMe();

    bomberman.run();

    Sound::delMe();
    JsManager::delMe();
  }
  catch (const EndOfGame & end)
  {
  }
  catch (const std::exception & end)
  {
    std::cerr << end.what() << std::endl;
  }
  catch (...)
  {
    std::cerr << "Unknown error occured." << std::endl;
  }
  return 0;
}
