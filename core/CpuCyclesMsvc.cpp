#include "core/CpuCycles.h"

#include <stdio.h>
#include <intrin.h>

namespace core {
    uint64_t getCpuCycles()
    {
        return __rdtsc();
    }
}