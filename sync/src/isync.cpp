#include <isync.h>

ISync::ISync() { }

ISync::~ISync() { }

ISync* ISync::create(const char* name) {
  return name == nullptr ? nullptr : nullptr;
}

ISync* ISync::open(const char *name) {
  return name == nullptr ? nullptr : nullptr;
}

void ISync::destroy(const char *name) {
  if (name == nullptr)
    throw SYNC_INVPARAM;
  else
    throw SYNC_NOTIMPLEMETED;
}
