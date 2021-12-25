#pragma once

#include <systemc>
#include <vector>

#include "devices.h"

using namespace sc_core;

class Interface: public sc_interface {

public:

    virtual void receive(const std::vector<unsigned short>& packet) = 0;

    void send(sc_port<Interface>& port, Id from, Id to, const std::vector<unsigned short>& packet) {
        auto copyPacket = packet;

        // Insert sender id to sending package
        copyPacket.insert(copyPacket.begin(), static_cast<unsigned short>(from));
        copyPacket.insert(copyPacket.begin(), static_cast<unsigned short>(to));

	    port->receive(copyPacket);
    }

};