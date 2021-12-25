#include "antenna.h"
#include "defs.h"

Antenna::Antenna(const sc_module_name& name): sc_module(name){
    std::cout << std::string(name) + " module is created" << std::endl;
}

void Antenna::write_packet(const std::vector<unsigned short> &packet) {
    std::cout << sc_time_stamp().to_string() << " " << name() << " got a packet!" << std::endl;
    std::cout << sc_time_stamp().to_string() << " " << name() << " SEND NEW DATA TO EARTH!!!" << std::endl;
}

void Antenna::read_packet(const std::vector<unsigned short> &packet) {
}

void Antenna::check_receive_buffer() {
}
