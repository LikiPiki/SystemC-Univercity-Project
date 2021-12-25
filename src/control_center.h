#pragma once

#include <iostream>
#include <optional>
#include <systemc>
#include <random>

#include "interface.h"
#include "devices.h"
#include "helper.h"

using namespace sc_core;

class ControlCenter : public sc_module, public Interface {

private:

public:
    sc_port<Interface> port;

    SC_CTOR( ControlCenter ) {
        dont_initialize();
        std::cout << "ControlCenter init" << std::endl;
    }

    void receive(const std::vector<unsigned short>& packet) override;

};