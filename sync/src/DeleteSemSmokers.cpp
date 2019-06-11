#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"
#include "sync.h"

using namespace std;

int
main(void) {

  for (int i = 0; i < nSEM; ++i) {
    try {
      Sync::destroy(names[i]);
    }
    catch (SynException& se) {
      cerr << "Error borrando los semaforos: " << endl;
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
