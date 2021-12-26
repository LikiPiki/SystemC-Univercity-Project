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

class ControlCenter :
    public sc_module,
    public Logger,
    public Interface {

private:
    /**
     * Buffer vector
     */ 
    std::vector<unsigned short> buffer;

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Control Center";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

public:
    sc_port<Interface> port;

    SC_CTOR( ControlCenter ) {
        log("Control Center inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};