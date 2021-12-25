#include "helper.h"

Id helper::getIdFromPacket(std::vector<unsigned short>& packet) {
    const auto senderId = static_cast<Id>(packet[0]);
    packet.erase(packet.begin());
    return senderId;
}
