#pragma once

enum SynException { SYNC_EXCEPTION,
		    SYNC_INVPARAM,
		    SYNC_NOTIMPLEMETED,
		    SYNC_UKNOWN,
                    SYNC_NOTEXIST};

class ISync {
public:
  static ISync* create(const char* name);
  static ISync* open(const char *name);
  static void destroy(const char *name);
  virtual void wait() = 0;
  virtual void signal() = 0;
  virtual void close() = 0;
  ISync();
  virtual ~ISync() = 0;
};
