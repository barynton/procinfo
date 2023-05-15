#include <iostream>
#include <functional>
#include <unordered_map>

#include <CLI/CLI.hpp>

#include "core/CpuInformation.h"

int main(int argc, char **argv) {
    core::CpuInformation info;
    CLI::App app{"CPU information"};
    app.require_subcommand(1, 1);

    auto all = app.add_subcommand("all", "Shows all information available");
    auto cores = app.add_subcommand("cores", "Shows cores count");
    auto frequency = app.add_subcommand("frequency", "Counts cpu frequency");
    auto model = app.add_subcommand("model", "Shows cpu model name, f.e. Intel Core i9-10900F");

    all->callback([&]() {
        std::cout 
        << "CPU model: " << info.model() << "\n"
        << "CPU cores: " << info.coreCount() << "\n"
        << "CPU frequency MHz: " << info.frequency() 
        << std::endl;
    });
    cores->callback([&]() {std::cout << info.coreCount() << std::endl;});
    frequency->callback([&]() {std::cout << info.frequency() << std::endl;});
    model->callback([&]() {std::cout << info.model() << std::endl;});
    
    CLI11_PARSE(app, argc, argv);
}