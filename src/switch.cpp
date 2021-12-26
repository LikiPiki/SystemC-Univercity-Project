#include "switch.h"

void Switch::handler() {
    procLog("TICK", "ticking");
}

void Switch::receive(const std::vector<unsigned short>& packet) {
    procLog("RECEIVE", dataToLoggableString(&packet.front(), 12));

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
            procLog("UNKNOWN PACKAGE", "recived unknown package");
            break;
    }
}