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
    }

    if (buffer.size() == 11) {
        auto checksum = buffer[10];
        auto checksumCalculated = calcCRC8(&buffer[0], 0, buffer.size() - 1);

        if (checksum == checksumCalculated) {
            procLog("CHECKSUM", "VERIFIED!");
        } else {
            procLog("CHECKSUM", "PACKET NOT VALID!");
        }

        buffer.clear();
    }
}