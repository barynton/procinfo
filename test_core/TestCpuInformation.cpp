#include <catch2/catch_test_macros.hpp>

#include "core/CpuInformation.h"
#include <iostream>

TEST_CASE ("Get cores") {
    auto info = core::CpuInformation();
    CHECK(info.coreCount() != 0);
}

TEST_CASE ("Get model") {
    auto info = core::CpuInformation();
    auto model = info.model();
    CHECK(model != "Unknown");
    CHECK(!model.empty());

}

TEST_CASE ("Get frequency") {
    auto info = core::CpuInformation();
    CHECK(info.frequency() > 0);
}