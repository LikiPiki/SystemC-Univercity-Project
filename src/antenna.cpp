#include "antenna.h"
#include "defs.h"

Antenna::Antenna(const sc_module_name& name): sc_module(name){
    log("Module created");
}

void Antenna::write_packet(const std::vector<unsigned short> &packet) {
    procLog("RECEIVE", "got a packet!");
    procLog("SEND", "transmitting data to the EARTH");
}

void Antenna::read_packet(const std::vector<unsigned short> &packet) {
}

void Antenna::check_receive_buffer() {
}
