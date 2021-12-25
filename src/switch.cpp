#include "switch.h"

void Switch::handler() {
	std::cout << "switch tick" << std::endl;
}

void Switch::receive(const std::vector<unsigned short>& packet) {
    std::cout << "[switch receive]" << std::endl; 

    auto copyPacket = packet;
    auto senderId = helper::getIdFromPacket(copyPacket);
    auto fromId = helper::getIdFromPacket(copyPacket);

    switch (senderId) {
        case Id::CPU:
            send(cpu_port, fromId, senderId, copyPacket);
            break;
        case Id::ANTENNA:
            send(antenna_port, fromId, senderId, copyPacket);
            break;
        default:
            std::cout << "destination not found" << std::endl;
            break;
    }
}