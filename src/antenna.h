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

class Antenna :
    public sc_module,
    public Logger,
    public Interface {

private:

    /**
     * Tick handler
     */
    void handler();
    
    std::optional<unsigned short> byte;

    void sendToControlCenter(unsigned short byte);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Antenna";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

public:
    sc_port<Interface> port;
    sc_port<Interface> radio;
    sc_in<bool> clk;

    SC_CTOR( Antenna ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        log("Antenna inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};