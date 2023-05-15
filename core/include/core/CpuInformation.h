#pragma once

#include <cstdint>
#include <string>

namespace core {

class CpuInformation {
public:
    CpuInformation();

    //returns sum of cores
    uint32_t coreCount() const;

    //returns CPU model, f.e. Intel Core i9-10900F
    std::string model(uint32_t packageId = 0) const;

    //calculates CPU frequencey (MHz)
    uint32_t frequency() const;

protected:
    uint32_t _id;
};

}