#include "gyroscope.h"
#include "defs.h"

Gyroscope::Gyroscope(const sc_module_name &name) : sc_module(name) {
    log("Module created");

    mersenne = std::mt19937(rd());

    SC_METHOD(new_position_data);
    sensitive << e_generation_position_data;
}

void Gyroscope::read_packet(const std::vector<unsigned short> &packet) {

}

void Gyroscope::write_packet(const std::vector<unsigned short> &packet) {

}

void Gyroscope::new_position_data() {
    auto x = mersenne();
    auto y = mersenne();
    auto z = mersenne();

    std::cout << sc_time_stamp().to_string()
                << " "
                << name()
                << " new position is generated "
                << "x [" << x << "], "
                << "y [" << y << "], "
                << "z [" << z << "], " << std::endl;

    std::vector<unsigned short> packet;
    packet.push_back(32);
    packet.push_back(GYRO_PACKET_TYPE);
    packet.push_back(x & 0x000000FF);
    packet.push_back((x >> 8) & 0x000000FF);
    packet.push_back((x >> 16) & 0x000000FF);
    packet.push_back((x >> 24) & 0x000000FF);

    packet.push_back(y & 0x000000FF);
    packet.push_back((y >> 8) & 0x000000FF);
    packet.push_back((y >> 16) & 0x000000FF);
    packet.push_back((y >> 24) & 0x000000FF);

    packet.push_back(z & 0x000000FF);
    packet.push_back((z >> 8) & 0x000000FF);
    packet.push_back((z >> 16) & 0x000000FF);
    packet.push_back((z >> 24) & 0x000000FF);

    auto packet_size = packet.size();
    packet.push_back(calcCRC8(packet, 0, packet_size - 1));

    p_to_switch->write_packet(packet);

}
