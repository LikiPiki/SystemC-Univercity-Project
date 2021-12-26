#pragma once

#include <iostream>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "logger.h"

using namespace sc_core;

class Gelio : public sc_module, public Interface {

private:

    /**
     * Tick handler
     */
    void handler();

    /**
     * Buffer vector
     */ 
    std::vector<unsigned short> buffer;

    int currentTick = 0;

    /**
     * Generate fake gelio data
     */
    static unsigned short generatePartOfData();

    static constexpr int generateDataLen = 100;
    static constexpr int maxBufferSize = 10;

    static constexpr int sleepTicks = 30;

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Gelio";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

public:
    sc_port<Interface> port;
    sc_in<bool> clk;

    SC_CTOR( Gelio ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        log("gelio inited");
    }

    void receive(const std::vector<unsigned short>& packet) override;

};