#include "control_center.h"

void ControlCenter::receive(const std::vector<unsigned short>& packet) {
    auto current = packet.front();
    procLog("RECEIVE", std::to_string(current));

    buffer.push_back(current);

    /**
     * Receive full buffer,
     * erase buffer, calculate checksum
     */
    if (buffer.size() == 10) {
        procLog("RECEIVE FULL BUFFER", dataToLoggableString(&buffer[0], 10));

        buffer.clear();
    }
}