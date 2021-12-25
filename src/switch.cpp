#include "switch.h"

SwitchModule::SwitchModule(const sc_module_name& name): sc_module(name) {
    log("Module created");

    //32 - CPU
    routing_table.push_back({1, 32});
    //33 - Engine
    routing_table.push_back({1, 33});
    //34 - Gyroscope
    routing_table.push_back({1, 34});
    //35 - Camera
    routing_table.push_back({1, 35});
    //36 - Gelio
    routing_table.push_back({1, 36});
    //37 - Antenna
    routing_table.push_back({1, 37});
}

void SwitchModule::write_packet(const std::vector<unsigned short> &packet) {
    procLog("RECEIVE", "got a packet!");

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
            procLog("UNKW DEST", " got addrees, " + std::to_string(address));
    }

}

void SwitchModule::read_packet(const std::vector<unsigned short> &packet) {

}
