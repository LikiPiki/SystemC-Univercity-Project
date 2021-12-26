#pragma once

#include <iostream>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "helper.h"
#include "logger.h"

using namespace sc_core;

class CPU :
    public sc_module,
    public Logger,
    public Interface {

private:

    /**
     * Tick handler
     */
    void handler();

    /**
     * Buffer vector
     */ 
    std::vector<unsigned short> buffer;

    std::vector<unsigned short> bufferToSend;

    unsigned short proccess(unsigned short value);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "CPU";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);


public:
    sc_port<Interface> port;
    sc_in<bool> clk;

    SC_CTOR( CPU ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        log("CPU inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};