#pragma once

#include <iostream>
#include <systemc>

#include "interface.h"
#include "devices.h"
#include "helper.h"
#include "logger.h"

using namespace sc_core;

class Switch :
    public sc_module,
    public Logger,
    public Interface {

private:

    void handler();

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Switch";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);
    
public:
    sc_port<Interface> gelio_port;
    sc_port<Interface> cpu_port;
    sc_port<Interface> antenna_port;

    sc_in<bool> clk;

    SC_CTOR( Switch ) {
	    SC_METHOD( handler );
	    sensitive << clk.pos();

        log("switch inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};