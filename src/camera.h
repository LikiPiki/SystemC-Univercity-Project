//
// Created by Nikolai Sinyov on 25.10.2021.
//

#ifndef ONBOARD_PROJECTS_CAMERA_H
#define ONBOARD_PROJECTS_CAMERA_H

#include <systemc>
#include "interface.h"

using namespace sc_core;
class camera:
        public sc_module,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_switch;
public:
    SC_HAS_PROCESS(camera);
    explicit camera(const sc_module_name& name);

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;
};


#endif //ONBOARD_PROJECTS_CAMERA_H
