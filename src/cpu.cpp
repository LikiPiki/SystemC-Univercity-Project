#include "cpu.h"
#include "defs.h"

Cpu::Cpu(const sc_module_name& name): sc_module(name){
    log("Module created");

    SC_METHOD(check_receive_buffer);
    sensitive << checkRxBuffer;
}

void Cpu::write_packet(const std::vector<unsigned short> &packet) {
    std::cout << sc_time_stamp().to_string() << " " << name() << " got a packet!" << std::endl;
    auto type = packet.at(TYPE_PACKET_POSITION);

    switch(type) {
        case GELIO_PACKET_TYPE: {
            std::cout << sc_time_stamp().to_string()
                      << " "
                      << name()
                      << " Recognized packet type = GELIO_PACKET_TYPE"
                      << std::endl;
            
            // skip to first numbers becase, reciever_number, packet_type
            std::cout << "RECEIVE DATA: ";
            for (int i = 0; i < 10; i++) {
                std::cout << packet[i+2] << " ";
            }

            std::cout << std::endl;
            std::cout << "DATA ANALIZED" << std::endl;

            auto new_packet = packet;
            new_packet[0] = 37;
            p_to_switch->write_packet(new_packet);
            // sending to antenna
        }
            break;
        case CAMERA_PACKET_TYPE:
            break;
        case GYRO_PACKET_TYPE: {
            std::cout << sc_time_stamp().to_string()
                      << " "
                      << name()
                      << " Recognized packet type = GYRO_PACKET_TYPE"
                      << std::endl;
            auto new_packet = packet;
            new_packet[0] = 33;
            new_packet[TYPE_PACKET_POSITION] = ENGINE_PACKET_TYPE;
            new_packet[new_packet.size() - 1] = calcCRC8(new_packet, 0, new_packet.size() - 1);
            p_to_switch->write_packet(new_packet);
        }
            break;
        case ENGINE_PACKET_TYPE:
            break;
        default:
            break;
    }
}

void Cpu::read_packet(const std::vector<unsigned short> &packet) {

}

void Cpu::check_receive_buffer() {
    std::cout << sc_time_stamp().to_string()<<  " CPU time" << std::endl;
    checkRxBuffer.notify(1, SC_MS);
}
