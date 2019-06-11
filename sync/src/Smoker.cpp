#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "sync.h"

using namespace std;

static void usage(const char*);
static void smoker(const char *,
		   ISync *,
		   ISync *);

int
main(int argc, const char *argv[]) {

  if (argc != 3) usage(argv[0]);

  ISync *semwait = nullptr;
  ISync *semagent = nullptr;

  try {
    semwait = Sync::open(argv[1]);
    semagent = Sync::open(argv[2]);
  }
  catch (SynException& se) {
    cerr << "Error open semaphores"
	 << endl;
  }

  smoker(argv[1], semwait, semagent);

  return EXIT_SUCCESS;
}

static void usage(const char* progname) {
  cerr << "Usage: " << progname
       << " <smoker semaphore> <agent semaphore>"
       << endl;
  exit(EXIT_FAILURE);
}

static void smoker(const char *nombre,
		   ISync *semwait,
		   ISync *semagent) {

  for (;;) {
    semwait->wait();
    cerr << "Smoker: " << nombre
	 << " smoking" << endl;
    sleep(rand() % 10);
    semagent->signal();
  }
}
