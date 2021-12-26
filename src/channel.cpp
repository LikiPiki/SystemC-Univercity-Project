#include "channel.h"

// proxy all bytes to controll center
void Channel::receive(const std::vector<unsigned short>& packet) {
    auto current = packet.front();
    procLog("RECEIVE", std::to_string(current));

    auto errorProbability = rand() % 100 == errorPercent ? true : false;

    if (errorProbability) {
        current = !current;
    }

    out->receive({current});
}