#include "antenna.h"

void Antenna::handler() {
    procLog("TICK", "ticking");

    if (byte) {
        procLog("SEND", std::to_string(*byte));
        sendToControlCenter(*byte);
        byte = std::nullopt;
    }
}

void Antenna::receive(const std::vector<unsigned short>& packet) {
    auto copyPacket = packet;
    auto senderId = helper::getIdFromPacket(copyPacket);
    auto fromId = helper::getIdFromPacket(copyPacket);

    byte = copyPacket.front();

    procLog("RECEIVE", std::to_string(*byte));
}

void Antenna::sendToControlCenter(unsigned short byte) {
    radio->receive({byte});
}
