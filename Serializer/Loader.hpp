/*
 * Fiahil
 *
 * 3 Mai 2012
 */

#include <fstream>

namespace Serializer {
  class Loader {
    public:
      Loader(std::ifstream&);
      ~Loader();

    private:
      Loader(Loader const&);
  };
}
