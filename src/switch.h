#pragma once

#include <iostream>
#include <systemc>

#include "interface.h"
#include "devices.h"
#include "helper.h"

using namespace sc_core;

class Switch : public sc_module, public Interface {

private:

    void handler();
    
public:
    sc_port<Interface> gelio_port;
    sc_port<Interface> cpu_port;
    sc_port<Interface> antenna_port;

    sc_in<bool> clk;

    SC_CTOR( Switch ) {
	    SC_METHOD( handler );
        dont_initialize();
	    sensitive << clk.pos();

        std::cout << "switch init" << std::endl;
    }

    void receive(const std::vector<unsigned short>& packet) override;

};