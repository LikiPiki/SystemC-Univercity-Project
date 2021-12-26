#include "cpu.h"

void CPU::handler() {
    procLog("TICK", "ticking");

    if (!buffer.empty()) {
        for (int i = 0; i < buffer.size(); i++) {
            buffer[i] = proccess(buffer[i]);
        }

        // copy buffer to sending
        bufferToSend = buffer;

        buffer.clear();
        return;
    }

    if (!bufferToSend.empty()) {
        auto current = bufferToSend.front();

        send(port, Id::CPU, Id::ANTENNA, {current});

        bufferToSend.erase(bufferToSend.begin());
    }
}

void CPU::receive(const std::vector<unsigned short>& packet) {
    procLog("RECEIVE", dataToLoggableString(&packet.front(), 12));

    auto copyPacket = packet;
    auto senderId = helper::getIdFromPacket(copyPacket);
    auto fromId = helper::getIdFromPacket(copyPacket);

    buffer = copyPacket;
}

unsigned short CPU::proccess(unsigned short value) {
    return ((value & 0xFF) << 8) | ((value & 0xFF00) >> 8);
}