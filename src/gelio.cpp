#include "gelio.h"
#include "defs.h"

Gelio::Gelio(const sc_module_name& name): sc_module(name){
    std::cout << std::string(name) + " module is created" << std::endl;

    SC_METHOD(new_data);
}

void Gelio::new_data() {
    std::cout << sc_time_stamp().to_string() << " " << name() << " generate new data!" << std::endl;

    std::vector<unsigned short> packet;
    packet.push_back(32);
    packet.push_back(GELIO_PACKET_TYPE);
    for (int i = 0; i < 10; i++)
    {
        packet.push_back(i & 0x000000FF);
    }

    auto packet_size = packet.size();

    /**
     * Generating gelio data packet, sending data to main CPU
     */
    packet.push_back(calcCRC8(packet, 0, packet_size - 2));

    p_to_switch->write_packet(packet);
}

void Gelio::write_packet(const std::vector<unsigned short> &packet) {
    std::cout << sc_time_stamp().to_string() << " " << name() << " got a packet!" << std::endl;
}

void Gelio::read_packet(const std::vector<unsigned short> &packet) {
}

void Gelio::check_receive_buffer() {
}
