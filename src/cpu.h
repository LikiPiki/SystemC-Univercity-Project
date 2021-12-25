#pragma once

#include <iostream>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "helper.h"

using namespace sc_core;

class CPU : public sc_module, public Interface {

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

public:
    sc_port<Interface> port;
    sc_in<bool> clk;

    SC_CTOR( CPU ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        std::cout << "CPU init" << std::endl;
    }

    void receive(const std::vector<unsigned short>& packet) override;

};