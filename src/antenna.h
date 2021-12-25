#pragma once

#include <iostream>
#include <optional>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "helper.h"

using namespace sc_core;

class Antenna : public sc_module, public Interface {

private:

    /**
     * Tick handler
     */
    void handler();
    
    std::optional<unsigned short> byte;

    void sendToControlCenter(unsigned short byte);

public:
    sc_port<Interface> port;
    sc_port<Interface> radio;
    sc_in<bool> clk;

    SC_CTOR( Antenna ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        std::cout << "Antenna init" << std::endl;
    }

    void receive(const std::vector<unsigned short>& packet) override;

};