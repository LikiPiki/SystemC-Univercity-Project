#pragma once

#include <vector>

#include "devices.h"

namespace helper {

	Id getIdFromPacket(std::vector<unsigned short>& packet);

}