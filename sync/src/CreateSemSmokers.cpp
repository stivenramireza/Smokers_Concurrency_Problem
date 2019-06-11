#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"
#include "sync.h"

using namespace std;

int
main(void) {
  ISync *sem[nSEM];

  for (int i = 0; i < nSEM; ++i) {
    try {
      sem[i] = Sync::create(names[i]);
    }
    catch (SynException& se) {
      cerr << "Error creating semaphores" << endl;
      return EXIT_FAILURE;
    }
    sem[i]->close();
  }

  return EXIT_SUCCESS;
}
