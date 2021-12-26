#pragma once

#include <iostream>
#include <optional>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "helper.h"
#include "logger.h"

using namespace sc_core;

class Channel :
    public sc_module,
    public Logger,
    public Interface {

private:
    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Channel";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);
    
    static inline const int errorPercent = 1; 

public:
    sc_port<Interface> port;
    sc_port<Interface> out;

    SC_CTOR( Channel ) {
        log("Channel inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};