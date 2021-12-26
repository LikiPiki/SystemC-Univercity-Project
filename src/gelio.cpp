#include "gelio.h"

void Gelio::handler() {
    procLog("TICK", "ticking");

    currentTick++;

    if (currentTick == 30) {
        currentTick = 0;
        return;
    }

    if (currentTick > 10) {
        return;
    }

    const auto generatedByte = generatePartOfData();
    buffer.push_back(generatedByte);

    if (buffer.size() == Gelio::maxBufferSize) {
        send(port, Id::GELIO, Id::CPU, buffer);
        buffer.clear();
    }
}

void Gelio::receive(const std::vector<unsigned short>& packet) {
}

/**
 * Generate fake gelio data
 */
unsigned short Gelio::generatePartOfData() {
    return rand() % Gelio::generateDataLen;
}