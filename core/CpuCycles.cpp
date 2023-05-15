#include "core/CpuCycles.h"

namespace core {

uint64_t getCpuCycles()
{
    uint32_t hi, lo;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)lo) | (((uint64_t)hi) << 32 );
}

}