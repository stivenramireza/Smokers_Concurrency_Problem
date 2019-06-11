#pragma once
#include "isync.h"
#include <semaphore.h>

class Sync{
public:
    static ISync* create(const char* name);
    static ISync* open(const char *name);
    static void destroy(const char *name);
    virtual void wait() = 0;
    virtual void signal() = 0;
    virtual void close() = 0;
    Sync(const char *name, bool open);
    virtual ~Sync() = 0;
};