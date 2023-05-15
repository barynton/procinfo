#include "core/CpuInformation.h"

#include <thread>
#include <chrono>

#include <cpuinfo.h>

#include "core/CpuCycles.h"

using namespace std::chrono_literals;

namespace {
    auto constexpr kFrequencyCalculationTime = 100ms;
}

namespace core {

CpuInformation::CpuInformation()
{
    cpuinfo_initialize();
}

uint32_t CpuInformation::coreCount() const {
    return cpuinfo_get_cores_count();
}

std::string CpuInformation::model(uint32_t packageId) const {
    auto packageInfo = cpuinfo_get_package(packageId);
    
    if (packageInfo) {
        return cpuinfo_get_package(packageId)->name;
    } else {
        return "Unknown";
    }
}

uint32_t CpuInformation::frequency() const {
    typedef std::chrono::duration<double, std::ratio<1,1>> floatseconds;
    auto cyclesStart = core::getCpuCycles();
    auto startTime = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(kFrequencyCalculationTime);
    auto elapsedCycles = core::getCpuCycles() - cyclesStart;
    auto elapsedTime = floatseconds(std::chrono::high_resolution_clock::now() - startTime).count();
    return elapsedCycles / elapsedTime / 1000000;
}

}