#include "sync.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>
#include "names.h"

Sync::Sync(const char *name, bool open) :
  ISync(),
  name(name) {

}

Sync::~Sync() {
}

ISync* Sync::create(const char *name) {
  //sem_open(name,
            //O_CREAT | O_EXCL,
            //S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP, 0);
}

ISync* Sync::open(const char* name) {
  //sem_open(name, 0);
}

void Sync::destroy(const char* name) {
  //sem_unlink(name);
}

void Sync::wait() {
  // Implementar el método wait()
}

void Sync::signal() {
  // Implementar el método signal()
}

void Sync::close() {
  // Implementarel método close()
}