#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "names.h"
#include "sync.h"

using namespace std;

static void agent(ISync *[]);

int
main(void) {

  ISync *sems[nSEM];

  try {
    for (int i = 0; i < nSEM; ++i) {
      sems[i] = Sync::open(names[i]);
    }
  }
  catch(SynException& se) {
    cerr << "Error openning semaphores"
	 << endl;
    return EXIT_FAILURE;
  }

  agent(sems);

  return EXIT_SUCCESS;
}


static void agent(ISync *sems[]) {

  for (;;) {
    cout << "Offering" << endl;
    int smoker = rand() % 3;
    sems[smoker]->signal();
    sems[nSEM - 1]->wait();
  }
}
