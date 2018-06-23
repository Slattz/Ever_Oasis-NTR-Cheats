#ifndef CTRPLUGINFRAMEWORK_SYSTEM_LOCK_HPP
#define CTRPLUGINFRAMEWORK_SYSTEM_LOCK_HPP

#include "ctrulib/synchronization.h"

struct KRecursiveLock;

namespace CTRPluginFramework
{
    class Mutex;
    class Lock
    {
    public:
        explicit Lock(LightLock &llock);
        explicit Lock(RecursiveLock &rlock);
        explicit Lock(KRecursiveLock *krlock);
        explicit Lock(Mutex &mutex);

        ~Lock(void);

    private:
        int     _type;
        union
        {
            LightLock       *_llock;
            RecursiveLock   *_rlock;
            KRecursiveLock  *_krlock;
            Mutex           *_mutex;
        };
    };
}

#endif
