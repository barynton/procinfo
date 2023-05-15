#pragma once

#include <cstdint>
#include <string>

namespace core {

class CpuInformation {
public:
    CpuInformation();

    //returns sum of cores
    uint32_t coreCount() const;

    std::string model(uint32_t packageId = 0) const;

    //returns frequencey of core with given id in MHz
    uint32_t frequency() const;

protected:
    uint32_t _id;
};

}