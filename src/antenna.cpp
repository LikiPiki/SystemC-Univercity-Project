#include "antenna.h"

void Antenna::handler() {
	std::cout << "Antenna tick" << std::endl;

    if (byte) {
        std::cout << "SEND" << *byte << std::endl;
        sendToControlCenter(*byte);
        byte = std::nullopt;
    }
}

void Antenna::receive(const std::vector<unsigned short>& packet) {
    std::cout << "[antenna received]" << std::endl;

    auto copyPacket = packet;
    auto senderId = helper::getIdFromPacket(copyPacket);
    auto fromId = helper::getIdFromPacket(copyPacket);

    byte = copyPacket.front();
}

void Antenna::sendToControlCenter(unsigned short byte) {
    radio->receive({byte});
}
