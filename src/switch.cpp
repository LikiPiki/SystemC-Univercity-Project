//
// Created by Nikolai Sinyov on 24.10.2021.
//

#include "switch.h"


SwitchModule::SwitchModule(const sc_module_name& name): sc_module(name) {
    std::cout << std::string(name) + " module is created" << std::endl;
    //32 - CPU
    //33 - Engine
    //34 - Gyroscope
    //35 - Camera
    //36 - Gelio
    //37 - Antenna
    routing_table.push_back({1, 32});
    routing_table.push_back({1, 33});
    routing_table.push_back({1, 34});
    routing_table.push_back({1, 35});
    routing_table.push_back({1, 36});
    routing_table.push_back({1, 37});
}

void SwitchModule::write_packet(const std::vector<unsigned short> &packet) {
    std::cout << sc_time_stamp().to_string() << " " << name() << " got a packet" << std::endl;

    auto address = packet.front();

    switch(address) {
        case 32:
            p_to_cpu->write_packet(packet);
            break;
        case 33:
            p_to_engine->write_packet(packet);
            break;
        case 34:
            p_to_gyroscope->write_packet(packet);
            break;
        case 35:
            p_to_camera->write_packet(packet);
            break;
        case 36:
            p_to_gelio->write_packet(packet);
            break;
        case 37:
            p_to_antenna->write_packet(packet);
            break;
        default:
            std::cout << sc_time_stamp().to_string() << " " << name() << " unknown dest address!" << std::endl;
    }

}

void SwitchModule::read_packet(const std::vector<unsigned short> &packet) {

}
